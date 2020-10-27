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
    thisball = new ball( v2(0, 300), 20, v2(5, 0));
    connect(balltimer, SIGNAL(timeout()), this, SLOT(updateball()));
    balltimer->start(200);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateball(){

    //改这里，这是每秒球受到的力，改变v2的值试试。
    thisball->updatepos(v2(5,-1), 1);


    ui->balltest->setGeometry(static_cast<int>(thisball->s().x()),
                              static_cast<int>((thisball->s().y())), 121,121);

}
