#include "studentwindow.h"
#include "ui_studentwindow.h"

#include "stu_check_score_.h"
#include "stu_change_password_.h"
#include "total_score.h"

StudentWindow::StudentWindow(QString s,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentWindow)
{
    ui->setupUi(this);

    setFixedSize(800,600);

    stu=student(s);

    connect(ui->btn_student_check,&QPushButton::clicked,this,&StudentWindow::on_btn_student_check_clicked);//跳入查询成绩界面

    connect(ui->btn_student_revise_password,&QPushButton::clicked,this,&StudentWindow::on_btn_student_revise_password_clicked);//跳入重置密码界面

    connect(ui->btn_student_total_score,&QPushButton::clicked,this,&StudentWindow::on_btn_student_total_clicked);//跳入显示一分一段表界面

    connect(ui->btn_student_return,&QPushButton::clicked,this,&StudentWindow::close);//退出

}

void StudentWindow::on_btn_student_check_clicked()//跳入查询成绩界面
{
    stu_check_score_ *ch_st = new stu_check_score_(stu,this);
    ch_st->show();
}

void StudentWindow::on_btn_student_revise_password_clicked()//重置密码
{
    stu_change_password_ *ch_st = new stu_change_password_(stu,this);
    ch_st->show();
}

void StudentWindow::on_btn_student_total_clicked()//跳入显示一分一段表界面
{
    totalscore *to_st = new totalscore(stu.student_id);
    to_st->show();
}


StudentWindow::~StudentWindow()
{
    delete ui;
}
