#ifndef MYSQLTEXT_H
#define MYSQLTEXT_H

#include <QWidget>
#include <mainwindow.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QVector>
#include <iostream>
#include <QMessageBox>
#include <QTableWidget>
#include <QFileDialog>
#include <QFile>
#include <QDateTime>

using namespace std;

namespace Ui {
class mysqltext;
}

class mysqltext : public QWidget
{
    Q_OBJECT

public:
    explicit mysqltext(QWidget *parent = nullptr);
    ~mysqltext();
public:
    void into_add_class();
    void into_delete_class();
    void btn_save();
    void search();
    void btn_return();
    void init();
    void init_ui();
    void derive_clicked();
    bool textdate(int n);
    void btn_textdata();
private:
    bool trueORfalse();

private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

private:
    Ui::mysqltext *ui;
    QSqlDatabase db;
    // 获取TableWidget对象

};

#endif // MYSQLTEXT_H
