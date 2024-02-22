#include "myobject.h"
#include<QDebug>
#include<QMovie>
#include<QPainter>

myobject::myobject(int nx, int ny, bool nput, int bonus, int lev, QWidget *p) {
    item = new QLabel;
    x = nx, y = ny;
    notput = nput;
    level = lev;
    QString str;
    if (nput == true) {
        str = QString(":/image/_objects/_level0%1.gif").arg(lev);
        movie = new QMovie(str);
        movie->setScaledSize(QSize(150, 130));
        item->setParent(p);
        item->setMovie(movie);
        movie->start();
    } else {
        QPixmap tp;
        if (level == -1) str = QString(":/image/objects/rock.png");
        else str = QString(":/image/objects/level%1%2.png").arg(bonus).arg(lev);
        tp.load(str);
        tp = tp.scaled(142, 124);
        item->setParent(p);
        item->setPixmap(tp);

        ground = new QLabel;
        tp.load(":/image/background/_background.png");
        tp = tp.scaled(120, 120);
        ground->setParent(p);
        ground->setPixmap(tp);
        ground->move(56 + x * 120, 51 + y * 120);
        ground->show();
        ground->lower();
    }
    item->move(50 + x * 120, 50 + y * 120);
    item->show();
}

myobject::~myobject() {
    delete item;
    if (notput) delete movie;
    else delete ground;
}

void myobject::change(int dx, int dy) {
    int tx = x + dx, ty = y + dy;
    if (tx >= 0 && tx < 6 && ty >= 0 && ty < 6) {
        x = tx, y = ty;
        item->move(50 + x * 120, 50 + y * 120);
    }

}

/*void myobject::putdown()
{
    QPixmap tp;
    tp.load(QString(":/image/objects/level0%1.png").arg(level));
    tp = tp.scaled(156, 138);
    item->setPixmap(tp);
}*/
