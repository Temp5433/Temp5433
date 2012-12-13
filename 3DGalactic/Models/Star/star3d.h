#ifndef STAR3D_H
#define STAR3D_H

#include <QObject>
#include "Models/AbstractModels/spaceobject.h"

class Star3d : public SpaceObject
{
    Q_OBJECT
public:
    explicit Star3d(QObject *parent = 0);

signals:

public slots:

};

#endif // STAR3D_H
