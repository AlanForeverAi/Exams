#include"mainapp.h"
#include <QMessageBox>
#include <QDebug>
MainApp::MainApp()
{
    readConfig();
    iniMainWindow();
    iniDBManager();
    iniServer();
    _IOM=new IOManager;

    _serverState=STATE_NOEXAM;
    //在信息字符串前预留一位用来填写考试状态
    _infoList.append("*,");
}

MainApp::~MainApp()
{
    delete(_DBM);
    delete(_server);
    delete(_IOM);
}

void MainApp::readConfig()
{
    QFile Config("./config.ini");
    if(!Config.open(QIODevice::ReadOnly|QIODevice::Text))
        return;
    QTextStream in(&Config);
    QString temp;
    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    _dbName=temp;
    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    _dbUser=temp;
    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    _dbPassword=temp;
    temp=in.readLine();
    temp=temp.mid(temp.indexOf(" ")+1);
    _port=temp.toInt();
    Config.close();
}

void MainApp::iniDBManager()
{
    _DBM=new DBManager(_dbName,_dbUser,_dbPassword);
}

void MainApp::iniServer()
{
    _server=new Server(this,_port);
    connect(this,SIGNAL(sendData(int,qint32,QVariant)),_server,SIGNAL(sendData(int,qint32,QVariant)));
    connect(_server,SIGNAL(messageArrive(int,qint32,QVariant)),this,SLOT(messageArrive(int,qint32,QVariant)),Qt::QueuedConnection);
    connect(_server,SIGNAL(removeUser(int)),this,SLOT(removeUser(int)));
}

