#include <QApplication>
#include"mysql_connect.h"
#include "signin.h"
#include"managerwindow.h"
//DB db;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // signin w1;
    // w1.show();//显示登录界面
    managerwindow m1;
    m1.show();
    return a.exec();
}
