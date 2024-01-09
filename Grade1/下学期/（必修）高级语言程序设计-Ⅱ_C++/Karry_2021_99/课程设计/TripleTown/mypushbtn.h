#ifndef MYPUSHBTN_H
#define MYPUSHBTN_H

#include<QString>
#include<QWidget>
#include<QPushButton>

class mypushbtn : public QPushButton {
    Q_OBJECT
public:
    mypushbtn() {}

    mypushbtn(QString NormalImg, QString PressImg = "");

    QString NormalImgPath;
    QString PressImgPath;

    //设置弹跳动画
    void zoom1();//向上跳
    void zoom2();//向下跳

    //重写按钮 按下和释放事件
    void mousePressEvent(QMouseEvent *e);

    void mouseReleaseEvent(QMouseEvent *e);

    signals:

public
    slots:
};

#endif // MYPUSHBTN_H