void MainApp::iniMainWindow()
{
    //与题库管理界面连接的信号和槽
    connect(&_window,SIGNAL(getQuestions()),this,SLOT(getQuestions()));
    connect(this,SIGNAL(showQuestions(QList<ObQuestions*>,QList<SubQuestions*>)),&_window,SIGNAL(showQuestions(QList<ObQuestions*>,QList<SubQuestions*>)));
    connect(&_window,SIGNAL(addOb_Questoins(ObQuestions*)),this,SLOT(addOb_Questions(ObQuestions*)));
    connect(&_window,SIGNAL(addSub_Questoins(SubQuestions*)),this,SLOT(addSub_Questions(SubQuestions*)));
    connect(&_window,SIGNAL(modifyOb_Questoins(ObQuestions*)),this,SLOT(modifyOb_Questoins(ObQuestions*)));
    connect(&_window,SIGNAL(modifySub_Questoins(SubQuestions*)),this,SLOT(modifySub_Questoins(SubQuestions*)));
    connect(&_window,SIGNAL(deleteOb_Questoins(int)),this,SLOT(deleteOb_Questoins(int)));
    connect(&_window,SIGNAL(deleteSub_Questoins(int)),this,SLOT(deleteSub_Questoins(int)));
    //与试卷管理界面连接的信号和槽
    connect(&_window,SIGNAL(addPaper(Paper)),this,SLOT(addPaper(Paper)));
    connect(&_window,SIGNAL(getAllPaper()),this,SLOT(getAllPaper()));
    connect(this,SIGNAL(showAllPaper(QList<Paper*>)),&_window,SIGNAL(showAllPaper(QList<Paper*>)));
    connect(&_window,SIGNAL(getPaperById(int)),this,SLOT(getPaperById(int)));
    connect(&_window,SIGNAL(deletePaper(int)),this,SLOT(deletePaper(int)));
    connect(&_window,SIGNAL(modifyPaper(Paper)),this,SLOT(modifyPaper(Paper)));
    connect(this,SIGNAL(showCurrentPaper(Paper)),&_window,SIGNAL(showCurrentPaper(Paper)));
    connect(&_window,SIGNAL(saveUsertoPaperMark(int,QList<Student*>)),this,SLOT(saveUsertoPaperMark(int,QList<Student*>)));

    ////////examctrl
    connect(&_window,SIGNAL(sendPaper(int)),this,SLOT(sendPaper(int)));
    connect(&_window,SIGNAL(beginExam()),this,SLOT(beginExam()));
    connect(&_window,SIGNAL(getUserList()),this,SLOT(getUserList()));
    connect(this,SIGNAL(updateUserTable(QList<Student*>)),&_window,SIGNAL(updateUserTable(QList<Student*>)));
    connect(&_window,SIGNAL(endExam()),this,SLOT(endExam()));
    connect(this,SIGNAL(getcurrentPaperTime(int)),&_window,SIGNAL(getcurrentPaperTime(int)));
    connect(&_window,SIGNAL(sendPaperTime(int,int)),this,SLOT(sendPaperTime(int,int)));
    connect(&_window,SIGNAL(sendInfo(QStringList)),this,SLOT(sendInfo(QStringList)));
    //subcore
    connect(&_window,SIGNAL(getUserByPaperId(int,QString)),this,SLOT(getUserByPaperId(int,QString)));
    connect(this,SIGNAL(showUserByPaperId(QList<Student*>)),&_window,SIGNAL(showUserByPaperId(QList<Student*>)));
    connect(&_window,SIGNAL(getSubAnswer(int,QString)),this,SLOT(getSubAnswer(int,QString)));
    connect(this,SIGNAL(showSubAnswer(QVector<QString>)),&_window,SIGNAL(showSubAnswer(QVector<QString>)));
    connect(&_window,SIGNAL(submitSubMark(QStringList)),this,SLOT(submitSubMark(QStringList)));
    ///mem
    connect(&_window,SIGNAL(getUser()),this,SLOT(getUser()));//mainwindow发，mainapp收
    connect(this,SIGNAL(showUser(QList<Student*>,QList<USER*>)),&_window,SIGNAL(showUser(QList<Student*>,QList<USER*>)));
    connect(&_window,SIGNAL(addUser(Student*)),this,SLOT(addUser(Student *)));
    connect(&_window,SIGNAL(addManager(USER*)),this,SLOT(addManager(USER*)));
    connect(&_window,SIGNAL(deleteUserId(QString)),this,SLOT(deleteUserId(QString)));
    connect(&_window,SIGNAL(deleteManagerId(int)),this,SLOT(deleteManagerId(int)));
    //login
    connect(&_window,SIGNAL(loginSignal(USER)),this,SLOT(managerLogin(USER)));
    connect(this,SIGNAL(LoginOK()),&_window,SLOT(LoginOK()));
    //scomem
    connect(&_window,SIGNAL(getCombo_id(QString)),this,SLOT(getCombo_id(QString)));
    connect(this,SIGNAL(showCombo(QList<Combo*>)),&_window,SIGNAL(showCombo(QList<Combo*>)));
    connect(&_window,SIGNAL(getCombo_paperid(int)),this,SLOT(getCombo_paperid(int)));
    connect(&_window,SIGNAL(delete_score(int,qlonglong)),this,SLOT(delete_score(int,qlonglong)));
    //InOutPutUI
    connect(&_window,SIGNAL(inputUser(QString)),this,SLOT(inputUser(QString)));
    connect(&_window,SIGNAL(inputOb(QString)),this,SLOT(inputOb(QString)));
    connect(&_window,SIGNAL(inputSub(QString)),this,SLOT(inputSub(QString)));
    connect(&_window,SIGNAL(inputPaper(QString)),this,SLOT(inputPaper(QString)));
    connect(&_window,SIGNAL(outputUser()),this,SLOT(outputUser()));
    connect(&_window,SIGNAL(outputOb()),this,SLOT(outputOb()));
    connect(&_window,SIGNAL(outputSub()),this,SLOT(outputSub()));
    connect(&_window,SIGNAL(outputPaper()),this,SLOT(outputPaper()));
    _window.show();
}

/*
 * PS：不应该每位学生都需要老师判断是否能进行考试，这样太不符合真实情况
 * 应该通过数据库来判断吧。。。。。。
 */
