#include "Models/ModelsLibrary.h"
#include "Managers/Draw/qopenglwidget.h"

void test(QGLWidget *widget)
{
    SpaceObject* temp;
    temp= new Planet3D();
    //widget->addModel(temp);
    temp->setBeginPosition(0,0,0);
    temp->setBeginTime(0);
    temp->setRadius(0.3);
    temp->setSize(0.1);

//    temp = new Planet3D();
//    widget->addModel(temp);

//    temp = new Planet3D();
//    widget->addModel(temp);

//    temp = new Planet3D();
//    widget->addModel(temp);

//    temp = new Planet3D();
//    widget->addModel(temp);
}
