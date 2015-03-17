#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);

//    _ui->action_mainmenu->setEnabled(false);//按钮置灰
//    _ui->action_makepaper->setEnabled(false);
//    _ui->action_QuestionsManager->setEnabled(false);
//    _ui->action_memmanager->setEnabled(false);
//    _ui->action_examctrl->setEnabled(false);
//    _ui->action_subscore->setEnabled(false);
//    _ui->action_scomanage->setEnabled(false);
//    _ui->action_config->setEnabled(false);
//    _ui->action_inoutput->setEnabled(false);

    _statusBar = statusBar();
    this->on_action_login_triggered();
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::do_QuestionsManager()
{
    QuestionsManageUI *questionManager  =  new QuestionsManageUI();
    connect(questionManager, SIGNAL(importChoiceQuestion(QString)), this, SIGNAL(importChoiceQuestion(QString)));
    connect(questionManager, SIGNAL(importEssayQuestion(QString)), this, SIGNAL(importEssayQuestion(QString)));
    connect(questionManager, SIGNAL(exportEssayQuestion(QList<EssayQuestions*>,QString)), this, SIGNAL(exportEssayQuestion(QList<EssayQuestions*>,QString)));
    connect(questionManager, SIGNAL(exportChoiceQuestion(QList<ChoiceQuestions*>,QString)), this, SIGNAL(exportChoiceQuestion(QList<ChoiceQuestions*>,QString)));
    connect(questionManager, SIGNAL(updateChoiceQuestion(ChoiceQuestions*)), this, SIGNAL(updateChoiceQuestion(ChoiceQuestions*)));
    connect(questionManager, SIGNAL(updateEssayQuestion(EssayQuestions*)), this, SIGNAL(updateEssayQuestion(EssayQuestions*)));
    connect(this, SIGNAL(setChoiceQuestions(QList<ChoiceQuestions*>)), questionManager, SLOT(setChoiceQuestions(QList<ChoiceQuestions*>)));
    connect(this,SIGNAL(setEssayQuestions(QList<EssayQuestions*>)), questionManager, SLOT(setEssayQuestions(QList<EssayQuestions*>)));
    connect(this, SIGNAL(showChoiceQuestionList(QList<ChoiceQuestions*>)), questionManager, SLOT(showChoiceQuestionList(QList<ChoiceQuestions*>)));
    connect(this, SIGNAL(showEssayQuestionList(QList<EssayQuestions*>)), questionManager, SLOT(showEssayQuestionList(QList<EssayQuestions*>)));
    connect(questionManager,SIGNAL(addOb_Questoins(ChoiceQuestions*)),this,SIGNAL(addOb_Questoins(ChoiceQuestions*)));
    connect(questionManager,SIGNAL(addSub_Questoins(EssayQuestions*)),this,SIGNAL(addSub_Questoins(EssayQuestions*)));
    connect(questionManager,SIGNAL(modifyOb_Questoins(ChoiceQuestions*)),this,SIGNAL(modifyOb_Questoins(ChoiceQuestions*)));
    connect(questionManager,SIGNAL(modifySub_Questoins(EssayQuestions*)),this,SIGNAL(modifySub_Questoins(EssayQuestions*)));
    connect(questionManager,SIGNAL(deleteOb_Questoins(int)),this,SIGNAL(deleteOb_Questoins(int)));
    connect(questionManager,SIGNAL(deleteSub_Questoins(int)),this,SIGNAL(deleteSub_Questoins(int)));
    connect(questionManager->pushButton_back,SIGNAL(clicked()),this,SLOT(backToMenu()));
    connect(questionManager->Button_delete, SIGNAL(clicked()), this, SIGNAL(getChoiceQuestions()));
    connect(questionManager->Button_delete, SIGNAL(clicked()), this, SIGNAL(getEssayQuestions()));
    this->setCentralWidget(questionManager);
    emit this->getChoiceQuestions();
    emit this->getEssayQuestions();
    _statusBar->showMessage(QStringLiteral("题库管理"));
}

