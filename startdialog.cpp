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
    this->setWindowTitle("Blowy Balley");
}

StartDialog::~StartDialog()
{

    delete ui;
}

void StartDialog::start()
{
    bool yes = false;
    bool yes2 = false;

    double v = ui->inputV->toPlainText().toDouble(&yes);
    double angle = (ui->InputA->toPlainText().toDouble(&yes2))*M_PI/180;

    if(!(yes&&yes2)){
        ui->msg->setText("Invalid Input!");
        return;
    }

    QDialog::accept();
    MainWindow* m = new MainWindow;
    m->setV(v2(cos(angle),sin(angle))*v);
    m->show();
    emit sendV(v2(cos(angle),sin(angle))*v);
    setAttribute (Qt::WA_DeleteOnClose);
}
