#ifndef FILESAVE_H
#define FILESAVE_H

#include <QObject>
#include "Managers/Files/filedata.h"
#include "Managers/Files/file3d.h"

class FileSave : public QObject
{
    Q_OBJECT
public:
    explicit FileSave(QObject *parent = 0);

    void setPath(QString *path);

    void writeData(QString *data);
private:
    void Configuration();


    QString *path;
    FileData *data;
    File3d *f3d;
signals:

public slots:

};

#endif // FILESAVE_H
