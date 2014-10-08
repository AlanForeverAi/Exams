/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_QuestionsManager;
    QAction *action_examctrl;
    QAction *action_makepaper;
    QAction *action_subscore;
    QAction *action_memmanager;
    QAction *action_login;
    QAction *action_mainmenu;
    QAction *action_config;
    QAction *action_scomanage;
    QAction *action_Qt;
    QAction *action_program;
    QAction *action_inoutput;
    QWidget *centralWidget;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_ctrl;
    QMenu *menu_2;
    QMenu *menu_about;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(1280, 720));
        MainWindow->setStyleSheet(QStringLiteral(""));
        action_QuestionsManager = new QAction(MainWindow);
        action_QuestionsManager->setObjectName(QStringLiteral("action_QuestionsManager"));
        action_examctrl = new QAction(MainWindow);
        action_examctrl->setObjectName(QStringLiteral("action_examctrl"));
        action_makepaper = new QAction(MainWindow);
        action_makepaper->setObjectName(QStringLiteral("action_makepaper"));
        action_subscore = new QAction(MainWindow);
        action_subscore->setObjectName(QStringLiteral("action_subscore"));
        action_memmanager = new QAction(MainWindow);
        action_memmanager->setObjectName(QStringLiteral("action_memmanager"));
        action_login = new QAction(MainWindow);
        action_login->setObjectName(QStringLiteral("action_login"));
        action_mainmenu = new QAction(MainWindow);
        action_mainmenu->setObjectName(QStringLiteral("action_mainmenu"));
        action_config = new QAction(MainWindow);
        action_config->setObjectName(QStringLiteral("action_config"));
        action_scomanage = new QAction(MainWindow);
        action_scomanage->setObjectName(QStringLiteral("action_scomanage"));
        action_Qt = new QAction(MainWindow);
        action_Qt->setObjectName(QStringLiteral("action_Qt"));
        action_program = new QAction(MainWindow);
        action_program->setObjectName(QStringLiteral("action_program"));
        action_inoutput = new QAction(MainWindow);
        action_inoutput->setObjectName(QStringLiteral("action_inoutput"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 19));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_ctrl = new QMenu(menuBar);
        menu_ctrl->setObjectName(QStringLiteral("menu_ctrl"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_about = new QMenu(menuBar);
        menu_about->setObjectName(QStringLiteral("menu_about"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_ctrl->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_about->menuAction());
        menu->addAction(action_QuestionsManager);
        menu->addAction(action_makepaper);
        menu->addAction(action_memmanager);
        menu->addAction(action_scomanage);
        menu_ctrl->addAction(action_login);
        menu_ctrl->addAction(action_examctrl);
        menu_ctrl->addAction(action_subscore);
        menu_ctrl->addAction(action_mainmenu);
        menu_2->addAction(action_config);
        menu_2->addAction(action_inoutput);
        menu_about->addAction(action_Qt);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\234\250\347\272\277\350\200\203\350\257\225\347\263\273\347\273\237", 0));
        action_QuestionsManager->setText(QApplication::translate("MainWindow", "\351\242\230\345\272\223\347\256\241\347\220\206", 0));
        action_examctrl->setText(QApplication::translate("MainWindow", "\350\200\203\350\257\225\346\216\247\345\210\266", 0));
        action_makepaper->setText(QApplication::translate("MainWindow", "\350\257\225\345\215\267\347\256\241\347\220\206", 0));
        action_subscore->setText(QApplication::translate("MainWindow", "\344\270\273\350\247\202\351\242\230\346\211\271\346\224\271", 0));
        action_memmanager->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\347\256\241\347\220\206", 0));
        action_login->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", 0));
        action_mainmenu->setText(QApplication::translate("MainWindow", "\344\270\273\350\217\234\345\215\225", 0));
        action_config->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0));
        action_scomanage->setText(QApplication::translate("MainWindow", "\346\210\220\347\273\251\347\256\241\347\220\206", 0));
        action_Qt->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216Qt", 0));
        action_program->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216\346\234\254\347\250\213\345\272\217", 0));
        action_inoutput->setText(QApplication::translate("MainWindow", "\345\257\274\345\205\245\345\257\274\345\207\272", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\347\256\241\347\220\206", 0));
        menu_ctrl->setTitle(QApplication::translate("MainWindow", "\346\216\247\345\210\266", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\345\205\266\344\273\226", 0));
        menu_about->setTitle(QApplication::translate("MainWindow", "\345\205\263\344\272\216", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
