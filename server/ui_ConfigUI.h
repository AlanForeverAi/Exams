/********************************************************************************
** Form generated from reading UI file 'ConfigUI.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGUI_H
#define UI_CONFIGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigUI
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_DBname;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLineEdit *lineEdit_DBuser;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_DBpw;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_port;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_save;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_6;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *ConfigUI)
    {
        if (ConfigUI->objectName().isEmpty())
            ConfigUI->setObjectName(QStringLiteral("ConfigUI"));
        ConfigUI->resize(1280, 720);
        ConfigUI->setMinimumSize(QSize(1280, 720));
        ConfigUI->setMaximumSize(QSize(1280, 720));
        ConfigUI->setStyleSheet(QStringLiteral(""));
        layoutWidget = new QWidget(ConfigUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1261, 708));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(400, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(400, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(400, 16777215));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        groupBox->setFont(font);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(80, 0));

        horizontalLayout->addWidget(label_2);

        lineEdit_DBname = new QLineEdit(groupBox);
        lineEdit_DBname->setObjectName(QStringLiteral("lineEdit_DBname"));

        horizontalLayout->addWidget(lineEdit_DBname);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(label_3);

        lineEdit_DBuser = new QLineEdit(groupBox);
        lineEdit_DBuser->setObjectName(QStringLiteral("lineEdit_DBuser"));

        horizontalLayout_2->addWidget(lineEdit_DBuser);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(80, 0));

        horizontalLayout_3->addWidget(label_4);

        lineEdit_DBpw = new QLineEdit(groupBox);
        lineEdit_DBpw->setObjectName(QStringLiteral("lineEdit_DBpw"));
        lineEdit_DBpw->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(lineEdit_DBpw);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(80, 0));

        horizontalLayout_4->addWidget(label_5);

        lineEdit_port = new QLineEdit(groupBox);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));

        horizontalLayout_4->addWidget(lineEdit_port);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        pushButton_save = new QPushButton(groupBox);
        pushButton_save->setObjectName(QStringLiteral("pushButton_save"));
        pushButton_save->setMinimumSize(QSize(83, 50));

        horizontalLayout_5->addWidget(pushButton_save);

        pushButton_back = new QPushButton(groupBox);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setMinimumSize(QSize(83, 50));

        horizontalLayout_5->addWidget(pushButton_back);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(24);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_6->raise();
        label->raise();

        gridLayout_2->addWidget(groupBox, 1, 1, 1, 1);

        verticalSpacer = new QSpacerItem(397, 287, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(400, 100, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);


        retranslateUi(ConfigUI);

        QMetaObject::connectSlotsByName(ConfigUI);
    } // setupUi

    void retranslateUi(QWidget *ConfigUI)
    {
        ConfigUI->setWindowTitle(QApplication::translate("ConfigUI", "ConfigUI", 0));
        groupBox->setTitle(QApplication::translate("ConfigUI", "\351\205\215\347\275\256config.ini", 0));
        label_2->setText(QApplication::translate("ConfigUI", "\346\225\260\346\215\256\345\272\223\345\220\215\347\247\260\357\274\232    ", 0));
        label_3->setText(QApplication::translate("ConfigUI", "\346\225\260\346\215\256\345\272\223\347\224\250\346\210\267\345\220\215\357\274\232", 0));
        label_4->setText(QApplication::translate("ConfigUI", "\346\225\260\346\215\256\345\272\223\345\257\206\347\240\201\357\274\232    ", 0));
        label_5->setText(QApplication::translate("ConfigUI", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\357\274\232    ", 0));
        pushButton_save->setText(QApplication::translate("ConfigUI", "\344\277\235\345\255\230", 0));
        pushButton_back->setText(QApplication::translate("ConfigUI", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", 0));
        label_6->setText(QApplication::translate("ConfigUI", "\344\277\235\345\255\230\345\220\216\350\257\267\351\207\215\345\220\257\347\250\213\345\272\217\357\274\214\344\273\245\345\272\224\347\224\250\346\226\260\351\205\215\347\275\256\343\200\202", 0));
        label->setText(QApplication::translate("ConfigUI", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class ConfigUI: public Ui_ConfigUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGUI_H
