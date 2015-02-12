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
        txt = QString("%1 Debug: %2").arg(QTime::currentTime().toString("hh:mm:ss")).arg(msg);
        break;
    case QtWarningMsg:
        txt = QString("%1 Warning: %2").arg(QTime::currentTime().toString("hh:mm:ss")).arg(msg);
        break;
    case QtFatalMsg:
        txt = QString("%1 Fatal: %2").arg(QTime::currentTime().toString("hh:mm:ss")).arg(msg);
        abort();
    }
    QTextStream ts(&outFile);
    ts << txt << endl;
}

int main(int argc, char *argv[])
{
    outFile.setFileName(QString("%1.log").arg(QDate::currentDate().toString("dd_MM_yyyy")));
    outFile.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));
    QApplication a(argc, argv);
    qInstallMessageHandler(customMessageHandler);
    QString strLibPath(QDir::toNativeSeparators(QApplication::applicationDirPath()) + QDir::separator() + "plugins");
    a.addLibraryPath(strLibPath);
    MainApp app;

    return a.exec();
}
