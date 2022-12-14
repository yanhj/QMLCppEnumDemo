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

    IconEnum
    {
        id: help
    }
    Text
    {
        //使用枚举
        text:help.getIcon(IconEnum.IconDelete) + "\n" + help.getSex(EnumSpace.Female);
    }
}


