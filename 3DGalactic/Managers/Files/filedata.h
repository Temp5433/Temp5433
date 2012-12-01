#ifndef FILEDATA_H
#define FILEDATA_H

#include <QObject>
#include <qmap.h>
#include <qfile.h>

#include "Models/AbstractModels/emptymodel.h"

class FileData : public QObject
{
    Q_OBJECT
public:
    explicit FileData(QObject *parent = 0);

    EmptyModel* askData(QString *type, QString *name);
    bool writeData(EmptyModel *model);

    void setPath(QString path);
private:
    void Configuration();

    QFile* findFile(QString* type, QString name);
    //QString* readData(QFile *file);

    //QMap<QString *, QString *> *files;
    QString path;
signals:

public slots:

};

#endif // FILEDATA_H
