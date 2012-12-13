#ifndef USER_H
#define USER_H

#include "Managers/Mode/modemanager.h"
#include "Managers/Draw/draw.h"

class User : public QThread
{
    Q_OBJECT
public:
    explicit User(QObject *parent = 0);

    void connectToMode(ModeManager *mode);
    void connectToDraw(Draw *draw);

    void userAction(QString *action);
private:
    void Configuration();
    void run();

    void changeMode(QString *name);
    QStringList* parse(QString *command);
    QString nextWord(QStringList *list);

signals:

public slots:
    void update();
};

#endif // USER_H
