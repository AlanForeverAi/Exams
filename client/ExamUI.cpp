#include "ExamUI.h"
//#include <QColorGroup>

ExamUI::ExamUI(QWidget *parent) :QWidget(parent)
{
    setupUi(this);

    radionGroup.addButton(radio_A);
    radionGroup.addButton(radio_B);
    radionGroup.addButton(radio_C);
    radionGroup.addButton(radio_D);
    radionGroup.setExclusive(false);
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));
    this->showFullScreen();


}

ExamUI::~ExamUI()
{

}

void ExamUI::showPaper(Paper paper)
{
    currentPaper=paper;
    obanslist.resize(currentPaper.obList.count());
    subanslist.resize(currentPaper.subList.count());
    obanslist.fill("");
    subanslist.fill("");
    totalque=currentPaper.obList.count()+currentPaper.subList.count();
    label_totalque->setText(QString("共%1题").arg(totalque));

    currentQue=0;

    examTime.setHMS(currentPaper.getTime()/3600,currentPaper.getTime()%3600/60,currentPaper.getTime()%3600%60);
    timeEdit->setTime(examTime);

    this->iniQueInfo();
    this->showQuestion(currentQue);
    this->showQueInfo(0);
}

void ExamUI::on_Button_prev_clicked()
{
    if(currentQue>0)
    {
        this->showQueInfo(0);
        currentQue--;
        this->showQuestion(currentQue);

    }

}

void ExamUI::on_Button_next_clicked()
{
    if(currentQue+1<totalque)
    {

        this->showQueInfo(0);
        yiditijiao();
        currentQue++;

        this->showQuestion(currentQue);

    }

}

void ExamUI::yiditijiao()
{
    if(currentQue<currentPaper.obList.count())
    {
        QString answer;
        if(radio_A->isChecked()) answer.append("A-");
        if(radio_B->isChecked()) answer.append("B-");
        if(radio_C->isChecked()) answer.append("C-");
        if(radio_D->isChecked()) answer.append("D-");
        obanslist.replace(currentQue,answer);

    }
    else
    {
        subanslist.replace(currentQue-obanslist.size(),textEdit_subans->toPlainText());
    }
    SubAnswers subanswers;
    subanswers.setPaperId(currentPaper.getPaperId());
    subanswers.setSubansList(subanslist);


    ObAnswers obanswers;
    obanswers.setPaperId(currentPaper.getPaperId());
    QString ans_string;
    for(int i=0; i<obanslist.size(); i++)
    {
        ans_string.append(obanslist.at(i));
        ans_string.append(",");
    }
    obanswers.setAnswers(ans_string);

    AllAnswers allanswers;
    allanswers.setPaperId(currentPaper.getPaperId());
    allanswers.setObAnswer(obanswers);
    allanswers.setSubAnswer(subanswers);
    emit this->sendAnswersingle(allanswers);
}

void ExamUI::on_pushButton_jump_clicked()
{
    int id=lineEdit_jump->text().toInt()-1;
    if(id<totalque&&id>=0)
    {
        currentQue=id;
        this->showQuestion(id);
    }
}

void ExamUI::showQuestion(int queNO)
{
    if(btngroup->button(queNO)->text().contains("*"))
    {
        this->Button_mark->setText(QString("取消标记"));
    }
    else
    {
        this->Button_mark->setText(QString("标记该题"));
    }
    currentQue=queNO;
    label_queNO->setText(QString("第%1题").arg(queNO+1));

    if(queNO<currentPaper.obList.count())
    {
        this->resetRadioGroup();
        stackedWidget->setCurrentIndex(0);

        ObQuestions obque=currentPaper.obList.at(queNO);

        QString title=obque.getTitle();
        QString s_maintitle=title.mid(0,title.indexOf("@a"));
        QString s_ansA=title.mid(title.indexOf("@a")+2,title.indexOf("@b")-title.indexOf("@a")-2);
        QString s_ansB=title.mid(title.indexOf("@b")+2,title.indexOf("@c")-title.indexOf("@b")-2);
        QString s_ansC=title.mid(title.indexOf("@c")+2,title.indexOf("@d")-title.indexOf("@c")-2);
        QString s_ansD=title.mid(title.indexOf("@d")+2,title.length()-title.indexOf("@d")-2);

        textEdit_obtitle->setText(s_maintitle);
        label_A->setText(s_ansA);
        label_B->setText(s_ansB);
        label_C->setText(s_ansC);
        label_D->setText(s_ansD);

        if(!obanslist.at(queNO).isEmpty())
        {

            QStringList list=obanslist.at(queNO).split("-");
            for(int i=0; i<list.count(); i++)
            {

                if(list.at(i)=="A") radio_A->setChecked(true);
                if(list.at(i)=="B") radio_B->setChecked(true);
                if(list.at(i)=="C") radio_C->setChecked(true);
                if(list.at(i)=="D") radio_D->setChecked(true);
            }

        }

    }
    else if(queNO>=currentPaper.obList.count()&&queNO<totalque)
    {
        textEdit_subans->clear();
        stackedWidget->setCurrentIndex(1);
        SubQuestions subque=currentPaper.subList.at(queNO-obanslist.size());
        textEdit_subtitle->setText(subque.getTitle());
        if(!subanslist.at(queNO-obanslist.size()).isEmpty())
        {
            textEdit_subans->setText(subanslist.at(queNO-obanslist.size()));
        }
    }

    if(queNO>0&&queNO+1<totalque)
        Button_prev->setEnabled(true);
    Button_next->setEnabled(true);
    if(queNO==0)
        Button_prev->setEnabled(false);
    if(queNO+1==totalque)
        Button_next->setEnabled(false);

}

