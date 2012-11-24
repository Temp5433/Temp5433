#ifndef MODEPREPARER_H
#define MODEPREPARER_H

#include <QObject>
#include <qthread.h>
#include <qtimer.h>
#include <qqueue.h>

#include "Managers/Memory/memorymanager.h"
#include "Managers/ReMode/remodemanager.h"
#include "Managers/Mathematics/mathematicsmanager.h"

class ModePreparer : public QThread
{
    Q_OBJECT
public:
    explicit ModePreparer(QObject *parent = 0);

    void connectionToMemory(MemoryManager *manager);
    QVector<EmptyModel *> getLevel();
private:
    void Configuration();

    void run();


    ReModeManager *remode;
    MathematicsManager *math;

    QTimer *timer;
    QQueue<QString *> askQue();
signals:

public slots:
    void update();
};

#endif // MODEPREPARER_H
