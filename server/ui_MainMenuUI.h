/********************************************************************************
** Form generated from reading UI file 'MainMenuUI.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMENUUI_H
#define UI_MAINMENUUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMenuUI
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QFrame *line_16;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_question;
    QFrame *line;
    QLabel *label_3;
    QFrame *line_9;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_paper;
    QFrame *line_3;
    QLabel *label_4;
    QFrame *line_10;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_mem;
    QFrame *line_2;
    QLabel *label_5;
    QFrame *line_11;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_examctrl;
    QFrame *line_5;
    QLabel *label_7;
    QFrame *line_12;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_subscore;
    QFrame *line_6;
    QLabel *label_8;
    QFrame *line_13;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_scoremanage;
    QFrame *line_4;
    QLabel *label_6;
    QFrame *line_14;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_config;
    QFrame *line_7;
    QLabel *label_9;
    QFrame *line_15;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton_inoutput;
    QFrame *line_8;
    QLabel *label_10;

    void setupUi(QWidget *MainMenuUI)
    {
        if (MainMenuUI->objectName().isEmpty())
            MainMenuUI->setObjectName(QStringLiteral("MainMenuUI"));
        MainMenuUI->resize(1280, 675);
        MainMenuUI->setMinimumSize(QSize(1280, 675));
        MainMenuUI->setMaximumSize(QSize(1280, 675));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        MainMenuUI->setFont(font);
        widget = new QWidget(MainMenuUI);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 12, 1261, 664));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 16777215));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/res/minilogo.png")));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(36);
        label_11->setFont(font1);
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_11);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 200));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(28);
        label->setFont(font2);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_2->addWidget(label);


        horizontalLayout_10->addLayout(verticalLayout_2);

        horizontalSpacer_6 = new QSpacerItem(147, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_10);

        line_16 = new QFrame(widget);
        line_16->setObjectName(QStringLiteral("line_16"));
        line_16->setFrameShape(QFrame::HLine);
        line_16->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_16);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_question = new QPushButton(widget);
        pushButton_question->setObjectName(QStringLiteral("pushButton_question"));
        pushButton_question->setMinimumSize(QSize(150, 45));
        pushButton_question->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_2->addWidget(pushButton_question);

        line = new QFrame(widget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font3;
        font3.setPointSize(12);
        label_3->setFont(font3);

        horizontalLayout_2->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_2);

        line_9 = new QFrame(widget);
        line_9->setObjectName(QStringLiteral("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_9);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton_paper = new QPushButton(widget);
        pushButton_paper->setObjectName(QStringLiteral("pushButton_paper"));
        pushButton_paper->setMinimumSize(QSize(150, 45));
        pushButton_paper->setMaximumSize(QSize(16777215, 50));

        horizontalLayout_3->addWidget(pushButton_paper);

        line_3 = new QFrame(widget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_3->addWidget(line_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font3);

        horizontalLayout_3->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_3);

        line_10 = new QFrame(widget);
        line_10->setObjectName(QStringLiteral("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_mem = new QPushButton(widget);
        pushButton_mem->setObjectName(QStringLiteral("pushButton_mem"));
        pushButton_mem->setMinimumSize(QSize(150, 45));
        pushButton_mem->setMaximumSize(QSize(11111111, 50));

        horizontalLayout_4->addWidget(pushButton_mem);

        line_2 = new QFrame(widget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_2);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font3);

        horizontalLayout_4->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_4);

        line_11 = new QFrame(widget);
        line_11->setObjectName(QStringLiteral("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_11);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pushButton_examctrl = new QPushButton(widget);
        pushButton_examctrl->setObjectName(QStringLiteral("pushButton_examctrl"));
        pushButton_examctrl->setMinimumSize(QSize(150, 45));

        horizontalLayout_6->addWidget(pushButton_examctrl);

        line_5 = new QFrame(widget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(line_5);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font3);

        horizontalLayout_6->addWidget(label_7);


        verticalLayout->addLayout(horizontalLayout_6);

        line_12 = new QFrame(widget);
        line_12->setObjectName(QStringLiteral("line_12"));
        line_12->setFrameShape(QFrame::HLine);
        line_12->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_12);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_subscore = new QPushButton(widget);
        pushButton_subscore->setObjectName(QStringLiteral("pushButton_subscore"));
        pushButton_subscore->setMinimumSize(QSize(150, 45));

        horizontalLayout_7->addWidget(pushButton_subscore);

        line_6 = new QFrame(widget);
        line_6->setObjectName(QStringLiteral("line_6"));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);

        horizontalLayout_7->addWidget(line_6);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font3);

        horizontalLayout_7->addWidget(label_8);


        verticalLayout->addLayout(horizontalLayout_7);

        line_13 = new QFrame(widget);
        line_13->setObjectName(QStringLiteral("line_13"));
        line_13->setFrameShape(QFrame::HLine);
        line_13->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_13);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_scoremanage = new QPushButton(widget);
        pushButton_scoremanage->setObjectName(QStringLiteral("pushButton_scoremanage"));
        pushButton_scoremanage->setMinimumSize(QSize(150, 45));

        horizontalLayout_5->addWidget(pushButton_scoremanage);

        line_4 = new QFrame(widget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(line_4);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font3);

        horizontalLayout_5->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_5);

        line_14 = new QFrame(widget);
        line_14->setObjectName(QStringLiteral("line_14"));
        line_14->setFrameShape(QFrame::HLine);
        line_14->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_14);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        pushButton_config = new QPushButton(widget);
        pushButton_config->setObjectName(QStringLiteral("pushButton_config"));
        pushButton_config->setMinimumSize(QSize(150, 45));

        horizontalLayout_8->addWidget(pushButton_config);

        line_7 = new QFrame(widget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::VLine);
        line_7->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line_7);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font3);

        horizontalLayout_8->addWidget(label_9);


        verticalLayout->addLayout(horizontalLayout_8);

        line_15 = new QFrame(widget);
        line_15->setObjectName(QStringLiteral("line_15"));
        line_15->setFrameShape(QFrame::HLine);
        line_15->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_15);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButton_inoutput = new QPushButton(widget);
        pushButton_inoutput->setObjectName(QStringLiteral("pushButton_inoutput"));
        pushButton_inoutput->setMinimumSize(QSize(150, 45));

        horizontalLayout_9->addWidget(pushButton_inoutput);

        line_8 = new QFrame(widget);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::VLine);
        line_8->setFrameShadow(QFrame::Sunken);

        horizontalLayout_9->addWidget(line_8);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font3);

        horizontalLayout_9->addWidget(label_10);


        verticalLayout->addLayout(horizontalLayout_9);


        verticalLayout_3->addLayout(verticalLayout);


        retranslateUi(MainMenuUI);

        QMetaObject::connectSlotsByName(MainMenuUI);
    } // setupUi

    void retranslateUi(QWidget *MainMenuUI)
    {
        MainMenuUI->setWindowTitle(QApplication::translate("MainMenuUI", "MainMenu", 0));
        label_2->setText(QString());
        label_11->setText(QApplication::translate("MainMenuUI", "\345\234\250\347\272\277\350\200\203\350\257\225\347\263\273\347\273\237", 0));
        label->setText(QApplication::translate("MainMenuUI", "\344\270\273\350\217\234\345\215\225", 0));
        pushButton_question->setText(QApplication::translate("MainMenuUI", "\351\242\230\345\272\223\347\256\241\347\220\206", 0));
        label_3->setText(QApplication::translate("MainMenuUI", "\346\265\217\350\247\210\351\242\230\345\272\223\357\274\214\344\270\273\343\200\201\345\256\242\350\247\202\351\242\230\347\232\204\345\275\225\345\205\245\343\200\201\344\277\256\346\224\271\345\222\214\345\210\240\351\231\244\343\200\202", 0));
        pushButton_paper->setText(QApplication::translate("MainMenuUI", "\350\257\225\345\215\267\347\256\241\347\220\206", 0));
        label_4->setText(QApplication::translate("MainMenuUI", "\346\265\217\350\247\210\350\257\225\345\215\267\345\272\223\357\274\214\346\226\260\345\242\236\343\200\201\344\277\256\346\224\271\345\222\214\345\210\240\351\231\244\350\257\225\345\215\267\357\274\233\344\270\272\350\257\225\345\215\267\350\256\276\347\275\256\345\217\202\345\212\240\350\200\203\350\257\225\347\232\204\345\255\246\347\224\237", 0));
        pushButton_mem->setText(QApplication::translate("MainMenuUI", "\347\224\250\346\210\267\347\256\241\347\220\206", 0));
        label_5->setText(QApplication::translate("MainMenuUI", "\345\255\246\347\224\237\347\256\241\347\220\206\345\217\212\347\256\241\347\220\206\345\221\230\347\256\241\347\220\206\343\200\202", 0));
        pushButton_examctrl->setText(QApplication::translate("MainMenuUI", "\350\200\203\350\257\225\346\216\247\345\210\266", 0));
        label_7->setText(QApplication::translate("MainMenuUI", "\345\274\200\345\247\213\344\270\200\345\234\272\350\200\203\350\257\225\343\200\202", 0));
        pushButton_subscore->setText(QApplication::translate("MainMenuUI", "\345\234\250\347\272\277\350\257\204\345\215\267", 0));
        label_8->setText(QApplication::translate("MainMenuUI", "\344\270\273\350\247\202\351\242\230\347\232\204\346\211\271\346\224\271\343\200\202", 0));
        pushButton_scoremanage->setText(QApplication::translate("MainMenuUI", "\346\210\220\347\273\251\347\256\241\347\220\206", 0));
        label_6->setText(QApplication::translate("MainMenuUI", "\346\237\245\347\234\213\346\210\220\347\273\251\343\200\202", 0));
        pushButton_config->setText(QApplication::translate("MainMenuUI", "\350\256\276\347\275\256", 0));
        label_9->setText(QApplication::translate("MainMenuUI", "\351\205\215\347\275\256\346\225\260\346\215\256\345\272\223\345\222\214\344\270\216\345\256\242\346\210\267\347\253\257\350\277\236\346\216\245\347\232\204\347\253\257\345\217\243\343\200\202", 0));
        pushButton_inoutput->setText(QApplication::translate("MainMenuUI", "\345\257\274\345\205\245\345\217\212\345\257\274\345\207\272", 0));
        label_10->setText(QApplication::translate("MainMenuUI", "\345\260\206\351\242\230\345\272\223\343\200\201\350\257\225\345\215\267\345\217\212\347\224\250\346\210\267\350\265\204\346\226\231\345\257\274\345\205\245\346\210\226\345\257\274\345\207\272", 0));
    } // retranslateUi

};

namespace Ui {
    class MainMenuUI: public Ui_MainMenuUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMENUUI_H
