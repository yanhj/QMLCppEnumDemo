//********************************************************
/// @brief
/// @author yanhuajian
/// @date 2021/11/25
/// @note
/// @version 1.0.0
//********************************************************

#include "ToolButtonHelper.h"

ToolButtonHelper::ToolButtonHelper()
:QObject(){
}

ToolButtonHelper::~ToolButtonHelper() {

}

ToolButtonHelper* ToolButtonHelper::instance() {
    static ToolButtonHelper sInstance;
    return &sInstance;
}