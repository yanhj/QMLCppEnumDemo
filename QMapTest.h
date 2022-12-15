//********************************************************
/// @brief 
/// @author yanhuajian
/// @date 2022/12/15
/// @note
/// @version 1.0.0
//********************************************************

#pragma once

#include <QtCore/QObject>
#include <QtCore/QMap>
#include <QtCore/QVariantMap>

class QMapTest : public QObject
{
    Q_OBJECT
public:
    explicit QMapTest();

    ~QMapTest();

    Q_INVOKABLE QVariantMap getMapData()
    {
        QMap<QString, QString> map;
        map.insert("1", "map-value-1");
        map.insert("2", "map-value-2");
        map.insert("3", "map-value-3");
        QVariantMap variantMap;
        for(auto key : map.keys())
        {
            variantMap.insert(key, map.value(key));
        }
        return variantMap;
    }
};
