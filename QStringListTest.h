//********************************************************
/// @brief 
/// @author yanhuajian
/// @date 2022/12/15
/// @note
/// @version 1.0.0
//********************************************************

#pragma once

#include <QtCore/QObject>
#include <QtCore/QStringList>

class QStringListTest : public QObject
{
    Q_OBJECT
public:
    explicit QStringListTest();

    ~QStringListTest();

    Q_INVOKABLE QStringList getListData()
    {
        QStringList list;
        list << "list-index-1" << "list-index-2" << "list-index-3";
        return list;
    }

    Q_INVOKABLE QString getQStringData()
    {
        return QString("I'm QString");
    }
};
