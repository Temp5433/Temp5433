#ifndef STAR_H
#define STAR_H

#include "Models/AbstractModels/spaceobject.h"

class Star : public SpaceObject
{
    Q_OBJECT
public:
    explicit Star(QObject *parent = 0);

signals:

public slots:

};

#endif // STAR_H
