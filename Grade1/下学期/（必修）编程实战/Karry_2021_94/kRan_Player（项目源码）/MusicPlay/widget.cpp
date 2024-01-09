#include "widget.h"
#include "ui_widget.h"
#include<QMediaMetaData>

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget) {
    ui->setupUi(this);

    //重设窗口大小
    this->setFixedSize(1000, 1000);
    this->setWindowIcon(QIcon(":/image/icon.JPG"));
    this->setWindowTitle("kRan_Player");

    isPlay = true;
    isSilence = false;

    lrc = new LyricWidget(this);
    lrc->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
    lrc->move(350, 100);
    lrc->show();

    ui->startBtn->setIcon(QIcon(":/image/PlayMusic.png"));// 暂停时候显示播放图标
    ui->startBtn->setIconSize(QSize(50, 50));
    ui->startBtn->setFlat(true);
    ui->startBtn->setStyleSheet(
            "QToolTip{border:1px solid rgb(0, 0, 0); background-color: #ffffff; color:#484848; font-size:12px;}");
    ui->startBtn->setToolTip(tr("播放"));// 鼠标停留时显示播放文字

    ui->lastBtn->setIcon(QIcon(":/image/circle_previous.png"));// 显示上一曲图标
    ui->lastBtn->setIconSize(QSize(50, 50));
    ui->lastBtn->setFlat(true);
    ui->lastBtn->setStyleSheet(
            "QToolTip{border:1px solid rgb(0, 0, 0); background-color: #ffffff; color:#484848; font-size:12px;}");
    ui->lastBtn->setToolTip(tr("上一曲"));// 鼠标停留时显示上一曲文字

    ui->nextBtn->setIcon(QIcon(":/image/circle_next.png"));// 显示下一曲图标
    ui->nextBtn->setIconSize(QSize(50, 50));
    ui->nextBtn->setFlat(true);
    ui->nextBtn->setStyleSheet(
            "QToolTip{border:1px solid rgb(0, 0, 0); background-color: #ffffff; color:#484848; font-size:12px;}");
    ui->nextBtn->setToolTip(tr("下一曲"));// 鼠标停留时显示下一曲文字

    ui->addBtn->setIcon(QIcon(":/image/addIcon.png"));// 显示加大音量图标
    ui->addBtn->setIconSize(QSize(30, 30));
    ui->addBtn->setFlat(true);
    ui->addBtn->setStyleSheet(
            "QToolTip{border:1px solid rgb(0, 0, 0); background-color: #ffffff; color:#484848; font-size:12px;}");
    ui->addBtn->setToolTip(tr("加大音量"));// 鼠标停留时显示加大音量文字

    ui->loseBtn->setIcon(QIcon(":/image/loseIcon.png"));// 显示减小音量图标
    ui->loseBtn->setIconSize(QSize(30, 30));
    ui->loseBtn->setFlat(true);
    ui->loseBtn->setStyleSheet(
            "QToolTip{border:1px solid rgb(0, 0, 0); background-color: #ffffff; color:#484848; font-size:12px;}");
    ui->loseBtn->setToolTip(tr("减小音量"));// 鼠标停留时显示减小音量文字

    fileList = getFileNames(this->MusicPath);

    QImage *img = new QImage;
    img->load(":/image/soundOn.png");
    *img = img->scaled(40, 40, Qt::KeepAspectRatio);
    ui->label->setPixmap(QPixmap::fromImage(*img));

    player = new QMediaPlayer;
    playerlist = new QMediaPlaylist(player);

    ui->strTime->setText("00:00");

    ui->volumeSlider->setRange(0, 100);
    ui->volumeSpinBox->setRange(0, 100);

    ui->volumeSlider->setValue(5);
    ui->volumeSpinBox->setValue(5);
    player->setVolume(5);
    Vposition = 5;

    for (int i = 0; i < fileList.size(); i++) {
        QString fileName = fileList.at(i);
        playerlist->addMedia(QUrl::fromLocalFile(MusicPath + "\\" + fileName));
    }

    playerlist->setCurrentIndex(0);
    player->setPlaylist(playerlist);

    //调声音控件结合
    connect(ui->volumeSlider, SIGNAL(valueChanged(int)), ui->volumeSpinBox, SLOT(setValue(int)));
    connect(ui->volumeSpinBox, SIGNAL(valueChanged(int)), ui->volumeSlider, SLOT(setValue(int)));
    //声音组件的调节和player的声音相结合
    connect(ui->volumeSlider, SIGNAL(valueChanged(int)), this, SLOT(volumChange(int)));
    connect(ui->volumeSpinBox, SIGNAL(valueChanged(int)), this, SLOT(volumChange(int)));

    //开始键点击后 进行音乐播放或停止
    connect(ui->startBtn, SIGNAL(clicked(bool)), this, SLOT(play_pause_music()));

    // 切换歌曲的同时改变歌曲名和歌曲图片
    connect(player, SIGNAL(metaDataChanged()), this, SLOT(musicInfo()));

    connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(play_list_music(int)));

    //进度条改变时播放位置随着改变
    connect(ui->progressBar, SIGNAL(sliderMoved(int)), this, SLOT(setPlayerPosition(int)));

    //当播放歌曲位置改变时progressBar设置对应的位置 对应的播放时间与总时间的显示
    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    //歌曲总时间改变了 进度条显示总时间改变
    connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(durationChanged(qint64)));

    //换歌曲或者歌曲播放改变歌词
    connect(player, &QMediaPlayer::currentMediaChanged, lrc, &LyricWidget::slotShowCurrentLrc);

    //每次切歌后清除之前的map
    connect(player, &QMediaPlayer::currentMediaChanged, lrc, &LyricWidget::cleanmap);

    connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(skipFirst(QMediaPlayer::State)));
}


