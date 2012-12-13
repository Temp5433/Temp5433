#ifndef MODEPREPARER_H
#define MODEPREPARER_H

#include "Managers/Files/filemanager.h"

class ModePreparer : public QThread
{
    Q_OBJECT
public:
    explicit ModePreparer(QObject *parent = 0);

    void connectionToMemory(MemoryManager *manager);
    void connectionToFiles(FileManager *manager);
    QVector<EmptyModel *> getLevel(FileManager *manager);
private:
    void Configuration();
    void run();
    QTimer *timer;
signals:

public slots:
    void update();
};

#endif // MODEPREPARER_H
