#include "memorymanager.h"
#include "Managers/Memory/memorycollection.h"
#include <qdebug.h>

MemoryManager::MemoryManager(QObject *parent)
{
    MemoryCollection *collection = new MemoryCollection(this);
    this->adder = new MemoryAdder(collection, this);
    this->destroyer = new MemoryDestroyer(collection, this);

    this->queAskModel = new QQueue<QString *>();
    this->queTakeModel = new QQueue<EmptyModel *>();
    this->queDestruction = new QQueue<EmptyModel *>();

    this->timer = new QTimer(this);

    Configuration();
}

void MemoryManager::Configuration()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
}

void MemoryManager::update()
{
    if(queAskModel->size())
    {
        EmptyModel* temp;
        temp=this->adder->askModel(*queAskModel->first());
        if(temp!=NULL)
        {
            qDebug()<<"MEMORY-Ask: "<<queAskModel->first()<<" - "<<temp->metaObject()->className();
            queTakeModel->push_back( temp);
            this->queAskModel->pop_front();
        }
    }
    else if(queDestruction->size())
    {
        bool temp=this->destroyer->DestroyModel( queDestruction->first());
        qDebug()<<"MEMORY-Destruct: "<<queDestruction->first()->metaObject()->className()<<" - "<<temp;
        if(temp)this->queDestruction->pop_front();
    }
}

void MemoryManager::askModel(QString *type)
{
    this->queAskModel->push_back(type);
}

EmptyModel* MemoryManager::takeModel()
{
    EmptyModel* temp=NULL;
    if(queTakeModel->size())
    {
        temp = queTakeModel->first();
        qDebug()<<"MEMORY-take Model: "<<temp->metaObject()->className();
        queTakeModel->pop_front();
    }
    return temp;
}

void MemoryManager::destroy(EmptyModel* model)
{
    this->queDestruction->push_back(model);
}

void MemoryManager::run()
{
    exec();
}
