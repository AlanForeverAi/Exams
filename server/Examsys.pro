#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T09:48:19
#
#-------------------------------------------------

QT       += core gui
QT        += sql
QT        +=network
QT        +=widgets
TARGET = Examsys
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainapp.cpp \
    data.cpp \
    server.cpp\
    PaperManageUI.cpp \
    QuestionsManageUI.cpp \
    ExamCtrlUI.cpp \
    SubMarkUI.cpp \
    IOManager.cpp \
    InOutPutUI.cpp \
    ConfigUI.cpp \
    MainMenuUI.cpp \
    MemberManageUI.cpp \
    LoginUI.cpp \
    ScoreManageUI.cpp \
    DBManager.cpp


HEADERS  += mainwindow.h \
    DBManager.h \
    mainapp.h \
    data.h \
    server.h\
    PaperManageUI.h \
    QuestionsManageUI.h \
    ExamCtrlUI.h \
    SubMarkUI.h \
    IOManager.h \
    InOutPutUI.h \
    ConfigUI.h \
    MainMenuUI.h \
    MemberManageUI.h \
    LoginUI.h \
    ScoreManageUI.h


FORMS    += mainwindow.ui \
    QuestionsManageUI.ui \
    PaperManageUI.ui \
    ExamCtrlUI.ui \
    SubMarkUI.ui \
    InOutPutUI.ui \
    ConfigUI.ui \
    MainMenuUI.ui \
    MemberManageUI.ui \
    LoginUI.ui \
    ScoreManageUI.ui

RESOURCES += \
    res.qrc

OTHER_FILES += \
    icon.rc
RC_FILE += \
    icon.rc






