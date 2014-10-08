/********************************************************************************
** Form generated from reading UI file 'LoginUI.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINUI_H
#define UI_LOGINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginUI
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_logo;
    QLabel *label;
    QLabel *label_title;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_ID;
    QLineEdit *lineEdit_ID;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_id_PW;
    QLineEdit *lineEdit_PW;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_login;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *LoginUI)
    {
        if (LoginUI->objectName().isEmpty())
            LoginUI->setObjectName(QStringLiteral("LoginUI"));
        LoginUI->resize(1280, 720);
        LoginUI->setMinimumSize(QSize(1280, 720));
        LoginUI->setMaximumSize(QSize(1280, 720));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        LoginUI->setFont(font);
        gridLayout = new QGridLayout(LoginUI);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_logo = new QLabel(LoginUI);
        label_logo->setObjectName(QStringLiteral("label_logo"));
        label_logo->setMinimumSize(QSize(228, 252));
        label_logo->setMaximumSize(QSize(228, 250));
        label_logo->setPixmap(QPixmap(QString::fromUtf8(":/res/logo.png")));

        horizontalLayout_4->addWidget(label_logo);


        verticalLayout_2->addLayout(horizontalLayout_4);

        label = new QLabel(LoginUI);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(26);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_title = new QLabel(LoginUI);
        label_title->setObjectName(QStringLiteral("label_title"));
        label_title->setMinimumSize(QSize(800, 100));
        label_title->setMaximumSize(QSize(16777215, 100));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(20);
        label_title->setFont(font2);
        label_title->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_title);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label_ID = new QLabel(LoginUI);
        label_ID->setObjectName(QStringLiteral("label_ID"));
        label_ID->setMaximumSize(QSize(100, 50));

        horizontalLayout->addWidget(label_ID);

        lineEdit_ID = new QLineEdit(LoginUI);
        lineEdit_ID->setObjectName(QStringLiteral("lineEdit_ID"));
        lineEdit_ID->setMinimumSize(QSize(150, 20));
        lineEdit_ID->setMaximumSize(QSize(150, 20));

        horizontalLayout->addWidget(lineEdit_ID);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        label_id_PW = new QLabel(LoginUI);
        label_id_PW->setObjectName(QStringLiteral("label_id_PW"));

        horizontalLayout_2->addWidget(label_id_PW);

        lineEdit_PW = new QLineEdit(LoginUI);
        lineEdit_PW->setObjectName(QStringLiteral("lineEdit_PW"));
        lineEdit_PW->setMinimumSize(QSize(150, 20));
        lineEdit_PW->setMaximumSize(QSize(150, 20));
        lineEdit_PW->setEchoMode(QLineEdit::Password);

        horizontalLayout_2->addWidget(lineEdit_PW);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_9 = new QSpacerItem(330, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_9);

        pushButton_login = new QPushButton(LoginUI);
        pushButton_login->setObjectName(QStringLiteral("pushButton_login"));
        pushButton_login->setMinimumSize(QSize(150, 0));
        pushButton_login->setMaximumSize(QSize(150, 50));

        horizontalLayout_3->addWidget(pushButton_login);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);


        retranslateUi(LoginUI);

        QMetaObject::connectSlotsByName(LoginUI);
    } // setupUi

    void retranslateUi(QWidget *LoginUI)
    {
        LoginUI->setWindowTitle(QApplication::translate("LoginUI", "Login", 0));
        label_logo->setText(QString());
        label->setText(QApplication::translate("LoginUI", "\346\254\242\350\277\216\344\275\277\347\224\250\345\234\250\347\272\277\350\200\203\350\257\225\347\263\273\347\273\237", 0));
        label_title->setText(QApplication::translate("LoginUI", "\347\256\241\347\220\206\347\231\273\351\231\206", 0));
        label_ID->setText(QApplication::translate("LoginUI", "\345\267\245\345\217\267\357\274\232", 0));
        label_id_PW->setText(QApplication::translate("LoginUI", "\345\257\206\347\240\201\357\274\232", 0));
        pushButton_login->setText(QApplication::translate("LoginUI", "\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginUI: public Ui_LoginUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINUI_H