void MainWindow::do_makepaper()
{
    PaperManageUI *make_paper  =  new PaperManageUI();
    connect(make_paper, SIGNAL(insertPaper(Paper*)), this, SIGNAL(insertPaper(Paper*)));
    connect(make_paper, SIGNAL(updatePaper(Paper*)), this,SIGNAL(updatePaper(Paper*)));
    connect(this, SIGNAL(setChoiceQuestions(QList<ChoiceQuestions*>)), make_paper, SLOT(setChoiceQuestions(QList<ChoiceQuestions*>)));
    connect(this, SIGNAL(setEssayQuestions(QList<EssayQuestions*>)), make_paper, SLOT(setEssayQuestions(QList<EssayQuestions*>)));
    connect(make_paper,SIGNAL(addPaper(Paper)),this,SIGNAL(addPaper(Paper)));
    connect(this,SIGNAL(showAllPaper(QList<Paper*>)),make_paper,SLOT(showAllPaper(QList<Paper*>)));
    connect(make_paper->pushButton_AddorMoidfy,SIGNAL(clicked()),this,SIGNAL(getAllPaper()));
    connect(make_paper->pushButton_delete,SIGNAL(clicked()),this,SIGNAL(getAllPaper()));
    connect(make_paper,SIGNAL(deletePaper(int)),this,SIGNAL(deletePaper(int)));
    connect(make_paper,SIGNAL(modifyPaper(Paper)),this,SIGNAL(modifyPaper(Paper)));
    connect(make_paper,SIGNAL(getPaperById(int)),this,SIGNAL(getPaperById(int)));
    connect(make_paper->pushButton_back,SIGNAL(clicked()),this,SLOT(backToMenu()));
    connect(make_paper,SIGNAL(queryPaperMark(int,QString)),this,SIGNAL(getUserByPaperId(int,QString)));
    connect(this,SIGNAL(showUserByPaperId(QList<Student*>)),make_paper,SLOT(showSelectUser(QList<Student*>)));
    connect(make_paper,SIGNAL(saveUsertoPaperMark(int,QList<Student*>)),this,SIGNAL(saveUsertoPaperMark(int,QList<Student*>)));
    connect(this, SIGNAL(showStudent(QList<Student*>)), make_paper, SLOT(showStudent(QList<Student*>)));
    this->setCentralWidget(make_paper);

    emit this->getAllPaper();
    emit this->getStudent();
    emit this->getChoiceQuestions();
    emit this->getEssayQuestions();
    _statusBar->showMessage(QStringLiteral("试卷管理"));
}

void MainWindow::do_examsetting()
{
    ExamSettingUI *examSetting = new ExamSettingUI();
    connect(examSetting, SIGNAL(setPaper(int)), this, SIGNAL(setPaper(int)));
    connect(examSetting, SIGNAL(setInfo(QStringList)), this, SIGNAL(setInfo(QStringList)));
    connect(examSetting, SIGNAL(startServer()), this, SIGNAL(startServer()));
    connect(examSetting, SIGNAL(closeServer()), this, SIGNAL(closeServer()));
    connect(this,SIGNAL(showAllPaper(QList<Paper*>)),examSetting,SLOT(showPapers(QList<Paper*>)));
    connect(examSetting,SIGNAL(sendPaper(int)),this,SIGNAL(sendPaper(int)));
    connect(examSetting, SIGNAL(beginExam()), this, SIGNAL(beginExam()));
    connect(examSetting, SIGNAL(beginExam()), this, SLOT(examMode()));
    connect(this, SIGNAL(updateUserTable(QList<Student*>)), examSetting, SIGNAL(updateStudentTable(QList<Student*>)));
    connect(examSetting,SIGNAL(endExam()),this,SIGNAL(endExam()));
    connect(examSetting,SIGNAL(endExam()),this,SLOT(endExamMode()));
    connect(examSetting, SIGNAL(pauseExam()), this, SIGNAL(pauseExam()));
    connect(examSetting, SIGNAL(continueExam()), this, SIGNAL(continueExam()));
    connect(examSetting, SIGNAL(sendMessage(QString)), this, SIGNAL(sendMessage(QString)));
    connect(examSetting->pushButton_back,SIGNAL(clicked()),this,SLOT(backToMenu()));
    connect(this,SIGNAL(getcurrentPaperTime(int)),examSetting,SIGNAL(getcurrentPaperTime(int)));
    connect(examSetting,SIGNAL(sendPaperTime(int,int)),this,SIGNAL(sendPaperTime(int,int)));
    connect(examSetting,SIGNAL(sendInfo(QStringList)),this,SIGNAL(sendInfo(QStringList)));
    this->setCentralWidget(examSetting);
    emit this->getAllPaper();
    emit this->getUserList();
    _statusBar->showMessage(QStringLiteral("考试控制"));

}

