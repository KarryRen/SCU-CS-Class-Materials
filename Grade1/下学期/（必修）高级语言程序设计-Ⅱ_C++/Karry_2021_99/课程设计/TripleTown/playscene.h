#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QWidget>
#include<QKeyEvent>
#include"myobject.h"
#include"dataconfig.h"
#include<QLCDNumber>

namespace Ui {
    class playscene;
}

class playscene : public QWidget {
    Q_OBJECT
    friend class recordscene;

    friend class mainscene;

public:
    explicit playscene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

    void keyPressEvent(QKeyEvent *eve);

    void spawnA();         //生成物体
    bool compose(myobject *A);      //合成物体
    int dfs(int x, int y, int lev, bool flg); //查找函数

    bool isWin(); //判断是否胜利

    //对处理分数的函数
    QLCDNumber *Best;

    void updateScore(int bonus, int level); // 每放下一个物体都更新一次score
    int get_ScoreNum(); //与文件交互 获取文件里的分数个数
    void init_Score();  //将文件里的分数存到score数组里
    void saveScore(); //更新数组 并将新的数组读到文件里去

private:
    int gameArray[6][6];
    myobject *a[6][6], *A;      //*A：正在移动的物体

    dataconfig config;
    int score; //存储当下游戏里的最终分数
    int score_Num; //文件里读到的分数个数
    int *score_arry; //存储文件里读的score

    QLabel *S;

    Ui::playscene *ui;
    signals:
            void PlaySenceBack();//playscene 点击return 发出返回信号
    void ScoreUp();//playscene 发出分数上升信号

public
    slots:
            void Restart();
};

#endif // PLAYSCENE_H
