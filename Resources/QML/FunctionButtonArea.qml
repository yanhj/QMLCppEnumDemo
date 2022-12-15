//********************************************************
/// @brief
/// @author yanhuajian
/// @date 2021/11/25
/// @note
/// @version 1.0.0
//********************************************************

import QtQuick 2.0
import EnumDemo 1.0

Rectangle {
    id: window
    width: 300
    height: 300
    color:"red"

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
        anchors.top: text1.bottom
        text: "\n\nthis is QStringListTest\n" + list.getQStringData() + "\n" + list.getListData()[0]
    }

    QMapTest {
        id: mapObj
    }
    Text {
        id: text3
        anchors.top: text2.bottom
        text: "\n\nthis is QMapTest\n" + mapObj.getMapData()["2"]
    }

    StructTest {
        id: structObj
    }
    Text {
        id: text4
        anchors.top: text3.bottom
        text: "\n\nthis is StructTest\n" + structObj.getStructData()["name"] + "\n" + structObj.getStructData()["id"]
    }

    Image {
        id: label5
        anchors.top: text4.bottom
        source: "qrc:images/1.png"
    }
}