void MainWindow::do_examconctrol()
{
    ExamControl *examControl = new ExamControl();
    connect(this, SIGNAL(updateUserTable(QList<Student*>)), examControl, SLOT(updateStudentTable(QList<Student*>)));
    connect(examControl, SIGNAL(beginExam()), this, SIGNAL(beginExam()));
    connect(examControl, SIGNAL(endExam()), this, SIGNAL(endExam()));
    connect(examControl, SIGNAL(pauseExam()), this, SIGNAL(pauseExam()));
    connect(examControl, SIGNAL(continueExam()), this, SIGNAL(continueExam()));
    connect(examControl, SIGNAL(sendMessage(QString)), this, SIGNAL(sendMessage(QString)));
    connect(examControl, SIGNAL(sendPaperTime(int,int)), this, SIGNAL(sendPaperTime(int,int)));
    connect(this, SIGNAL(setPaperName(QString)), examControl, SLOT(setPaperName(QString)));
    connect(this, SIGNAL(setExamTime(QTime)), examControl, SLOT(setTime(QTime)));
    connect(examControl->pushButton_back, SIGNAL(clicked()), this, SLOT(backToMenu()));
    this->setCentralWidget(examControl);
    emit this->getUserList();
    emit this->getPaperName();
    emit this->getExamTime();
}

void MainWindow::do_subscore()
{
    SubMarkUI *sub_score = new SubMarkUI;
    connect(this,SIGNAL(showAllPaper(QList<Paper*>)),sub_score,SLOT(showPapers(QList<Paper*>)));
    connect(sub_score,SIGNAL(getUserByPaperId(int,QString)),this,SIGNAL(getUserByPaperId(int,QString)));
    connect(this,SIGNAL(showUserByPaperId(QList<Student*>)),sub_score,SLOT(showUserByPaperId(QList<Student*>)));
    connect(sub_score,SIGNAL(getSubAnswer(int,QString)),this,SIGNAL(getSubAnswer(int,QString)));
    connect(this,SIGNAL(showSubAnswer(QVector<QString>)),sub_score,SLOT(showSubAnswer(QVector<QString>)));
    connect(sub_score,SIGNAL(submitSubMark(QStringList)),this,SIGNAL(submitSubMark(QStringList)));
//    connect(sub_score->pushButton_back,SIGNAL(clicked()),this,SLOT(backToMenu()));
    emit this->getAllPaper();
    this->setCentralWidget(sub_score);
    _statusBar->showMessage(QStringLiteral("在线评卷"));

}

