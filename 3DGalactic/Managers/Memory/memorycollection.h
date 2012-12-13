#ifndef MEMORYCOLLECTION_H
#define MEMORYCOLLECTION_H

#include "Models/AbstractModels/emptymodel.h"

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
signals:

public slots:

};

#endif // MEMORYCOLLECTION_H
