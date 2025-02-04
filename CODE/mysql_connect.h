﻿#ifndef MYSQL_CONNECT_H
#define MYSQL_CONNECT_H

#include <QSql>

#include <QSqlQueryModel>

#include <QSqlDatabase>

#include <QSqlQuery>

#include<QMessageBox>

#include<QSqlError>


#include<QString>

#include<QSqlRecord>

#include <QMessageBox>

#include <QSqlError>

#include <utility>
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
#include <vector>

typedef std::vector<QPair<QString,int>> VP;
//用于初始化连接云数据库 失败时返回Null。


//数据库字段说明： SUM为总分 CME为语数外总分 PCB为理综总分
class DB{
private:
    QSqlDatabase db;
    QSqlDatabase Init();

public:
    DB();

    ~DB();

    //检查是否有重复的数据库连接,如有则删
    void connection_check();

    //登录检查
    int login_check(QString username, QString password);//返回登陆账户的identity(int)：0表示管理员 1表示学生 2表示老师 -1表示错误 3表示新用户

    //密码修改
    bool revise_password(QString username,QString new_password);

    //返回某学生的单科成绩

    int get_single_score(QString student_id,QString subject);

    //将一个学生的科目和成绩保存在一个pair的vector数组中返回

    VP get_all_score(QString student_id);

    //修改某个学生某科目的成绩

    bool update_score(QString student_id,QString subject,int new_score);

    //将excel文件上传到数据库，批量上传可用for循环-待实现

    bool upload_score(QString file_path);

    //批量获取学生的单科成绩，保存在pair类型的vector中返回
    void get_students_scores(QString start_student_id,QString end_student_id,QString subject,std::vector<int>& scores);

    //删除某个学生
    bool delete_student(QString student_id);

    //添加学生信息
    bool add_score(QString student_id, QString student_name, VP subject_scores);

    //获取各科排名 总分用SUM替代
    int get_rank(QString student_id,QString subject,int& delta);

    //获取所有学生的一分一段数据 使用应用返回结果 类型QMap<int,int> 总分用SUM表示
    void get_all_ranks(QString subject,QMap<int,int> &scoreDistribution);

    void get_ranks(QString subject,int rank[751]);
};

#endif // MYSQL_CONNECT_H



