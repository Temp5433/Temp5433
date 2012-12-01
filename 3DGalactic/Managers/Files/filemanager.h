#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <qthread.h>
#include <qtimer.h>
#include <qqueue.h>
#include <qpair.h>

#include "filesave.h"
#include "fileload.h"
#include "filedata.h"
#include "file3d.h"

#include "Managers/Memory/memorymanager.h"

#include "Models/AbstractModels/emptymodel.h"

class FileManager : public QThread
{
    Q_OBJECT
public:
    explicit FileManager(QObject *parent = 0);

    void setPath(QString path);

    void askData(QString *type, QString *name);
    EmptyModel* takeData();
    void writeData(EmptyModel* data);
private:
    void Configuration();
    void run();

    QQueue<QPair< QString *, QString *> *> *queAskData;
    QQueue<EmptyModel *> *queTakeData;
    QQueue<EmptyModel *> *queWriteData;
    QTimer *timer;

    FileSave *saver;
    FileLoad *loader;
    FileData *data;
    File3d *f3d;

    MemoryManager *memory;

    QString *path;
signals:

public slots:
    void update();
};

#endif // FILEMANAGER_H
