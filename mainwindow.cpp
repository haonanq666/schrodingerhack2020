#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "v2.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    balltimer = new QTimer(this);
    thisball = new ball( v2(0, 300), 40, v2(100, 0));  //ball(v2 pos, double mass,v2 velocity, v2 acc)
    thisfan = new fan(v2(300,500), 50, 7);            //fan(v2 leftPoint, double length, double velocity)
    fanForce = thisfan->getForce(thisball);
    connect(balltimer, SIGNAL(timeout()), this, SLOT(updateball()));
    balltimer->start(200);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateball(){

    //改这里，这是每秒球受到的力，改变v2的值试试。(右/下为正方向)
    thisball->updatepos(v2(0,0), 1);
    if(thisfan->isIn(thisball->s())){
        thisball->updatepos(fanForce,1);
    }

    ui->balltest->setGeometry(static_cast<int>(thisball->s().x()),
                              static_cast<int>((thisball->s().y())), 121,121);

}
