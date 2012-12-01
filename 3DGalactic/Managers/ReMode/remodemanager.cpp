#include "remodemanager.h"

ReModeManager::ReModeManager(QObject *parent) :
    QObject(parent)
{
    this->model = new ReModelChanger(this);
    this->texture = new ReTextureChanger(this);
}

void ReModeManager::connectionToMemory(MemoryManager *manager)
{
    this->memory = manager;
}

void ReModeManager::connectionToFiles(FileManager *manager)
{
    this->files = manager;
}
