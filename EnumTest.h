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

enum class CppEnum{
    Index_One,
    Index_Two,
};
//枚举在qml中使用非方式1
namespace EnumTestSpace {
    Q_NAMESPACE
    enum class Sex{
        //qml中使用的枚举必须首字母大写
        Female = (int)CppEnum::Index_One,
        Male = (int)CppEnum::Index_Two,
    };
    Q_ENUM_NS(Sex)
}

//枚举在qml中使用非方式2
class EnumTest : public QObject{
    Q_OBJECT
public:
    enum class Sex{
        //qml中使用的枚举必须首字母大写
        Female = (int)CppEnum::Index_One,
        Male = (int)CppEnum::Index_Two,
    };
    Q_ENUM(Sex)

public:
    EnumTest();
    ~EnumTest();

    Q_INVOKABLE QString getSex(EnumTestSpace::Sex type)
   {
        switch (type) {
            case EnumTestSpace::Sex::Female:
                return QString("EnumTestSpace::Sex::Female");
            case EnumTestSpace::Sex::Male:
                return QString("EnumTestSpace::Sex::Male");
        }
        return QString("error");
    }
    Q_INVOKABLE QString getSex2(Sex type)
   {
        switch (type) {
            case Sex::Female:
                return QString("EnumTest::Sex::Female");
            case Sex::Male:
                return QString("EnumTest::Sex::Male");
        }
        return QString("error");
    }
};
