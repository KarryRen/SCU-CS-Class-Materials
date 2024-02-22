#ifndef LYRICWIDGET_H
#define LYRICWIDGET_H

#include <QWidget>
#include <QFile>
#include <QString>
#include <QTextCodec>
#include <QMap>
#include <QMediaPlaylist>
#include <QDir>
#include <QMapIterator>

namespace Ui {
    class LyricWidget;
}

class LyricWidget : public QWidget {
    Q_OBJECT

public:
    explicit LyricWidget(QWidget *parent = 0);

    ~LyricWidget();

    void slotShowCurrentLrc();

    void initlrc(const QString &fileName);// 初始化歌词
    void getTime(QString line);

    void showWord(int time);// 显示歌词

    void getHeader(const char *str, QString &des);

    void cleanmap();

private:
    Ui::LyricWidget *ui;
    QMap<int, QString> map;
    QString LrcPath = "D:\\Music\\";

public:
    QString musicName;
};

#endif // LYRICWIDGET_H
