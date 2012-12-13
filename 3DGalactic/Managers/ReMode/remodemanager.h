#ifndef REMODEMANAGER_H
#define REMODEMANAGER_H

#include "Managers/Files/filemanager.h"

class ReModeManager : public QObject
{
    Q_OBJECT
public:
    explicit ReModeManager(QObject *parent = 0);
    void connectionToMemory(MemoryManager *manager);
    void connectionToFiles(FileManager *manager);

    QVector<EmptyModel *> getLevel(QString *type, QString *path);
private:
    void Configuration();

    void askAllFromFile(QString *data);


    void askDataFromFile(QString *data);
    void askMemory(QString *type);

    MemoryManager *memory;
    FileManager *files;

signals:

public slots:

};

#endif // REMODEMANAGER_H
