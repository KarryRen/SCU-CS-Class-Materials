#include "recordscene.h"
#include "ui_recordscene.h"
#include "QTimer"
#include <QPainter>
#include <QLabel>
#include<QDebug>

#define FILENAME "Record.txt"

recordscene::recordscene(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::recordscene) {
    ui->setupUi(this);


    this->setWindowTitle("Triple Town");
    this->setFixedSize(900, 900);

    QPixmap *tp = new QPixmap(":/image/icon/icon.png");
    tp->scaled(1000, 1000);
    this->setWindowIcon(*tp);
    //画图
    //ranking
    QPixmap rpix;
    QLabel *Rankpix = new QLabel;
    rpix.load(":/image/recordscene/ranking_list.png");
    rpix = rpix.scaled(800, 150);
    Rankpix->setPixmap(rpix);
    Rankpix->resize(800, 150);
    Rankpix->setParent(this);
    Rankpix->move(55, 50);
    //first
    QLabel *Firstpix = new QLabel;
    rpix.load(":/image/recordscene/NO1.png");
    rpix = rpix.scaled(280, 140);
    Firstpix->setPixmap(rpix);
    Firstpix->resize(280, 140);
    Firstpix->setParent(this);
    Firstpix->move(130, 200);
    //second
    QLabel *Secondpix = new QLabel;
    rpix.load(":/image/recordscene/NO2.png");
    rpix = rpix.scaled(280, 140);
    Secondpix->setPixmap(rpix);
    Secondpix->resize(280, 140);
    Secondpix->setParent(this);
    Secondpix->move(130, 290);
    //third
    QLabel *Thirdpix = new QLabel;
    rpix.load(":/image/recordscene/NO3.png");
    rpix = rpix.scaled(280, 140);
    Thirdpix->setPixmap(rpix);
    Thirdpix->resize(280, 140);
    Thirdpix->setParent(this);
    Thirdpix->move(130, 380);
    //fourth
    QLabel *Fourthpix = new QLabel;
    rpix.load(":/image/recordscene/NO4.png");
    rpix = rpix.scaled(280, 140);
    Fourthpix->setPixmap(rpix);
    Fourthpix->resize(280, 140);
    Fourthpix->setParent(this);
    Fourthpix->move(130, 470);
    //fifth
    QLabel *Fifthpix = new QLabel;
    rpix.load(":/image/recordscene/NO5.png");
    rpix = rpix.scaled(280, 140);
    Fifthpix->setPixmap(rpix);
    Fifthpix->resize(280, 140);
    Fifthpix->setParent(this);
    Fifthpix->move(130, 560);

//设置lcd
    this->first = new QLCDNumber;
    this->second = new QLCDNumber;
    this->third = new QLCDNumber;
    this->fourth = new QLCDNumber;
    this->fifth = new QLCDNumber;
    setLCD(first);
    setLCD(second);
    setLCD(third);
    setLCD(fourth);
    setLCD(fifth);
    first->move(530, 235);
    second->move(530, 325);
    third->move(530, 415);
    fourth->move(530, 505);
    fifth->move(530, 595);

//返回按钮
    ui->returnbtn->setFixedSize(QSize(320, 160));
    ui->returnbtn->setIcon(QIcon(":/image/playscene/return.png"));
    ui->returnbtn->setGeometry(500, 700, 320, 160);
    ui->returnbtn->setIconSize(QSize(320, 160));
    ui->returnbtn->setFlat(true);
    ui->returnbtn->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
    connect(ui->returnbtn, &QPushButton::clicked, [=]() {
        QTimer::singleShot(500, this, [=]() {
            emit
            this->RecordSenceBack();
        });
    });
    ui->returnbtn->setAttribute(Qt::WA_TouchPadAcceptSingleTouchEvents, true);
    ui->returnbtn->setFocusPolicy(Qt::NoFocus);

//清空记录按钮
    ui->clearbtn->setFixedSize(QSize(250, 125));
    ui->clearbtn->setIcon(QIcon(":/image/recordscene/clear.png"));
    ui->clearbtn->setGeometry(140, 720, 250, 125);
    ui->clearbtn->setIconSize(QSize(250, 125));
    ui->clearbtn->setFlat(true);
    ui->clearbtn->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
    ui->clearbtn->setAttribute(Qt::WA_TouchPadAcceptSingleTouchEvents, true);
    ui->clearbtn->setFocusPolicy(Qt::NoFocus);
    plscene = new playscene;
    connect(ui->clearbtn, &QPushButton::clicked, [=] {
        delete[] plscene->score_arry;
        plscene->score_arry = NULL;
        this->fileClear();
        plscene->init_Score();

        qDebug() << "recordscene：" << plscene->score_arry[0];
        first->display(plscene->score_arry[0]);
        second->display(0);
        third->display(0);
        fourth->display(0);
        fifth->display(0);
        emit
        this->clear();
    });
}


void recordscene::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/background/background.png");
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);
}

void recordscene::setLCD(QLCDNumber *q) {
    q->setParent(this);
    q->resize(200, 80);
    // 设置能显示的位数
    q->setDigitCount(7);
    // 设置显示的模式为十进制
    q->setMode(QLCDNumber::Dec);
    // 设置显示外观
    q->setSegmentStyle(QLCDNumber::Flat);
    // 设置样式
    q->setStyleSheet("border: 1px solid green; color: green; background: silver;");
}

void recordscene::fileClear() {
    QFile file(FILENAME);
    file.open(QFile::WriteOnly | QFile::Truncate);
    file.close();
}

recordscene::~recordscene() {
    delete ui;
}
