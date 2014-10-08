#include <QApplication>
#include "mainapp.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    //QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QApplication a(argc, argv);
    MainApp app;

    return a.exec();
}