void MainApp::messageArrive(int descriptor,qint32 m, QVariant v)
{
    QMessageBox msg;
    Student u;
    AllAnswers allans;
    switch(m)
    {
    case MSG_NEWCONNECT:
        _infoList.replace(0,1,QString::number(_serverState));
        v.setValue(_infoList);
        emit this->sendData(descriptor,MSG_NEWCONNECT,v);
        break;
    case MSG_LOGIN:
        u=v.value<Student>();
        if(this->userLogin(u))
        {
            if(_serverState==STATE_EXAMING)
            {

                QPushButton *agree=new QPushButton(QString("批准"));
                QPushButton *reject=new QPushButton(QString("拒绝"));
                msg.setText(QString("考生 %1 请求考试，\n是否批准？").arg(u.getID()));
                msg.addButton(agree,QMessageBox::AcceptRole);
                msg.addButton(reject,QMessageBox::RejectRole);
                int ret=msg.exec();
                if(ret==QMessageBox::AcceptRole)
                {
                    emit this->sendData(descriptor,MSG_BEGINEXAM,0);
                    this->userStateChange(descriptor,QString("考试中"));
                }
                if(ret==QMessageBox::RejectRole)
                {
                    QString errorstring=QString("考试要求被拒绝\n请联系工作人员");
                    v.setValue(errorstring);
                    emit this->sendData(u.getSockDescriptor(),MSG_ERROR,v);
                }
            }
        }

        break;
    case MSG_GETPAPER:
        if(_serverState==STATE_PAPERREADY)
        {
            v.setValue(_mainPaper);
            emit this->sendData(descriptor,MSG_GETPAPER,v);
        }
        else if(_serverState==STATE_EXAMING)
        {
            emit this->getcurrentPaperTime(descriptor);
        }
        break;

    case MSG_ANSWER:
        allans=v.value<AllAnswers>();
        this->userStateChange(descriptor,QString("已经交卷"));
        this->updateUserTable(_userList);
        this->dealObAnswers(allans.getObanswer());
        this->dealSubAnswers(allans.getSubanswer());
        break;

    case MSG_ANSWERSINGLE:
        allans=v.value<AllAnswers>();
        this->updateUserTable(_userList);
        this->dealObAnswers(allans.getObanswer());
        this->dealSubAnswers(allans.getSubanswer());
        break;
    }

}

void MainApp::getQuestions()
{
    QList<ObQuestions*> obList;
    QList<SubQuestions*> subList;
    QSqlQuery query;
    query=_DBM->selectObQuestions();

    while(query.next())
    {
        ObQuestions *ob_que=new ObQuestions;
        ob_que->setQuestionId(query.value(0).toInt());
        ob_que->setQuestionTitle(query.value(1).toString());
        ob_que->setAnswer(query.value(2).toString());
        ob_que->setQuestionType(query.value(3).toString());
        obList.append(ob_que);
    }

    query.clear();
    query=_DBM->selectSubQuestions();
    while(query.next())
    {
        SubQuestions *sub_que=new SubQuestions;
        sub_que->setQuestionId(query.value(0).toInt());
        sub_que->setQuestionTitle(query.value(1).toString());
        sub_que->setQuestionType(query.value(2).toString());
        subList.append(sub_que);
    }
    emit this->showQuestions(obList,subList);

}

void MainApp::addOb_Questions(ObQuestions *o_que)
{
    _DBM->insertOb(NULL,o_que->getQuestionType(),o_que->getQuestionTitle(),o_que->getAnswer());
}

void MainApp::addSub_Questions(SubQuestions *s_que)
{
    _DBM->insertSub(NULL,s_que->getQuestionType(),s_que->getQuestionTitle());
}

void MainApp::modifyOb_Questoins(ObQuestions *o_que)
{
    _DBM->alterObQuestions(o_que->getQuestionId(),o_que->getQuestionType(),o_que->getQuestionTitle(),o_que->getAnswer());
}

void MainApp::modifySub_Questoins(SubQuestions *s_que)
{
    _DBM->alterSubQuestions(s_que->getQuestionId(),s_que->getQuestionType(),s_que->getQuestionTitle());
}

void MainApp::deleteOb_Questoins(int id)
{
    _DBM->deleteObQuestions(id);
}

void MainApp::deleteSub_Questoins(int id)
{
    _DBM->deleteSubQuestions(id);
}

void MainApp::addPaper(Paper paper)
{
    _DBM->insertPaper(
        paper.getObQuIds(),
        paper.getSubQuIds(),
        paper.getTotalMark(),
        paper.getPercent(),
        paper.getDescription(),
        paper.getTime());
}

void MainApp::getAllPaper()
{
    QList<Paper*> paperList;
    QSqlQuery query;
    query=_DBM->selectPaper();
    while(query.next())
    {

        Paper *p=new Paper;
        p->setPaperId(query.value(0).toInt());
        p->setObQuIds(query.value(1).toString());
        p->setSubQuIds(query.value(2).toString());
        p->setTotalMark(query.value(3).toInt());
        p->setPercent(query.value(4).toInt());
        p->setDescription(query.value(5).toString());
        p->setTime(query.value(6).toInt());
        paperList.append(p);
    }
    emit this->showAllPaper(paperList);
}

void MainApp::deletePaper(int id)
{
    _DBM->deletePaperById(id);
}

