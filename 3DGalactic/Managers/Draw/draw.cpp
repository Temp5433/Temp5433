#include "draw.h"
#include <qdebug.h>

Draw::Draw(QObject *parent)
{
    qDebug()<<"Create"<<this->metaObject()->className();
    this->queDraw = new QQueue<EmptyModel *>();
    this->timer = new QTimer(this);
    Configuration();
}

//����� ��� ��������� ���� ��������� �������
void Draw::Configuration()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    this->timer->start(100);
}

//��������� ��� ���������������
void Draw::run()
{
    qDebug()<<"run thread: "<< this->metaObject()->className();
    exec();
}

//����������� � �������. ����������� �����
void Draw::update()
{
    if(queDraw->size())
    {

    }
}

//���������� � ������� �� ���������
void Draw::addModel(EmptyModel *model)
{
    qDebug()<<"DRAW: "<<"ADD "<< model->metaObject()->className();
    this->queDraw->push_back(model);
}

//������� �� ��������� ������ ������ ���������
void Draw::changeMode(QString *type)
{

}
