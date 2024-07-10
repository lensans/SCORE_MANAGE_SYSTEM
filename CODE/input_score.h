﻿#ifndef INPUT_SCORE_H
#define INPUT_SCORE_H

#include <QMainWindow>
#include <QObject>

namespace Ui {
class Input_score;
}

class Input_score : public QMainWindow
{
    Q_OBJECT

public:
    explicit Input_score(QWidget *parent = nullptr);

    void on_btn_single_return_clicked();//点击单个导入界面的返回按钮
    void on_btn_excel_return_clicked();//点击EXCEL导入界面的返回按钮
    void on_input_single_confirm_clicked();//点击单个导入界面的确认导入按钮

    ~Input_score();

public slots:
    void contextMenuEvent(QContextMenuEvent *event) override;
    void on_btn_excel_return_clicked();
    void on_btn_single_return_clicked();
    void on_input_single_confirm_clicked();

private:
    Ui::Input_score *ui;
};

#endif // INPUT_SCORE_H