void MainApp::getPaperById(int id)
{
    QSqlQuery query;
    query=_DBM->selectPaperById(id);
    query.next();
    if(!query.isValid())
    {
        qDebug("null");
        return;
    }
    Paper paper;
    paper.setPaperId(query.value(0).toInt());
    paper.setObQuIds(query.value(1).toString());
    paper.setSubQuIds(query.value(2).toString());
    paper.setTotalMark(query.value(3).toInt());
    paper.setPercent(query.value(4).toInt());
    paper.setDescription(query.value(5).toString());
    paper.setTime(query.value(6).toInt());
    emit this->showCurrentPaper(paper);
}

void MainApp::modifyPaper(Paper p)
{
    _DBM->alterPaper(p.getPaperId(),
                    p.getObQuIds(),
                    p.getSubQuIds(),
                    p.getTotalMark(),
                    p.getPercent(),
                    p.getDescription(),
                    p.getTime());
}

Paper MainApp::preparePaper(int id)
{
    QSqlQuery query;
    query=_DBM->selectPaperById(id);
    query.next();
    if(!query.isValid())
    {
        qDebug("null");

    }
    Paper paper;
    paper.setPaperId(query.value(0).toInt());
    paper.setObQuIds(query.value(1).toString());
    paper.setSubQuIds(query.value(2).toString());
    paper.setTotalMark(query.value(3).toInt());
    paper.setPercent(query.value(4).toInt());
    paper.setDescription(query.value(5).toString());
    paper.setTime(query.value(6).toInt());
    query.clear();

    query=_DBM->selectObQuestions();
    while(query.next())
    {
        if(paper.getObQuIds().indexOf(query.value(0).toString())>=0)
        {
            ObQuestions *ob_que=new ObQuestions;
            ob_que->setQuestionId(query.value(0).toInt());
            ob_que->setQuestionTitle(query.value(1).toString());
            ob_que->setAnswer(query.value(2).toString());
            ob_que->setQuestionType(query.value(3).toString());

            paper.obList.append(*ob_que);
        }

    }

    query.clear();
    query=_DBM->selectSubQuestions();
    while(query.next())
    {
        if(paper.getSubQuIds().indexOf(query.value(0).toString())>=0)
        {
            SubQuestions *sub_que=new SubQuestions;
            sub_que->setQuestionId(query.value(0).toInt());
            sub_que->setQuestionTitle(query.value(1).toString());
            sub_que->setQuestionType(query.value(2).toString());
            paper.subList.append(*sub_que);
        }
    }
    return paper;
}

void MainApp::sendPaper(int id)
{
    _mainPaper=this->preparePaper(id);
    _userList= this->getUserByPaperId(id,QString("未完成"));
    this->userStateChange(-1,QString("未登录"));

    QVariant v;
    v.setValue(_mainPaper);
    emit this->sendData(-1,MSG_GETPAPER,v);
    _serverState=STATE_PAPERREADY;
}

void MainApp::getUserList()
{
    emit this->updateUserTable(_userList);
}

void MainApp::beginExam()
{
    _serverState=STATE_EXAMING;
    for(int i=0; i<_userList.count(); i++)
    {
        if(_userList.at(i)->getState()==QString("等待"))
            this->userStateChange(_userList.at(i)->getSockDescriptor(),QString("考试中"));
    }
    emit this->sendData(-1,MSG_BEGINEXAM,0);

}

void MainApp::endExam()
{
    _serverState=STATE_NOEXAM;
    for(int i=0; i<_userList.count(); i++)
    {
        if(_userList.at(i)->getState()==QString("考试中"))
        {
            emit this->sendData(_userList.at(i)->getSockDescriptor(),MSG_ENDEXAM,0);
        }
    }
    _userList.clear();
}

