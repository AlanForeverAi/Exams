#include "ExamUI.h"

ExamUI::ExamUI(QWidget *parent) :QWidget(parent)
{
    setupUi(this);

    _radionGroup.addButton(radio_A);
    _radionGroup.addButton(radio_B);
    _radionGroup.addButton(radio_C);
    _radionGroup.addButton(radio_D);
    _radionGroup.setExclusive(false);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timeUpdate()));
    this->showFullScreen();
}

ExamUI::~ExamUI()
{

}

void ExamUI::showPaper(Paper paper)
{
    _currentPaper = paper;
    _obansList.resize(_currentPaper.obList.count());
    _subansList.resize(_currentPaper.subList.count());
    _obansList.fill("");
    _subansList.fill("");
    _totalque = _currentPaper.obList.count() + _currentPaper.subList.count();
    label_totalque->setText(QStringLiteral("共%1题").arg(_totalque));

    _currentQue = 0;

    _examTime.setHMS(_currentPaper.getTime() / 3600,_currentPaper.getTime() % 3600 / 60,_currentPaper.getTime() % 3600 % 60);
    timeEdit->setTime(_examTime);

    this->iniQueInfo();
    this->showQuestion(_currentQue);
    this->showQueInfo(0);
}

void ExamUI::on_Button_prev_clicked()
{
    if(_currentQue > 0)
    {
        this->showQueInfo(0);
        _currentQue--;
        this->showQuestion(_currentQue);

    }

}

void ExamUI::on_Button_next_clicked()
{
    if(_currentQue + 1 < _totalque)
    {

        this->showQueInfo(0);
        remoteSubmit();
        _currentQue++;

        this->showQuestion(_currentQue);

    }

}

void ExamUI::remoteSubmit()
{
    if(_currentQue < _currentPaper.obList.count())
    {
        QString answer;
        if(radio_A->isChecked()) answer.append("A-");
        if(radio_B->isChecked()) answer.append("B-");
        if(radio_C->isChecked()) answer.append("C-");
        if(radio_D->isChecked()) answer.append("D-");
        _obansList.replace(_currentQue,answer);

    }
    else
    {
        _subansList.replace(_currentQue-_obansList.size(),textEdit_subans->toPlainText());
    }
    ChoiceAnswers subanswers;
    subanswers.setPaperId(_currentPaper.getPaperId());
    subanswers.setAnswerList(_subansList);
    subanswers.setStudentId(Student::GetInstance().getID());


    EssayAnswers obanswers;
    obanswers.setPaperId(_currentPaper.getPaperId());
    QString ans_string;
    for(int i = 0; i < _obansList.size(); i++)
    {
        ans_string.append(_obansList.at(i));
        ans_string.append(",");
    }
    obanswers.setAnswers(ans_string);
    obanswers.setStudentId(Student::GetInstance().getID());

    AllAnswers allanswers;
    allanswers.setPaperId(_currentPaper.getPaperId());
    allanswers.setObanswer(obanswers);
    allanswers.setSubanswer(subanswers);
    emit this->sendAnswersingle(allanswers);
}

void ExamUI::on_pushButton_jump_clicked()
{
    int id = lineEdit_jump->text().toInt() - 1;
    if(id < _totalque && id >=  0)
    {
        _currentQue = id;
        this->showQuestion(id);
    }
}

//显示题目！！！！
void ExamUI::showQuestion(int questionNumber)
{
    if(_btnGroup->button(questionNumber)->text().contains("*"))
    {
        this->Button_mark->setText(QStringLiteral("取消标记"));
    }
    else
    {
        this->Button_mark->setText(QStringLiteral("标记该题"));
    }
    _currentQue = questionNumber;
    label_queNO->setText(QStringLiteral("第%1题").arg(questionNumber+1));

    if(questionNumber < _currentPaper.obList.count())
    {
        this->resetRadioGroup();
        stackedWidget->setCurrentIndex(0);

        ChoiceQuestions choiceQuestion = _currentPaper.obList.at(questionNumber);

        QString title = choiceQuestion.getQuestionTitle();
        QString s_maintitle = title.mid(0,title.indexOf("@a"));
        QString s_ansA = title.mid(title.indexOf("@a")+2,title.indexOf("@b")-title.indexOf("@a")-2);
        QString s_ansB = title.mid(title.indexOf("@b")+2,title.indexOf("@c")-title.indexOf("@b")-2);
        QString s_ansC = title.mid(title.indexOf("@c")+2,title.indexOf("@d")-title.indexOf("@c")-2);
        QString s_ansD = title.mid(title.indexOf("@d")+2,title.length()-title.indexOf("@d")-2);

        textEdit_obtitle->setText(s_maintitle);
        label_A->setText(s_ansA);
        label_B->setText(s_ansB);
        label_C->setText(s_ansC);
        label_D->setText(s_ansD);

        if(!_obansList.at(questionNumber).isEmpty())
        {

            QStringList list = _obansList.at(questionNumber).split("-");
            for(int i = 0; i < list.count(); i++)
            {

                if(list.at(i) ==  "A") radio_A->setChecked(true);
                if(list.at(i) ==  "B") radio_B->setChecked(true);
                if(list.at(i) ==  "C") radio_C->setChecked(true);
                if(list.at(i) ==  "D") radio_D->setChecked(true);
            }

        }

    }
    else if(questionNumber >=  _currentPaper.obList.count()&&questionNumber<_totalque)
    {
        textEdit_subans->clear();
        stackedWidget->setCurrentIndex(1);
        EssayQuestions essayQuestions = _currentPaper.subList.at(questionNumber-_obansList.size());
        textEdit_subtitle->setText(essayQuestions.getQuestionTitle());
        if(!_subansList.at(questionNumber-_obansList.size()).isEmpty())
        {
            textEdit_subans->setText(_subansList.at(questionNumber-_obansList.size()));
        }
    }

    if(questionNumber > 0 && questionNumber + 1 < _totalque)
        Button_prev->setEnabled(true);
    Button_next->setEnabled(true);
    if(questionNumber ==  0)
        Button_prev->setEnabled(false);
    if(questionNumber + 1 ==  _totalque)
        Button_next->setEnabled(false);

}

