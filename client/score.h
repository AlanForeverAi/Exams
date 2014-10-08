#ifndef SCORE_H
#define SCORE_H

#include <QWidget>
#include "ui_Score.h"
#include "data.h"
class Score : public QWidget,public Ui::Score
{
    Q_OBJECT
public:
    explicit Score(QWidget *parent = 0);

signals:

public slots:
    void showScore(QList<Combo>);
};

#endif // SCORE_H
