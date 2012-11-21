#include "memorycollection.h"

MemoryCollection::MemoryCollection(QObject *parent) :
    QObject(parent)
{
    status = false;
    this->freeModel = new QVector<QVector<EmptyModel *> *>();

    Configuration();

    status=true;
}

void MemoryCollection::Configuration()
{
    QVector<EmptyModel *> *temp = new QVector<EmptyModel *>();
    temp->push_back(new Asteroid());
    this->freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new Fog());
    this->freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new Planet());
    this->freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new Planet3D());
    this->freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new Satallite());
    this->freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new Spline());
    this->freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new Star());
    this->freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new System());
    this->freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new TextureStar());
    this->freeModel->push_back(temp);
}

bool MemoryCollection::getControl()
{
    if(status == true)
    {
        status = false;
        return true;
    }
    return false;
}

void MemoryCollection::setMemorySize(QString type, unsigned int size)
{
    QVector<EmptyModel *>* temp = getVectorByModels(type);
    if(temp!=NULL)
    for(register unsigned int i=temp->size();i<size;i++)
    {
        temp->push_back(getNewModel(type));
    }
    this->status = true;
}

int MemoryCollection::getMemorySize(QString &type)
{
    QVector<QVector<EmptyModel *> *>::iterator iter = freeModel->begin();
    QVector<QVector<EmptyModel *> *>::iterator end = freeModel->end();
    unsigned int size=0;
    for(;iter!=end;iter++)
    {
        if(type==(QString)(*(iter))->first()->metaObject()->className())
        {
            size=(*(iter))->size();
            break;
        }
    }
    this->status = true;
    return size;
}

EmptyModel* MemoryCollection::getFreeModel(QString &type)
{
    QVector<QVector<EmptyModel *> *>::iterator iter = freeModel->begin();
    QVector<QVector<EmptyModel *> *>::iterator end = freeModel->end();
    EmptyModel* temp=NULL;
    for(;iter!=end;iter++)
    {
        if(type==(QString)(*(iter))->first()->metaObject()->className())
        {
            temp=(*(iter))->first();
            (*(iter))->pop_front();
            break;
        }
    }
    this->status = true;
    return temp;
}

void MemoryCollection::addFreeModel(EmptyModel *model)
{
    QVector<QVector<EmptyModel *> *>::iterator iter = freeModel->begin();
    QVector<QVector<EmptyModel *> *>::iterator end = freeModel->end();
    QString temp = (QString)(model)->metaObject()->className();
    for(;iter!=end;iter++)
    {
        if(temp==(QString)(*(iter))->first()->metaObject()->className())
            (*(iter))->push_front(model);
    }
    this->status = true;
}

QVector<EmptyModel *>* MemoryCollection::getVectorByModels(QString &type)
{
    QVector<QVector<EmptyModel *> *>::iterator iter = freeModel->begin();
    QVector<QVector<EmptyModel *> *>::iterator end = freeModel->end();
    for(;iter!=end;iter++)
    {
        if(type==(QString)(*(iter))->first()->metaObject()->className())
            return (*(iter));
    }
    return NULL;
}

EmptyModel* MemoryCollection::getNewModel(QString &type)
{
    EmptyModel* temp = this->getNewMemory(type);
    this->status = true;
    return temp;
}

EmptyModel* MemoryCollection::getNewMemory(QString &type)
{
    if(type=="Asteroid") return new Asteroid(this);
    if(type=="Fog") return new Fog(this);
    if(type=="Planet") return new Planet(this);
    if(type=="Planet3D") return new Planet3D(this);
    if(type=="Satallite") return new Satallite(this);
    if(type=="Spline") return new Spline(this);
    if(type=="Star") return new Star(this);
    if(type=="System") return new System(this);
    if(type=="TextureStar") return new TextureStar(this);
    return NULL;
}
