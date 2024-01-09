#ifndef RECORDSCENE_H
#define RECORDSCENE_H

#include <QWidget>
#include"playscene.h"
#include<QListWidget>
#include<QLCDNumber>

namespace Ui {
    class recordscene;
}

class recordscene : public QWidget {
    Q_OBJECT
    friend class mainscene;
public:
    explicit recordscene(QWidget *parent = 0);

    playscene *plscene = NULL;

    void paintEvent(QPaintEvent *);

    ~recordscene();

    void setLCD(QLCDNumber *);

    QLCDNumber *first;
    QLCDNumber *second;
    QLCDNumber *third;
    QLCDNumber *fourth;
    QLCDNumber *fifth;

    void fileClear();


private:
    Ui::recordscene *ui;


    signals:
            void RecordSenceBack();//playscene 点击return 发出返回信号
    void clear();
};

#endif // RECORDSCENE_H
