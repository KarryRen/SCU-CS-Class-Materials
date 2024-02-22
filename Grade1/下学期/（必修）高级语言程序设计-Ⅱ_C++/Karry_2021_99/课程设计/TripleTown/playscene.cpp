#include "playscene.h"
#include "ui_playscene.h"
#include"mypushbtn.h"
#include"myobject.h"
#include"dataconfig.h"
#include<QObject>
#include<QDebug>
#include<QtGlobal>
#include<QTime>
#include<QLabel>
#include<QMenuBar>
#include<QPainter>
#include<QTimer>
#include<QPropertyAnimation>
#include<QMessageBox>
#include<QFile>
#include<algorithm>
#include<QLCDNumber>

#define FILENAME "Record.txt"

//对数组排序 从大到小排序的规则
bool bigger(int x, int y) {
    return x > y;
}

playscene::playscene(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::playscene) {
    ui->setupUi(this);

    this->setWindowTitle("Triple Town");
    this->setWindowIcon(QPixmap(":/image/icon/icon.png"));

    //设置计分板
    ui->Record->move(900, 210);
    ui->Record->resize(200, 80);
    // 设置能显示的位数
    ui->Record->setDigitCount(7);
    // 设置显示的模式为十进制
    ui->Record->setMode(QLCDNumber::Dec);
    // 设置显示外观
    ui->Record->setSegmentStyle(QLCDNumber::Flat);
    // 设置样式
    ui->Record->setStyleSheet("border: 1px solid green; color: green; background: silver;");
    connect(this, &playscene::ScoreUp, [=]() {
        ui->Record->display(score);
    });

    //score 图片
    QLabel *RecordPix = new QLabel;
    QPixmap rpix;
    rpix.load(":/image/playscene/score.png");
    rpix = rpix.scaled(300, 150);
    RecordPix->setPixmap(rpix);
    RecordPix->resize(300, 150);
    RecordPix->setParent(this);
    RecordPix->move(860, 60);
    //best 图片
    QLabel *Bestpix = new QLabel;
    rpix.load(":/image/playscene/best.png");
    rpix = rpix.scaled(280, 140);
    Bestpix->setPixmap(rpix);
    Bestpix->resize(280, 140);
    Bestpix->setParent(this);
    Bestpix->move(860, 290);


    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    this->setFixedSize(1200, 900);
    //初始化地图
    config.spawnMap();
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            this->gameArray[i][j] = config.a[i][j];


    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j) {
            if (gameArray[i][j]) {
                a[i][j] = new myobject(i, j, 0, 0, gameArray[i][j], this);
            }
        }
    spawnA();
    score = 0;
    S = new QLabel;
    S->setParent(this);
    S->move(1000, 100);
    S->resize(50, 50);
    S->show();
//返回按钮
    ui->returnBtn->setFixedSize(QSize(250, 125));
    ui->returnBtn->setIcon(QIcon(":/image/playscene/return.png"));
    ui->returnBtn->setGeometry(this->width() - 325, this->height() - 150, 250, 125);
    ui->returnBtn->setIconSize(QSize(250, 125));
    ui->returnBtn->setFlat(true);
    ui->returnBtn->setStyleSheet("QPushButton{color:white; background-color:transparent;}");
    connect(ui->returnBtn, &QPushButton::clicked, [=]() {
//        if(QMessageBox::Yes==QMessageBox::question(this,"question","DO YOU WANT TO RETURN TO THE MAIN GAME INTERFACE？")){
        QTimer::singleShot(500, this, [=]() {
            emit
            this->PlaySenceBack();
        });
//        }
    });
    ui->returnBtn->setAttribute(Qt::WA_TouchPadAcceptSingleTouchEvents, true);
    ui->returnBtn->setFocusPolicy(Qt::NoFocus);