void MainWindow::do_memmanage()
{
    MemberManageUI *mem_Manage = new MemberManageUI();
    connect(mem_Manage, SIGNAL(exportStudent(QList<Student*>,QString)), this, SIGNAL(exportStudent(QList<Student*>,QString)));
    connect(mem_Manage, SIGNAL(exportTeacher(QList<User*>,QString)), this, SIGNAL(exportTeacher(QList<User*>,QString)));
    connect(mem_Manage, SIGNAL(exportManager(QList<User*>,QString)), this, SIGNAL(exportManager(QList<User*>,QString)));
    connect(mem_Manage, SIGNAL(exportType(QMap<int,QString>,QString)), this, SIGNAL(exportType(QMap<int,QString>,QString)));
    connect(mem_Manage, SIGNAL(importStudent(QString)), this, SIGNAL(importStudent(QString)));
    connect(mem_Manage, SIGNAL(importTeacher(QString)), this, SIGNAL(importTeacher(QString)));
    connect(mem_Manage, SIGNAL(importManager(QString)), this, SIGNAL(importManager(QString)));
    connect(mem_Manage, SIGNAL(importType(QString)), this, SIGNAL(importType(QString)));
    connect(this, SIGNAL(updateTeacherList(QList<User*>)), mem_Manage, SLOT(updateTeacherList(QList<User*>)));
    connect(this, SIGNAL(updateManagerList(QList<User*>)), mem_Manage, SLOT(updateManagerList(QList<User*>)));
    connect(this, SIGNAL(updateStudentList(QList<Student*>)), mem_Manage, SLOT(updateStudentList(QList<Student*>)));
    connect(this, SIGNAL(updateTypeList(QMap<int,QString>)), mem_Manage, SLOT(updateTypeList(QMap<int,QString>)));
    connect(this, SIGNAL(showStudent(QList<Student*>)), mem_Manage, SLOT(showStudent(QList<Student*>)));
    connect(this, SIGNAL(showTeacher(QList<User*>)), mem_Manage, SLOT(showTeacher(QList<User*>)));
    connect(this, SIGNAL(showType(QMap<int,QString>)), mem_Manage, SLOT(showType(QMap<int,QString>)));
    connect(this, SIGNAL(showManager(QList<User*>)), mem_Manage, SLOT(showManager(QList<User*>)));
    connect(this, SIGNAL(showSubject(QList<QString>)), mem_Manage, SLOT(showSubject(QList<QString>)));
    connect(mem_Manage, SIGNAL(updateStudent(Student*)), this, SIGNAL(updateStudent(Student*)));
    connect(mem_Manage, SIGNAL(updateTeacher(User*)), this, SIGNAL(updateTeacher(User*)));
    connect(mem_Manage, SIGNAL(updateManager(User*)), this, SIGNAL(updateManager(User*)));
    connect(mem_Manage, SIGNAL(updateType(int,QString)), this, SIGNAL(updateType(int,QString)));
    connect(mem_Manage, SIGNAL(addStudent(Student*)),this,SIGNAL(addStudent(Student*)));
    connect(mem_Manage, SIGNAL(addTeacher(User*)),this,SIGNAL(addTeacher(User*)));
    connect(mem_Manage, SIGNAL(addManager(User*)), this, SIGNAL(addManger(User*)));
    connect(mem_Manage, SIGNAL(addType(int,QString)), this, SIGNAL(addType(int,QString)));
    connect(mem_Manage, SIGNAL(deleteType(int)), this, SIGNAL(deleteType(int)));
    connect(mem_Manage->pushButton_add_user, SIGNAL(clicked()), this, SIGNAL(getType()));
    connect(mem_Manage->pushButton_delete_user, SIGNAL(clicked()), this, SIGNAL(getType()));
    connect(mem_Manage->pushButton_add_user, SIGNAL(clicked()), this, SIGNAL(getManager()));
    connect(mem_Manage->pushButton_add_user, SIGNAL(clicked()), this, SIGNAL(getStudent()));
    connect(mem_Manage->pushButton_add_user, SIGNAL(clicked()), this, SIGNAL(getTeacher()));
    connect(mem_Manage,SIGNAL(deleteUserId(QString)),this,SIGNAL(deleteUserId(QString)));
    connect(mem_Manage,SIGNAL(deleteManagerId(int)),this,SIGNAL(deleteManagerId(int)));
    connect(mem_Manage->pushButton_delete_user, SIGNAL(clicked()), this, SIGNAL(getStudent()));
    connect(mem_Manage->pushButton_delete_user, SIGNAL(clicked()), this, SIGNAL(getTeacher()));
    connect(mem_Manage->pushButton_delete_user,SIGNAL(clicked()),this,SIGNAL(getManager()));
    connect(mem_Manage->pushButton_back,SIGNAL(clicked()),this,SLOT(backToMenu()));
    this->setCentralWidget(mem_Manage);
    emit this->getStudent();
    emit this->getTeacher();
    emit this->getSubject();
    emit this->getManager();
    emit this->getType();
    _statusBar->showMessage(QStringLiteral("用户管理"));
}

void MainWindow::do_login()
{
    LoginUI *loginPage = new LoginUI;
    connect(loginPage,SIGNAL(loginSignal(User)),this,SIGNAL(loginSignal(User)));
    this->setCentralWidget(loginPage);
    _statusBar->showMessage(QStringLiteral("登录"));
}

