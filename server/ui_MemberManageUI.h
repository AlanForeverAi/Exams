/********************************************************************************
** Form generated from reading UI file 'MemberManageUI.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMBERMANAGEUI_H
#define UI_MEMBERMANAGEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemberManageUI
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_22;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_21;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit_search;
    QPushButton *pushButton_search;
    QPushButton *pushButton_all;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tableWidget_Student;
    QFrame *line_2;
    QFrame *line_7;
    QLabel *label_8;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLineEdit *lineEdit_userID;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *lineEdit_userName;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *lineEdit_userGrade;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_19;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_userClass;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_20;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *lineEdit_userPwd;
    QSpacerItem *horizontalSpacer_12;
    QWidget *tab_2;
    QTableWidget *tableWidget_Teacher;
    QFrame *line_8;
    QFrame *line_9;
    QLabel *label_12;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QLineEdit *lineEdit_managerId;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_10;
    QLineEdit *lineEdit_managerName;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_13;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_11;
    QLineEdit *lineEdit_managerPwd;
    QSpacerItem *horizontalSpacer_13;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_add_user;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_delete_user;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QWidget *MemberManageUI)
    {
        if (MemberManageUI->objectName().isEmpty())
            MemberManageUI->setObjectName(QStringLiteral("MemberManageUI"));
        MemberManageUI->resize(1280, 675);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        MemberManageUI->setFont(font);
        layoutWidget = new QWidget(MemberManageUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1261, 651));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        horizontalSpacer_3 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_3);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(24);
        label_2->setFont(font1);

        horizontalLayout_22->addWidget(label_2);

        pushButton_back = new QPushButton(layoutWidget);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_back->sizePolicy().hasHeightForWidth());
        pushButton_back->setSizePolicy(sizePolicy);
        pushButton_back->setMinimumSize(QSize(83, 50));
        pushButton_back->setMaximumSize(QSize(83, 50));
        pushButton_back->setFont(font);

        horizontalLayout_22->addWidget(pushButton_back);

        horizontalSpacer_5 = new QSpacerItem(17, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_22->addItem(horizontalSpacer_5);


        verticalLayout_6->addLayout(horizontalLayout_22);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lineEdit_search = new QLineEdit(layoutWidget);
        lineEdit_search->setObjectName(QStringLiteral("lineEdit_search"));
        sizePolicy.setHeightForWidth(lineEdit_search->sizePolicy().hasHeightForWidth());
        lineEdit_search->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(lineEdit_search);

        pushButton_search = new QPushButton(layoutWidget);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));

        horizontalLayout->addWidget(pushButton_search);


        horizontalLayout_21->addLayout(horizontalLayout);

        pushButton_all = new QPushButton(layoutWidget);
        pushButton_all->setObjectName(QStringLiteral("pushButton_all"));

        horizontalLayout_21->addWidget(pushButton_all);

        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_21);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(1141, 519));
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableWidget_Student = new QTableWidget(tab);
        if (tableWidget_Student->columnCount() < 5)
            tableWidget_Student->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_Student->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_Student->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Student->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Student->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Student->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget_Student->setObjectName(QStringLiteral("tableWidget_Student"));
        tableWidget_Student->setGeometry(QRect(10, 40, 691, 441));
        tableWidget_Student->setDragEnabled(true);
        tableWidget_Student->setDragDropMode(QAbstractItemView::NoDragDrop);
        tableWidget_Student->setTextElideMode(Qt::ElideLeft);
        tableWidget_Student->setSortingEnabled(true);
        line_2 = new QFrame(tab);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(710, 0, 20, 491));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(tab);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setGeometry(QRect(720, 50, 411, 16));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        label_8 = new QLabel(tab);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(730, 10, 81, 31));
        layoutWidget1 = new QWidget(tab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(780, 100, 262, 351));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_9->addWidget(label_7);

        lineEdit_userID = new QLineEdit(layoutWidget1);
        lineEdit_userID->setObjectName(QStringLiteral("lineEdit_userID"));
        sizePolicy.setHeightForWidth(lineEdit_userID->sizePolicy().hasHeightForWidth());
        lineEdit_userID->setSizePolicy(sizePolicy);
        lineEdit_userID->setMinimumSize(QSize(0, 40));
        lineEdit_userID->setFrame(true);
        lineEdit_userID->setCursorPosition(0);

        horizontalLayout_9->addWidget(lineEdit_userID);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);


        horizontalLayout_16->addLayout(horizontalLayout_9);


        verticalLayout_3->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_5->addWidget(label_3);

        lineEdit_userName = new QLineEdit(layoutWidget1);
        lineEdit_userName->setObjectName(QStringLiteral("lineEdit_userName"));
        sizePolicy.setHeightForWidth(lineEdit_userName->sizePolicy().hasHeightForWidth());
        lineEdit_userName->setSizePolicy(sizePolicy);
        lineEdit_userName->setMinimumSize(QSize(0, 40));

        horizontalLayout_5->addWidget(lineEdit_userName);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);


        horizontalLayout_17->addLayout(horizontalLayout_5);


        verticalLayout_3->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        lineEdit_userGrade = new QLineEdit(layoutWidget1);
        lineEdit_userGrade->setObjectName(QStringLiteral("lineEdit_userGrade"));
        sizePolicy.setHeightForWidth(lineEdit_userGrade->sizePolicy().hasHeightForWidth());
        lineEdit_userGrade->setSizePolicy(sizePolicy);
        lineEdit_userGrade->setMinimumSize(QSize(0, 40));

        horizontalLayout_7->addWidget(lineEdit_userGrade);


        horizontalLayout_18->addLayout(horizontalLayout_7);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_9);


        verticalLayout_3->addLayout(horizontalLayout_18);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        lineEdit_userClass = new QLineEdit(layoutWidget1);
        lineEdit_userClass->setObjectName(QStringLiteral("lineEdit_userClass"));
        sizePolicy.setHeightForWidth(lineEdit_userClass->sizePolicy().hasHeightForWidth());
        lineEdit_userClass->setSizePolicy(sizePolicy);
        lineEdit_userClass->setMinimumSize(QSize(0, 40));

        horizontalLayout_6->addWidget(lineEdit_userClass);


        horizontalLayout_19->addLayout(horizontalLayout_6);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_10);


        verticalLayout_3->addLayout(horizontalLayout_19);

        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        lineEdit_userPwd = new QLineEdit(layoutWidget1);
        lineEdit_userPwd->setObjectName(QStringLiteral("lineEdit_userPwd"));
        sizePolicy.setHeightForWidth(lineEdit_userPwd->sizePolicy().hasHeightForWidth());
        lineEdit_userPwd->setSizePolicy(sizePolicy);
        lineEdit_userPwd->setMinimumSize(QSize(0, 40));
        lineEdit_userPwd->setEchoMode(QLineEdit::Password);

        horizontalLayout_8->addWidget(lineEdit_userPwd);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_12);


        horizontalLayout_20->addLayout(horizontalLayout_8);


        verticalLayout_3->addLayout(horizontalLayout_20);

        tabWidget->addTab(tab, QString());
        layoutWidget->raise();
        tableWidget_Student->raise();
        line_2->raise();
        line_7->raise();
        label_8->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableWidget_Teacher = new QTableWidget(tab_2);
        if (tableWidget_Teacher->columnCount() < 3)
            tableWidget_Teacher->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Teacher->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Teacher->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_Teacher->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        tableWidget_Teacher->setObjectName(QStringLiteral("tableWidget_Teacher"));
        tableWidget_Teacher->setGeometry(QRect(10, 40, 691, 441));
        tableWidget_Teacher->setSortingEnabled(true);
        line_8 = new QFrame(tab_2);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setGeometry(QRect(710, 0, 20, 491));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(tab_2);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setGeometry(QRect(720, 50, 411, 16));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(730, 10, 81, 31));
        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(780, 140, 305, 261));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_10->addWidget(label_9);

        lineEdit_managerId = new QLineEdit(layoutWidget2);
        lineEdit_managerId->setObjectName(QStringLiteral("lineEdit_managerId"));
        sizePolicy.setHeightForWidth(lineEdit_managerId->sizePolicy().hasHeightForWidth());
        lineEdit_managerId->setSizePolicy(sizePolicy);
        lineEdit_managerId->setMinimumSize(QSize(0, 40));

        horizontalLayout_10->addWidget(lineEdit_managerId);


        horizontalLayout_15->addLayout(horizontalLayout_10);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_8);


        verticalLayout_4->addLayout(horizontalLayout_15);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_11->addWidget(label_10);

        lineEdit_managerName = new QLineEdit(layoutWidget2);
        lineEdit_managerName->setObjectName(QStringLiteral("lineEdit_managerName"));
        sizePolicy.setHeightForWidth(lineEdit_managerName->sizePolicy().hasHeightForWidth());
        lineEdit_managerName->setSizePolicy(sizePolicy);
        lineEdit_managerName->setMinimumSize(QSize(0, 40));

        horizontalLayout_11->addWidget(lineEdit_managerName);


        horizontalLayout_14->addLayout(horizontalLayout_11);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_11);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_12->addWidget(label_11);

        lineEdit_managerPwd = new QLineEdit(layoutWidget2);
        lineEdit_managerPwd->setObjectName(QStringLiteral("lineEdit_managerPwd"));
        lineEdit_managerPwd->setEnabled(true);
        sizePolicy.setHeightForWidth(lineEdit_managerPwd->sizePolicy().hasHeightForWidth());
        lineEdit_managerPwd->setSizePolicy(sizePolicy);
        lineEdit_managerPwd->setMinimumSize(QSize(0, 40));
        lineEdit_managerPwd->setEchoMode(QLineEdit::Password);

        horizontalLayout_12->addWidget(lineEdit_managerPwd);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_13);


        horizontalLayout_13->addLayout(horizontalLayout_12);


        verticalLayout_4->addLayout(horizontalLayout_13);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_3->addWidget(tabWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_add_user = new QPushButton(layoutWidget);
        pushButton_add_user->setObjectName(QStringLiteral("pushButton_add_user"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_add_user->sizePolicy().hasHeightForWidth());
        pushButton_add_user->setSizePolicy(sizePolicy1);
        pushButton_add_user->setMinimumSize(QSize(0, 30));
        pushButton_add_user->setFont(font);

        verticalLayout->addWidget(pushButton_add_user);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_delete_user = new QPushButton(layoutWidget);
        pushButton_delete_user->setObjectName(QStringLiteral("pushButton_delete_user"));
        sizePolicy1.setHeightForWidth(pushButton_delete_user->sizePolicy().hasHeightForWidth());
        pushButton_delete_user->setSizePolicy(sizePolicy1);
        pushButton_delete_user->setMinimumSize(QSize(0, 30));
        pushButton_delete_user->setFont(font);

        verticalLayout->addWidget(pushButton_delete_user);

        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);


        horizontalLayout_2->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(13, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_6->addLayout(verticalLayout_5);


        retranslateUi(MemberManageUI);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MemberManageUI);
    } // setupUi

    void retranslateUi(QWidget *MemberManageUI)
    {
        MemberManageUI->setWindowTitle(QApplication::translate("MemberManageUI", "\346\210\220\345\221\230\347\256\241\347\220\206\347\225\214\351\235\242", 0));
        label_2->setText(QApplication::translate("MemberManageUI", "\347\224\250\346\210\267\347\256\241\347\220\206", 0));
        pushButton_back->setText(QApplication::translate("MemberManageUI", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", 0));
        lineEdit_search->setText(QApplication::translate("MemberManageUI", "\347\202\271\345\207\273\346\255\244\345\244\204\350\276\223\345\205\245", 0));
        pushButton_search->setText(QApplication::translate("MemberManageUI", "\346\237\245\350\257\242", 0));
        pushButton_all->setText(QApplication::translate("MemberManageUI", "\346\230\276\347\244\272\345\205\250\351\203\250", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_Student->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MemberManageUI", "\350\200\203\347\224\237\345\255\246\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_Student->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MemberManageUI", "\345\247\223\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Student->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MemberManageUI", "\347\217\255\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Student->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MemberManageUI", "\345\271\264\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Student->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MemberManageUI", "\345\257\206\347\240\201", 0));
        label_8->setText(QApplication::translate("MemberManageUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\350\200\203\347\224\237\344\277\241\346\201\257\357\274\232</span></p></body></html>", 0));
        label_7->setText(QApplication::translate("MemberManageUI", "\357\274\251\357\274\244\357\274\232", 0));
        label_3->setText(QApplication::translate("MemberManageUI", "\345\247\223\345\220\215\357\274\232", 0));
        label_5->setText(QApplication::translate("MemberManageUI", "\345\271\264\347\272\247\357\274\232", 0));
        label_4->setText(QApplication::translate("MemberManageUI", "\347\217\255\347\272\247\357\274\232", 0));
        label_6->setText(QApplication::translate("MemberManageUI", "\345\257\206\347\240\201\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MemberManageUI", "\350\200\203\347\224\237\347\256\241\347\220\206", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Teacher->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MemberManageUI", "\346\225\231\345\270\210\345\267\245\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Teacher->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MemberManageUI", "\345\247\223\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Teacher->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("MemberManageUI", "\345\257\206\347\240\201", 0));
        label_12->setText(QApplication::translate("MemberManageUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">\346\225\231\345\270\210\344\277\241\346\201\257:</span></p></body></html>", 0));
        label_9->setText(QApplication::translate("MemberManageUI", "\357\274\251\357\274\244\357\274\232", 0));
        label_10->setText(QApplication::translate("MemberManageUI", "\345\247\223\345\220\215\357\274\232", 0));
        label_11->setText(QApplication::translate("MemberManageUI", "\345\257\206\347\240\201\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MemberManageUI", "\346\225\231\345\270\210\347\256\241\347\220\206", 0));
        pushButton_add_user->setText(QApplication::translate("MemberManageUI", "\346\226\260\345\242\236", 0));
        pushButton_delete_user->setText(QApplication::translate("MemberManageUI", "\345\210\240\351\231\244", 0));
    } // retranslateUi

};

namespace Ui {
    class MemberManageUI: public Ui_MemberManageUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMBERMANAGEUI_H