bool MainApp::userLogin(Student u)
{
    int isIn=0;
    QVariant v;
    QSqlQuery query=_DBM->login(u.getID(),u.getPassword());
    if(query.size()>0)
    {
        for(int i=0; i<_userList.count(); i++)
        {
            if(_userList.at(i)->getID()==u.getID())
            {
                if(_userList.at(i)->getState()==QStringLiteral("已经交卷"))
                {
                    QString errorstring=QStringLiteral("你已经交卷了");
                    v.setValue(errorstring);
                    emit this->sendData(u.getSockDescriptor(),MSG_ERROR,v);
                    return false;
                }
                if(_userList.at(i)->getState()!=QStringLiteral("未登录"))
                {
                    QString errorstring=QStringLiteral("你已经登录了");
                    v.setValue(errorstring);
                    emit this->sendData(u.getSockDescriptor(),MSG_ERROR,v);
                    return false;
                }

                isIn=1;
                _userList.at(i)->setHostname(u.getHostname());
                _userList.at(i)->setSockDescriptor(u.getSockDescriptor());

                this->userStateChange(_userList.at(i)->getSockDescriptor(),QStringLiteral("等待"));
                v.setValue(*_userList.at(i));

            }
        }
        if(isIn==1)
        {
            this->sendData(u.getSockDescriptor(),MSG_LOGIN,v);
            return true;
        }
        else
        {
            QString errorstring=QStringLiteral("你不能参加这个考试");
            v.setValue(errorstring);
            emit this->sendData(u.getSockDescriptor(),MSG_ERROR,v);
            return false;
        }

    }
    else
    {
        QString errorstring=QStringLiteral("用户名或密码错误");
        v.setValue(errorstring);
        emit this->sendData(u.getSockDescriptor(),MSG_ERROR,v);
        return false;
    }
}

void MainApp::sendPaperTime(int descriptor,int time)
{
    QVariant v;
    _mainPaper.setTime(time);
    v.setValue(_mainPaper);
    emit this->sendData(descriptor,MSG_GETPAPER,v);
}

//登录验证。。。
bool MainApp::managerLogin(USER m)
{
    QSqlQuery query=_DBM->managerLogin(m.getId(),m.getPassword());
    if(query.size()>0)
    {
        emit this->LoginOK();
        return true;
    }
    else
    {
        QMessageBox msg;
        msg.setText(QStringLiteral("用户名或密码错误"));
        msg.exec();
        return false;
    }
}

void MainApp::userStateChange(int descriptor, QString state)
{
    for(int i=0; i<_userList.count(); i++)
    {
        if(descriptor==_userList.at(i)->getSockDescriptor()||descriptor==-1)
        {
            _userList.at(i)->setState(state);
        }
    }

    emit this->updateUserTable(_userList);
}

void MainApp::removeUser(int descriptor)
{
    for(int i=0; i<_userList.count(); i++)
    {
        if(_userList.at(i)->getSockDescriptor()==descriptor)
        {
            if(_userList.at(i)->getState()!=QString("已经交卷"))
            {
                _userList.at(i)->setHostname("");
                this->userStateChange(descriptor,QString("未登录"));
            }
        }
    }
}

void MainApp::saveUsertoPaperMark(int pid, QList<Student *> ulist)
{

    bool isdelete=_DBM->deletePaperMark(pid);
    QMessageBox msg;
    for(int i=0; i<ulist.count(); i++)
    {
        if(_DBM->insertPaperMark(NULL,NULL,NULL,pid,ulist.at(i)->getID()))
        {
            _DBM->insertObAnswers(pid,ulist.at(i)->getID(),NULL);
            _DBM->insertSubAnswers(pid,ulist.at(i)->getID());

        }
        else
        {
            QString name=ulist.at(i)->getName();
            QString text=QString("学生 '%1' 添加失败，已完成该次考试的学生不能再次添加").arg(name);
            msg.setText(text);
            msg.exec();
        }
    }
    msg.setText(QString("操作完成"));
    msg.exec();
    // QMessageBox msg;
    // msg.setText(QString("已完成该次考试的学生不能再次添加"));
    // msg.exec();};

}

void MainApp::dealObAnswers(ObAnswers obans)
{
    _DBM->updateObAnswers(obans.getPaperId(),obans.getStudentId(),obans.getAnswers());

    QString ans_string=obans.getAnswers();
    QStringList ansList;
    int temp=0;
    while(temp<ans_string.length())
    {
        ansList.append(ans_string.mid(temp,ans_string.indexOf(",")));
        temp=ans_string.indexOf(",",temp)+1;
    }
    QString eachObmark;
    QString obMarkString;
    eachObmark=QString::number(_mainPaper.getTotalMark()*_mainPaper.getPercent()/100/_mainPaper.obList.count());
    for(int i=0; i<ansList.count(); i++)
    {
        QString correctAns=_mainPaper.obList.value(i).getAnswer();
        if(ansList.at(i)==correctAns)
        {

            obMarkString.append(eachObmark);
        }
        else
            obMarkString.append("0");

        obMarkString.append(",");
    }
    _DBM->updatePaperMarkObmark(obMarkString,obans.getPaperId(),obans.getStudentId());
}

