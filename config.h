#ifndef CONFIG_H
#define CONFIG_H
#include <QXmlStreamReader>
#include <QFile>
#include <QApplication>
#include <QDir>
#include <QDebug>

class Config
{
public:
    Config();
public:
    QString readConfig();    //读取xml文件的函数
};

#endif // CONFIG_H
