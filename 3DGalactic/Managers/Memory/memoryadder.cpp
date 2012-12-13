#include "memoryadder.h"
#include <qdebug.h>

MemoryAdder::MemoryAdder(MemoryCollection *collection, QObject *parent):
    QObject(parent)
{
    this->collection = collection;
}

void MemoryAdder::Configuration()
{
    this->collection->setMemorySize("Asteroid", 10);
    this->collection->setMemorySize("Fog", 10);
    this->collection->setMemorySize("Planet3D", 5);
    this->collection->setMemorySize("Satallite", 10);
    this->collection->setMemorySize("Spline", 10);
    this->collection->setMemorySize("Star", 5);
    this->collection->setMemorySize("System", 10);
    this->collection->setMemorySize("Star3d", 5);
}

EmptyModel* MemoryAdder::askModel(QString &type)
{
    EmptyModel* temp = NULL;
    bool control = this->collection->getControl();
    qDebug()<<"MEMORY:ADDER:GetControl - "<<control;
    if(control)
    {
        temp = this->collection->getFreeModel(type);
        if(temp==NULL)
        {
            unsigned int size = this->collection->getMemorySize(type);
            this->collection->setMemorySize(type,size+10);
            temp = this->collection->getFreeModel(type);
        }
    }
    return temp;
}

