#include "draw.h"
#include <QtCore>
#include <qdebug.h>
#include <qqueue.h>
#include <qtimer.h>

#include "Managers/Draw/qopenglwidget.h"
#include "Models/AbstractModels/spaceobject.h"
#include "Models/AbstractModels/phisicalobject.h"
#include "Models/ModelsLibrary.h"


QQueue<EmptyModel *> *queDraw;

QOpenGlWidget *widget;


Draw::Draw(QObject *parent)
{
    qDebug()<<"Create"<<this->metaObject()->className();
    queDraw = new QQueue<EmptyModel *>();
    //this->timer = new QTimer(this);
    try{
       widget = new QOpenGlWidget();
    }
    catch(...)
    {

    }
    this->resize(500,500);
    this->showMaximized();

    this->setCentralWidget(widget);

    Configuration();
//    EmptyModel* temp = new Planet3D();
//    widget->addModel(temp);

//    temp = new Star3d();
//    widget->addModel(temp);

    Test();
}

void Draw::Test()
{
    SpaceObject* temp;

    temp= new Planet3D();
    temp->setImage(":/planets/texture/planets/jupiter.jpg");

    widget->addModel(temp);
    temp->setBeginPosition(0,0,0);
    temp->setBeginTime(10);
    temp->setRadius(0.8);
    temp->setSize(0.09);
    temp->setSpeed(0.01);


    temp= new Planet3D();
    temp->setImage(":/planets/texture/planets/Earth.jpg");
    widget->addModel(temp);
    temp->setBeginPosition(0,0,0);
    temp->setBeginTime(0);
    temp->setRadius(1.3);
    temp->setSize(0.2);
    temp->setSpeed(0.01);


    temp= new Planet3D();
    temp->setImage(":/planets/texture/planets/klenda.png");
    widget->addModel(temp);
    temp->setBeginPosition(0,0,0);
    temp->setBeginTime(20);
    temp->setRadius(1.7);
    temp->setSize(0.4);
    temp->setSpeed(.005);


    temp= new Star3d();

    widget->addModel(temp);
    temp->setBeginPosition(0,0,0);
    temp->setSize(0.3);

    PhisicalObject* stars = new Star();
    widget->addModel(stars);
    stars->setBeginPosition(0,1,-1);
    stars->setSize(0.1);

    stars = new Star();
    widget->addModel(stars);
    stars->setBeginPosition(0,-1,-1);
    stars->setSize(0.2);

    stars = new Star();
    widget->addModel(stars);
    stars->setBeginPosition(-1,2,-1);
    stars->setSize(0.2);

    stars = new Star();
    widget->addModel(stars);
    stars->setBeginPosition(3,1.2,-1);
    stars->setSize(0.2);

    stars = new Star();
    widget->addModel(stars);
    stars->setBeginPosition(3,-2,-1);
    stars->setSize(0.2);

    stars = new Star();
    widget->addModel(stars);
    stars->setBeginPosition(-3,-1,-1);
    stars->setSize(0.1);

    stars = new Star();
    widget->addModel(stars);
    stars->setBeginPosition(-3,-1.6,-1);
    stars->setSize(0.1);

    stars = new Star();
    widget->addModel(stars);
    stars->setBeginPosition(-2.1,-0.5,-1);
    stars->setSize(0.15);

    stars = new Star();
    widget->addModel(stars);
    stars->setBeginPosition(-2.7,1.4,-1);
    stars->setSize(0.2);

    stars = new Star();
    widget->addModel(stars);
    stars->setBeginPosition(3,0.9,-1);
    stars->setSize(0.2);

    stars = new Star();
    widget->addModel(stars);
    stars->setBeginPosition(-0.2,-2,-1);
    stars->setSize(0.2);
}
//метод для настройки всех атрибутов классах
void Draw::Configuration()
{
//    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
//    this->timer->start(100);
}

////выполняется в таймере. Перерисовка всего
//void Draw::update()
//{
//    widget->change();
//}

//добавление в очередь на отрисовку
void Draw::addModel(EmptyModel *model)
{
    qDebug()<<"DRAW: "<<"ADD "<< model->metaObject()->className();
    widget->addModel(model);
}

//команда на изменение режима уровня просмотра
void Draw::changeMode(QString *type)
{
    widget->setMode(type);
}
