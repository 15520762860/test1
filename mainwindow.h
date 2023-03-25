#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mysqlconnect();
    void readxml();
    void init();
    void showtable();

private:
    Ui::MainWindow *ui;
    QSqlDatabase  db;
    QSqlQuery query;
};
#endif // MAINWINDOW_H