//重开按钮
    ui->restartBtn->setFixedSize(QSize(350, 175));
    ui->restartBtn->setIcon(QIcon(":/image/playscene/restart.png"));
    ui->restartBtn->setGeometry(this->width() - 365, this->height() - 280, 350, 175);
    ui->restartBtn->setIconSize(QSize(350, 175));
    ui->restartBtn->setFlat(true);
    ui->restartBtn->setAttribute(Qt::WA_TouchPadAcceptSingleTouchEvents, true);
    ui->restartBtn->setFocusPolicy(Qt::NoFocus);
    ui->restartBtn->setStyleSheet("QPushButton{color:white; background-color:transparent;}");

    connect(ui->restartBtn, &QPushButton::clicked, [=]() {
        if (QMessageBox::Yes == QMessageBox::question(this, "question", "Do you want to restart the game?")) {
            ui->gameover->hide();
            if (!isWin()) delete A;
            for (int i = 0; i < 6; ++i)
                for (int j = 0; j < 6; ++j) {
                    if (gameArray[i][j]) {
                        //qDebug() << i << " " << j;
                        delete a[i][j];
                        gameArray[i][j] = 0;
                    }
                }

            config.spawnMap();
            for (int i = 0; i < 6; ++i)
                for (int j = 0; j < 6; ++j)
                    this->gameArray[i][j] = config.a[i][j];
            for (int i = 0; i < 6; ++i)
                for (int j = 0; j < 6; ++j) {
                    if (gameArray[i][j]) {
                        a[i][j] = new myobject(i, j, 0, 0, gameArray[i][j], this);
                    }
                }
            spawnA();
            score = 0;
            ui->Record->display(0);
        }
    });

    //分数的读取
    // 1.File is not existed
    QFile f(FILENAME);
    if (!f.open(QIODevice::ReadOnly)) {
        qDebug() << "打开失败no" << endl;
        this->score_Num = 0;
        this->score_arry = NULL;
        f.close();
        return;
    }
    // 2.文件已经存在 并且记录数据
    int num = this->get_ScoreNum();
    this->score_Num = num;
    // 初始化数组
    this->init_Score();// 将文件里的数据存到数组中

    //显示最高分 如果是最高分了的话就直接跟着score走
    this->Best = new QLCDNumber;
    Best->setParent(this);
    Best->move(900, 430);
    Best->resize(200, 80);
    // 设置能显示的位数
    Best->setDigitCount(7);
    // 设置显示的模式为十进制
    Best->setMode(QLCDNumber::Dec);
    // 设置显示外观
    Best->setSegmentStyle(QLCDNumber::Flat);
    // 设置样式
    Best->setStyleSheet("border: 1px solid green; color: green; background: silver;");
    Best->display(this->score_arry[0]);
    connect(this, &playscene::ScoreUp, [=]() {
        if (this->score_arry[0] >= score) {
            Best->display(this->score_arry[0]);
        } else {
            Best->display(score);
        }
    });


    //显示gameover
    QPixmap game_over;
    game_over.load(":/image/playscene/game_over.png");
    game_over.scaled(ui->gameover->size(), Qt::KeepAspectRatio);//使图片大小随label的大小改变
    ui->gameover->setFixedSize(800, 200);
    ui->gameover->setGeometry(50, 300, 800, 200);
    ui->gameover->setScaledContents(true);
    ui->gameover->setPixmap(game_over);
    ui->gameover->hide();//将label隐藏起来
}

int scores[][8] =
        {{0, 5, 20, 100, 1000, 5000,  20000, 80000},
         {0, 5, 40, 200, 2000, 10000, 40000, 160000}};

int playscene::get_ScoreNum() {
    QFile f(FILENAME);
    f.open(QIODevice::ReadOnly | QIODevice::Text);

    int num = 0;
    while (!f.atEnd()) {
        QByteArray line = f.readLine();
        QString str(line);
        num++;
    }

    return num;
}

void playscene::init_Score() {
    this->score_arry = new int[1000];//开辟空间
    for (int i = 0; i < 5; i++) {
        score_arry[i] = 0;
    }
    QFile f(FILENAME);
    f.open(QIODevice::ReadOnly | QIODevice::Text);

    int index = 0;
    while (!f.atEnd()) {
        QByteArray line = f.readLine();
        QString str(line);
        this->score_arry[index] = atoi(str.toStdString().c_str());;
        index++;
    }
    f.close();
    std::sort(score_arry, score_arry + score_Num, bigger);
}

