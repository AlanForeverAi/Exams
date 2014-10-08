/********************************************************************************
** Form generated from reading UI file 'ScoreManageUI.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCOREMANAGEUI_H
#define UI_SCOREMANAGEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
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

class Ui_ScoreManageUI
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_search;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tableWidget_paper;
    QFrame *line_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QTableWidget *tableWidget_Detail;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_print;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *ScoreManageUI)
    {
        if (ScoreManageUI->objectName().isEmpty())
            ScoreManageUI->setObjectName(QStringLiteral("ScoreManageUI"));
        ScoreManageUI->resize(1280, 675);
        gridLayout = new QGridLayout(ScoreManageUI);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        label_3 = new QLabel(ScoreManageUI);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        label_3->setFont(font);

        horizontalLayout_5->addWidget(label_3);

        pushButton_back = new QPushButton(ScoreManageUI);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setMinimumSize(QSize(83, 50));
        pushButton_back->setMaximumSize(QSize(16777215, 1111));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        pushButton_back->setFont(font1);
        pushButton_back->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_5->addWidget(pushButton_back);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);


        verticalLayout_5->addLayout(horizontalLayout_5);

        line_5 = new QFrame(ScoreManageUI);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_5->addWidget(line_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(ScoreManageUI);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        lineEdit = new QLineEdit(ScoreManageUI);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));

        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout);

        pushButton_search = new QPushButton(ScoreManageUI);
        pushButton_search->setObjectName(QStringLiteral("pushButton_search"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_search->sizePolicy().hasHeightForWidth());
        pushButton_search->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(pushButton_search);


        verticalLayout_4->addLayout(horizontalLayout_6);

        line_4 = new QFrame(ScoreManageUI);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(ScoreManageUI);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_2);

        tableWidget_paper = new QTableWidget(ScoreManageUI);
        if (tableWidget_paper->columnCount() < 2)
            tableWidget_paper->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_paper->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_paper->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_paper->setObjectName(QStringLiteral("tableWidget_paper"));

        verticalLayout_4->addWidget(tableWidget_paper);


        horizontalLayout_7->addLayout(verticalLayout_4);

        line_3 = new QFrame(ScoreManageUI);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_2 = new QLabel(ScoreManageUI);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_4);

        tableWidget_Detail = new QTableWidget(ScoreManageUI);
        if (tableWidget_Detail->columnCount() < 9)
            tableWidget_Detail->setColumnCount(9);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_Detail->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_Detail->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_Detail->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_Detail->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_Detail->setHorizontalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_Detail->setHorizontalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_Detail->setHorizontalHeaderItem(6, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_Detail->setHorizontalHeaderItem(7, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_Detail->setHorizontalHeaderItem(8, __qtablewidgetitem10);
        tableWidget_Detail->setObjectName(QStringLiteral("tableWidget_Detail"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget_Detail->sizePolicy().hasHeightForWidth());
        tableWidget_Detail->setSizePolicy(sizePolicy2);
        tableWidget_Detail->setMinimumSize(QSize(800, 0));

        verticalLayout_2->addWidget(tableWidget_Detail);


        horizontalLayout_7->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 150, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        pushButton_delete = new QPushButton(ScoreManageUI);
        pushButton_delete->setObjectName(QStringLiteral("pushButton_delete"));
        pushButton_delete->setMinimumSize(QSize(75, 50));

        verticalLayout_3->addWidget(pushButton_delete);

        pushButton_print = new QPushButton(ScoreManageUI);
        pushButton_print->setObjectName(QStringLiteral("pushButton_print"));
        pushButton_print->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(pushButton_print);

        verticalSpacer_3 = new QSpacerItem(20, 150, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);


        horizontalLayout_7->addLayout(verticalLayout_3);


        verticalLayout_5->addLayout(horizontalLayout_7);


        gridLayout->addLayout(verticalLayout_5, 0, 0, 1, 1);


        retranslateUi(ScoreManageUI);

        QMetaObject::connectSlotsByName(ScoreManageUI);
    } // setupUi

    void retranslateUi(QWidget *ScoreManageUI)
    {
        ScoreManageUI->setWindowTitle(QApplication::translate("ScoreManageUI", "\346\210\220\347\273\251\347\256\241\347\220\206\347\225\214\351\235\242", 0));
        label_3->setText(QApplication::translate("ScoreManageUI", "\346\210\220\347\273\251\347\256\241\347\220\206", 0));
        pushButton_back->setText(QApplication::translate("ScoreManageUI", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", 0));
        label_5->setText(QApplication::translate("ScoreManageUI", "\346\214\211\345\255\246\347\224\237ID\346\220\234\347\264\242", 0));
        pushButton_search->setText(QApplication::translate("ScoreManageUI", "\346\237\245\350\257\242", 0));
        label->setText(QApplication::translate("ScoreManageUI", "\346\211\200\346\234\211\350\200\203\350\257\225", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_paper->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ScoreManageUI", "\350\257\225\345\215\267\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_paper->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ScoreManageUI", "\350\257\225\345\215\267\345\220\215\347\247\260", 0));
        label_2->setText(QApplication::translate("ScoreManageUI", "\350\257\246\347\273\206\344\277\241\346\201\257\357\274\232", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_Detail->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("ScoreManageUI", "\350\200\203\347\224\237\345\255\246\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_Detail->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("ScoreManageUI", "\345\247\223\345\220\215", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_Detail->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("ScoreManageUI", "\347\217\255\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_Detail->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("ScoreManageUI", "\345\271\264\347\272\247", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_Detail->horizontalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("ScoreManageUI", "\350\257\225\345\215\267\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_Detail->horizontalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("ScoreManageUI", "\350\257\225\345\215\267\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_Detail->horizontalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("ScoreManageUI", "\345\256\242\350\247\202\351\242\230\345\276\227\345\210\206", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_Detail->horizontalHeaderItem(7);
        ___qtablewidgetitem9->setText(QApplication::translate("ScoreManageUI", "\344\270\273\350\247\202\351\242\230\345\276\227\345\210\206", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_Detail->horizontalHeaderItem(8);
        ___qtablewidgetitem10->setText(QApplication::translate("ScoreManageUI", "\346\200\273\345\210\206", 0));
        pushButton_delete->setText(QApplication::translate("ScoreManageUI", "\345\210\240\351\231\244\350\256\260\345\275\225", 0));
        pushButton_print->setText(QApplication::translate("ScoreManageUI", "\345\257\274\345\207\272\346\210\220\347\273\251", 0));
    } // retranslateUi

};

namespace Ui {
    class ScoreManageUI: public Ui_ScoreManageUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCOREMANAGEUI_H
