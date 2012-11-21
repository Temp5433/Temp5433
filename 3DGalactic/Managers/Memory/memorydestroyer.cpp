#include "memorydestroyer.h"
#include <qdebug.h>

MemoryDestroyer::MemoryDestroyer(MemoryCollection *collection, QObject *parent):
    QObject(parent)
{
    this->collection = collection;
}

bool MemoryDestroyer::DestroyModel(EmptyModel *model)
{
    bool control = this->collection->getControl();
    qDebug()<<"MEMORY:DESTROYER:GetControl - "<<control;
    if(control)
    {
        this->collection->addFreeModel(model);
        return true;
    }
    return false;
}