void ExamUI::resetRadioGroup()
{
//    radionGroup.setExclusive(false);
//    for(int i=0;i<radionGroup.buttons().count();i++)
//    {
//        radionGroup.buttons().at(i)->setChecked(false);
//    }
//    radionGroup.setExclusive(true);
    radio_A->setChecked(false);
    radio_B->setChecked(false);
    radio_C->setChecked(false);
    radio_D->setChecked(false);

}
void ExamUI::showQueInfo(int )
{

    if(currentQue<currentPaper.obList.count())
    {
//           if(radionGroup.checkedButton())
//                obanslist.replace(currentQue,radionGroup.checkedButton()->text());
        QString answer;
        if(radio_A->isChecked()) answer.append("A-");
        if(radio_B->isChecked()) answer.append("B-");
        if(radio_C->isChecked()) answer.append("C-");
        if(radio_D->isChecked()) answer.append("D-");
        obanslist.replace(currentQue,answer);

    }
    else
    {
        subanslist.replace(currentQue-obanslist.size(),textEdit_subans->toPlainText());
    }


    for(int i=0; i<btngroup->buttons().count(); i++)
    {
        if(i<obanslist.count())
        {

            QPalette pal=btngroup->button(i)->palette();
            if(obanslist.at(i).isEmpty())
            {
                pal.setColor(QPalette::ButtonText,QColor("red"));
                btngroup->button(i)->setPalette(pal);
                //btngroup->button(i)->setText(QString("%1").arg(i+1));

            }
            else
            {
                pal.setColor(QPalette::ButtonText,QColor("green"));
                btngroup->button(i)->setPalette(pal);
                //btngroup->button(i)->setText(QString("%1").arg(i+1));
            }
        }

        if(i>=obanslist.count()&&(i-obanslist.count())<subanslist.count())
        {
            QPalette pal=btngroup->button(i)->palette();
            if(subanslist.at(i-obanslist.count()).isEmpty())
            {
                pal.setColor(QPalette::ButtonText,QColor("red"));
                btngroup->button(i)->setPalette(pal);
                // btngroup->button(i)->setText(QString("%1").arg(i+1));
            }
            else
            {
                pal.setColor(QPalette::ButtonText,QColor("green"));
                btngroup->button(i)->setPalette(pal);
                //btngroup->button(i)->setText(QString("%1").arg(i+1));
            }
        }
    }
}
void ExamUI::on_Button_mark_clicked()
{
    if(btngroup->button(currentQue)->text().contains("*"))
    {
        this->Button_mark->setText(QString("标记该题"));
        btngroup->button(currentQue)->setText(QString("%1").arg(currentQue+1));
    }
    else
    {
        this->Button_mark->setText(QString("取消标记"));
        btngroup->button(currentQue)->setText(QString("*%1").arg(currentQue+1));
    }
}

void ExamUI::iniQueInfo()
{

    //QWidget *queInfo=new QWidget;
    btngroup=new QButtonGroup;
    QGridLayout *mainlayout=new QGridLayout(widget_info);
    widget_info->setLayout(mainlayout);
    for(int i=0; i<totalque; i++)
    {
        QPushButton *btn=new QPushButton;
        btn->setText(QString("%1").arg(i+1));

        btn->setMaximumSize(30,30);
        btngroup->addButton(btn,i);

        mainlayout->addWidget(btn,i/3,i%3);
    }
    connect(btngroup,SIGNAL(buttonClicked(int)),this,SLOT(showQueInfo(int)));
    connect(btngroup,SIGNAL(buttonClicked(int)),this,SLOT(showQuestion(int)));


}

void ExamUI::on_pushButton_submit_clicked()
{


    QMessageBox msg;
    msg.setText(QString("确定要提交吗？"));
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    int ret=msg.exec();
    if(ret==QMessageBox::Ok)
    {
        this->submitAnswers();
    }
    else
        return;

}

void ExamUI::submitAnswers()
{
    if(currentQue<currentPaper.obList.count())
    {
        QString answer;
        if(radio_A->isChecked()) answer.append("A-");
        if(radio_B->isChecked()) answer.append("B-");
        if(radio_C->isChecked()) answer.append("C-");
        if(radio_D->isChecked()) answer.append("D-");
        obanslist.replace(currentQue,answer);

    }
    else
    {
        subanslist.replace(currentQue-obanslist.size(),textEdit_subans->toPlainText());
    }

    SubAnswers subanswers;
    subanswers.setPaperId(currentPaper.getPaperId());
    subanswers.setSubansList(subanslist);


    ObAnswers obanswers;
    obanswers.setPaperId(currentPaper.getPaperId());
    QString ans_string;
    for(int i=0; i<obanslist.size(); i++)
    {
        ans_string.append(obanslist.at(i));
        ans_string.append(",");
    }
    obanswers.setAnswers(ans_string);

    AllAnswers allanswers;
    allanswers.setPaperId(currentPaper.getPaperId());
    allanswers.setObAnswer(obanswers);
    allanswers.setSubAnswer(subanswers);
    emit this->sendAnswers(allanswers);

    timer->stop();



}

void ExamUI::timeUpdate()
{

    examTime=examTime.addSecs(-1);
    timeEdit->setTime(examTime);

    if(examTime.secsTo(QTime(0,0,0))==0)
    {
        this->submitAnswers();
        timer->stop();
        QMessageBox::about(this,"msg",QString("考试时间已到，你的答案已自动提交！"));
    }

}
