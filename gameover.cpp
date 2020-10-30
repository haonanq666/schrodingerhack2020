#include "gameover.h"
#include "ui_gameover.h"

gameOver::gameOver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gameOver)
{
    ui->setupUi(this);
    this->setObjectName("gameover");
    this->setStyleSheet("#gameover{border-image:url(:/new/prefix1/sucai/gameover.png);}");
}

gameOver::~gameOver()
{
    delete ui;
}
