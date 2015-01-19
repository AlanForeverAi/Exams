#include <QApplication>
#include "mainapp.h"
#include <QTextCodec>
#include <QDateTime>
#include <QTime>
#include <QtGlobal>

static QFile outFile;

void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg){
    QString txt;
    switch (type) {
    case QtDebugMsg:
        txt = QString("Debug: %1").arg(msg);
        break;
    case QtWarningMsg:
        txt = QString("Warning: %1").arg(msg);
        break;
    case QtFatalMsg:
        txt = QString("Fatal: %1").arg(msg);
        abort();
    }
    QTextStream ts(&outFile);
    ts << txt << endl;
}

int main(int argc, char *argv[])
{
    outFile.setFileName(QString("%1.log").arg(QTime::currentTime().toString("hh_mm")));
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QApplication a(argc, argv);
    qInstallMessageHandler(customMessageHandler);
    QString strLibPath(QDir::toNativeSeparators(QApplication::applicationDirPath()) + QDir::separator() + "plugins");
    a.addLibraryPath(strLibPath);
    MainApp app;

    return a.exec();
}
