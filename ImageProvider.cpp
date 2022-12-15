//********************************************************
/// @brief 
/// @author yanhuajian
/// @date 2022/12/15
/// @note
/// @version 1.0.0
//********************************************************

#include "ImageProvider.h"
#include <QtGui/QMovie>

constexpr int GIF_COUNT = 12;

class ImageProviderPrivate {
public:
    ImageProviderPrivate(ImageProvider* q):q_ptr(q) {
        m_imageProvider = new QuickImageProvider();
    }
    ~ImageProviderPrivate() {
    }

    void init() {
        for(int i = 0; i < GIF_COUNT; ++i) {
            m_movie[i] = new QMovie(QString(":/gif/0.gif"));
            QObject::connect(m_movie[i], &QMovie::frameChanged, q_ptr, [this, i](int frame) {
                m_imageProvider->updateImage(QString::number(i), m_movie[i]->currentImage());
                q_ptr->Q_EMIT imageChanged(i);
            });
        }
    }
public:
    QuickImageProvider* m_imageProvider = nullptr;
    ImageProvider* q_ptr = nullptr;
    QMovie* m_movie[GIF_COUNT]={0};
    Q_DECLARE_PUBLIC(ImageProvider)
};

ImageProvider::ImageProvider()
: d_ptr(new ImageProviderPrivate(this)) {
    d_ptr->init();
}

ImageProvider::~ImageProvider() {
}

QuickImageProvider* ImageProvider::getImageProvider() const {
    Q_D(const ImageProvider);
    return d->m_imageProvider;
}

void ImageProvider::start() {
    Q_D(ImageProvider);
    for(int i = 0; i < GIF_COUNT; ++i) {
        d->m_movie[i]->start();
    }
}

int ImageProvider::imageCount() const {
    return GIF_COUNT;
}