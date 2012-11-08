#ifndef SYSTEM_H
#define SYSTEM_H

#include "Models/AbstractModels/phisicalobject.h"

class System : public PhisicalObject
{
    Q_OBJECT
public:
    explicit System(QObject *parent = 0);

signals:

public slots:

};

#endif // SYSTEM_H
