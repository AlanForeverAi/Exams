#include "startexam.h"


startexam::startexam(QWidget *parent) :QWidget(parent)
{
    setupUi(this);

    radionGroup.addButton(radio_A);
    radionGroup.addButton(radio_B);
    radionGroup.addButton(radio_C);
    radionGroup.addButton(radio_D);

    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));



}

startexam::~startexam()
{

}

void startexam::showPaper(Paper paper)
{
    currentPaper=paper;
    obanslist.resize(currentPaper.obList.count());
    subanslist.resize(currentPaper.subList.count());
    obanslist.fill("");
    subanslist.fill("");
    totalque=currentPaper.obList.count()+currentPaper.subList.count();
    label_totalque->setText(tr("共%1题").arg(totalque));

    currentQue=0;

    examTime.setHMS(currentPaper.getTime()/3600,currentPaper.getTime()%3600/60,currentPaper.getTime()%3600%60);
    timeEdit->setTime(examTime);

    this->showQuestion(currentQue);
}

void startexam::on_Button_prev_clicked()
{
    if(currentQue>0)
    {
        if(currentQue<currentPaper.obList.count())
        {
            if(radionGroup.checkedButton())
                obanslist.replace(currentQue,radionGroup.checkedButton()->text());

        }
        else
        {
            subanslist.replace(currentQue-obanslist.size(),textEdit_subans->toPlainText());
        }
        currentQue--;
        this->showQuestion(currentQue);
    }

}

void startexam::on_Button_next_clicked()
{
    if(currentQue+1<totalque)
    {
        if(currentQue<currentPaper.obList.count())
        {
           if(radionGroup.checkedButton())
                obanslist.replace(currentQue,radionGroup.checkedButton()->text());

        }
        else
        {
            subanslist.replace(currentQue-obanslist.size(),textEdit_subans->toPlainText());
        }

        currentQue++;
        this->showQuestion(currentQue);
    }

}

void startexam::on_pushButton_jump_clicked()
{
    int id=lineEdit_jump->text().toInt()-1;
    if(id<totalque&&id>=0)
        {
            currentQue=id;
            this->showQuestion(id);
        }
}

void startexam::showQuestion(int queNO)
{
    label_queNO->setText(tr("第%1题").arg(queNO+1));

    if(queNO<currentPaper.obList.count())
    {
         this->resetRadioGroup();
        stackedWidget->setCurrentIndex(0);

        Ob_questions obque=currentPaper.obList.at(queNO);

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
            if(obanslist.at(queNO)=="A") radio_A->setChecked(true);
            if(obanslist.at(queNO)=="B") radio_B->setChecked(true);
            if(obanslist.at(queNO)=="C") radio_C->setChecked(true);
            if(obanslist.at(queNO)=="D") radio_D->setChecked(true);

        }

    }
    else
        if(queNO>=currentPaper.obList.count()&&queNO<totalque)
        {
            textEdit_subans->clear();
            stackedWidget->setCurrentIndex(1);
            Sub_questions subque=currentPaper.subList.at(queNO-obanslist.size());
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

void startexam::resetRadioGroup()
{
    radionGroup.setExclusive(false);
    for(int i=0;i<radionGroup.buttons().count();i++)
    {
        radionGroup.buttons().at(i)->setChecked(false);
    }
    radionGroup.setExclusive(true);

}

void startexam::on_Button_findUndo_clicked()
{
    if(currentQue<currentPaper.obList.count())
    {
        if(radionGroup.checkedButton())
            obanslist.replace(currentQue,radionGroup.checkedButton()->text());

    }
    else
    {
        subanslist.replace(currentQue-obanslist.size(),textEdit_subans->toPlainText());
    }

    for(int i=0;i<obanslist.size();i++)
    {
        if(obanslist.at(i).isEmpty())
           {
               currentQue=i;
            this->showQuestion(currentQue);
           }
    }
    for(int i=0;i<subanslist.size();i++)
    {
        if(subanslist.at(i).isEmpty())
           {
               currentQue=i+obanslist.size();
            this->showQuestion(currentQue);
           }
    }
}

void startexam::on_pushButton_submit_clicked()
{


    QMessageBox msg;
    msg.setText(tr("确定要提交吗？"));
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    int ret=msg.exec();
    if(ret==QMessageBox::Ok)
    {
        this->submitAnswers();
    }
    else
        return;

}

void startexam::submitAnswers()
{
    if(currentQue<currentPaper.obList.count())
    {
        if(radionGroup.checkedButton())
            obanslist.replace(currentQue,radionGroup.checkedButton()->text());

    }
    else
    {
        subanslist.replace(currentQue-obanslist.size(),textEdit_subans->toPlainText());
    }

    Sub_answers subanswers;
    subanswers.setPaper_id(currentPaper.getPaper_id());
    subanswers.setSubanslist(subanslist);


    Ob_answers obanswers;
    obanswers.setPaper_id(currentPaper.getPaper_id());
    QString ans_string;
    for(int i=0;i<obanslist.size();i++)
    {
        ans_string.append(obanslist.at(i));
        ans_string.append(",");
    }
    obanswers.setAnswers(ans_string);

    All_answers allanswers;
    allanswers.setPaperid(currentPaper.getPaper_id());
    allanswers.setObanswer(obanswers);
    allanswers.setSubanswer(subanswers);
    emit this->sendAnswers(allanswers);

    timer->stop();



}

void startexam::timeUpdate()
{

    examTime=examTime.addSecs(-1);
    timeEdit->setTime(examTime);

    if(examTime.secsTo(QTime(0,0,0))==0)
    {
        this->submitAnswers();
        timer->stop();
        QMessageBox::about(this,"msg",tr("考试时间已到，你的答案已自动提交！"));
    }

}
