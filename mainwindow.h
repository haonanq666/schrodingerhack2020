#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "ball.h"
#include "fan.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer* balltimer;
    ball* thisball;
    fan* thisfan;
    v2 fanForce;  //不知道在这里declare合不合适

public slots:
    void updateball();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
