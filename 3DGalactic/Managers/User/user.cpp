#include "user.h"
#include <qdebug.h>
#include <qtimer.h>
#include <qstringlist.h>
#include <qqueue.h>


QTimer *timer;
QQueue<QStringList *> *actions;
ModeManager *mode;
//Draw *draw;


User::User(QObject *parent)
{
    timer = new QTimer(this);
    actions = new QQueue<QStringList *>();

    Configuration();
}

void User::Configuration()
{
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));

    timer->start(100);
}

void User::connectToMode(ModeManager *mode)
{
    mode = mode;
}

void User::connectToDraw(Draw *draw)
{
    //draw = draw;
}

void User::update()
{
    if(actions->size())
    {
        QStringList *command = actions->first();
        QString temp = nextWord(command);
        if(temp=="MODE")
        {
            temp = nextWord(command);
            if(temp=="UP")mode->changeMode(new QString("UP"));
            //if(temp=="DOWN")this->mode->changeMode(new QString("DOWN")); ???
        }
        if(temp=="DRAW")
        {
            temp = nextWord(command);
        }
    }
}

void User::userAction(QString *action)
{
    QStringList *temp = parse(action);
    actions->push_back(temp);
}

void User::changeMode(QString *name)
{

}

QString User::nextWord(QStringList *list)
{
    QString temp = list->first();
    list->pop_front();
    return temp;
}

QStringList* User::parse(QString *command)
{
    QStringList *temp = new QStringList();
    *temp = command->split("|");
    return temp;
}

void User::run()
{
    qDebug()<<"run thread: "<< this->metaObject()->className();
    exec();
}
