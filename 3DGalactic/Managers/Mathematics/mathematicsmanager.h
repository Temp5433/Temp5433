#ifndef MATHEMATICSMANAGER_H
#define MATHEMATICSMANAGER_H

#include <QObject>
#include <qthread.h>
#include <qqueue.h>
#include <qtimer.h>

#include "Models/ModelsLibrary.h"

class MathematicsManager : public QThread
{
    Q_OBJECT
public:
    explicit MathematicsManager(QObject *parent = 0);

    void askModel(EmptyModel *model);
    EmptyModel* takeModel();

    int getCountOfModeElement(QString *type);

    void changeMode(QString *type);

private:
    void Configuration();
    void run();

    QQueue<EmptyModel *> *queAsk;
    QQueue<EmptyModel *> *queAnswer;
    QTimer *timer;
    void update();

signals:

public slots:

};

#endif // MATHEMATICSMANAGER_H
