/********************************************************************************
** Form generated from reading UI file 'mysqltext.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYSQLTEXT_H
#define UI_MYSQLTEXT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mysqltext
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *cmbox_col;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *le_keyword;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_search;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_add;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *btn_delete;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *btn_save;
    QSpacerItem *horizontalSpacer_8;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_testdata;
    QPushButton *btn_derive;
    QPushButton *btn_return;

    void setupUi(QWidget *mysqltext)
    {
        if (mysqltext->objectName().isEmpty())
            mysqltext->setObjectName(QString::fromUtf8("mysqltext"));
        mysqltext->resize(1173, 734);
        verticalLayout = new QVBoxLayout(mysqltext);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(mysqltext);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        cmbox_col = new QComboBox(widget);
        cmbox_col->addItem(QString());
        cmbox_col->addItem(QString());
        cmbox_col->addItem(QString());
        cmbox_col->addItem(QString());
        cmbox_col->addItem(QString());
        cmbox_col->addItem(QString());
        cmbox_col->addItem(QString());
        cmbox_col->addItem(QString());
        cmbox_col->addItem(QString());
        cmbox_col->addItem(QString());
        cmbox_col->setObjectName(QString::fromUtf8("cmbox_col"));

        horizontalLayout_2->addWidget(cmbox_col);

        horizontalSpacer_2 = new QSpacerItem(43, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        le_keyword = new QLineEdit(widget);
        le_keyword->setObjectName(QString::fromUtf8("le_keyword"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(le_keyword->sizePolicy().hasHeightForWidth());
        le_keyword->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(le_keyword);

        horizontalSpacer_3 = new QSpacerItem(42, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        btn_search = new QPushButton(widget);
        btn_search->setObjectName(QString::fromUtf8("btn_search"));

        horizontalLayout_2->addWidget(btn_search);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        btn_add = new QPushButton(widget);
        btn_add->setObjectName(QString::fromUtf8("btn_add"));

        horizontalLayout_2->addWidget(btn_add);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        btn_delete = new QPushButton(widget);
        btn_delete->setObjectName(QString::fromUtf8("btn_delete"));

        horizontalLayout_2->addWidget(btn_delete);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_7);

        btn_save = new QPushButton(widget);
        btn_save->setObjectName(QString::fromUtf8("btn_save"));

        horizontalLayout_2->addWidget(btn_save);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        verticalLayout->addWidget(widget);

        tableWidget = new QTableWidget(mysqltext);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_testdata = new QPushButton(mysqltext);
        btn_testdata->setObjectName(QString::fromUtf8("btn_testdata"));

        horizontalLayout->addWidget(btn_testdata);

        btn_derive = new QPushButton(mysqltext);
        btn_derive->setObjectName(QString::fromUtf8("btn_derive"));

        horizontalLayout->addWidget(btn_derive);

        btn_return = new QPushButton(mysqltext);
        btn_return->setObjectName(QString::fromUtf8("btn_return"));

        horizontalLayout->addWidget(btn_return);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(mysqltext);

        cmbox_col->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mysqltext);
    } // setupUi

    void retranslateUi(QWidget *mysqltext)
    {
        mysqltext->setWindowTitle(QCoreApplication::translate("mysqltext", "Form", nullptr));
        label->setText(QCoreApplication::translate("mysqltext", "\347\255\233\351\200\211:", nullptr));
        cmbox_col->setItemText(0, QCoreApplication::translate("mysqltext", "\345\205\250\351\203\250", nullptr));
        cmbox_col->setItemText(1, QCoreApplication::translate("mysqltext", "\345\247\223\345\220\215", nullptr));
        cmbox_col->setItemText(2, QCoreApplication::translate("mysqltext", "\345\234\260\345\214\272", nullptr));
        cmbox_col->setItemText(3, QCoreApplication::translate("mysqltext", "\347\224\265\350\257\235\345\217\267\347\240\201", nullptr));
        cmbox_col->setItemText(4, QCoreApplication::translate("mysqltext", "\346\200\247\345\210\253", nullptr));
        cmbox_col->setItemText(5, QCoreApplication::translate("mysqltext", "\350\264\255\344\271\260\346\227\245\346\234\237", nullptr));
        cmbox_col->setItemText(6, QCoreApplication::translate("mysqltext", "\344\272\244\346\230\223\351\207\221\351\242\235", nullptr));
        cmbox_col->setItemText(7, QCoreApplication::translate("mysqltext", "\344\272\244\346\230\223\347\211\251\345\223\201", nullptr));
        cmbox_col->setItemText(8, QCoreApplication::translate("mysqltext", "\346\230\257\345\220\246\347\273\223\346\254\276", nullptr));
        cmbox_col->setItemText(9, QCoreApplication::translate("mysqltext", "\345\244\207\346\263\250", nullptr));

        label_2->setText(QCoreApplication::translate("mysqltext", "\345\205\263\351\224\256\345\255\227:", nullptr));
        le_keyword->setPlaceholderText(QCoreApplication::translate("mysqltext", "\350\257\267\350\276\223\345\205\245\345\205\263\351\224\256\345\255\227", nullptr));
        btn_search->setText(QCoreApplication::translate("mysqltext", "\346\237\245\350\257\242", nullptr));
        btn_add->setText(QCoreApplication::translate("mysqltext", "\346\226\260\345\242\236", nullptr));
        btn_delete->setText(QCoreApplication::translate("mysqltext", "\345\210\240\351\231\244", nullptr));
        btn_save->setText(QCoreApplication::translate("mysqltext", "\344\277\235\345\255\230", nullptr));
        btn_testdata->setText(QCoreApplication::translate("mysqltext", "\347\224\237\346\210\220\345\201\207\346\225\260\346\215\256", nullptr));
        btn_derive->setText(QCoreApplication::translate("mysqltext", "\345\257\274\345\207\272\346\225\260\346\215\256", nullptr));
        btn_return->setText(QCoreApplication::translate("mysqltext", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mysqltext: public Ui_mysqltext {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYSQLTEXT_H
