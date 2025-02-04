#ifndef SCORE_DISTRIBUTION_H
#define SCORE_DISTRIBUTION_H

#include <QWidget>
#include<QtCharts>
#include"mysql_connect.h"
namespace Ui {
class score_distribution;
}

class score_distribution : public QWidget
{
    Q_OBJECT

public:
    explicit score_distribution(QString new_subject,QString new_student_id,bool student_call=1,QWidget *parent = nullptr);
    void initchart(QString subject);
    void create_distribution_chart(QString subject,QString student_id);
    QString student_id;
    QString subject;
    bool student=1;



    ~score_distribution();

private:
    Ui::score_distribution *ui;
private slots:
    void on_score_returnPressed();
    // void on_score_editingFinished();
    // void on_score_textChanged(const QString &arg1);
};

#endif // SCORE_DISTRIBUTION_H
