#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    m=new MainFrameUI;
    connect(m,SIGNAL(sendAnswers(AllAnswers)),this,SIGNAL(sendAnswers(AllAnswers)));
    connect(this,SIGNAL(endExam()),m,SIGNAL(endExam()));
    connect(this,SIGNAL(showUserInfo(Student)),m,SLOT(showUserInfo(Student)));
    connect(this,SIGNAL(paperReady(Paper)),m,SLOT(paperReady(Paper)));
    connect(this,SIGNAL(showPaper()),m,SLOT(showPaper()));
    connect(this,SIGNAL(showMessage(QString)),m,SLOT(showMessage(QString)));
    connect(m,SIGNAL(sendAnswersSingle(AllAnswers)),this,SIGNAL(sendAnswersSingle(AllAnswers)));


    loginPage=new LoginUI;
    connect(loginPage,SIGNAL(loginSignal(Student)),this,SIGNAL(loginSignal(Student)));

    this->do_login();
    statusbar=statusBar();
    statusbar->showMessage(QString("hello"));
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::do_login()
{
    this->setCentralWidget(loginPage);
}

void MainWindow::do_mainframe()
{

    this->setCentralWidget(m);
}

void MainWindow::LoginOK()
{
    this->do_mainframe();


}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox msg;
    msg.setText(QString("确定要退出吗？"));
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    int ret=msg.exec();
    if(ret==QMessageBox::Ok)
        event->accept();
    else
        event->ignore();
}

void MainWindow::updateInfo(QString info)
{
    //QMessageBox::about(this,"msg",info);
    QStringList list;
    list=info.split(",");
    if(info.length()<=2)
    {
        return;
    }
    this->setWindowTitle(list.at(1));
    this->loginPage->label_welcome->setText(list.at(2));
    this->m->label_NO->setText(list.at(3));
    this->m->label_pici->setText(list.at(4));
    this->m->label_message->setText(list.at(5));
//    this->m->label_message->adjustSize();
//    this->m->label_message->setGeometry();
//    this->m->label_message->setWordWrap(true);
//    this->m->label_message->setAlignment(Qt::AlignTop);
}
