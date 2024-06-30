#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QWidget>
#include "playscene.h"
#include"recordscene.h"
#include<QLCDNumber>

namespace Ui {
    class mainscene;
}

class mainscene : public QWidget {
    Q_OBJECT

public:
    explicit mainscene(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);


    playscene *plscene = NULL;
    recordscene *recscene = NULL;

    ~mainscene();

private:
    Ui::mainscene *ui;
};

#endif // MAINSCENE_H
