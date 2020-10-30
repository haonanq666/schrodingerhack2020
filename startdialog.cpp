#include "startdialog.h"
#include "ui_startdialog.h"
#include "mainwindow.h"
#include <cmath>

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
    connect(ui->Apply,&QPushButton::clicked,this,&StartDialog::start);
}

StartDialog::~StartDialog()
{
    delete ui;
}

void StartDialog::start()
{
    double v = ui->inputV->toPlainText().toDouble();
    double angle = (ui->InputA->toPlainText().toDouble())*M_PI/180;
    emit sendV(v2(cos(angle),sin(angle))*v);
    QDialog::accept();
    setAttribute (Qt::WA_DeleteOnClose);
}
