#include "total_score.h"
#include "ui_total_score.h"
#include"score_distribution.h"
//一分一段表

totalscore::totalscore(QString newstudent_id,bool student_call,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::totalscore)
{
    student=student_call;
    ui->setupUi(this);

    setFixedSize(800,600);

    student_id=newstudent_id;

    connect(ui->btn_check_all_return,&QPushButton::clicked,this,&totalscore::close);//退出
}

void totalscore::on_Chinese_clicked()
{
    score_distribution* s=new score_distribution("Chinese",student_id,student);
    s->show();
    this->close();
}


void totalscore::on_Math_clicked()
{
    score_distribution* s=new score_distribution("Math",student_id,student);
    s->show();
    this->close();
}


void totalscore::on_English_clicked()
{
    score_distribution* s=new score_distribution("English",student_id,student);
    s->show();
    this->close();
}


void totalscore::on_Physics_clicked()
{
    score_distribution* s=new score_distribution("Physics",student_id,student);
    s->show();
    this->close();
}


void totalscore::on_Chemestry_clicked()
{
    score_distribution* s=new score_distribution("Chemestry",student_id,student);
    s->show();
    this->close();
}


void totalscore::on_Biology_clicked()
{
    score_distribution* s=new score_distribution("Biology",student_id,student);
    s->show();
    this->close();
}


void totalscore::on_SUM_clicked()
{
    score_distribution* s=new score_distribution("SUM",student_id,student);
    s->show();
    this->close();
}


totalscore::~totalscore()
{
    delete ui;
}
