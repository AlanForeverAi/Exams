#include <QApplication>
#include "mainapp.h"
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QApplication a(argc, argv);
    QString strLibPath(QDir::toNativeSeparators(QApplication::applicationDirPath())+QDir::separator()+"plugins");
    a.addLibraryPath(strLibPath);
    MainApp app;

    return a.exec();
}