void MainWindow::do_mainmenu()
{
    MainMenuUI *mainmenu = new MainMenuUI;
    connect(mainmenu,SIGNAL(action_QuestionsManager()),this,SLOT(on_action_QuestionsManager_triggered()));
    connect(mainmenu,SIGNAL(action_makepaper()),this,SLOT(on_action_makepaper_triggered()));
    connect(mainmenu,SIGNAL(action_memmanager()),this,SLOT(on_action_memmanager_triggered()));
    connect(mainmenu,SIGNAL(action_examctrl()),this,SLOT(action_examconctrol()));
    connect(mainmenu,SIGNAL(action_subscore()),this,SLOT(on_action_subscore_triggered()));
    connect(mainmenu,SIGNAL(action_config()),this,SLOT(on_action_config_triggered()));
    connect(mainmenu,SIGNAL(action_scoremanage()),this,SLOT(on_action_scomanage_triggered()));
    connect(mainmenu,SIGNAL(action_inoutput()),this,SLOT(on_action_inoutput_triggered()));
    connect(mainmenu,SIGNAL(action_papersetting()),this,SLOT(action_papersetting()));
    connect(mainmenu,SIGNAL(action_examsetting()),this,SLOT(action_examsetting()));
    this->setCentralWidget(mainmenu);
    this->statusBar()->showMessage(QStringLiteral("主菜单"));
}

void MainWindow::do_config()
{
    ConfigUI *config = new ConfigUI;
    connect(config->pushButton_back,SIGNAL(clicked()),this,SLOT(backToMenu()));
    this->setCentralWidget(config);
    _statusBar->showMessage(QStringLiteral("设置"));
}

void MainWindow::do_scomanage()
{
    ScoreManageUI *score_manage  =  new ScoreManageUI();

    connect(this,SIGNAL(showCombo(QList<Combo*>)),score_manage,SLOT(showCombo(QList<Combo*>)));
    connect(score_manage,SIGNAL(getCombo_id(QString)),this,SIGNAL(getCombo_id(QString)));
    connect(score_manage,SIGNAL(getCombo_paperid(int)),this,SIGNAL(getCombo_paperid(int)));
    connect(this,SIGNAL(showAllPaper(QList<Paper*>)),score_manage,SLOT(showPapers(QList<Paper*>)));
    connect(score_manage->pushButton_back,SIGNAL(clicked()),this,SLOT(backToMenu()));
    connect(score_manage,SIGNAL(delete_score(int,qlonglong)),this,SIGNAL(delete_score(int,qlonglong)));
    emit this->getAllPaper();
    this->setCentralWidget(score_manage);

    _statusBar->showMessage(QStringLiteral("成绩管理"));
}

void MainWindow::do_inoutput()
{
    InOutPutUI *io = new InOutPutUI;
    connect(io,SIGNAL(inputUser(QString)),this,SIGNAL(inputUser(QString)));
    connect(io,SIGNAL(inputOb(QString)),this,SIGNAL(inputOb(QString)));
    connect(io,SIGNAL(inputSub(QString)),this,SIGNAL(inputSub(QString)));
    connect(io,SIGNAL(inputPaper(QString)),this,SIGNAL(inputPaper(QString)));
    connect(io,SIGNAL(outputUser()),this,SIGNAL(outputUser()));
    connect(io,SIGNAL(outputOb()),this,SIGNAL(outputOb()));
    connect(io,SIGNAL(outputSub()),this,SIGNAL(outputSub()));
    connect(io,SIGNAL(outputPaper()),this,SIGNAL(outputPaper()));
    connect(io->pushButton_back,SIGNAL(clicked()),this,SLOT(backToMenu()));
    this->setCentralWidget(io);
    _statusBar->showMessage(QStringLiteral("导入导出"));
}

