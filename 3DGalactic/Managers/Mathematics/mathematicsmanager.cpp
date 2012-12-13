#include "mathematicsmanager.h"
#include <qdebug.h>
#include <qqueue.h>
#include <qtimer.h>

#include "Models/ModelsLibrary.h"

QQueue<EmptyModel *> *queAsk;
QQueue<EmptyModel *> *queAnswer;

MathematicsManager::MathematicsManager(QObject *parent)
{
    qDebug()<<"Create"<<metaObject()->className();
    queAsk = new QQueue<EmptyModel *>();
    queAnswer = new QQueue<EmptyModel *>();
    timer = new QTimer(this);
    Configuration();
}

void MathematicsManager::Configuration()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(100);
}

/* ����� ���������� ���� � ������ :)
*/
void MathematicsManager::connectionToFiles(FileManager *manager)
{
    files = manager;
}

/*class MathematicsManager �� ����� ����������� ��������
  � ����� � ��������� �����.
*/
void MathematicsManager::run()
{
    qDebug()<<"run thread: "<< metaObject()->className();
    exec();
}

void MathematicsManager::update()
{
    if(queAsk->size())
    {
        //�����������, ���� ���� ������ �� ���������
        qDebug()<<"MATHEMATICS-Ask: "<<queAsk->first()->metaObject()->className();

        //��� ������ �������, ��� ����� �������� � ������� queAnswer
        //������:
        /*EmptyModel *temp = NULL;
        queAnswer->push_back(temp);*/
    }
}

/*�������� ��������� ������ ����������
  �������� ������� ��� �� ���� ���������.
*/
void MathematicsManager::changeMode(QString *type)
{

}

/*����� ���������� ������, �� ����� ����� ������
  ���� ����� ��� ����������� ����������
  ��������� ��� ��������� ��������
*/
int MathematicsManager::getCountOfModesElement(QString *type)
{

}

/*������ �� ��������� ������
*/
void MathematicsManager::askModel(EmptyModel *model)
{
    queAsk->push_back(model);
}

/*��������� �������, ���� �� ��� �����������
  ���� ������ ��� �� �����������, ����� ������� NULL
*/
EmptyModel* MathematicsManager::takeModel()
{
    EmptyModel* temp=NULL;
    if(queAnswer->size())
    {
        temp = queAnswer->first();
        qDebug()<<"MATHEMATICS-take Model: "<<temp->metaObject()->className();
        queAnswer->pop_front();
    }
    return temp;
}
