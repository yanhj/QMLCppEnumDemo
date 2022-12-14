//********************************************************
/// @brief
/// @author yanhuajian
/// @date 2021/11/25
/// @note
/// @version 1.0.0
//********************************************************

#pragma once

#include <QtCore/QObject>
#include <QtCore/QMetaType>
#include <QtCore/QDebug>

//枚举在qml中使用非方式1
namespace EnumSpace {
    Q_NAMESPACE
    enum class Sex{
        //qml中使用的枚举必须首字母大写
        Female,
        Male,
    };
    Q_ENUM_NS(Sex)
}

//枚举在qml中使用非方式2
class ToolButtonHelper : public QObject{
    Q_OBJECT
public:
    enum IconIndex
    {
        //qml中使用的枚举必须首字母大写
        IconText=1,
        IconDelete,
    };
    Q_ENUM(IconIndex)

public:
    ToolButtonHelper();
    ~ToolButtonHelper();
    static ToolButtonHelper* instance();
     Q_INVOKABLE QString getIcon(IconIndex type)
    {
         qDebug() << type;
         switch (type) {
             case IconIndex::IconText:
                 return QString("IconText");

             case IconIndex::IconDelete:
                 return QString("IconDelete");
         }
         return QString("unknown");
     }

    Q_INVOKABLE QString getSex(EnumSpace::Sex type)
   {
        switch (type) {
            case EnumSpace::Sex::Female:
                return QString("Female");
            case EnumSpace::Sex::Male:
                return QString("Male");
        }
        return QString("error");
    }
};
