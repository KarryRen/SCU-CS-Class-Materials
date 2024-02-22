#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
//#include <QVector>

class dataconfig : public QObject {
    Q_OBJECT
public:
    explicit dataconfig(QObject *parent = nullptr);

    void spawnMap();

    int a[6][6];
    signals:

public
    slots:
};

#endif // DATACONFIG_H
