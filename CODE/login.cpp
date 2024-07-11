﻿#include "login.h"
#include "ui_login.h"
#include <mysql_connect.h>
#include "change_password.h"
#include "managerwindow.h"
#include <QGraphicsDropShadowEffect>

login::login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::login)
{
    // 初始化UI界面
    ui->setupUi(this);

    //设置右侧图片
    QPixmap *pix = new QPixmap(":/Desktop/login_02.png");// 创建一个QPixmap对象，用于加载图片
    QSize sz = ui->label_image->size();// 用一个对象sz来获取label_image的大小
    ui->label_image->setPixmap(pix->scaled(sz));// 调整传入图片的大小到label_image的大小，并设置给label_image

    //设置阴影
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);// 创建一个阴影效果对象
    shadow->setOffset(-3, 0);// 设置阴影的偏移量
    shadow->setColor(QColor("#888888"));// 设置阴影的颜色为中等深度的灰色
    shadow->setBlurRadius(30);// 设置阴影的模糊半径
    ui->label_image->setGraphicsEffect(shadow);// 将阴影效果应用到label_image上

    connect(ui->btn_signin,&QPushButton::clicked,this,&login::on_btn_signin_clicked);//点击确认登录按钮

}

void login::on_btn_signin_clicked()//点击确认登录
{
    extern DB db;
    int res=INT_MIN;
    QString username, password;
    do{
        if(res==-1){
            QMessageBox::critical(this,"error","Please enter again.");
        }
        //从文本框读入姓名和密码
        username = ui->lineEdit_username->text();
        password = ui->lineEdit_password->text();
        res = db.login_check(username, password);
    }while(res==-1);
    if(res==3)//登陆成功并且是第一次登录，跳入修改密码界面
    {
        change_password *w3 = new change_password(this);
        w3->show();
    }
    if(res == 0)//登陆成功则进入管理员菜单界面
    {
        managerwindow *ma_on = new managerwindow(this);
        ma_on->show();
        this->close();
    }
    else if(res == 1){
        //进入学生界面
    }
    else if(res == 2){
        //进入老师界面
    }
}

login::~login()
{
    delete ui;
}
