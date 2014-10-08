/********************************************************************************
** Form generated from reading UI file 'InOutPutUI.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INOUTPUTUI_H
#define UI_INOUTPUTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InOutPutUI
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_back;
    QSpacerItem *horizontalSpacer_3;
    QFrame *line;
    QFrame *line_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QPushButton *pushButton_inuser;
    QPushButton *pushButton_inob;
    QPushButton *pushButton_insub;
    QPushButton *pushButton_inpaper;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_outuser;
    QPushButton *pushButton_outob;
    QPushButton *pushButton_outsub;
    QPushButton *pushButton_outpaper;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;
    QLabel *label_2;

    void setupUi(QWidget *InOutPutUI)
    {
        if (InOutPutUI->objectName().isEmpty())
            InOutPutUI->setObjectName(QStringLiteral("InOutPutUI"));
        InOutPutUI->resize(1280, 720);
        InOutPutUI->setMinimumSize(QSize(1280, 720));
        InOutPutUI->setMaximumSize(QSize(1280, 720));
        layoutWidget = new QWidget(InOutPutUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1261, 701));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_back = new QPushButton(layoutWidget);
        pushButton_back->setObjectName(QStringLiteral("pushButton_back"));
        pushButton_back->setMinimumSize(QSize(83, 50));
        pushButton_back->setMaximumSize(QSize(83, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        pushButton_back->setFont(font1);

        horizontalLayout_2->addWidget(pushButton_back);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        gridLayout_3->addLayout(horizontalLayout_3, 0, 1, 1, 2);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 1, 0, 1, 4);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line_2, 2, 0, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(400, 200));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(16);
        groupBox->setFont(font2);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_inuser = new QPushButton(groupBox);
        pushButton_inuser->setObjectName(QStringLiteral("pushButton_inuser"));
        pushButton_inuser->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(pushButton_inuser, 0, 0, 1, 1);

        pushButton_inob = new QPushButton(groupBox);
        pushButton_inob->setObjectName(QStringLiteral("pushButton_inob"));
        pushButton_inob->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(pushButton_inob, 1, 0, 1, 1);

        pushButton_insub = new QPushButton(groupBox);
        pushButton_insub->setObjectName(QStringLiteral("pushButton_insub"));
        pushButton_insub->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(pushButton_insub, 2, 0, 1, 1);

        pushButton_inpaper = new QPushButton(groupBox);
        pushButton_inpaper->setObjectName(QStringLiteral("pushButton_inpaper"));
        pushButton_inpaper->setMinimumSize(QSize(0, 50));

        gridLayout->addWidget(pushButton_inpaper, 3, 0, 1, 1);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(400, 200));
        groupBox_2->setFont(font2);
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        pushButton_outuser = new QPushButton(groupBox_2);
        pushButton_outuser->setObjectName(QStringLiteral("pushButton_outuser"));
        pushButton_outuser->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(pushButton_outuser, 0, 0, 1, 1);

        pushButton_outob = new QPushButton(groupBox_2);
        pushButton_outob->setObjectName(QStringLiteral("pushButton_outob"));
        pushButton_outob->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(pushButton_outob, 1, 0, 1, 1);

        pushButton_outsub = new QPushButton(groupBox_2);
        pushButton_outsub->setObjectName(QStringLiteral("pushButton_outsub"));
        pushButton_outsub->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(pushButton_outsub, 2, 0, 1, 1);

        pushButton_outpaper = new QPushButton(groupBox_2);
        pushButton_outpaper->setObjectName(QStringLiteral("pushButton_outpaper"));
        pushButton_outpaper->setMinimumSize(QSize(0, 50));

        gridLayout_2->addWidget(pushButton_outpaper, 3, 0, 1, 1);


        horizontalLayout->addWidget(groupBox_2);


        gridLayout_3->addLayout(horizontalLayout, 3, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer, 3, 3, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 5, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 4, 2, 1, 1);


        retranslateUi(InOutPutUI);

        QMetaObject::connectSlotsByName(InOutPutUI);
    } // setupUi

    void retranslateUi(QWidget *InOutPutUI)
    {
        InOutPutUI->setWindowTitle(QApplication::translate("InOutPutUI", "inoutput", 0));
        label->setText(QApplication::translate("InOutPutUI", "\345\257\274\345\205\245\345\217\212\345\257\274\345\207\272", 0));
        pushButton_back->setText(QApplication::translate("InOutPutUI", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", 0));
        groupBox->setTitle(QApplication::translate("InOutPutUI", "\345\257\274\345\205\245", 0));
        pushButton_inuser->setText(QApplication::translate("InOutPutUI", "\345\255\246\347\224\237\344\277\241\346\201\257", 0));
        pushButton_inob->setText(QApplication::translate("InOutPutUI", "\345\256\242\350\247\202\351\242\230\344\277\241\346\201\257", 0));
        pushButton_insub->setText(QApplication::translate("InOutPutUI", "\344\270\273\350\247\202\351\242\230\344\277\241\346\201\257", 0));
        pushButton_inpaper->setText(QApplication::translate("InOutPutUI", "\350\257\225\345\215\267\344\277\241\346\201\257", 0));
        groupBox_2->setTitle(QApplication::translate("InOutPutUI", "\345\257\274\345\207\272", 0));
        pushButton_outuser->setText(QApplication::translate("InOutPutUI", "\345\255\246\347\224\237\344\277\241\346\201\257", 0));
        pushButton_outob->setText(QApplication::translate("InOutPutUI", "\345\256\242\350\247\202\351\242\230\344\277\241\346\201\257", 0));
        pushButton_outsub->setText(QApplication::translate("InOutPutUI", "\344\270\273\350\247\202\351\242\230\344\277\241\346\201\257", 0));
        pushButton_outpaper->setText(QApplication::translate("InOutPutUI", "\350\257\225\345\215\267\344\277\241\346\201\257", 0));
        label_2->setText(QApplication::translate("InOutPutUI", "\345\257\274\345\207\272\347\232\204\346\226\207\344\273\266\345\234\250\347\250\213\345\272\217\347\233\256\345\275\225\347\232\204data\346\226\207\344\273\266\345\244\271\344\270\213\343\200\202", 0));
    } // retranslateUi

};

namespace Ui {
    class InOutPutUI: public Ui_InOutPutUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INOUTPUTUI_H
