#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "Managers/Files/filedata.h"

class FileManager : public QThread
{
    Q_OBJECT
public:
    explicit FileManager(QObject *parent = 0);

    void setPath(QString pathToData);
    void connectionToMemory(MemoryManager *memory);

    void askData(QString *type, QString *name);
    EmptyModel* takeData();
    void writeData(EmptyModel* data);
private:
    void Configuration();
    void run();

    QString *path;
    QTimer *timer;

signals:

public slots:
    void update();
};

#endif // FILEMANAGER_H