void MainApp::dealSubAnswers(SubAnswers subans)
{

    for(int i=0; i<subans.getAnswerList().count(); i++)
    {
        _DBM->updateSubAnswers(subans.getPaperId(),subans.getStudentId(),i+1,subans.getAnswerList().at(i));
    }
    _DBM->updatePaperMarkDone(QDate::currentDate().toString(),subans.getPaperId(),subans.getStudentId());
}

void MainApp::submitSubMark(QStringList submark)
{
    _DBM->updatePaperMarkSubmark(submark.at(2),submark.at(0).toInt(),submark.at(1));
    QSqlQuery query=_DBM->searchPaperMark(submark.at(0).toInt(),submark.at(1));
    query.next();
    int totalmark=0;
    QString ob=query.value(0).toString();
    QString sub=query.value(1).toString();
    int temp=0;
    while(temp<ob.length())
    {
        totalmark+=ob.mid(temp,ob.indexOf(",",temp)-temp).toInt();
        temp=ob.indexOf(",",temp)+1;
    }
    temp=0;
    while(temp<sub.length())
    {
        totalmark+=sub.mid(temp,sub.indexOf(",",temp)-temp).toInt();
        temp=sub.indexOf(",",temp)+1;
    }
    _DBM->updatePaperMarkTotalmark(totalmark,submark.at(0).toInt(),submark.at(1));
}

QList<Student*> MainApp::getUserByPaperId(int id,QString state)
{
    QSqlQuery query=_DBM->queryPaperMark1(id);
    QList<Student*> ulist;
    while(query.next())
    {
        Student *u=new Student;
        u->setID(query.value(8).toString());
        u->setName(query.value(9).toString());
        u->setGrade(query.value(10).toInt());
        u->setClass(query.value(11).toInt());
        u->setState(query.value(5).toString());
        if(u->getState()==state)
        {
            u->setState(query.value(6).toString());
            ulist.append(u);
        }

    }

    emit this->showUserByPaperId(ulist);
    return ulist;

}

void MainApp::getSubAnswer(int pid,QString uid)
{
    QVector<QString> sub;
    QSqlQuery query=_DBM->selectPaperById(pid);
    query.next();
    QString sub_ids=query.value(2).toString();
    // sub.resize(2*sub_ids.count(","));

    query.clear();
    query=_DBM->selectSubQuestions();
    while(query.next())
    {
        if(sub_ids.indexOf(query.value(0).toString())>=0)
        {
            sub.append(query.value(1).toString());
        }
    }
    query.clear();
    query=_DBM->querySubAnswers(pid,uid);
    query.next();
    int m=2;
    int count=sub.size();
    for(int i=count; i<count*2; i++)
    {
        sub.append(query.value(m).toString());
        m++;
    }
    emit this->showSubAnswer(sub);
}

////用户id 查找
void MainApp::getCombo_id(QString a)
{
    QList <Combo*> comboList;
    QSqlQuery query;
    query = _DBM->queryPaperMark2(a);

    QSqlQuery s = _DBM->selectUserId(a);
    QString temp;
    if(s.next())
    {
        temp = s.value(1).toString();
    }

    while(query.next())
    {
        if(query.value(6).toString()==QString("已批改"))
        {
            Combo *b = new Combo;

            //from user
            b->setUserId(a);
            b->setName(temp);
            b->setGrade(s.value(2).toInt());
            b->setClass(s.value(3).toInt());
            int obmark=0;
            int submark=0;
            QString ob=query.value(0).toString();
            QString sub=query.value(1).toString();
            int t=0;
            while(t<ob.length())
            {
                obmark+=ob.mid(t,ob.indexOf(",",t)-t).toInt();
                t=ob.indexOf(",",t)+1;
            }
            t=0;
            while(t<sub.length())
            {
                submark+=sub.mid(t,sub.indexOf(",",t)-t).toInt();
                t=sub.indexOf(",",t)+1;
            }
            b->setObmark(obmark);
            b->setSubmark(submark);
            //from paper
            b->setPaperId(query.value(3).toInt());
            QSqlQuery h = _DBM->selectPaperById(query.value(3).toInt());
            if(h.next())
                b->setPaperName(h.value(5).toString());

            //from self (paper mark)
            b->setPaperMark(query.value(2).toInt());
            comboList.append(b);
        }
    }
    emit this->showCombo(comboList);
}

