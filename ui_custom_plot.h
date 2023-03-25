/********************************************************************************
** Form generated from reading UI file 'custom_plot.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOM_PLOT_H
#define UI_CUSTOM_PLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_custom_plot
{
public:
    QCustomPlot *widget;

    void setupUi(QWidget *custom_plot)
    {
        if (custom_plot->objectName().isEmpty())
            custom_plot->setObjectName(QStringLiteral("custom_plot"));
        custom_plot->resize(617, 567);
        widget = new QCustomPlot(custom_plot);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(60, 60, 401, 371));

        retranslateUi(custom_plot);

        QMetaObject::connectSlotsByName(custom_plot);
    } // setupUi

    void retranslateUi(QWidget *custom_plot)
    {
        custom_plot->setWindowTitle(QApplication::translate("custom_plot", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class custom_plot: public Ui_custom_plot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOM_PLOT_H
