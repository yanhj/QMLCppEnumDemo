//********************************************************
/// @brief
/// @author yanhuajian
/// @date 2021/11/25
/// @note
/// @version 1.0.0
//********************************************************

import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: root
    width: 640
    height: 480
    visible: true
    color: "white"
    title: qsTr("Hello World")

    RowLayout {
        anchors {
            fill: parent
            margins: 10
        }
        Button {
            id: button
            text: qsTr("Basic Type")
            onClicked: {
                basicTypeTest.visible = true
                imageProviderDlg.visible = false
            }
        }
        Button {
            id: button2
            text: qsTr("QQuickImageProvider")
            onClicked: {
                imageProviderDlg.visible = true
                basicTypeTest.visible = false
            }
        }
    }

        BasicTypeTest {
            id: basicTypeTest
            visible: false
        }
        ImageProvider {
            id: imageProviderDlg
            visible: false
        }
}