#ifndef REVISE_SCORE_H
#define REVISE_SCORE_H

#include <QMainWindow>

namespace Ui {
class revise_score;
}

class revise_score : public QMainWindow
{
    Q_OBJECT

public:
    explicit revise_score(QWidget *parent = nullptr);
    ~revise_score();

private:
    Ui::revise_score *ui;
};

#endif // REVISE_SCORE_H
