#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startdialog.h"
#include <QDebug>
#include "v2.h"
#include "gameover.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Blowy Balley -- Level 1");
    balltimer = new QTimer(this);
    //ball(v2 pos, double mass,v2 velocity, v2 acc)

    fans.push_back(new fan(v2(800,100), v2(950,150), 15));            //fan(v2 leftPoint, v2 rightPoint, double velocity)1
    fans.push_back(new fan(v2(400,100), v2(600,100), 15));         //可以在这里调整风速
    //fanForce = thisfan->getForce(thisball);
    connect(balltimer, SIGNAL(timeout()), this, SLOT(updateball()));
    balltimer->start(clockspeed);
    drawfan(fans[0]);
    drawfan(fans[1]);
    canlabel = new QLabel(this);
    canlabel->setScaledContents(true);
    canlabel->setPixmap(canimg);
    canlabel->setGeometry(50,350,200,200);
    exitlabel = new QLabel(this);
    exitlabel->setScaledContents(true);
    exitlabel->setPixmap(exitimg);
    exitlabel->setGeometry(exitpos.x(),screenh-exitpos.y()-150,100,150);                    //可以调整(x,y,width,height)
    balllabel = new QLabel(this);
    balllabel->setScaledContents(true);
    balllabel->setPixmap(ballimg);

    v2 vec1(450,0, 600,120);
    arr = {vec1};
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setV(v2 v)
{
    ve = v;
    thisball = new ball( v2(137,167), 40, ve);  //137 167
    //qDebug()<<ve.magnitude();
    //qDebug()<<ve.angle();
}

v2 MainWindow::sumForce(ball * b){
    v2 sum = g*b->getM();
    for(QVector<fan*>::iterator i= fans.begin(); i!=fans.end();i++){
        sum= sum + (*i)->getForce(b);
        //qDebug()<<sum.y();
    }
    return sum;
}

void MainWindow::drawball(){

    balllabel->setGeometry(thisball->s().x(),screenh-thisball->s().y(), 30, 30);
}

void MainWindow::drawfan(fan * fan){
    QTransform trans;
    //trans.scale(   ((((fan)->rpoint()-(fan)->lpoint())).magnitude()), 40);
    trans.rotateRadians(-((fan)->rpoint()-(fan)->lpoint()).angle());

    QPixmap fan1 = fanimg.transformed(trans);
    labels.push_back(new QLabel(this));
    int i = labels.size()-1;
    labels[i]->setScaledContents(true);
    labels[i]->setPixmap(fan1);
    labels[i]->setGeometry(fan->paintlpoint().x(),screenh-fan->paintlpoint().y(), ((((fan)->rpoint()-(fan)->lpoint())).magnitude()),100);

}

bool MainWindow::checkexit(){
    bool yin = (exitpos.y()<=thisball->s().y()&&
                thisball->s().y()<= exitpos.y()+150
                );
    qDebug()<<exitpos.y();
    qDebug()<<thisball->s().y();
    bool xin = (exitpos.x()<=thisball->s().x()&&
                thisball->s().x()<= exitpos.x()+100
                );
    //qDebug()<<xin;
    if(yin&&xin){
        return true;
    }else{
        return false;
    }
}

void MainWindow::updateball(){

    //改这里，这是每秒球受到的力，改变v2的值试试。#(右/下为正方向)# 日后通过提取屏幕
    //分辨率，使得原点可以挪到左下。目前假设屏幕高600（按需求调整）。


    if(!gamewon){
        thisball->updatepos(sumForce(thisball), updateperiod);
        //qDebug()<<thisball->s().y();
        //c.updateCollisionStatus(thisball, arr);
        //cout << thisball->s().x()<< " x direction; " << thisball->s().y() << " y direction.\n";
        drawball();

        if(checkexit()){
            gamewon=true;
            gameOver* go = new gameOver;
            go->show();

        }
    }
/*    if(thisball->s().y()<-200){
        gameOver s;
        s.show();
        //close
    }
*/
}


