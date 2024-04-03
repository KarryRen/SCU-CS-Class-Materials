#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QKeyEvent>
#include <QLabel>

class myobject : public QObject {
    Q_OBJECT
public:
    explicit myobject(QObject *parent = nullptr);

    myobject(int nx, int ny, bool nput, int bonus, int lev, QWidget *p);

    ~myobject();
    //void mykeyPressEvent(QKeyEvent *eve);

    void change(int dx, int dy);

    //void putdown();
    int x, y;
    bool notput;        //是否已放置，只有未放置的才可以动（只有一个）
    int level;          //物体等级，相同的3个可以合成
    QLabel *item, *ground;        //item:图标  ground:小背景
    QMovie *movie;

private:

    signals:

public
    slots:
};

#endif // MYOBJECT_H
