#-------------------------------------------------
#
# Project created by QtCreator 2014-03-19T09:48:19
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       +=network
QT       +=widgets
TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mainapp.cpp \
    data.cpp \
    client.cpp \
    ExamUI.cpp \
    LoginUI.cpp \
    MainFrameUI.cpp

HEADERS  += mainwindow.h \
    mainapp.h \
    data.h \
    client.h \
    ExamUI.h \
    LoginUI.h \
    MainFrameUI.h

FORMS    += mainwindow.ui \
    ExamUI.ui \
    LoginUI.ui \
    MainFrameUI.ui

OTHER_FILES += \
    icon.rc
RC_FILE += \
    icon.rc

RESOURCES += \
    res.qrc