void ExamUI::resetRadioGroup()
{
    radio_A->setChecked(false);
    radio_B->setChecked(false);
    radio_C->setChecked(false);
    radio_D->setChecked(false);

}
void ExamUI::showQueInfo(int )
{

    if(_currentQue < _currentPaper.obList.count())
    {
        QString answer;
        if(radio_A->isChecked()) answer.append("A-");
        if(radio_B->isChecked()) answer.append("B-");
        if(radio_C->isChecked()) answer.append("C-");
        if(radio_D->isChecked()) answer.append("D-");
        _obansList.replace(_currentQue,answer);

    }
    else
    {
        _subansList.replace(_currentQue-_obansList.size(),textEdit_subans->toPlainText());
    }


    for(int i = 0; i < _btnGroup->buttons().count(); i++)
    {
        if(i < _obansList.count())
        {

            QPalette pal = _btnGroup->button(i)->palette();
            if(_obansList.at(i).isEmpty())
            {
                pal.setColor(QPalette::ButtonText,QColor("red"));
                _btnGroup->button(i)->setPalette(pal);
            }
            else
            {
                pal.setColor(QPalette::ButtonText,QColor("green"));
                _btnGroup->button(i)->setPalette(pal);
            }
        }

        if(i >= _obansList.count() && (i - _obansList.count()) < _subansList.count())
        {
            QPalette pal = _btnGroup->button(i)->palette();
            if(_subansList.at(i-_obansList.count()).isEmpty())
            {
                pal.setColor(QPalette::ButtonText,QColor("red"));
                _btnGroup->button(i)->setPalette(pal);
            }
            else
            {
                pal.setColor(QPalette::ButtonText,QColor("green"));
                _btnGroup->button(i)->setPalette(pal);
            }
        }
    }
}
void ExamUI::on_Button_mark_clicked()
{
    if(_btnGroup->button(_currentQue)->text().contains("*"))
    {
        this->Button_mark->setText(QStringLiteral("标记该题"));
        _btnGroup->button(_currentQue)->setText(QStringLiteral("%1").arg(_currentQue+1));
    }
    else
    {
        this->Button_mark->setText(QStringLiteral("取消标记"));
        _btnGroup->button(_currentQue)->setText(QStringLiteral("*%1").arg(_currentQue+1));
    }
}

void ExamUI::iniQueInfo()
{
    _btnGroup = new QButtonGroup;
    QGridLayout *mainlayout = new QGridLayout(widget_info);
    widget_info->setLayout(mainlayout);
    for(int i = 0; i < _totalque; i++)
    {
        QPushButton *btn = new QPushButton;
        btn->setText(QStringLiteral("%1").arg(i+1));

        btn->setMaximumSize(30,30);
        _btnGroup->addButton(btn,i);

        mainlayout->addWidget(btn,i/3,i%3);
    }
    connect(_btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(showQueInfo(int)));
    connect(_btnGroup,SIGNAL(buttonClicked(int)),this,SLOT(showQuestion(int)));


}

void ExamUI::on_pushButton_submit_clicked()
{


    QMessageBox msg;
    msg.setText(QStringLiteral("确定要提交吗？"));
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    int ret = msg.exec();
    if(ret == QMessageBox::Ok)
    {
        this->submitAnswers();
    }
    else
        return;

}

void ExamUI::submitAnswers()
{
    if(_currentQue < _currentPaper.obList.count())
    {
        QString answer;
        if(radio_A->isChecked()) answer.append("A-");
        if(radio_B->isChecked()) answer.append("B-");
        if(radio_C->isChecked()) answer.append("C-");
        if(radio_D->isChecked()) answer.append("D-");
        _obansList.replace(_currentQue,answer);

    }
    else
    {
        _subansList.replace(_currentQue-_obansList.size(),textEdit_subans->toPlainText());
    }

    ChoiceAnswers subanswers;
    subanswers.setPaperId(_currentPaper.getPaperId());
    subanswers.setAnswerList(_subansList);
    subanswers.setStudentId(Student::GetInstance().getID());

    EssayAnswers obanswers;
    obanswers.setPaperId(_currentPaper.getPaperId());
    QString ans_string;
    for(int i = 0; i < _obansList.size(); i++)
    {
        ans_string.append(_obansList.at(i));
        ans_string.append(",");
    }
    obanswers.setAnswers(ans_string);
    obanswers.setStudentId(Student::GetInstance().getID());

    AllAnswers allanswers;
    allanswers.setPaperId(_currentPaper.getPaperId());
    allanswers.setObanswer(obanswers);
    allanswers.setSubanswer(subanswers);
    emit this->sendAnswers(allanswers);

    timer->stop();
}

void ExamUI::timeUpdate()
{

    _examTime = _examTime.addSecs(-1);
    timeEdit->setTime(_examTime);

    if(_examTime.secsTo(QTime(0,0,0)) ==  0)
    {
        this->submitAnswers();
        timer->stop();
        QMessageBox::about(this,"msg",QStringLiteral("考试时间已到，你的答案已自动提交！"));
    }

}
