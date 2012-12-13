#include "modemanager.h"
#include "Managers/Mode/modechanger.h"

ModeChanger *changer;

ModeManager::ModeManager(QObject *parent) :
    QObject(parent)
{
    changer = new ModeChanger(this);
}

void ModeManager::Configuration()
{

}

void ModeManager::connectionToFiles(FileManager *manager)
{
    changer->connectionToFiles(manager);
}

void ModeManager::connectionToMemory(MemoryManager *manager)
{
    changer->connectionToMemory(manager);
}

void ModeManager::changeMode(QString *name)
{
    changer->changeMode(name);
}
