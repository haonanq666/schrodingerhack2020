#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QLabel>
#include <QTransform>
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
    const int screenh = 600;
    const double updateperiod = 0.01; //s
    const int clockspeed = 1; //ms
    QTimer* balltimer;
    ball* thisball;
    fan* thisfan;
    QVector<QLabel*> labels;
    QLabel* balllabel;
    QVector<fan*> fans;
    //v2 fanForce;  //不知道在这里declare合不合适
    const v2 g = v2(0,-9.80665);

    v2 sumForce(ball*);

    const QPixmap fanimg = QPixmap(":/new/prefix1/sucai/674774700.jpg");
    const QPixmap ballimg = QPixmap(":/new/prefix1/sucai/1436341580.jpg");
    void drawfan(fan*);
    void drawball();
    void setV(v2 v);

signals:


public slots:
    void updateball();

private:
    Ui::MainWindow *ui;
    v2 ve;
};
#endif // MAINWINDOW_H
