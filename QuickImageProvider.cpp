//********************************************************
/// @brief 
/// @author yanhuajian
/// @date 2022/12/15
/// @note
/// @version 1.0.0
//********************************************************

#include "QuickImageProvider.h"

QuickImageProvider::QuickImageProvider()
: QQuickImageProvider(QQuickImageProvider::Image){
}

QuickImageProvider::~QuickImageProvider() {
}

void QuickImageProvider::updateImage(const QString& id, const QImage& image) {
    m_imageMap[id] = image;
}

#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
QImage QuickImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize, const QQuickImageProviderOptions &options) {
    Q_UNUSED(id)
    Q_UNUSED(size)
    Q_UNUSED(requestedSize)
    auto img = m_imageMap[id];
    if(img.size() != requestedSize) {
        img = img.scaled(requestedSize);
    }
    return img;
}

QPixmap QuickImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize, const QQuickImageProviderOptions &options) {
    return QPixmap::fromImage(requestImage(id, size, requestedSize, options));
}

QQuickTextureFactory *QuickImageProvider::requestTexture(const QString &id, QSize *size, const QSize &requestedSize, const QQuickImageProviderOptions &options) {
    return nullptr;
}

#else
QImage QuickImageProvider::requestImage(const QString &id, QSize *size, const QSize &requestedSize) {
    auto img = m_imageMap[id.left(id.indexOf("###"))];
    if(img.isNull()) {
        return QImage();
    }
    if(!requestedSize.isEmpty() && img.size() != requestedSize) {
        img = img.scaled(requestedSize);
    }
    if(nullptr != size && !requestedSize.isEmpty()) {
        *size = requestedSize;
    }
    return img;
}

QPixmap QuickImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize) {
    return QPixmap::fromImage(requestImage(id, size, requestedSize));
}

QQuickTextureFactory *QuickImageProvider::requestTexture(const QString &id, QSize *size, const QSize &requestedSize) {
    Q_UNUSED(id)
    Q_UNUSED(size)
    Q_UNUSED(requestedSize)
    return nullptr;
}
#endif