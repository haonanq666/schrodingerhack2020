#ifndef STARTDIALOG_H
#define STARTDIALOG_H
#include "mainwindow.h"

#include <QDialog>

namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StartDialog(QWidget *parent = nullptr);
    ~StartDialog();
    //double initialV;
    //double initialA;

private:
    Ui::StartDialog *ui;
    void start();

signals:
    void sendV(v2);
};

#endif // STARTDIALOG_H
