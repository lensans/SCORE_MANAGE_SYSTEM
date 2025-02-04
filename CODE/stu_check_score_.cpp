#include "stu_check_score_.h"
#include "ui_stu_check_score_.h"
#include "mysql_connect.h"

stu_check_score_::stu_check_score_(student stu,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::stu_check_score_)
{
    ui->setupUi(this);
    this->stu=stu;
    connect(ui->btn_check_all_return,&QPushButton::clicked,this,&stu_check_score_::close);//查询全部成绩时点击返回,关闭查询成绩界面

    VP subject_scores;

    DB db;
    subject_scores=db.get_all_score(stu.student_id);
    int a=0;
    //显示成绩
    QString Chinese = QString("%1").arg(subject_scores[0].second);//将int型的分数强转为QString，赋给LineEdit的文本
    ui->check_Chinese_line->setText(Chinese);
    QString Math = QString("%1").arg(subject_scores[1].second);
    ui->check_math_line->setText(Math);
    QString English = QString("%1").arg(subject_scores[2].second);
    ui->check_English_line->setText(English);
    QString Physics = QString("%1").arg(subject_scores[3].second);
    ui->check_physics_line->setText(Physics);
    QString Chemistry = QString("%1").arg(subject_scores[4].second);
    ui->check_chemistry_line->setText(Chemistry);
    QString Biology = QString("%1").arg(subject_scores[5].second);
    ui->check_biology_line->setText(Biology);
    QString Sum = QString("%1").arg(subject_scores[6].second);
    ui->check_sum_line->setText(Sum);
    ui->check_sum_line_2->setText(QString::number(db.get_rank(stu.student_id,"SUM",a)));
}

stu_check_score_::~stu_check_score_()
{
    delete ui;
}