Widget::~Widget() {
    delete ui;
}

void Widget::skipFirst(QMediaPlayer::State MusicState) {
    //当歌曲播放到最后一首结束时，跳到第一首
    if (MusicState == QMediaPlayer::StoppedState) {
        MusicCurrent = 0;
        //设置当前的currentIndex
        playerlist->setCurrentIndex(MusicCurrent);
        isPlay = true;
        play_pause_music();
        return;
    }
}

void Widget::on_lastBtn_clicked() {
    //播放列表为空，按钮不可用，直接返回
    if (playerlist->isEmpty())
        return;

    int MusicCount = playerlist->mediaCount();
    int MusicCurrent = playerlist->currentIndex();

    //如果是第一首歌就返回播放最后一首
    if (MusicCurrent == 0) {
        playerlist->setCurrentIndex(MusicCount - 1);
        isPlay = true;
        play_pause_music();
        return;
    }

    playerlist->previous();
    isPlay = true;
    play_pause_music();
}

void Widget::on_nextBtn_clicked() {
    //如果播放列表为空，按钮不可用，直接返回
    if (playerlist->isEmpty())
        return;

    //如果列表到尽头，则回到列表开头
    int MusicCurrent = playerlist->currentIndex();
    if (++MusicCurrent == playerlist->mediaCount()) {
        MusicCurrent = 0;
        //设置当前的currentIndex
        playerlist->setCurrentIndex(MusicCurrent);
        isPlay = true;
        play_pause_music();
        return;
    }
    playerlist->next();
    isPlay = true;
    play_pause_music();
}

void Widget::play_pause_music() {
    //如果播放列表为空，按钮不可用，直接返回
    if (playerlist->isEmpty())
        return;

    if (isPlay) {
        player->play();
        ui->startBtn->setIcon(QIcon(":/image/pause.png"));// 播放时候显示暂停图标
        ui->startBtn->setIconSize(QSize(50, 50));
        ui->startBtn->setFlat(true);
        ui->startBtn->setStyleSheet(
                "QToolTip{border:1px solid rgb(0, 0, 0); background-color: #ffffff; color:#484848; font-size:12px;}");
        ui->startBtn->setToolTip(tr("暂停"));
    } else {
        player->pause();
        ui->startBtn->setIcon(QIcon(":/image/PlayMusic.png"));// 暂停时候显示播放图标
        ui->startBtn->setIconSize(QSize(50, 50));
        ui->startBtn->setFlat(true);
        ui->startBtn->setStyleSheet(
                "QToolTip{border:1px solid rgb(0, 0, 0); background-color: #ffffff; color:#484848; font-size:12px;}");
        ui->startBtn->setToolTip(tr("播放"));
    }
    isPlay = !isPlay;
}

