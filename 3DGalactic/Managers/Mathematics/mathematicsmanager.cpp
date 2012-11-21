#include "mathematicsmanager.h"
#include <qdebug.h>

MathematicsManager::MathematicsManager(QObject *parent)
{
    this->queAsk = new QQueue<EmptyModel *>();
    this->queAnswer = new QQueue<EmptyModel *>();
    this->timer = new QTimer(this);
    Configuration();
}

void MathematicsManager::Configuration()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    this->timer->start(100);
}

/*class MathematicsManager со всеми надлежащими классами
  я вынес в отдельный поток.
*/
void MathematicsManager::run()
{
    exec();
}

void MathematicsManager::update()
{
    if(queAsk->size())
    {
        //Выполняется, если есть данные на обработку
        qDebug()<<"MATHEMATICS-Ask: "<<queAsk->first()->metaObject()->className();

        //Для выдачи объекта, его нужно добавить в очередь queAnswer
        //пример:
        /*EmptyModel *temp = NULL;
        queAnswer->push_back(temp);*/
    }
}

/*Означает изменения режима построения
  Названия режимов еще не были обсуждены.
*/
void MathematicsManager::changeMode(QString *type)
{

}

/*После построения модели, их нужно будет выдать
  Этот метод для определения количества
  требуемых для обработки объектов
*/
int MathematicsManager::getCountOfModeElement(QString *type)
{

}

/*Запрос на обработку модели
*/
void MathematicsManager::askModel(EmptyModel *model)
{
    this->queAsk->push_back(model);
}

/*Забирание объекта, если он уже подготовлен
  Если объект еще не подготовлен, будет выданно NULL
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
