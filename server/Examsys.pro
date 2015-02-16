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
    alterstudent.cpp \
    alterteacher.cpp \
    altermanager.cpp \
    altertype.cpp \
    configui.cpp \
    dbmanager.cpp \
    iomanager.cpp \
    loginui.cpp \
    mainmenu.cpp \
    examctrl.cpp \
    inoutput.cpp \
    membermanage.cpp \
    papermanage.cpp \
    questionsmanage.cpp \
    scoremanage.cpp \
    submark.cpp


HEADERS  += mainwindow.h \
    mainapp.h \
    data.h \
    server.h\
    alterstudent.h \
    alterteacher.h \
    altermanager.h \
    altertype.h \
    dbmanager.h \
    iomanager.h \
    mainmenu.h \
    login.h \
    config.h \
    examctrl.h \
    inoutput.h \
    membermanage.h \
    papermanage.h \
    questionsmanage.h \
    scoremanage.h \
    submark.h


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
    ScoreManageUI.ui \
    alterstudent.ui \
    alterteacher.ui \
    altermanager.ui \
    altertype.ui

RESOURCES += \
    res.qrc

OTHER_FILES += \
    icon.rc
RC_FILE += \
    icon.rc






