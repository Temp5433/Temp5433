#ifndef FILEDATA_H
#define FILEDATA_H

#include <qfile.h>
#include "Managers/Memory/memorymanager.h"

class FileData : public QObject
{
    Q_OBJECT
public:
    explicit FileData(QObject *parent = 0);

    EmptyModel* askData(QString *type, QString *name);
    EmptyModel* getData();
    bool writeData(EmptyModel *model);
    bool isFind();

    void setPath(QString path);
    void connectionToMemory(MemoryManager *memory);
private:
    void Configuration();
    QFile* findFile(QString* type, QString name);

signals:

public slots:

};

#endif // FILEDATA_H
