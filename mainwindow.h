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
    QLabel* exitlabel;
    QLabel* canlabel;
    QVector<fan*> fans;
    const v2 g = v2(0,-9.80665);

    v2 sumForce(ball*);

    const QPixmap fanimg = QPixmap(":/new/prefix1/sucai/Wind.png");
    const QPixmap ballimg = QPixmap(":/new/prefix1/sucai/Ball.png");
    const QPixmap exitimg = QPixmap(":/new/prefix1/sucai/Exit.png");
    const QPixmap canimg = QPixmap(":/new/prefix1/sucai/Cannon.png");
    void drawfan(fan*);
    void drawball();
    void setV(v2 v);

signals:


public slots:
    void updateball();
    //void setV(v2);

private:
    Ui::MainWindow *ui;
    v2 ve;
};
#endif // MAINWINDOW_H