void playscene::saveScore() {
    this->score_arry[this->score_Num] = score;
    this->score_Num += 1;
    std::sort(score_arry, score_arry + score_Num, bigger);

    QString str;
    for (int i = 0; i < this->score_Num; i++) {
        str += QString::number(this->score_arry[i]) + "\t" + "\n";
    }
    QFile file(FILENAME);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "sdf", "can't open", QMessageBox::Yes);
    }
    QTextStream stream(&file);
    stream << str;

    file.close();
}

void playscene::updateScore(int bonus, int level) {
    score += scores[bonus][level];
    emit
    this->ScoreUp();
    qDebug() << score;
}

void playscene::spawnA() {
    //qDebug() << "AAAAA";
    int x = qrand() % 6, y = qrand() % 6;
    while (gameArray[x][y]) x = qrand() % 6, y = qrand() % 6;
    int lev = 0;
    int temp = rand() % 100 + 1;
    if (temp >= 90) lev = 3;
    else if (temp >= 60) lev = 2;
    else lev = 1;

//默认只生成等级1~3的物体 level1 60% level2 30% level3 10%

    A = new myobject(x, y, 1, 0, lev, this);
}

bool vis[6][6];
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};

int playscene::dfs(int x, int y, int lev, bool flg) {
    vis[x][y] = 1;
    int ret = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < 6 && ny >= 0 && ny < 6 && !vis[nx][ny]) {
            if (gameArray[nx][ny] == lev)
                ret += dfs(nx, ny, lev, flg);
        }
    }
    if (flg)     //清除可合成的同级物体，逻辑相同，不必另写函数
    {
        gameArray[x][y] = 0;
        delete a[x][y];
    }
    return ret;
}

bool playscene::compose(myobject *A) {
    memset(vis, 0, sizeof(vis));
    int x = A->x, y = A->y;
    int lev = A->level;
    int cnt = dfs(x, y, lev, 0);
    if (cnt < 3) return 0;
    memset(vis, 0, sizeof(vis));
    dfs(x, y, lev, 1);
    a[x][y] = new myobject(x, y, 0, cnt > 3, lev + 1, this);
    gameArray[x][y] = lev + 1;
    updateScore(cnt > 3, gameArray[x][y]);
    return 1;
}

bool playscene::isWin() {
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j)
            if (!gameArray[i][j]) return 0;
    return 1;
}

void playscene::Restart() {

}

void playscene::keyPressEvent(QKeyEvent *eve) {
    if (eve->key() == Qt::Key_Left) {
        A->change(-1, 0);
    }
    if (eve->key() == Qt::Key_Right) {
        A->change(1, 0);
    }
    if (eve->key() == Qt::Key_Up) {
        A->change(0, -1);
    }
    if (eve->key() == Qt::Key_Down) {
        A->change(0, 1);
    }
    if (eve->key() == Qt::Key_Space) {
        if (isWin()) return;
        //qDebug() << "Space!";
        if (gameArray[A->x][A->y]) return;
        updateScore(0, A->level);
        gameArray[A->x][A->y] = A->level;
        a[A->x][A->y] = new myobject(A->x, A->y, 0, 0, A->level, this);
        while (compose(a[A->x][A->y])) compose(a[A->x][A->y]);
        delete A;
        if (!isWin()) spawnA();
        else {
            ui->gameover->raise();//label显示在最上层
            ui->gameover->show();//将gameover展示出来
            this->saveScore();
        }
    }
}

void playscene::paintEvent(QPaintEvent *) {
    //创建背景
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/image/background/background.png");
    //                         和主场景宽匹配   和主场景高匹配
    painter.drawPixmap(0, 0, this->width(), this->height(), pix);

    //设置标题
    /*pix.load(":/image/background/hole1.png");
    pix = pix.scaled(pix.width(), pix.height());
    painter.drawPixmap(60, 50, pix);*/

    //画坑
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 6; ++j) {
            pix.load(":/image/background/hole1.png");
            pix = pix.scaled(pix.width() * 0.8, pix.height() * 0.8);
            //qDebug() << pix.width() << "  " << pix.height();
            painter.drawPixmap(50 + i * 120, 50 + j * 120, pix);
        }
}
