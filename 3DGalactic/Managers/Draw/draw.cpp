#include "draw.h"
#include <qdebug.h>

Draw::Draw(QObject *parent)
{
    qDebug()<<"Create"<<this->metaObject()->className();
    this->queDraw = new QQueue<EmptyModel *>();
    this->timer = new QTimer(this);
    Configuration();
}

//метод для настройки всех атрибутов классах
void Draw::Configuration()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    this->timer->start(100);
}

//требуется для многопоточности
void Draw::run()
{
    qDebug()<<"run thread: "<< this->metaObject()->className();
    exec();
}

//выполняется в таймере. Перерисовка всего
void Draw::update()
{
    if(queDraw->size())
    {

    }
}

//добавление в очередь на отрисовку
void Draw::addModel(EmptyModel *model)
{
    qDebug()<<"DRAW: "<<"ADD "<< model->metaObject()->className();
    this->queDraw->push_back(model);
}

//команда на изменение режима уровня просмотра
void Draw::changeMode(QString *type)
{

}
