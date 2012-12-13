#include "memorymanager.h"
#include <qdebug.h>
#include <QQueue.h>


QQueue<QString *> *queAskModel;
QQueue<EmptyModel *> *queTakeModel;
QQueue<EmptyModel *> *queDestruction;
MemoryAdder *adder;
MemoryDestroyer *destroyer;
MemoryCollection *collection;

MemoryManager::MemoryManager(QObject *parent)
{
    qDebug()<<"Create"<<metaObject()->className();
    collection = new MemoryCollection(this);
    adder = new MemoryAdder(collection, this);
    destroyer = new MemoryDestroyer(collection, this);

    queAskModel = new QQueue<QString *>();
    queTakeModel = new QQueue<EmptyModel *>();
    queDestruction = new QQueue<EmptyModel *>();

    timer = new QTimer(this);

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
        temp=adder->askModel(*queAskModel->first());
        if(temp!=NULL)
        {
            qDebug()<<"MEMORY-Ask: "<<queAskModel->first()<<" - "<<temp->metaObject()->className();
            queTakeModel->push_back( temp);
            queAskModel->pop_front();
        }
    }
    else if(queDestruction->size())
    {
        bool temp=destroyer->DestroyModel( queDestruction->first());
        qDebug()<<"MEMORY-Destruct: "<<queDestruction->first()->metaObject()->className()<<" - "<<temp;
        if(temp)queDestruction->pop_front();
    }
}

void MemoryManager::askModel(QString *type)
{
    queAskModel->push_back(type);
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
    queDestruction->push_back(model);
}

void MemoryManager::run()
{
    qDebug()<<"run thread: "<< metaObject()->className();
    exec();
}
