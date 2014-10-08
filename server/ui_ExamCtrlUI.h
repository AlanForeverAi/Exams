/********************************************************************************
** Form generated from reading UI file 'ExamCtrlUI.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXAMCTRLUI_H
#define UI_EXAMCTRLUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExamCtrlUI
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_3;
    QPushButton *pushButton_back;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_6;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_date;
    QDateTimeEdit *dateTimeEdit;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tableWidget_paper;
    QWidget *tab_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QTextEdit *textEdit_message;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *lineEdit_windowtitle;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *lineEdit_welcome;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *lineEdit_NO;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *lineEdit_pici;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_8;
    QFrame *line_2;
    QGroupBox *groupBox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_papername;
    QLabel *label_name;
    QFrame *line;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QLabel *label_papertime;
    QTimeEdit *timeEdit_papertime;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_state;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_send;
    QPushButton *pushButton_begin;
    QPushButton *pushButton_end;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLabel *label_usercount;
    QTableWidget *tableWidget_user;

    void setupUi(QWidget *ExamCtrlUI)
    {
        if (ExamCtrlUI->objectName().isEmpty())
            ExamCtrlUI->setObjectName(QStringLiteral("ExamCtrlUI"));
        ExamCtrlUI->resize(1280, 670);
        ExamCtrlUI->setMinimumSize(QSize(1280, 670));
        ExamCtrlUI->setMaximumSize(QSize(1280, 670));
        layoutWidget = new QWidget(ExamCtrlUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 11, 1261, 653));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_7);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(label_3);

        pushButton_back = new QPushButton(layoutWidget);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setMinimumSize(QSize(83, 50));
        pushButton_back->setMaximumSize(QSize(83, 16777215));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        pushButton_back->setFont(font1);
        pushButton_back->setStyleSheet(QStringLiteral(""));

        horizontalLayout_12->addWidget(pushButton_back);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_6);


        horizontalLayout_12->addLayout(horizontalLayout_11);


        verticalLayout_3->addLayout(horizontalLayout_12);

        line_4 = new QFrame(layoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_date = new QLabel(layoutWidget);
        label_date->setObjectName(QStringLiteral("label_date"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(16);
        label_date->setFont(font2);

        horizontalLayout_6->addWidget(label_date);

        dateTimeEdit = new QDateTimeEdit(layoutWidget);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setReadOnly(true);
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout_6->addWidget(dateTimeEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        tabWidget = new QTabWidget(layoutWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 280));
        tabWidget->setMaximumSize(QSize(525, 280));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(11);
        tabWidget->setFont(font3);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tableWidget_paper = new QTableWidget(tab);
        if (tableWidget_paper->columnCount() < 3)
            tableWidget_paper->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_paper->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_paper->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_paper->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_paper->setObjectName(QStringLiteral("tableWidget_paper"));
        tableWidget_paper->setGeometry(QRect(9, 9, 501, 231));
        tableWidget_paper->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_paper->setTextElideMode(Qt::ElideLeft);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        layoutWidget1 = new QWidget(tab_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(300, 10, 211, 231));
        verticalLayout_6 = new QVBoxLayout(layoutWidget1);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_6->addWidget(label_5);

        textEdit_message = new QTextEdit(layoutWidget1);
        textEdit_message->setObjectName(QStringLiteral("textEdit_message"));

        verticalLayout_6->addWidget(textEdit_message);

        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 11, 281, 231));
        verticalLayout_8 = new QVBoxLayout(layoutWidget2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_3 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_8->addItem(verticalSpacer_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_8);

        lineEdit_windowtitle = new QLineEdit(layoutWidget2);
        lineEdit_windowtitle->setObjectName(QStringLiteral("lineEdit_windowtitle"));
        lineEdit_windowtitle->setMinimumSize(QSize(137, 0));
        lineEdit_windowtitle->setMaximumSize(QSize(137, 16777215));

        horizontalLayout_2->addWidget(lineEdit_windowtitle);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_8->addWidget(label_4);

        horizontalSpacer_3 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        lineEdit_welcome = new QLineEdit(layoutWidget2);
        lineEdit_welcome->setObjectName(QStringLiteral("lineEdit_welcome"));
        lineEdit_welcome->setMinimumSize(QSize(137, 0));
        lineEdit_welcome->setMaximumSize(QSize(137, 16777215));

        horizontalLayout_8->addWidget(lineEdit_welcome);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_10->addWidget(label_6);

        horizontalSpacer_4 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        lineEdit_NO = new QLineEdit(layoutWidget2);
        lineEdit_NO->setObjectName(QStringLiteral("lineEdit_NO"));
        lineEdit_NO->setMinimumSize(QSize(137, 0));
        lineEdit_NO->setMaximumSize(QSize(137, 16777215));

        horizontalLayout_10->addWidget(lineEdit_NO);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_9->addWidget(label_7);

        horizontalSpacer_5 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        lineEdit_pici = new QLineEdit(layoutWidget2);
        lineEdit_pici->setObjectName(QStringLiteral("lineEdit_pici"));
        lineEdit_pici->setMinimumSize(QSize(137, 0));
        lineEdit_pici->setMaximumSize(QSize(137, 16777215));

        horizontalLayout_9->addWidget(lineEdit_pici);


        verticalLayout_4->addLayout(horizontalLayout_9);


        verticalLayout_8->addLayout(verticalLayout_4);

        verticalSpacer_2 = new QSpacerItem(262, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_2);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(0, 50));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(10);
        label_8->setFont(font4);

        verticalLayout_8->addWidget(label_8);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_5->addWidget(tabWidget);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_2);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(711, 281));
        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 20, 703, 27));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_papername = new QLabel(layoutWidget3);
        label_papername->setObjectName(QStringLiteral("label_papername"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font5.setPointSize(14);
        label_papername->setFont(font5);
        label_papername->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_papername);

        label_name = new QLabel(layoutWidget3);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setMinimumSize(QSize(600, 0));
        label_name->setFont(font5);
        label_name->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_name);

        line = new QFrame(groupBox);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(0, 50, 703, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        layoutWidget4 = new QWidget(groupBox);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 60, 681, 211));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_2 = new QGroupBox(layoutWidget4);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(311, 171));
        layoutWidget5 = new QWidget(groupBox_2);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(0, 20, 331, 181));
        verticalLayout_7 = new QVBoxLayout(layoutWidget5);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_papertime = new QLabel(layoutWidget5);
        label_papertime->setObjectName(QStringLiteral("label_papertime"));
        label_papertime->setFont(font5);

        horizontalLayout->addWidget(label_papertime);

        timeEdit_papertime = new QTimeEdit(layoutWidget5);
        timeEdit_papertime->setObjectName(QStringLiteral("timeEdit_papertime"));
        timeEdit_papertime->setMaximumSize(QSize(100, 30));
        QFont font6;
        font6.setPointSize(14);
        timeEdit_papertime->setFont(font6);
        timeEdit_papertime->setReadOnly(true);
        timeEdit_papertime->setButtonSymbols(QAbstractSpinBox::NoButtons);

        horizontalLayout->addWidget(timeEdit_papertime);

        horizontalSpacer_2 = new QSpacerItem(100, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_7->addLayout(horizontalLayout);

        label_state = new QLabel(layoutWidget5);
        label_state->setObjectName(QStringLiteral("label_state"));
        label_state->setFont(font5);
        label_state->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_state);


        verticalLayout_2->addWidget(groupBox_2);


        horizontalLayout_4->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_send = new QPushButton(layoutWidget4);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setMinimumSize(QSize(0, 50));
        pushButton_send->setFont(font5);

        verticalLayout->addWidget(pushButton_send);

        pushButton_begin = new QPushButton(layoutWidget4);
        pushButton_begin->setObjectName(QStringLiteral("pushButton_begin"));
        pushButton_begin->setMinimumSize(QSize(0, 50));
        pushButton_begin->setFont(font5);

        verticalLayout->addWidget(pushButton_begin);

        pushButton_end = new QPushButton(layoutWidget4);
        pushButton_end->setObjectName(QStringLiteral("pushButton_end"));
        pushButton_end->setMinimumSize(QSize(0, 50));
        pushButton_end->setFont(font5);

        verticalLayout->addWidget(pushButton_end);


        horizontalLayout_4->addLayout(verticalLayout);


        horizontalLayout_5->addWidget(groupBox);


        verticalLayout_3->addLayout(horizontalLayout_5);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font3);

        horizontalLayout_7->addWidget(label_2);

        label_usercount = new QLabel(layoutWidget);
        label_usercount->setObjectName(QStringLiteral("label_usercount"));
        label_usercount->setFont(font3);

        horizontalLayout_7->addWidget(label_usercount);


        verticalLayout_5->addLayout(horizontalLayout_7);

        tableWidget_user = new QTableWidget(layoutWidget);
        if (tableWidget_user->columnCount() < 6)
            tableWidget_user->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_user->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_user->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_user->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_user->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_user->setHorizontalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_user->setHorizontalHeaderItem(5, __qtablewidgetitem8);
        tableWidget_user->setObjectName(QStringLiteral("tableWidget_user"));
        tableWidget_user->setMinimumSize(QSize(0, 215));
        tableWidget_user->setMaximumSize(QSize(16777215, 220));
        tableWidget_user->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_5->addWidget(tableWidget_user);


        verticalLayout_3->addLayout(verticalLayout_5);


        retranslateUi(ExamCtrlUI);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ExamCtrlUI);
    } // setupUi

    void retranslateUi(QWidget *ExamCtrlUI)
    {
        ExamCtrlUI->setWindowTitle(QApplication::translate("ExamCtrlUI", "Form", 0));
        label_3->setText(QApplication::translate("ExamCtrlUI", "\350\200\203\350\257\225\346\216\247\345\210\266", 0));
        pushButton_back->setText(QApplication::translate("ExamCtrlUI", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", 0));
        label_date->setText(QApplication::translate("ExamCtrlUI", "\345\275\223\345\211\215\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_paper->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ExamCtrlUI", "\350\257\225\345\215\267\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_paper->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ExamCtrlUI", "\350\257\225\345\215\267\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_paper->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ExamCtrlUI", "\346\227\266\351\225\277\357\274\210\345\210\206\351\222\237\357\274\211", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ExamCtrlUI", "\350\257\225\345\215\267\345\272\223", 0));
        label_5->setText(QApplication::translate("ExamCtrlUI", "\350\200\203\350\257\225\351\241\273\347\237\245\357\274\232", 0));
        textEdit_message->setHtml(QApplication::translate("ExamCtrlUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1.\350\257\267\350\207\252\350\247\211\351\201\265\345\256\210\350\200\203\345\234\272\347\272\252\345\276\213</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2.\350\257\267\345\234\250\345\267\246\346\226\271\346\240\270\345\257\271\344\275\240\347\232\204</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">  \344\270\252\344\272\272\344\277\241\346\201\257\345\222\214"
                        "\350\200\203\350\257\225\344\277\241\346\201\257</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3.\350\257\267\345\234\250\344\272\244\345\215\267\344\271\213\345\211\215\345\244\215\346\237\245\344\275\240\347\232\204\347\255\224\346\241\210</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4.\350\257\267\344\270\215\350\246\201\351\232\217\344\276\277\345\205\263\351\227\255\345\256\242\346\210\267\347\253\257</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">5.\346\234\211\344\273\273\344\275\225\351\227\256\351\242\230\350\257\267\350\201\224\347\263\273\345\267\245\344\275\234\344\272\272\345\221\230</p></body></html>", 0));
        label->setText(QApplication::translate("ExamCtrlUI", "\345\256\242\346\210\267\347\253\257\347\252\227\345\217\243\345\220\215\347\247\260\357\274\232", 0));
        lineEdit_windowtitle->setText(QApplication::translate("ExamCtrlUI", "\345\234\250\347\272\277\350\200\203\350\257\225\347\263\273\347\273\237\345\256\242\346\210\267\347\253\257", 0));
        label_4->setText(QApplication::translate("ExamCtrlUI", "\346\254\242\350\277\216\344\277\241\346\201\257\357\274\232", 0));
        lineEdit_welcome->setText(QApplication::translate("ExamCtrlUI", "\346\254\242\350\277\216\345\217\202\345\212\240\350\200\203\350\257\225", 0));
        label_6->setText(QApplication::translate("ExamCtrlUI", "\350\200\203\345\234\272\347\274\226\345\217\267\357\274\232", 0));
        lineEdit_NO->setText(QApplication::translate("ExamCtrlUI", "001", 0));
        label_7->setText(QApplication::translate("ExamCtrlUI", "\350\200\203\350\257\225\346\211\271\346\254\241\357\274\232", 0));
        lineEdit_pici->setText(QApplication::translate("ExamCtrlUI", "002", 0));
        label_8->setText(QApplication::translate("ExamCtrlUI", "\350\257\267\347\241\256\350\256\244\350\200\203\350\257\225\344\277\241\346\201\257\345\241\253\345\206\231\346\255\243\347\241\256\345\220\216\n"
"\345\206\215\347\202\271\345\207\273\342\200\234\350\256\276\344\270\272\345\275\223\345\211\215\350\200\203\350\257\225\342\200\235\346\214\211\351\222\256", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ExamCtrlUI", "\350\200\203\350\257\225\344\277\241\346\201\257\350\256\276\347\275\256", 0));
        groupBox->setTitle(QApplication::translate("ExamCtrlUI", "\350\200\203\350\257\225\344\277\241\346\201\257", 0));
        label_papername->setText(QApplication::translate("ExamCtrlUI", "\345\275\223\345\211\215\350\200\203\350\257\225\357\274\232", 0));
        label_name->setText(QApplication::translate("ExamCtrlUI", "\346\234\252\351\200\211\346\213\251", 0));
        groupBox_2->setTitle(QApplication::translate("ExamCtrlUI", "\345\275\223\345\211\215\347\212\266\346\200\201", 0));
        label_papertime->setText(QApplication::translate("ExamCtrlUI", "\345\211\251\344\275\231\346\227\266\351\227\264\357\274\232", 0));
        label_state->setText(QApplication::translate("ExamCtrlUI", "TextLabel", 0));
        pushButton_send->setText(QApplication::translate("ExamCtrlUI", "\350\256\276\344\270\272\345\275\223\345\211\215\350\200\203\350\257\225", 0));
        pushButton_begin->setText(QApplication::translate("ExamCtrlUI", "\345\274\200\345\247\213\350\200\203\350\257\225", 0));
        pushButton_end->setText(QApplication::translate("ExamCtrlUI", "\347\273\223\346\235\237\350\200\203\350\257\225", 0));
        label_2->setText(QApplication::translate("ExamCtrlUI", "\345\217\202\345\212\240\350\200\203\350\257\225\347\232\204\345\255\246\347\224\237\344\277\241\346\201\257", 0));
        label_usercount->setText(QApplication::translate("ExamCtrlUI", "\345\205\261\346\234\211\345\220\215\345\255\246\347\224\237", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_user->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("ExamCtrlUI", "\344\270\273\346\234\272\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_user->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("ExamCtrlUI", "\345\255\246\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_user->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("ExamCtrlUI", "\345\247\223\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_user->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("ExamCtrlUI", "\345\271\264\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_user->horizontalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("ExamCtrlUI", "\347\217\255\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_user->horizontalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("ExamCtrlUI", "\347\212\266\346\200\201", 0));
    } // retranslateUi

};

namespace Ui {
    class ExamCtrlUI: public Ui_ExamCtrlUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXAMCTRLUI_H
