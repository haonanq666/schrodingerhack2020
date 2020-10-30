#include "mainwindow.h"
#include "startdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    StartDialog s;
    s.show();


    return a.exec();
}
