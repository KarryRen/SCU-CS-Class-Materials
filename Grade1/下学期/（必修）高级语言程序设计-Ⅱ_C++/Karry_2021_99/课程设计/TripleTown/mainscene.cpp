#include "mainscene.h"
#include "ui_mainscene.h"
#include"mypushbtn.h"
#include<QDebug>
#include<QPainter>
#include<QTimer>
#include<QMediaPlayer>
#include<QUrl>
#include<QPushButton>
#include<QMessageBox>
#include<QPropertyAnimation>

mainscene::mainscene(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::mainscene) {
    ui->setupUi(this);
    this->setWindowTitle("Triple Town");
    this->setFixedSize(1200, 900);

    QPixmap *tp = new QPixmap(":/image/icon/icon.png");
    tp->scaled(1000, 1000);
    this->setWindowIcon(*tp);

    QMediaPlayer *sound = new QMediaPlayer();     //加载音乐
    sound->setMedia(QUrl("qrc:/music/bgm_main.mp3"));
    sound->setVolume(10);
    sound->setPlaybackRate(100);
    sound->play();

    QMediaPlayer *play_sound = new QMediaPlayer();
    play_sound->setMedia(QUrl("qrc:/music/bgm_play.mp3"));
    play_sound->setPlaybackRate(100);
    play_sound->setVolume(10);

    plscene = new playscene;
    recscene = new recordscene;

    //开始按钮
    ui->startbtn->setFixedSize(QSize(280, 140));
    ui->startbtn->setIcon(QIcon(":/image/mainscene/start.png"));
    ui->startbtn->setGeometry(475, 680, 280, 140);
    ui->startbtn->setIconSize(QSize(280, 140));
    ui->startbtn->setFlat(true);
    ui->startbtn->setStyleSheet("QPushButton{color:white; background-color:transparent;}");

    connect(ui->startbtn, &QPushButton::clicked, [=]() {
        sound->stop();
        play_sound->play();

        qDebug() << "点击按钮" << endl;
        //延时进入下一步
        //进入到选择关卡的场景中
        QTimer::singleShot(200, this, [=]() {
            //先把mainscene隐藏掉 而不能关掉
            this->hide();
            //打开新的场景
            plscene->show();
        });
    });

    //查看 记录/排名 按钮
    ui->rankbtn->setFixedSize(QSize(160, 80));
    ui->rankbtn->setIcon(QIcon(":/image/mainscene/rank.png"));
    ui->rankbtn->setGeometry(285, 706, 160, 80);
    ui->rankbtn->setIconSize(QSize(160, 80));
    ui->rankbtn->setFlat(true);
    ui->rankbtn->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
    connect(ui->rankbtn, &QPushButton::clicked, [=]() {
        QTimer::singleShot(200, this, [=]() {
            this->hide();
            recscene->show();
            recscene->first->display(plscene->score_arry[0]);
            recscene->second->display(plscene->score_arry[1]);
            recscene->third->display(plscene->score_arry[2]);
            recscene->fourth->display(plscene->score_arry[3]);
            recscene->fifth->display(plscene->score_arry[4]);
        });
    });
    connect(recscene, &recordscene::clear, [=]() {
        plscene->init_Score();
        plscene->Best->display(plscene->score_arry[0]);
    });

//exit按钮
    ui->exitbtn->setFixedSize(QSize(200, 100));
    ui->exitbtn->setIcon(QIcon(":/image/mainscene/exit.png"));
    ui->exitbtn->setGeometry(750, 698, 200, 100);
    ui->exitbtn->setIconSize(QSize(200, 100));
    ui->exitbtn->setFlat(true);
    ui->exitbtn->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
    connect(ui->exitbtn, &QPushButton::clicked, [=]() {
        if (QMessageBox::Yes == QMessageBox::question(this, "question", "DO YOU WANT TO EXIT THE GAME?")) {
            QTimer::singleShot(200, this, [=]() {
                this->close();
            });
        }
    });

    connect(plscene, playscene::PlaySenceBack, [=]() {
        plscene->hide();
        sound->play();
        play_sound->stop();
        this->show();
    });
    connect(recscene, recordscene::RecordSenceBack, [=]() {
        recscene->hide();
        this->show();
    });

    //不能用键盘触发
    ui->startbtn->setAttribute(Qt::WA_TouchPadAcceptSingleTouchEvents, true);
    ui->startbtn->setFocusPolicy(Qt::NoFocus);
    ui->rankbtn->setAttribute(Qt::WA_TouchPadAcceptSingleTouchEvents, true);
    ui->rankbtn->setFocusPolicy(Qt::NoFocus);
    ui->exitbtn->setAttribute(Qt::WA_TouchPadAcceptSingleTouchEvents, true);
    ui->exitbtn->setFocusPolicy(Qt::NoFocus);

}

mainscene::~mainscene() {
    delete ui;
}

void mainscene::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/mainscene/background.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}


