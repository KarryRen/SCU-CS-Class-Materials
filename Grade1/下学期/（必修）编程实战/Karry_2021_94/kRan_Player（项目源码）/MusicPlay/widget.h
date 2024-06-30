#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QIcon>
#include <QTime>
#include <QFile>
#include <QSlider>
#include <QDir>
#include <QListWidget>
#include <QPainter>
#include "LyricWidget.h"


namespace Ui {
    class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();

private
    slots:
            QStringList getFileNames(
    const QString &path
    );//从文件里读取到歌曲名称
    void musicInfo();//初始化歌曲信息

    void on_lastBtn_clicked();//重载点击lastBtn的槽函数 实现目的功能
    void play_pause_music();//播放和停止播放的槽函数
    void on_nextBtn_clicked();//重载点击nextBtn的槽函数 实现目的功能
    void skipFirst(QMediaPlayer::State MusicState);//如果是最后一曲跳到第一首

    void volumChange(int position);//带参数的槽函数，实现多重方式来更改音乐音量
    void on_addBtn_clicked();//加音量
    void on_loseBtn_clicked();//减音量

    void setPlayerPosition(int position);//改变音乐播放进度
    void positionChanged(qint64 position);//改变进度条位置，同时改变时间
    void durationChanged(qint64 duration);//改变总时间 初始化进度条长度

    void play_list_music(int index);//点击列表里的音乐名字实现音乐播放
    void addItem(QString name);//列表添加歌曲
    void on_pushButton_clicked();//刷新按钮的方法

    void paintEvent(QPaintEvent *);

private:
    Ui::Widget *ui;
    bool isPlay;
    bool isSilence;

    QStringList fileList;
    QString MusicPath = "D:\\Music\\";
    QMediaPlayer *player;
    QMediaPlaylist *playerlist;
    int Vposition;//进度位置
    int MusicCurrent;//当前播放的歌曲下标

    QTime *currentTime;
    QTime *totalTime;

    LyricWidget *lrc;
    int time;
    QString musicLrcName;
    QString authorLrcName;

};

#endif // WIDGET_H
