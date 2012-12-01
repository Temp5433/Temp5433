#ifndef FILELOAD_H
#define FILELOAD_H

#include <QObject>
#include "Managers/Files/filedata.h"
#include "Managers/Files/file3d.h"

class FileLoad : public QObject
{
    Q_OBJECT
public:
    explicit FileLoad(QObject *parent = 0);

private:
    void Configuration();
    QString *path;



    FileData *data;
    File3d *f3d;
signals:

public slots:

};

#endif // FILELOAD_H
