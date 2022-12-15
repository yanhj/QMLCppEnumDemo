#include <QApplication>
#include <QPushButton>
#include <QtQuickWidgets/QQuickWidget>
#include <QtQuick/QQuickView>
#include <QtCore/QObject>
#include <QtQml/QQmlEngine>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include "EnumTest.h"
#include "QStringListTest.h"
#include "QMapTest.h"
#include "StructTest.h"
#include "ImageProvider.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    //注册Qml数据
    //方式
    qmlRegisterUncreatableMetaObject(
            EnumTestSpace::staticMetaObject, // meta object created by Q_NAMESPACE macro
      "EnumDemo",                // import statement (can be any string)
      1, 0,                          // major and minor version of the import
      "EnumTestSpace",                 // name in QML (does not have to match C++ name)
      "Error: only enums"            // error in case someone tries to create a MyNamespace object
    );
    qRegisterMetaType <EnumTestSpace::Sex>( "EnumTestSpace" );

    //方式2
    qmlRegisterType<EnumTest>("EnumDemo", 1, 0, "EnumTest");
    //注册Qml数据
    qmlRegisterType<QStringListTest>("EnumDemo", 1, 0, "QStringListTest");
    //注册Qml数据
    qmlRegisterType<QMapTest>("EnumDemo", 1, 0, "QMapTest");
    //注册Qml数据
    qmlRegisterType<StructTest>("EnumDemo", 1, 0, "StructTest");

    const QString mainQmlApp =  QStringLiteral("qrc:///QML/main.qml");
    ImageProvider* imageProvider = new ImageProvider();
    QQmlApplicationEngine qml;
    qml.addImageProvider("imageProvider", imageProvider->getImageProvider());
    qml.rootContext()->setContextProperty("imageProvider", imageProvider);
    qml.load(QUrl(mainQmlApp));
    imageProvider->start();
    return a.exec();
}
