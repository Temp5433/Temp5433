#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H

#include "phisicalobject.h"

class SpaceObject : public PhisicalObject
{
    Q_OBJECT
public:
    explicit SpaceObject(QObject *parent = 0);

signals:

public slots:

};

#endif // SPACEOBJECT_H
