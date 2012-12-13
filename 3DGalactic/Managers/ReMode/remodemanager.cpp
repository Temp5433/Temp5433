#include "remodemanager.h"




ReModeManager::ReModeManager(QObject *parent) :
    QObject(parent)
{

}

void ReModeManager::connectionToMemory(MemoryManager *manager)
{
    memory = manager;
}

void ReModeManager::connectionToFiles(FileManager *manager)
{
    files = manager;
}
