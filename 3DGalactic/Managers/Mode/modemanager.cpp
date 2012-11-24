#include "modemanager.h"

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
