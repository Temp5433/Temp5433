#ifndef MEMORYADDER_H
#define MEMORYADDER_H

#include "Managers/Memory/memorycollection.h"

class MemoryAdder : public QObject
{
    Q_OBJECT
public:
    explicit MemoryAdder(MemoryCollection* collection, QObject *parent = 0);
    EmptyModel* askModel(QString &type);
private:
    void Configuration();
    MemoryCollection *collection;

signals:

public slots:
};

#endif // MEMORYADDER_H
