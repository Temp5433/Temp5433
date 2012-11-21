#ifndef FRAME_H
#define FRAME_H

#include <QFrame>
#include "Core/core.h"

namespace Ui {
    class Frame;
}

class Frame : public QFrame
{
    Q_OBJECT

public:
    explicit Frame(QWidget *parent = 0);
    Core *core;
    ~Frame();

private:
    Ui::Frame *ui;

private slots:
    void on_pushButton_clicked();
    void on_Frame_destroyed();
};

#endif // FRAME_H