void Widget::musicInfo() {
    MusicCurrent = playerlist->currentIndex();
    QString musicName = fileList[MusicCurrent];
    QString authorName = player->metaData("Author").toString().toUtf8().data();
    // 设置歌曲名
    ui->nameLab->setText("歌曲名： " + musicName);
    if (!(musicName == "")) {
        musicLrcName = musicName;
        authorLrcName = authorName;
    }

    // 显示歌曲的图片
    // 查找歌曲图片信息并提取
    QImage picImage = player->metaData(QStringLiteral("ThumbnailImage")).value<QImage>();
    if (picImage.isNull()) {
        picImage = QImage(":/image/non-music.png");
    }
    ui->imageLab->setPixmap(QPixmap::fromImage(picImage));
    ui->imageLab->setScaledContents(true);

    // 设置lrc子窗口 歌词文件的路径
    lrc->musicName = musicLrcName + ".txt";
    lrc->slotShowCurrentLrc();
}

void Widget::volumChange(int position) {
    Vposition = position;
    player->setVolume(position);
    if (position == 0) {
        QImage *img = new QImage;
        img->load(":/image/volumeMuted.png");
        *img = img->scaled(40, 40, Qt::KeepAspectRatio);
        ui->label->setPixmap(QPixmap::fromImage(*img));
    } else {
        QImage *img = new QImage;
        img->load(":/image/soundOn.png");
        *img = img->scaled(40, 40, Qt::KeepAspectRatio);
        ui->label->setPixmap(QPixmap::fromImage(*img));

    }
}

// 当进度条改变时，设置歌曲对应的播放位置
void Widget::setPlayerPosition(int position) {
    player->setPosition(position);
}


// 当播放歌曲位置改变时，progressBar设置对应的位置、对应的播放时间与总时间的显示
void Widget::positionChanged(qint64 position)//
{
    ui->progressBar->setValue(position);//position 单位：毫秒 1000ms=1s

    currentTime = new QTime(0, (position / 60000) % 60, (position / 1000) % 60);//构造当前时间（小时,分钟,秒和毫秒）
    QString t = currentTime->toString("mm:ss");
    ui->strTime->setText(currentTime->toString("mm:ss"));//播放时间   输出时间格式09:02（都是两位）

    QString mm = t.mid(0, 2);
    QString ss = t.mid(3, 2);
    int m = mm.toInt();
    int s = ss.toInt();
    time = m * 60 * 1000 + s * 1000;
    lrc->showWord(time);
}

// 当progressBar改变时，构造歌曲总时间
void Widget::durationChanged(qint64 duration) {
    ui->progressBar->setRange(0, duration);// progressBar的范围从0到duration（总时间）
    totalTime = new QTime(0, (duration / 60000) % 60, (duration / 1000) % 60);
    ui->endTime->setText(totalTime->toString("mm:ss"));//歌曲总时间
}

QStringList Widget::getFileNames(const QString &path) {
    QDir dir(path);
    QStringList nameFilters;
    nameFilters << "*.mp3";
    QStringList files = dir.entryList(nameFilters, QDir::Files | QDir::Readable, QDir::Name);
    qDebug() << files;
    return files;
}

void Widget::on_addBtn_clicked() {
    Vposition += 1;
    if (Vposition > 100) {
        Vposition = 100;
    }
    volumChange(Vposition);
    ui->volumeSpinBox->setValue(Vposition);
    ui->volumeSlider->setValue(Vposition);
}

void Widget::on_loseBtn_clicked() {
    Vposition -= 1;
    if (Vposition < 0) {
        Vposition = 0;
    }
    volumChange(Vposition);
    ui->volumeSpinBox->setValue(Vposition);
    ui->volumeSlider->setValue(Vposition);
}

void Widget::addItem(QString name) {
    QListWidgetItem *item = new QListWidgetItem;
    item->setText(name);
    if (name != NULL) {
        ui->listWidget->addItem(item);
    }
}

void Widget::play_list_music(int index) {
    playerlist->setCurrentIndex(index);
    isPlay = true;
    play_pause_music();
}


void Widget::on_pushButton_clicked() {
    playerlist->clear();
    ui->listWidget->clear();
    fileList = getFileNames(this->MusicPath);
    for (int i = 0; i < fileList.size(); i++) {
        QString fileName = fileList.at(i);
        addItem(fileName);
        playerlist->addMedia(QUrl::fromLocalFile(MusicPath + "\\" + fileName));
    }
    playerlist->setCurrentIndex(0);
    isPlay = false;
    play_pause_music();
}

void Widget::paintEvent(QPaintEvent *) {
    QPainter myPainter(this);
    myPainter.setOpacity(0.9);
    myPainter.drawPixmap(0, 0, this->width(), this->height(), QPixmap(":/image/bg1.jpg"));
}