void MainApp::getCombo_paperid(int id)
{
    QList <Combo*> comboList;
    QSqlQuery query;
    query = _DBM->queryPaperMark1(id);

    QSqlQuery s = _DBM->selectPaperById(id);
    QString temp;
    if(s.next())
    {
        temp = s.value(5).toString();
    }

    while(query.next())
    {
        if(query.value(6).toString()==QString("已批改"))
        {
            Combo *b = new Combo;
            b->setPaperId(id);
            b->setPaperName(temp);
            int obmark=0;
            int submark=0;
            QString ob=query.value(0).toString();
            QString sub=query.value(1).toString();
            int t=0;
            while(t<ob.length())
            {
                obmark+=ob.mid(t,ob.indexOf(",",t)-t).toInt();
                t=ob.indexOf(",",t)+1;
            }
            t=0;
            while(t<sub.length())
            {
                submark+=sub.mid(t,sub.indexOf(",",t)-t).toInt();
                t=sub.indexOf(",",t)+1;
            }
            b->setObmark(obmark);
            b->setSubmark(submark);
            //from paper
            b->setPaperId(query.value(3).toInt());
            QSqlQuery h = _DBM->selectUserId(query.value(4).toString());
            if(h.next())
            {
                b->setUserId(h.value(0).toString());
                b->setName(h.value(1).toString());
                b->setGrade(h.value(2).toInt());
                b->setClass(h.value(3).toInt());
            }
            //from self (paper mark)
            b->setPaperMark(query.value(2).toInt());
            comboList.append(b);
        }
    }
    emit this->showCombo(comboList);
}

void MainApp::getUser()
{
    QList<Student*> userList;
    QList<USER*> managerList;

    QSqlQuery query;
    query = _DBM->selectUser();

    while(query.next())
    {
        Student *userptr = new Student;
        userptr->setID(query.value(0).toString());
        userptr->setName(query.value(1).toString());
        userptr->setGrade(query.value(2).toInt());
        userptr->setClass(query.value(3).toInt());
        userptr->setPassword(query.value(4).toString());
        userList.append(userptr);
    }

    query.clear();
    query = _DBM->selectManager();
    while(query.next())
    {
        USER *managerptr = new USER;
        managerptr->setId(query.value(0).toInt());
        managerptr->setName(query.value(1).toString());
        managerptr->setPassword(query.value(2).toString());
        managerList.append(managerptr);
    }
    /*      QSqlTableModel *ob_model=new QSqlTableModel(this,DBM->db);
            ob_model->setTable("user");
            ob_model->select();
            QTableView *view = new QTableView;
            view->setModel(ob_model);
            view->show();
    */
    emit this->showUser(userList,managerList);
}

void MainApp::addUser(Student *user)
{
    _DBM->insertUser(
        user->getID(),
        user->getName(),
        user->getGrade(),
        user->getClass(),
        user->getPassword());
}

//serveruser用户添加
void MainApp::addManager(USER *m)
{
    _DBM->insertManager(m->getId(),m->getName(),m->getPassword());
}

void MainApp::modifyUser(Student u)
{
    _DBM->modifyUser(u.getID(),u.getName(),u.getGrade(),u.getClass(),u.getPassword());
}

void MainApp::deleteUserId(QString a)
{
    _DBM->deleteUserId(a);
}

void MainApp::deleteManagerId(int a)
{
    _DBM->deleteManagerId(a);
}

void MainApp::outputUser()
{
    QList<Student*> userList;

    QSqlQuery query;
    query = _DBM->selectUser();

    while(query.next())
    {
        Student *userptr = new Student;
        userptr->setID(query.value(0).toString());
        userptr->setName(query.value(1).toString());
        userptr->setGrade(query.value(2).toInt());
        userptr->setClass(query.value(3).toInt());
        userptr->setPassword(query.value(4).toString());
        userList.append(userptr);
    }
    _IOM->outputUser(userList);
    QMessageBox msg;
    msg.setText(QString("导出成功。"));
    msg.exec();
}

