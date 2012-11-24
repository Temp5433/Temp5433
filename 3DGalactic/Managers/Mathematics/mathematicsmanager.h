#ifndef MATHEMATICSMANAGER_H
#define MATHEMATICSMANAGER_H

#include <QObject>
#include <qthread.h>
#include <qqueue.h>
#include <qtimer.h>

#include "Models/ModelsLibrary.h"
#include "Managers/Files/filemanager.h"

class MathematicsManager : public QThread
{
    Q_OBJECT
public:
    explicit MathematicsManager(QObject *parent = 0);

    void connectionToFiles(FileManager *manager);

    void askModel(EmptyModel *model);
    EmptyModel* takeModel();
    int getCountOfModesElement(QString *type);
    void changeMode(QString *type);

private:
    void Configuration();
    void run();

    FileManager *files;

    QQueue<EmptyModel *> *queAsk;
    QQueue<EmptyModel *> *queAnswer;
    QTimer *timer;
signals:

public slots:
    void update();
};

#endif // MATHEMATICSMANAGER_H
