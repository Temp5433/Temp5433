#ifndef ASTEROID_H
#define ASTEROID_H

#include "Models/AbstractModels/spaceobject.h"

class Asteroid : public SpaceObject
{
    Q_OBJECT
public:
    explicit Asteroid(QObject *parent = 0);

signals:

public slots:

};

#endif // ASTEROID_H
