#include <QApplication>
#include "mainapp.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainApp app;

    return a.exec();
}
