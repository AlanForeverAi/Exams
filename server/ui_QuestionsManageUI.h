/********************************************************************************
** Form generated from reading UI file 'QuestionsManageUI.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUESTIONSMANAGEUI_H
#define UI_QUESTIONSMANAGEUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuestionsManageUI
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_3;
    QPushButton *pushButton_back;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_4;
    QFrame *line_4;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_10;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *obTable;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *subTable;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_2;
    QPushButton *Button_delete;
    QSpacerItem *verticalSpacer;
    QFrame *line;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label;
    QComboBox *comboBox_type;
    QFrame *line_2;
    QLineEdit *lineEdit_type;
    QPushButton *Button_addtype;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_Content;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_Answer;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout;
    QCheckBox *radio_A;
    QTextEdit *textEdit_A;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *radio_B;
    QTextEdit *textEdit_B;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *radio_C;
    QTextEdit *textEdit_C;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *radio_D;
    QTextEdit *textEdit_D;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QLabel *label_tips;
    QSpacerItem *horizontalSpacer_3;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label2_Content;
    QTextEdit *textEdit2_Content;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_5;
    QPushButton *Button_new;
    QPushButton *Button_Save;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *QuestionsManageUI)
    {
        if (QuestionsManageUI->objectName().isEmpty())
            QuestionsManageUI->setObjectName(QStringLiteral("QuestionsManageUI"));
        QuestionsManageUI->setWindowModality(Qt::WindowModal);
        QuestionsManageUI->setEnabled(true);
        QuestionsManageUI->resize(1280, 670);
        QuestionsManageUI->setMinimumSize(QSize(1280, 670));
        QuestionsManageUI->setMaximumSize(QSize(1280, 670));
        QuestionsManageUI->setFocusPolicy(Qt::NoFocus);
        QuestionsManageUI->setLayoutDirection(Qt::LeftToRight);
        layoutWidget = new QWidget(QuestionsManageUI);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 10, 1262, 656));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_5);

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
        pushButton_back->setMinimumSize(QSize(80, 50));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(11);
        pushButton_back->setFont(font1);

        horizontalLayout_12->addWidget(pushButton_back);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);


        horizontalLayout_12->addLayout(horizontalLayout_11);


        verticalLayout_4->addLayout(horizontalLayout_12);

        line_4 = new QFrame(layoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line_4);

        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(1260, 281));
        groupBox_2->setMaximumSize(QSize(1260, 281));
        groupBox_2->setFont(font1);
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 1235, 246));
        horizontalLayout_10 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        tabWidget_2 = new QTabWidget(layoutWidget1);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy);
        tabWidget_2->setMinimumSize(QSize(1150, 0));
        tabWidget_2->setMaximumSize(QSize(1150, 300));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_2 = new QVBoxLayout(tab_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        obTable = new QTableWidget(tab_3);
        if (obTable->columnCount() < 8)
            obTable->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        obTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        obTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        obTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        obTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        obTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        obTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        obTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        obTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        obTable->setObjectName(QStringLiteral("obTable"));
        obTable->setMaximumSize(QSize(1150, 16777215));
        obTable->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        obTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        obTable->setSortingEnabled(true);
        obTable->horizontalHeader()->setCascadingSectionResizes(true);
        obTable->horizontalHeader()->setDefaultSectionSize(100);
        obTable->horizontalHeader()->setMinimumSectionSize(20);
        obTable->verticalHeader()->setStretchLastSection(false);

        verticalLayout_2->addWidget(obTable);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_3 = new QVBoxLayout(tab_4);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        subTable = new QTableWidget(tab_4);
        if (subTable->columnCount() < 3)
            subTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        subTable->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        subTable->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        subTable->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        subTable->setObjectName(QStringLiteral("subTable"));
        subTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        subTable->setSortingEnabled(true);

        verticalLayout_3->addWidget(subTable);

        tabWidget_2->addTab(tab_4, QString());

        horizontalLayout_10->addWidget(tabWidget_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalSpacer_2 = new QSpacerItem(20, 68, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_2);

        Button_delete = new QPushButton(layoutWidget1);
        Button_delete->setObjectName(QStringLiteral("Button_delete"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Button_delete->sizePolicy().hasHeightForWidth());
        Button_delete->setSizePolicy(sizePolicy1);
        Button_delete->setMaximumSize(QSize(16777215, 50));

        verticalLayout_6->addWidget(Button_delete);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer);


        horizontalLayout_10->addLayout(verticalLayout_6);


        verticalLayout_4->addWidget(groupBox_2);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(1260, 291));
        groupBox->setMaximumSize(QSize(1260, 291));
        groupBox->setStyleSheet(QString::fromUtf8("font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        verticalLayout_8 = new QVBoxLayout(groupBox);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_6);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_14->addWidget(label);

        comboBox_type = new QComboBox(groupBox);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));
        comboBox_type->setMinimumSize(QSize(150, 0));
        comboBox_type->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_14->addWidget(comboBox_type);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout_14->addWidget(line_2);

        lineEdit_type = new QLineEdit(groupBox);
        lineEdit_type->setObjectName(QStringLiteral("lineEdit_type"));
        lineEdit_type->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_14->addWidget(lineEdit_type);

        Button_addtype = new QPushButton(groupBox);
        Button_addtype->setObjectName(QStringLiteral("Button_addtype"));

        horizontalLayout_14->addWidget(Button_addtype);


        verticalLayout_7->addLayout(horizontalLayout_14);

        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setMinimumSize(QSize(1150, 0));
        tabWidget->setMaximumSize(QSize(1150, 250));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        tabWidget->setFont(font2);
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab->setMinimumSize(QSize(1150, 0));
        tab->setMaximumSize(QSize(1150, 16777215));
        verticalLayout_5 = new QVBoxLayout(tab);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_Content = new QLabel(tab);
        label_Content->setObjectName(QStringLiteral("label_Content"));

        horizontalLayout_7->addWidget(label_Content);

        textEdit = new QTextEdit(tab);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout_7->addWidget(textEdit);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_Answer = new QLabel(tab);
        label_Answer->setObjectName(QStringLiteral("label_Answer"));

        horizontalLayout_6->addWidget(label_Answer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        radio_A = new QCheckBox(tab);
        radio_A->setObjectName(QStringLiteral("radio_A"));

        horizontalLayout->addWidget(radio_A);

        textEdit_A = new QTextEdit(tab);
        textEdit_A->setObjectName(QStringLiteral("textEdit_A"));

        horizontalLayout->addWidget(textEdit_A);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radio_B = new QCheckBox(tab);
        radio_B->setObjectName(QStringLiteral("radio_B"));

        horizontalLayout_3->addWidget(radio_B);

        textEdit_B = new QTextEdit(tab);
        textEdit_B->setObjectName(QStringLiteral("textEdit_B"));

        horizontalLayout_3->addWidget(textEdit_B);


        horizontalLayout->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        radio_C = new QCheckBox(tab);
        radio_C->setObjectName(QStringLiteral("radio_C"));

        horizontalLayout_4->addWidget(radio_C);

        textEdit_C = new QTextEdit(tab);
        textEdit_C->setObjectName(QStringLiteral("textEdit_C"));

        horizontalLayout_4->addWidget(textEdit_C);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        radio_D = new QCheckBox(tab);
        radio_D->setObjectName(QStringLiteral("radio_D"));

        horizontalLayout_5->addWidget(radio_D);

        textEdit_D = new QTextEdit(tab);
        textEdit_D->setObjectName(QStringLiteral("textEdit_D"));

        horizontalLayout_5->addWidget(textEdit_D);


        horizontalLayout_4->addLayout(horizontalLayout_5);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        horizontalLayout_6->addLayout(gridLayout_2);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_8->setContentsMargins(0, -1, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        label_tips = new QLabel(tab);
        label_tips->setObjectName(QStringLiteral("label_tips"));
        label_tips->setMaximumSize(QSize(150, 50));
        label_tips->setFont(font2);
        label_tips->setStyleSheet(QStringLiteral(""));
        label_tips->setTextFormat(Qt::PlainText);

        horizontalLayout_8->addWidget(label_tips);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_3);


        verticalLayout_5->addLayout(horizontalLayout_8);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_2->setMinimumSize(QSize(1150, 0));
        tab_2->setMaximumSize(QSize(1150, 16777215));
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label2_Content = new QLabel(tab_2);
        label2_Content->setObjectName(QStringLiteral("label2_Content"));

        horizontalLayout_13->addWidget(label2_Content);

        textEdit2_Content = new QTextEdit(tab_2);
        textEdit2_Content->setObjectName(QStringLiteral("textEdit2_Content"));

        horizontalLayout_13->addWidget(textEdit2_Content);


        gridLayout_4->addLayout(horizontalLayout_13, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        gridLayout_4->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());

        verticalLayout_7->addWidget(tabWidget);


        horizontalLayout_9->addLayout(verticalLayout_7);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_5 = new QSpacerItem(20, 18, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_5);

        Button_new = new QPushButton(groupBox);
        Button_new->setObjectName(QStringLiteral("Button_new"));
        sizePolicy1.setHeightForWidth(Button_new->sizePolicy().hasHeightForWidth());
        Button_new->setSizePolicy(sizePolicy1);
        Button_new->setMinimumSize(QSize(75, 0));
        Button_new->setMaximumSize(QSize(75, 16777215));

        verticalLayout->addWidget(Button_new);

        Button_Save = new QPushButton(groupBox);
        Button_Save->setObjectName(QStringLiteral("Button_Save"));
        Button_Save->setEnabled(true);
        sizePolicy1.setHeightForWidth(Button_Save->sizePolicy().hasHeightForWidth());
        Button_Save->setSizePolicy(sizePolicy1);
        Button_Save->setMinimumSize(QSize(75, 0));
        Button_Save->setMaximumSize(QSize(75, 16777215));

        verticalLayout->addWidget(Button_Save);

        verticalSpacer_3 = new QSpacerItem(20, 32, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout_9->addLayout(verticalLayout);


        verticalLayout_8->addLayout(horizontalLayout_9);


        verticalLayout_4->addWidget(groupBox);

        QWidget::setTabOrder(Button_new, subTable);
        QWidget::setTabOrder(subTable, Button_delete);
        QWidget::setTabOrder(Button_delete, textEdit2_Content);
        QWidget::setTabOrder(textEdit2_Content, Button_Save);
        QWidget::setTabOrder(Button_Save, obTable);
        QWidget::setTabOrder(obTable, textEdit_A);
        QWidget::setTabOrder(textEdit_A, textEdit_B);
        QWidget::setTabOrder(textEdit_B, textEdit_C);
        QWidget::setTabOrder(textEdit_C, textEdit_D);
        QWidget::setTabOrder(textEdit_D, tabWidget_2);

        retranslateUi(QuestionsManageUI);

        tabWidget_2->setCurrentIndex(1);
        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(QuestionsManageUI);
    } // setupUi

    void retranslateUi(QWidget *QuestionsManageUI)
    {
        QuestionsManageUI->setWindowTitle(QApplication::translate("QuestionsManageUI", "\346\267\273\345\212\240\350\257\225\351\242\230\347\225\214\351\235\242", 0));
#ifndef QT_NO_WHATSTHIS
        QuestionsManageUI->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        label_3->setText(QApplication::translate("QuestionsManageUI", "\351\242\230\345\272\223\347\256\241\347\220\206", 0));
        pushButton_back->setText(QApplication::translate("QuestionsManageUI", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", 0));
        groupBox_2->setTitle(QApplication::translate("QuestionsManageUI", "\351\242\230\345\272\223\345\206\205\345\256\271", 0));
        QTableWidgetItem *___qtablewidgetitem = obTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("QuestionsManageUI", "\351\242\230\347\233\256\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem1 = obTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("QuestionsManageUI", "\351\242\230\347\233\256\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem2 = obTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("QuestionsManageUI", "\351\242\230\345\271\262", 0));
        QTableWidgetItem *___qtablewidgetitem3 = obTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("QuestionsManageUI", "\347\255\224\346\241\210A", 0));
        QTableWidgetItem *___qtablewidgetitem4 = obTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("QuestionsManageUI", "\347\255\224\346\241\210B", 0));
        QTableWidgetItem *___qtablewidgetitem5 = obTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("QuestionsManageUI", "\347\255\224\346\241\210C", 0));
        QTableWidgetItem *___qtablewidgetitem6 = obTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("QuestionsManageUI", "\347\255\224\346\241\210D", 0));
        QTableWidgetItem *___qtablewidgetitem7 = obTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("QuestionsManageUI", "\346\255\243\347\241\256\347\255\224\346\241\210", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("QuestionsManageUI", "\345\256\242\350\247\202\351\242\230", 0));
        QTableWidgetItem *___qtablewidgetitem8 = subTable->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("QuestionsManageUI", "\351\242\230\347\233\256\347\274\226\345\217\267", 0));
        QTableWidgetItem *___qtablewidgetitem9 = subTable->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("QuestionsManageUI", "\351\242\230\347\233\256\347\261\273\345\236\213", 0));
        QTableWidgetItem *___qtablewidgetitem10 = subTable->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("QuestionsManageUI", "\351\242\230\345\271\262", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("QuestionsManageUI", "\344\270\273\350\247\202\351\242\230", 0));
        Button_delete->setText(QApplication::translate("QuestionsManageUI", "\345\210\240\351\231\244", 0));
        groupBox->setTitle(QApplication::translate("QuestionsManageUI", "\350\257\267\345\234\250\344\270\213\346\226\271\350\276\223\345\205\245\350\257\225\351\242\230\345\206\205\345\256\271", 0));
        label->setText(QApplication::translate("QuestionsManageUI", "\351\242\230\347\233\256\347\261\273\345\236\213", 0));
        Button_addtype->setText(QApplication::translate("QuestionsManageUI", "\346\267\273\345\212\240\346\226\260\347\261\273\345\236\213", 0));
        label_Content->setText(QApplication::translate("QuestionsManageUI", "\351\242\230\345\271\262\357\274\232", 0));
        label_Answer->setText(QApplication::translate("QuestionsManageUI", "\347\255\224\346\241\210\357\274\232", 0));
        radio_A->setText(QApplication::translate("QuestionsManageUI", "A", 0));
        radio_B->setText(QApplication::translate("QuestionsManageUI", "B", 0));
        radio_C->setText(QApplication::translate("QuestionsManageUI", "C", 0));
        radio_D->setText(QApplication::translate("QuestionsManageUI", "D", 0));
        label_tips->setText(QApplication::translate("QuestionsManageUI", "\350\257\267\351\200\211\346\213\251\346\255\243\347\241\256\347\232\204\347\255\224\346\241\210", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("QuestionsManageUI", "\345\256\242\350\247\202\351\242\230", 0));
        label2_Content->setText(QApplication::translate("QuestionsManageUI", "\351\242\230\345\271\262\357\274\232", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("QuestionsManageUI", "\344\270\273\350\247\202\351\242\230", 0));
#ifndef QT_NO_TOOLTIP
        Button_new->setToolTip(QApplication::translate("QuestionsManageUI", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\202\271\345\207\273\346\267\273\345\212\240\345\210\260\351\242\230\345\272\223</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        Button_new->setText(QApplication::translate("QuestionsManageUI", "\346\226\260\345\273\272", 0));
        Button_Save->setText(QApplication::translate("QuestionsManageUI", "\344\277\235\345\255\230", 0));
    } // retranslateUi

};

namespace Ui {
    class QuestionsManageUI: public Ui_QuestionsManageUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUESTIONSMANAGEUI_H
