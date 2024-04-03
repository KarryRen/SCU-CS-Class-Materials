#include "dataconfig.h"
#include <QDebug>
#include <QtGlobal>
#include<QTime>

const int initialN = 15;

bool mp[6][6];

dataconfig::dataconfig(QObject *parent) : QObject(parent) {
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));

}

void dataconfig::spawnMap() {
    memset(a, 0, sizeof(a));
    memset(mp, 0, sizeof(mp));
    for (int i = 0; i < initialN; ++i)    //随机initialN个格子生成物体
    {
        int x = qrand() % 6, y = qrand() % 6;
        while (mp[x][y] == true) {
            x = qrand() % 6, y = qrand() % 6;
        }
        mp[x][y] = true;
        int tp = qrand() % 100 + 1;
        if (tp <= 10) a[x][y] = -1;
        else {
            tp = qrand() % 100 + 1;     //按一定比例生成等级1~4的物体
            if (tp >= 90) a[x][y] = 4;
            else if (tp >= 70) a[x][y] = 3;
            else if (tp >= 25) a[x][y] = 2;
            else a[x][y] = 1;
        }
    }
}
