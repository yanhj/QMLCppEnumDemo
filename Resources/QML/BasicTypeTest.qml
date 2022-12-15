//********************************************************
/// @brief
/// @author yanhuajian
/// @date 2021/11/25
/// @note
/// @version 1.0.0
//********************************************************

import QtQuick 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import EnumDemo 1.0

ApplicationWindow {
    id: window
    width: 300
    height: 400
    color:"white"
    title: qsTr("基本类型测试")
    ScrollView {
    width: 300
    height: 400
        ColumnLayout {
            id: columnLayout
            anchors.fill: parent
            anchors.margins: 10
            spacing: 10
            EnumTest
            {
                id: help
            }
            Text
            {
                id: text1
                //使用枚举
                text:help.getSex2(EnumTest.Female) + "\n" + help.getSex(EnumTestSpace.Male);
            }
            onWidthChanged:
            {
                console.log("EnumTestSpace")
                console.log(EnumTestSpace.Female)
                console.log(EnumTestSpace.Male)

                console.log("EnumTest")
                console.log(EnumTest.Female)
                console.log(EnumTest.Male)
            }

            QStringListTest {
                id: list
            }
            Text {
                id: text2
                text: "\n\nthis is QStringListTest\n" + list.getQStringData() + "\n" + list.getListData()[0]
            }

            QMapTest {
                id: mapObj
            }
            Text {
                id: text3
                text: "\n\nthis is QMapTest\n" + mapObj.getMapData()["2"]
            }

            StructTest {
                id: structObj
            }
            Text {
                id: text4
                text: "\n\nthis is StructTest\n" + structObj.getStructData()["name"] + "\n" + structObj.getStructData()["id"]
            }

            Text {
                text: qsTr("显示图片示例")
            }
            Image {
                id: label5
                source: "qrc:images/1.png"
            }
        }
    }

}


