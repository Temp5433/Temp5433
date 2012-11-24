#ifndef MODEMANAGER_H
#define MODEMANAGER_H

#include <QObject>

#include "Managers/Files/filemanager.h"
#include "Managers/Memory/memorymanager.h"

#include "Managers/Mode/modechanger.h"

class ModeManager : public QObject
{
    Q_OBJECT
public:
    explicit ModeManager(QObject *parent = 0);

    void userAction(QString *action);
    void connectionToMemory(MemoryManager *manager);
    void connectionToFiles(FileManager *manager);
private:
    void Configuration();

    ModeChanger *changer;
signals:

public slots:

};

#endif // MODEMANAGER_H
