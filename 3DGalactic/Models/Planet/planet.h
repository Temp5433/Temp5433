#ifndef PLANET_H
#define PLANET_H

#include "Models/AbstractModels/spaceobject.h"

class Planet : public SpaceObject
{
    Q_OBJECT
public:
    explicit Planet(QObject *parent = 0);

signals:

public slots:

};

#endif // PLANET_H
