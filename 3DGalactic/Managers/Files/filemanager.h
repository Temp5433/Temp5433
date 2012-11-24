#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <qthread.h>
#include <qtimer.h>

#include "filesave.h"
#include "fileload.h"
#include "filedata.h"
#include "filebase.h"
#include "file3d.h"

class FileManager : public QThread
{
    Q_OBJECT
public:
    explicit FileManager(QObject *parent = 0);
    void Configuration(QString path);
private:

    FileSave *saver;
    FileLoad *loader;
    FileData *data;
    FileBase *base;
    File3d *f3d;

    QString path;
    QTimer timer;

    void run();
    void update();
signals:

public slots:

};

#endif // FILEMANAGER_H
