#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T09:48:19
#
#-------------------------------------------------

QT       += core gui
QT        += sql
QT        += network
QT        += widgets
QT  += axcontainer
TARGET = Examsys
TEMPLATE = app

CONFIG+=precompile_header
PRECOMPILED_HEADER = stable.h

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
    inoutput.cpp \
    membermanage.cpp \
    papermanage.cpp \
    questionsmanage.cpp \
    scoremanage.cpp \
    submark.cpp \
    alterchoicequestion.cpp \
    alteressayquestion.cpp \
    addquestion.cpp \
    addinformation.cpp \
    sendmessage.cpp \
    alterpaper.cpp \
    setmark.cpp \
    papersetting.cpp \
    addstudent.cpp \
    examsetting.cpp \
    examcontrol.cpp \
    excelengine.cpp \
    menu.cpp


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
    inoutput.h \
    membermanage.h \
    papermanage.h \
    questionsmanage.h \
    scoremanage.h \
    submark.h \
    alterchoicequestion.h \
    alteressayquestion.h \
    addquestion.h \
    addinformation.h \
    sendmessage.h \
    alterpaper.h \
    setmark.h \
    papersetting.h \
    addstudent.h \
    examsetting.h \
    examcontrol.h \
    excelengine.h \
    menu.h \
    stable.h


FORMS    += mainwindow.ui \
    alterstudent.ui \
    alterteacher.ui \
    altermanager.ui \
    altertype.ui \
    showchoicequestion.ui \
    showessayquestion.ui \
    addquestion.ui \
    addinformation.ui \
    sendmessage.ui \
    alterpaper.ui \
    setmark.ui \
    papersetting.ui \
    addstudent.ui \
    examsetting.ui \
    config.ui \
    inoutput.ui \
    login.ui \
    mainmenu.ui \
    membermanage.ui \
    papermanage.ui \
    questionsmanage.ui \
    scoremanage.ui \
    submark.ui \
    examcontrol.ui \
    menu.ui

RESOURCES += \
    res.qrc

OTHER_FILES += \
    icon.rc
RC_FILE += \
    icon.rc






