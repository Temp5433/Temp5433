#ifndef MATHEMATICSMANAGER_H
#define MATHEMATICSMANAGER_H

#include "Managers/Files/filemanager.h"

class MathematicsManager : public QThread
{
    Q_OBJECT
public:
    explicit MathematicsManager(QObject *parent = 0);

    void connectionToFiles(FileManager *manager);

    void askModel(EmptyModel *model);
    EmptyModel* takeModel();
    int getCountOfModesElement(QString *type);
    void changeMode(QString *type);

private:
    void Configuration();
    void run();
    QTimer *timer;
    FileManager *files;
signals:

public slots:
    void update();
};

#endif // MATHEMATICSMANAGER_H
