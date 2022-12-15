//********************************************************
/// @brief
/// @author yanhuajian
/// @date 2021/11/25
/// @note
/// @version 1.0.0
//********************************************************

import QtQuick 2.0
import QtQuick.Controls 2.2


ApplicationWindow
{
    width: 640
    height: 480
    visible: true
    title: qsTr("QQuickImageProvider demo")
    Connections {
        target: imageProvider
        function onImageChanged(index){
            /**
              * 1. source为图像源索引
              * 2. ###用于分隔
              * 3. Date.now()用于更新
              */
            sourceRepeater.itemAt(index).source = "image://imageProvider/" + index + "###" + Date.now();
        }
    }
    Grid {
        id: grid
       rows: 3
       columns: imageProvider.imageCount() / 3
       anchors.fill: parent

       Repeater {
           id: sourceRepeater
           model: imageProvider.imageCount()

           Image {
               width: parent.width / grid.columns
               height: parent.height / grid.rows
               fillMode: Image.PreserveAspectFit

               property bool running: true

               Image {
                   width: 80
                   height: 80
                   anchors.centerIn: parent
                   opacity: 0.7
                   source: parent.running ? "" : "qrc:/images/1.png"
               }

               Text {
                   anchors.left: parent.left
                   anchors.leftMargin: 12
                   anchors.top: parent.top
                   anchors.topMargin: 12
                   font.bold: true
                   font.pointSize: 30
                   color: "red"
                   text: index
               }

               Rectangle {
                   anchors.fill: parent
                   border.width: 2
                   border.color: "#89f2f5"
                   color: "transparent"
               }
           }
       }
   }
}