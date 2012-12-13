#include "planet3d.h"



Planet3D::Planet3D(QObject *parent) :
    SpaceObject(parent)
{
    this->spline->setRadius(1);
    this->spline->setSpeed(0.005);

    image->load(":/planets/texture/planets/Earth.jpg"); // загружаем изображение в переменную image1
}

