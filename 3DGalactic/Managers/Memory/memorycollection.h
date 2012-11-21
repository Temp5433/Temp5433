#ifndef MEMORYCOLLECTION_H
#define MEMORYCOLLECTION_H

#include <QObject>
#include <QVector>
#include "Models/ModelsLibrary.h"

class MemoryCollection : public QObject
{
    Q_OBJECT
public:
    explicit MemoryCollection(QObject *parent = 0);

    EmptyModel* getFreeModel(QString &type);
    void addFreeModel(EmptyModel* model);
    void setMemorySize(QString type, unsigned int size);
    int getMemorySize(QString &type);
    bool getControl();

private:
    void Configuration();

    QVector<EmptyModel *>* getVectorByModels(QString &type);

    EmptyModel* getNewModel(QString &type);
    EmptyModel* getNewMemory(QString &type);

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

signals:

public slots:

};

#endif // MEMORYCOLLECTION_H