void MainWindow::do_papersetting()
{
    PaperSetting *paperSetting = new PaperSetting();
    connect(this, SIGNAL(showAllPaper(QList<Paper*>)), paperSetting, SLOT(setPaperList(QList<Paper*>)));
    connect(this, SIGNAL(showAllPaper(QList<Paper*>)), paperSetting, SLOT(showPaper(QList<Paper*>)));
    connect(this, SIGNAL(showStudent(QList<Student*>)), paperSetting, SLOT(setStudentList(QList<Student*>)));
    connect(paperSetting, SIGNAL(getSelectStudent(int)), this, SIGNAL(getSelectPaper(int)));
    connect(this, SIGNAL(showSelectStudent(QStringList)), paperSetting, SLOT(showSelectStudent(QStringList)));
    connect(this, SIGNAL(showSelectStudent(QStringList)), paperSetting, SLOT(setSelectStudent(QStringList)));
    connect(paperSetting, SIGNAL(importExaminee(QString)), this, SIGNAL(importExaminee(QString)));
    connect(this, SIGNAL(appendExaminee(QStringList)), paperSetting, SLOT(appendExaminee(QStringList)));
    connect(paperSetting, SIGNAL(saveExaminee(int,QStringList)), this, SIGNAL(saveExaminee(int,QStringList)));
    connect(paperSetting->pushButton_back, SIGNAL(clicked()), this, SLOT(backToMenu()));
    this->setCentralWidget(paperSetting);

    emit this->getAllPaper();
    emit this->getStudent();
}

void MainWindow::on_action_QuestionsManager_triggered()
{
    do_QuestionsManager();
}

void MainWindow::on_action_makepaper_triggered()
{
    do_makepaper();
}

void MainWindow::action_examsetting()
{
    do_examsetting();
}

void MainWindow::action_examconctrol()
{
    do_examconctrol();
}

void MainWindow::on_action_subscore_triggered()
{
    do_subscore();
}

void MainWindow::on_action_memmanager_triggered()
{
    do_memmanage();
}


void MainWindow::on_action_login_triggered()
{
    this->do_login();
}

void MainWindow::on_action_mainmenu_triggered()
{
    this->do_mainmenu();
}

void MainWindow::on_action_config_triggered()
{
    this->do_config();
}

void MainWindow::on_action_scomanage_triggered()
{
    do_scomanage();
}

void MainWindow::on_action_inoutput_triggered()
{
    do_inoutput();
}

void MainWindow::examMode()
{
    _ui->action_makepaper->setEnabled(false);
    _ui->action_QuestionsManager->setEnabled(false);
    _ui->action_examctrl->setEnabled(false);
    _ui->action_config->setEnabled(false);
    _ui->action_login->setEnabled(false);
    _ui->action_mainmenu->setEnabled(false);
    _ui->action_memmanager->setEnabled(false);
    _ui->action_subscore->setEnabled(false);
    _ui->action_scomanage->setEnabled(false);
    _ui->action_inoutput->setEnabled(false);
}

void MainWindow::endExamMode()
{
    _ui->action_makepaper->setEnabled(true);
    _ui->action_QuestionsManager->setEnabled(true);
    _ui->action_examctrl->setEnabled(true);
    _ui->action_config->setEnabled(true);
    _ui->action_login->setEnabled(true);
    _ui->action_mainmenu->setEnabled(true);
    _ui->action_memmanager->setEnabled(true);
    _ui->action_subscore->setEnabled(true);
    _ui->action_scomanage->setEnabled(true);
    _ui->action_inoutput->setEnabled(true);
}

//设置菜单栏的按钮是否活动
void MainWindow::LoginOK()
{
    if(User::GetInstance().getType()  ==  1)
    {
        _ui->action_memmanager->setEnabled(true);
        _ui->action_config->setEnabled(true);

    }
    else
    {
        _ui->action_examctrl->setEnabled(true);
        _ui->action_makepaper->setEnabled(true);
        _ui->action_scomanage->setEnabled(true);
        _ui->action_subscore->setEnabled(true);
    }
    _ui->action_inoutput->setEnabled(true);
    this->on_action_mainmenu_triggered();
}

void MainWindow::on_action_Qt_triggered()
{
    QMessageBox::aboutQt(this,QStringLiteral("关于Qt"));
}

void MainWindow::action_papersetting()
{
    do_papersetting();
}

void MainWindow::backToMenu()
{
    this->do_mainmenu();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox msg;
    msg.setText(QStringLiteral("确定离开吗？"));
    msg.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
    int ret = msg.exec();
    if(ret == QMessageBox::Ok)
        event->accept();
    else
        event->ignore();
}

void MainWindow::pauseExamMode()
{

}
