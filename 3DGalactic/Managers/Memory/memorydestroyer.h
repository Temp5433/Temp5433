#ifndef MEMORYDESTROYER_H
#define MEMORYDESTROYER_H

#include <QObject>
#include "Managers/Memory/memorycollection.h"

class MemoryDestroyer : public QObject
{
    Q_OBJECT
public:
    explicit MemoryDestroyer(MemoryCollection* collection, QObject *parent = 0);
    bool DestroyModel(EmptyModel *model);
private:
    MemoryCollection *collection;
signals:

public slots:

};

#endif // MEMORYDESTROYER_H
