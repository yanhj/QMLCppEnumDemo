//********************************************************
/// @brief 
/// @author yanhuajian
/// @date 2022/12/15
/// @note
/// @version 1.0.0
//********************************************************

#pragma once

#include <QtCore/QObject>
#include "QuickImageProvider.h"

class ImageProviderPrivate;
class ImageProvider : public QObject {
    Q_OBJECT
public:
    explicit ImageProvider();
    ~ImageProvider();

    Q_INVOKABLE void start();
    Q_INVOKABLE QuickImageProvider* getImageProvider() const;
    Q_INVOKABLE int imageCount() const;

Q_SIGNALS:
    void imageChanged(int index);

private:
    Q_DECLARE_PRIVATE(ImageProvider);
    ImageProviderPrivate* d_ptr;
};