void MainApp::outputOb()
{
    QList<ObQuestions*> obList;
    QSqlQuery query;
    query=_DBM->selectObQuestions();
    while(query.next())
    {
        ObQuestions *ob_que=new ObQuestions;
        ob_que->setQuestionId(query.value(0).toInt());
        ob_que->setQuestionTitle(query.value(1).toString());
        ob_que->setAnswer(query.value(2).toString());
        ob_que->setQuestionType(query.value(3).toString());
        obList.append(ob_que);
    }
    _IOM->outputOb(obList);
    QMessageBox msg;
    msg.setText(QString("导出成功。"));
    msg.exec();
}

void MainApp::outputSub()
{
    QList<SubQuestions*> subList;
    QSqlQuery query=_DBM->selectSubQuestions();
    while(query.next())
    {
        SubQuestions *sub_que=new SubQuestions;
        sub_que->setQuestionId(query.value(0).toInt());
        sub_que->setQuestionTitle(query.value(1).toString());
        sub_que->setQuestionType(query.value(2).toString());
        subList.append(sub_que);
    }
    _IOM->outputSub(subList);
    QMessageBox msg;
    msg.setText(QString("导出成功。"));
    msg.exec();
}

void MainApp::outputPaper()
{
    QList<Paper*> paperList;
    QSqlQuery query;
    query=_DBM->selectPaper();
    while(query.next())
    {
        Paper *p=new Paper;
        p->setPaperId(query.value(0).toInt());
        p->setObQuIds(query.value(1).toString());
        p->setSubQuIds(query.value(2).toString());
        p->setTotalMark(query.value(3).toInt());
        p->setPercent(query.value(4).toInt());
        p->setDescription(query.value(5).toString());
        p->setTime(query.value(6).toInt());
        paperList.append(p);
    }
    _IOM->outputPaper(paperList);
    QMessageBox msg;
    msg.setText(QString("导出成功。"));
    msg.exec();
}

void MainApp::inputUser(QString path)
{
    QList<Student*> userlist;
    userlist=_IOM->inputUser(path);
    for(int i=0; i<userlist.count(); i++)
    {
        /*qDebug()<< userlist.at(i)->getID()<<
                userlist.at(i)->getName()<<
                userlist.at(i)->getGrade()<<
                userlist.at(i)->getClass()<<
                userlist.at(i)->getPassword()<<"\n";*/
        _DBM->insertUser(
            userlist.at(i)->getID(),
            userlist.at(i)->getName(),
            userlist.at(i)->getGrade(),
            userlist.at(i)->getClass(),
            userlist.at(i)->getPassword());
    }
    QMessageBox msg;
    msg.setText(QString("导入成功。"));
    msg.exec();
}

void MainApp::inputOb(QString path)
{
    QList<ObQuestions*> oblist;
    oblist=_IOM->inputOb(path);
    for(int i=0; i<oblist.count(); i++)
    {
        _DBM->insertOb(oblist.at(i)->getQuestionId(),oblist.at(i)->getQuestionType(),oblist.at(i)->getQuestionTitle(),oblist.at(i)->getAnswer());
    }
    QMessageBox msg;
    msg.setText(QString("导入成功。"));
    msg.exec();
}

void MainApp::inputSub(QString path)
{
    QList<SubQuestions*> sublist;
    sublist=_IOM->inputSub(path);
    for(int i=0; i<sublist.count(); i++)
    {
        _DBM->insertSub(sublist.at(i)->getQuestionId(),sublist.at(i)->getQuestionType(),sublist.at(i)->getQuestionTitle());
    }
    QMessageBox msg;
    msg.setText(QString("导入成功。"));
    msg.exec();
}

void MainApp::inputPaper(QString path)
{
    QList<Paper*> plist;
    plist=_IOM->inputPaper(path);
    for(int i=0; i<plist.count(); i++)
    {
        _DBM->insertPaper(
            plist.at(i)->getObQuIds(),
            plist.at(i)->getSubQuIds(),
            plist.at(i)->getTotalMark(),
            plist.at(i)->getPercent(),
            plist.at(i)->getDescription(),
            plist.at(i)->getTime());
    }
    QMessageBox msg;
    msg.setText(QString("导入成功。"));
    msg.exec();
}

void MainApp::sendInfo(QStringList list)
{
    _infoList.clear();
    _infoList.append("*,");
    for(int i=0; i<list.count(); i++)
    {
        _infoList.append(list.at(i));
        _infoList.append(",");
    }
}

void MainApp::delete_score(int pid,qlonglong uid)
{
    if(_DBM->deleteScore(pid,uid))
    {
        QMessageBox msg;
        msg.setText("删除成功");
        msg.exec();
    }
}
