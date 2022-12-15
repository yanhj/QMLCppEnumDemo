//********************************************************
/// @brief 
/// @author yanhuajian
/// @date 2022/12/15
/// @note
/// @version 1.0.0
//********************************************************

#pragma once

#include <QtQuick/QQuickImageProvider>
#include <QtCore/QHash>
#include <QtCore/QString>
#include <QtGui/QImage>
#include <QtGui/QPixmap>

class QuickImageProvider : public QQuickImageProvider {
public:
    explicit QuickImageProvider();

    ~QuickImageProvider();

    void updateImage(const QString& id, const QImage& image);

#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    virtual QImage requestImage(const QString &id, QSize *size, const QSize& requestedSize, const QQuickImageProviderOptions &options);
    virtual QPixmap requestPixmap(const QString &id, QSize *size, const QSize& requestedSize, const QQuickImageProviderOptions &options);
    virtual QQuickTextureFactory *requestTexture(const QString &id, QSize *size, const QSize &requestedSize, const QQuickImageProviderOptions &options);
#else
    virtual QImage requestImage(const QString &id, QSize *size, const QSize& requestedSize);
    virtual QPixmap requestPixmap(const QString &id, QSize *size, const QSize& requestedSize);
    virtual QQuickTextureFactory *requestTexture(const QString &id, QSize *size, const QSize &requestedSize);
#endif

private:
    QHash<QString, QImage> m_imageMap;
};
