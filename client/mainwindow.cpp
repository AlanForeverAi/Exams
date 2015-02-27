#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);

    _mainFrame = new MainFrameUI;
    connect(_mainFrame,SIGNAL(sendAnswers(AllAnswers)),this,SIGNAL(sendAnswers(AllAnswers)));
    connect(this,SIGNAL(endExam()),_mainFrame,SIGNAL(endExam()));
    connect(this,SIGNAL(showUserInfo(Student)),_mainFrame,SLOT(showUserInfo(Student)));
    connect(this,SIGNAL(paperReady(Paper)),_mainFrame,SLOT(paperReady(Paper)));
    connect(this,SIGNAL(showPaper()),_mainFrame,SLOT(showPaper()));
    connect(this,SIGNAL(showMessage(QString)),_mainFrame,SLOT(showMessage(QString)));
    connect(this, SIGNAL(pauseExam()), _mainFrame, SLOT(pauseExam()));
    connect(this, SIGNAL(continueExam()), _mainFrame, SLOT(continueExam()));
    connect(_mainFrame,SIGNAL(sendAnswersSingle(AllAnswers)),this,SIGNAL(sendAnswersSingle(AllAnswers)));

    _loginPage = new LoginUI;
    connect(_loginPage,SIGNAL(loginSignal(Student)),this,SIGNAL(loginSignal(Student)));

    this->do_login();
    statusbar = statusBar();
    statusbar->showMessage(QStringLiteral("hello"));
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::do_login()
{
    this->setCentralWidget(_loginPage);
}

void MainWindow::do_mainframe()
{

    this->setCentralWidget(_mainFrame);
}

void MainWindow::LoginOK()
{
    this->do_mainframe();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox msg;
    msg.setText(QStringLiteral("确定要退出吗？"));
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    int ret = msg.exec();
    if(ret == QMessageBox::Ok)
        event->accept();
    else
        event->ignore();
}

void MainWindow::updateInfo(QString info)
{
    QStringList list;
    list = info.split(",");
    if(info.length() <= 2)
    {
        return;
    }
    this->setWindowTitle(list.at(1));
    this->_loginPage->label_welcome->setText(list.at(2));
    this->_mainFrame->label_NO->setText(list.at(3));
    this->_mainFrame->label_pici->setText(list.at(4));
    this->_mainFrame->label_message->setText(list.at(5));
}
