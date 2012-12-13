#include "memorycollection.h"

#include <QVector>
#include "Models/ModelsLibrary.h"

bool status;
QVector<QVector<EmptyModel *> *> *freeModel;
QVector<EmptyModel *> *asteroidsFree;
QVector<EmptyModel *> *fogsFree;
QVector<EmptyModel *> *planetsFree;
QVector<EmptyModel *> *planets3dFree;
QVector<EmptyModel *> *satellitesFree;
QVector<EmptyModel *> *splinesFree;
QVector<EmptyModel *> *starsFree;
QVector<EmptyModel *> *systemsFree;
QVector<EmptyModel *> *textureStarsFree;

MemoryCollection::MemoryCollection(QObject *parent) :
    QObject(parent)
{
    status = false;
    freeModel = new QVector<QVector<EmptyModel *> *>();

    Configuration();

    status=true;
}

void MemoryCollection::Configuration()
{
    QVector<EmptyModel *> *temp = new QVector<EmptyModel *>();
    temp->push_back(new Asteroid());
    freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new Fog());
    freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new Planet3D());
    freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new Satallite());
    freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new Spline());
    freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new Star());
    freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new Star3d());
    freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new System());
    freeModel->push_back(temp);

    temp = new QVector<EmptyModel *>();
    temp->push_back(new TextureStar());
    freeModel->push_back(temp);
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
    status = true;
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
    status = true;
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
    status = true;
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
    status = true;
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
    EmptyModel* temp = getNewMemory(type);
    status = true;
    return temp;
}

EmptyModel* MemoryCollection::getNewMemory(QString &type)
{
    if(type=="Asteroid") return new Asteroid(this);
    if(type=="Fog") return new Fog(this);
    if(type=="Planet3D") return new Planet3D(this);
    if(type=="Satallite") return new Satallite(this);
    if(type=="Spline") return new Spline(this);
    if(type=="Star") return new Star(this);
    if(type=="Star3D") return new Star3d(this);
    if(type=="System") return new System(this);
    if(type=="TextureStar") return new TextureStar(this);
    return NULL;
}
