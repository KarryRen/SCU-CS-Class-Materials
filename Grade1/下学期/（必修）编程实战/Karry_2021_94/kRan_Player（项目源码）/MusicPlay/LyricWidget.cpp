#include "LyricWidget.h"
#include "ui_LyricWidget.h"

LyricWidget::LyricWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::LyricWidget) {
    ui->setupUi(this);
}

LyricWidget::~LyricWidget() {
    delete ui;
}

void LyricWidget::slotShowCurrentLrc() {
    initlrc(musicName);
}

void LyricWidget::initlrc(const QString &fileName) {
    QString l;
    QFile file(LrcPath + fileName);

    if (file.exists()) {
        //qDebug("文件存在");
    } else {
        //qDebug("文件z不存在");
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        //qDebug() << "wrong open";
        return;
    }
    qDebug() << "open ok";

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    while (!file.atEnd()) {
        QString line = codec->toUnicode(file.readLine());
        QString s(line);
        if (s.length() < 4)
            continue;
        if (s.startsWith("[ti:")) {
            getHeader("[ti:", s);
            //歌手map的键值是 0
            map.insert(0, s);
            ui->topmusicname->setText("歌曲：" + s);
            continue;
        } else if (s.startsWith("[ar:")) {
            getHeader("[ar:", s);
            map.insert(1000, s);
            ui->singer->setText("歌手：" + s);
            continue;
        } else if (s.startsWith("[al:")) {
            getHeader("[al:", s);
            map.insert(2000, s);
            ui->album->setText("专辑：" + s);
            continue;
        } else if (s.startsWith("[by:")) {
            getHeader("[by:", s);
            ui->fromlab->setText("提供者：" + s);
            map.insert(3000, s);
            continue;
        } else {
            getTime(s);
        }
    }
    file.close();
}

// 获取lrc文件的每句的时间 存到map里面
void LyricWidget::getTime(QString line) {
    if (line.startsWith("[")) {
        //得到这句话末尾标号
        int index = line.indexOf("]");
        //得到中间得文字
        QString t = line.mid(1, index - 1);
        //得到歌词前面的时间戳
        QString mm = t.mid(0, 2);
        QString ss = t.mid(3, 2);
        int m = mm.toInt();
        int s = ss.toInt();
        //计算出时间
        int time = m * 60 * 1000 + s * 1000;

        t = line.mid(6, index - 6);
        index = t.lastIndexOf("]");
        if (index < 0) {
            map.insert(time, t);
        } else {
            t = t.mid(index + 1);
            map.insert(time, t);
            getTime(t);
        }
    }
}

void LyricWidget::getHeader(const char *str, QString &des) {
    des = des.remove(str);
    des = des.remove("]");
}

void LyricWidget::showWord(int time) {
    if (map.contains(time)) {
        ui->label->setText(map.value(time));
    }
}

void LyricWidget::cleanmap() {
    map.clear();
}

