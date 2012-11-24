#ifndef REMODEMANAGER_H
#define REMODEMANAGER_H

#include <QObject>

#include "Managers/Memory/memorymanager.h"
#include "Managers/ReMode/remodechanger.h"
#include "Managers/ReMode/retexturechanger.h"

class ReModeManager : public QObject
{
    Q_OBJECT
public:
    explicit ReModeManager(QObject *parent = 0);
    void connectionToMemory(MemoryManager *manager);
private:
    void Configuration();

    ReModeChanger *model;
    ReTextureChanger *texture;
    MemoryManager *memory;
signals:

public slots:

};

#endif // REMODEMANAGER_H
