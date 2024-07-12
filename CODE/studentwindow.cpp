#include "studentwindow.h"
#include "ui_studentwindow.h"

#include "check_score.h"
#include "change_password.h"
#include "total_score.h"

StudentWindow::StudentWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StudentWindow)
{
    ui->setupUi(this);

    connect(ui->btn_student_check,&QPushButton::clicked,this,&StudentWindow::on_btn_student_check_clicked);//跳入查询成绩界面

    connect(ui->btn_student_revise_password,&QPushButton::clicked,this,&StudentWindow::on_btn_student_revise_password_clicked);//跳入重置密码界面

    connect(ui->btn_student_total_score,&QPushButton::clicked,this,&StudentWindow::on_btn_student_total_clicked);//跳入显示一分一段表界面

    connect(ui->btn_student_return,&QPushButton::clicked,this,&StudentWindow::close);//退出

}

void StudentWindow::on_btn_student_check_clicked()//跳入查询成绩界面
{
    check_score *ch_st = new check_score(this);
    ch_st->show();
}

void StudentWindow::on_btn_student_revise_password_clicked()//重置密码
{
    change_password *ch_st = new change_password(this);
    ch_st->show();
}

void StudentWindow::on_btn_student_total_clicked()//跳入显示一分一段表界面
{
    total_score *to_st = new total_score(this);
    to_st->show();
}


StudentWindow::~StudentWindow()
{
    delete ui;
}
