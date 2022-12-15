//********************************************************
/// @brief 
/// @author yanhuajian
/// @date 2022/12/15
/// @note
/// @version 1.0.0
//********************************************************

#pragma once

#include <QtCore/QString>
#include <QtCore/QObject>
#include <QtCore/QJsonObject>

struct StructTestInfo
{
    QString name;
    int id;
};

class StructTest : public QObject
{
    Q_OBJECT
public:
    explicit StructTest();

    ~StructTest();
    Q_INVOKABLE QJsonObject getStructData()
    {
        StructTestInfo info;
        info.name = "struct-name";
        info.id = 1;
        QJsonObject jsonObject;
        jsonObject.insert("name", info.name);
        jsonObject.insert("id", info.id);
        return jsonObject;
    }
};
