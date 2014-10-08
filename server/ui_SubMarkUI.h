/********************************************************************************
** Form generated from reading UI file 'SubMarkUI.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBMARKUI_H
#define UI_SUBMARKUI_H

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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubMarkUI
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_10;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_7;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_10;
    QTableWidget *tableWidget_paper;
    QFrame *line;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget_examInfo;
    QFrame *line_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget_userInfo;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_4;
    QTextBrowser *textBrowser_answser;
    QLabel *label_5;
    QTextBrowser *textBrowser_title;
    QFrame *line_5;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label;
    QLineEdit *lineEdit_mark;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_GotMark;
    QPushButton *pushButton_Pre;
    QPushButton *pushButton_Next;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QFrame *line_6;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_submit;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SubMarkUI)
    {
        if (SubMarkUI->objectName().isEmpty())
            SubMarkUI->setObjectName(QStringLiteral("SubMarkUI"));
        SubMarkUI->resize(1280, 675);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(11);
        SubMarkUI->setFont(font);
        layoutWidget = new QWidget(SubMarkUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1258, 652));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        QFont font1;
        font1.setPointSize(24);
        label_10->setFont(font1);

        horizontalLayout_8->addWidget(label_10);

        pushButton_back = new QPushButton(layoutWidget);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setMinimumSize(QSize(83, 50));
        pushButton_back->setMaximumSize(QSize(83, 50));
        pushButton_back->setSizeIncrement(QSize(0, 0));
        QFont font2;
        font2.setPointSize(11);
        pushButton_back->setFont(font2);

        horizontalLayout_8->addWidget(pushButton_back);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_8);

        line_7 = new QFrame(layoutWidget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_7);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_11->addWidget(label_2);


        verticalLayout_3->addLayout(horizontalLayout_11);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        tableWidget_paper = new QTableWidget(layoutWidget);
        if (tableWidget_paper->columnCount() < 2)
            tableWidget_paper->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_paper->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_paper->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_paper->setObjectName(QStringLiteral("tableWidget_paper"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget_paper->sizePolicy().hasHeightForWidth());
        tableWidget_paper->setSizePolicy(sizePolicy);
        tableWidget_paper->setMinimumSize(QSize(345, 0));
        tableWidget_paper->setSizeIncrement(QSize(0, 0));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font3.setPointSize(9);
        tableWidget_paper->setFont(font3);
        tableWidget_paper->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout_10->addWidget(tableWidget_paper);


        verticalLayout_3->addLayout(horizontalLayout_10);


        horizontalLayout_12->addLayout(verticalLayout_3);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(line);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_5->addWidget(label_9);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_5);

        tableWidget_examInfo = new QTableWidget(layoutWidget);
        if (tableWidget_examInfo->columnCount() < 1)
            tableWidget_examInfo->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_examInfo->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        if (tableWidget_examInfo->rowCount() < 4)
            tableWidget_examInfo->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_examInfo->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_examInfo->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_examInfo->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_examInfo->setVerticalHeaderItem(3, __qtablewidgetitem6);
        tableWidget_examInfo->setObjectName(QStringLiteral("tableWidget_examInfo"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget_examInfo->sizePolicy().hasHeightForWidth());
        tableWidget_examInfo->setSizePolicy(sizePolicy1);
        tableWidget_examInfo->setMaximumSize(QSize(500, 16777215));
        tableWidget_examInfo->setFont(font3);
        tableWidget_examInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(tableWidget_examInfo);


        horizontalLayout_12->addLayout(verticalLayout_2);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_12->addWidget(line_2);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);


        verticalLayout_4->addLayout(horizontalLayout_6);

        tableWidget_userInfo = new QTableWidget(layoutWidget);
        if (tableWidget_userInfo->columnCount() < 5)
            tableWidget_userInfo->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_userInfo->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_userInfo->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_userInfo->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_userInfo->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_userInfo->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        tableWidget_userInfo->setObjectName(QStringLiteral("tableWidget_userInfo"));
        tableWidget_userInfo->setMinimumSize(QSize(600, 192));

        verticalLayout_4->addWidget(tableWidget_userInfo);


        horizontalLayout_12->addLayout(verticalLayout_4);


        verticalLayout_5->addLayout(horizontalLayout_12);

        line_4 = new QFrame(layoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(1100, 0));

        verticalLayout_10->addWidget(label_4);

        textBrowser_answser = new QTextBrowser(layoutWidget);
        textBrowser_answser->setObjectName(QStringLiteral("textBrowser_answser"));
        textBrowser_answser->setMinimumSize(QSize(1100, 0));
        textBrowser_answser->setMaximumSize(QSize(16777215, 80));
        QFont font4;
        font4.setPointSize(10);
        textBrowser_answser->setFont(font4);

        verticalLayout_10->addWidget(textBrowser_answser);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_10->addWidget(label_5);

        textBrowser_title = new QTextBrowser(layoutWidget);
        textBrowser_title->setObjectName(QStringLiteral("textBrowser_title"));
        textBrowser_title->setMinimumSize(QSize(1100, 200));
        textBrowser_title->setFont(font4);

        verticalLayout_10->addWidget(textBrowser_title);


        horizontalLayout_2->addLayout(verticalLayout_10);

        line_5 = new QFrame(layoutWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_5);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_9->addWidget(label);

        lineEdit_mark = new QLineEdit(layoutWidget);
        lineEdit_mark->setObjectName(QStringLiteral("lineEdit_mark"));
        lineEdit_mark->setMinimumSize(QSize(50, 20));
        lineEdit_mark->setMaximumSize(QSize(50, 20));
        lineEdit_mark->setDragEnabled(false);
        lineEdit_mark->setReadOnly(true);

        horizontalLayout_9->addWidget(lineEdit_mark);


        verticalLayout_7->addLayout(horizontalLayout_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit_GotMark = new QLineEdit(layoutWidget);
        lineEdit_GotMark->setObjectName(QStringLiteral("lineEdit_GotMark"));
        lineEdit_GotMark->setMinimumSize(QSize(50, 20));
        lineEdit_GotMark->setMaximumSize(QSize(50, 20));
        lineEdit_GotMark->setEchoMode(QLineEdit::Normal);

        horizontalLayout->addWidget(lineEdit_GotMark);


        verticalLayout_7->addLayout(horizontalLayout);

        pushButton_Pre = new QPushButton(layoutWidget);
        pushButton_Pre->setObjectName(QStringLiteral("pushButton_Pre"));
        sizePolicy1.setHeightForWidth(pushButton_Pre->sizePolicy().hasHeightForWidth());
        pushButton_Pre->setSizePolicy(sizePolicy1);
        pushButton_Pre->setMaximumSize(QSize(150, 16777215));

        verticalLayout_7->addWidget(pushButton_Pre);

        pushButton_Next = new QPushButton(layoutWidget);
        pushButton_Next->setObjectName(QStringLiteral("pushButton_Next"));
        sizePolicy1.setHeightForWidth(pushButton_Next->sizePolicy().hasHeightForWidth());
        pushButton_Next->setSizePolicy(sizePolicy1);
        pushButton_Next->setMaximumSize(QSize(150, 16777215));

        verticalLayout_7->addWidget(pushButton_Next);


        verticalLayout_8->addLayout(verticalLayout_7);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));

        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));

        verticalLayout->addLayout(horizontalLayout_4);

        line_6 = new QFrame(layoutWidget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));

        verticalLayout->addLayout(horizontalLayout_7);


        verticalLayout_6->addLayout(verticalLayout);

        pushButton_submit = new QPushButton(layoutWidget);
        pushButton_submit->setObjectName(QStringLiteral("pushButton_submit"));
        sizePolicy1.setHeightForWidth(pushButton_submit->sizePolicy().hasHeightForWidth());
        pushButton_submit->setSizePolicy(sizePolicy1);

        verticalLayout_6->addWidget(pushButton_submit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);


        verticalLayout_8->addLayout(verticalLayout_6);


        horizontalLayout_2->addLayout(verticalLayout_8);


        verticalLayout_5->addLayout(horizontalLayout_2);


        retranslateUi(SubMarkUI);

        QMetaObject::connectSlotsByName(SubMarkUI);
    } // setupUi

    void retranslateUi(QWidget *SubMarkUI)
    {
        SubMarkUI->setWindowTitle(QApplication::translate("SubMarkUI", "\344\270\273\350\247\202\351\242\230\350\257\204\345\210\206", 0));
        label_10->setText(QApplication::translate("SubMarkUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\256\213\344\275\223'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:26pt; font-weight:600;\">\345\234\250\347\272\277\350\257\204\345\215\267</span></p></body></html>", 0));
        pushButton_back->setText(QApplication::translate("SubMarkUI", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", 0));
        label_2->setText(QApplication::translate("SubMarkUI", "\350\257\225\345\215\267\345\272\223\357\274\232", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_paper->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SubMarkUI", "\350\257\225\345\215\267\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_paper->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SubMarkUI", "\350\257\225\345\215\267\345\220\215\347\247\260", 0));
        label_9->setText(QApplication::translate("SubMarkUI", "\350\200\203\350\257\225\344\277\241\346\201\257\357\274\232", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_examInfo->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("SubMarkUI", "\350\257\225\345\215\267\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_examInfo->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("SubMarkUI", "\350\257\225\345\215\267\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_examInfo->verticalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("SubMarkUI", "\345\256\242\350\247\202\351\242\230\346\225\260\351\207\217", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_examInfo->verticalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("SubMarkUI", "\344\270\273\350\247\202\351\242\230\346\225\260\351\207\217", 0));
        label_6->setText(QApplication::translate("SubMarkUI", "\345\255\246\347\224\237\344\277\241\346\201\257\357\274\232", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_userInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("SubMarkUI", "\345\255\246\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_userInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("SubMarkUI", "\345\247\223\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_userInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("SubMarkUI", "\345\271\264\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_userInfo->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("SubMarkUI", "\347\217\255\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_userInfo->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("SubMarkUI", "\347\212\266\346\200\201", 0));
        label_4->setText(QApplication::translate("SubMarkUI", "\351\242\230\347\233\256\345\206\205\345\256\271", 0));
        label_5->setText(QApplication::translate("SubMarkUI", "\350\200\203\347\224\237\347\255\224\346\241\210", 0));
        label->setText(QApplication::translate("SubMarkUI", "\346\234\254\345\260\217\351\242\230\346\273\241\345\210\206", 0));
        label_3->setText(QApplication::translate("SubMarkUI", "\346\234\254\345\260\217\351\242\230\345\276\227\345\210\206", 0));
#ifndef QT_NO_TOOLTIP
        lineEdit_GotMark->setToolTip(QApplication::translate("SubMarkUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\270\272\350\257\245\351\242\230\350\257\204\345\210\206</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        lineEdit_GotMark->setText(QApplication::translate("SubMarkUI", "0", 0));
        pushButton_Pre->setText(QApplication::translate("SubMarkUI", "\344\270\212\344\270\200\351\242\230", 0));
        pushButton_Next->setText(QApplication::translate("SubMarkUI", "\344\270\213\344\270\200\351\242\230", 0));
        pushButton_submit->setText(QApplication::translate("SubMarkUI", "\350\257\204\345\215\267\346\217\220\344\272\244", 0));
    } // retranslateUi

};

namespace Ui {
    class SubMarkUI: public Ui_SubMarkUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBMARKUI_H
