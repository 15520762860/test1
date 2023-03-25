#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProgressBar>
#include <QDebug>
#include <QHeaderView>
#include <config.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QProgressBar *pProgressBar = new QProgressBar(this);
//    pProgressBar->setOrientation(Qt::Horizontal);  // 水平方向
//    pProgressBar->setMinimum(0);  // 最小值
//    pProgressBar->setMaximum(0);  // 最大值
//    int x=0;//自己定义一个值
//    pProgressBar->setValue(x);  // 当前进度
//    double dProgress = (pProgressBar->value() - pProgressBar->minimum()) * 100.0
//                    / (pProgressBar->maximum() - pProgressBar->minimum());
//    pProgressBar->setFormat(QString::fromLocal8Bit("%p%").arg(QString::number(dProgress,0,1)));
//    pProgressBar->setAlignment(Qt::AlignRight | Qt::AlignVCenter);  // 对齐方式

    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init(){
    mysqlconnect();
    //readxml();
}

void MainWindow::showtable()
{
    QString cmd = "show tables;"; //查询所有的表
    QSqlQuery query(cmd);
    QVector<QString> v;

    while (query.next()) {
        QString s=query.value(0).toString();
        qDebug()<<"table name:"<<qUtf8Printable(s);
        v.append(s);
    }

    for (int i=0;i<v.size();i++) {
        QTreeWidgetItem *item = new QTreeWidgetItem(QStringList()<<v[i]);
        item->setCheckState(0,Qt::Checked);
        ui->treeWidget->addTopLevelItem(item);

    }

    ui->treeWidget->setTreePosition(1); //子项前调
    ui->treeWidget->header()->hide();
    //SELECT table_name FROM information_schema.TABLES
}

void MainWindow::mysqlconnect()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");  //连接的MYSQL的数据库驱动
    qDebug() << QSqlDatabase::drivers();
    db.setHostName("localhost");//主机名
   // db.setPort(3306);//端口
    db.setDatabaseName("test");//数据库名
    db.setUserName("root");//用户名
    db.setPassword("123456");//密码
    db.open();
    //query.exec();
    if(db.open())
        {
            qDebug()<<"sucess";
            QSqlQuery query=QSqlQuery(db);//将query指令与数据库绑定
            //initForm(ui->tableWidget);
        }
        else {
            qDebug() << "Error:" << db.lastError().text();//输出无法打开数据库的错误
    }
   //showtable();
//    QString s;
//    QString user_type = ui->buttonGroup->checkedButton()->text();
//    s = (user_type == QString::fromLocal8Bit("学生")) ? "Stu" : "admin";
//    qDebug()<<s;
}

void MainWindow::readxml()
{
    Config config;
    QString str;
    str = config.readConfig();
    qDebug()<<qUtf8Printable(str);  //输出不带双引号，需要用qUtf8Printable转换
    ui->xml_text->appendPlainText("读取XML信息如下:\n");
    ui->xml_text->appendPlainText(str);
}

