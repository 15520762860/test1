#include "mainwindow.h"
#include "custom_plot.h"
#include <mysqltext.h>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    mysqltext w;
    w.show();
    return a.exec();
}
