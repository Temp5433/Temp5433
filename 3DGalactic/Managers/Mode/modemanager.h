#ifndef MODEMANAGER_H
#define MODEMANAGER_H

#include "Managers/Files/filemanager.h"

class ModeManager : public QObject
{
    Q_OBJECT
public:
    explicit ModeManager(QObject *parent = 0);

    void userAction(QString *action);
    void connectionToMemory(MemoryManager *manager);
    void connectionToFiles(FileManager *manager);

    void changeMode(QString *name);
private:
    void Configuration();


signals:

public slots:

};

#endif // MODEMANAGER_H
