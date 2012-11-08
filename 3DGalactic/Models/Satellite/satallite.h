#ifndef SATALLITE_H
#define SATALLITE_H

#include "Models/AbstractModels/spaceobject.h"

class Satallite : public SpaceObject
{
    Q_OBJECT
public:
    explicit Satallite(QObject *parent = 0);

signals:

public slots:

};

#endif // SATALLITE_H
