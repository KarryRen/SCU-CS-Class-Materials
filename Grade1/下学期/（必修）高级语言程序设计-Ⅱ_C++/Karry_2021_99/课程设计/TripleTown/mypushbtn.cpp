#include "mypushbtn.h"
#include<QDebug>
#include<QPropertyAnimation>

mypushbtn::mypushbtn(QString NormalImg, QString PressImg) {

    this->NormalImgPath = NormalImg;
    this->PressImgPath = PressImg;

    QPixmap pix;
    bool ret = pix.load(NormalImg);
    if (!ret) {
        qDebug() << "加载图片失败" << endl;
        return;
    }

    //设置图片固定大小 设置框的大小
    this->setFixedSize(pix.width(), pix.height());

    //设置不规则图片样式
    this->setStyleSheet("QPushButton{border:0px;}");

    //设置图标
    this->setIcon(pix);

    //设置图片在框里面的大小
    this->setIconSize(QSize(100, 100));
}

void mypushbtn::zoom1() {
    //创建动态对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(), this->y(), this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();
}

void mypushbtn::zoom2() {
    //创建动态对象
    QPropertyAnimation *animation = new QPropertyAnimation(this, "geometry");
    //设置动画时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(), this->y() + 10, this->width(), this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(), this->y(), this->width(), this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();
}

//选择关卡切换按钮的动画
void mypushbtn::mousePressEvent(QMouseEvent *e) {
    if (this->PressImgPath != "")//传入的按下图片不为空 说明为按下状态需要切换
    {
        QPixmap pix;
        bool ret = pix.load(this->PressImgPath);
        if (!ret) {
            qDebug() << "加载图片失败" << endl;
            return;
        }

        //设置图片固定大小 设置框的大小
        this->setFixedSize(pix.width(), pix.height());

        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pix);

        //设置图片在框里面的大小
        this->setIconSize(QSize(100, 100));
    }

    //让父类执行其他内容
    return QPushButton::mousePressEvent(e);
}

void mypushbtn::mouseReleaseEvent(QMouseEvent *e) {
    if (this->PressImgPath != "")//传入的按下图片不为空 说明为按下状态需要切换
    {
        QPixmap pix;
        bool ret = pix.load(this->NormalImgPath);
        if (!ret) {
            qDebug() << "加载图片失败" << endl;
            return;
        }

        //设置图片固定大小 设置框的大小
        this->setFixedSize(pix.width(), pix.height());

        //设置不规则图片样式
        this->setStyleSheet("QPushButton{border:0px;}");

        //设置图标
        this->setIcon(pix);

        //设置图片在框里面的大小
        this->setIconSize(QSize(100, 100));
    }

    //让父类执行其他内容
    return QPushButton::mouseReleaseEvent(e);
}
