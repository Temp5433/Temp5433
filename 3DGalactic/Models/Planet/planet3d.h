#ifndef PLANET3D_H
#define PLANET3D_H

#include "Models/AbstractModels/spaceobject.h"
#include "Models/Spline/spline.h"
class Planet3D : public SpaceObject
{
    Q_OBJECT
public:
    explicit Planet3D(QObject *parent = 0);
private:

signals:

public slots:

};

#endif // PLANET3D_H
