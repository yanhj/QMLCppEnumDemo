#include <QApplication>
#include <QPushButton>
#include <QtQuickWidgets/QQuickWidget>
#include <QtQuick/QQuickView>
#include <QtCore/QObject>
#include <QtQml/QQmlEngine>
#include "EnumTest.h"
#include "QStringListTest.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QQuickView view;

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

    const QString mainQmlApp = QStringLiteral("qrc:///QML/FunctionButtonArea.qml");
    view.setSource(QUrl(mainQmlApp));
    view.setResizeMode(QQuickView::SizeRootObjectToView);

    QObject::connect(view.engine(), SIGNAL(quit()), qApp, SLOT(quit()));
    view.setGeometry(QRect(100, 100, 360, 640));
    view.show();
    return QApplication::exec();
}
