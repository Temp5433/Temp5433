#include "star3d.h"

Star3d::Star3d(QObject *parent): SpaceObject(parent)
{
    this->spline->setRadius(0);
    this->spline->setSpeed(0.01);


    image->load(":/stars/texture/stars/TextureSun.jpg"); // загружаем изображение в переменную image1
}
