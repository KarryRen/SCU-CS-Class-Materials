/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget {
public:
    QGroupBox *groupBox1;
    QPushButton *startBtn;
    QPushButton *nextBtn;
    QSpinBox *volumeSpinBox;
    QLabel *nameLab;
    QLabel *strTime;
    QPushButton *lastBtn;
    QLabel *label;
    QLabel *imageLab;
    QSlider *volumeSlider;
    QLabel *endTime;
    QSlider *progressBar;
    QPushButton *addBtn;
    QPushButton *loseBtn;
    QLabel *label_3;
    QGroupBox *groupBox;
    QListWidget *listWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *Widget) {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1000, 1000);
        Widget->setMaximumSize(QSize(2000, 2000));
        Widget->setStyleSheet(QStringLiteral(""));
        groupBox1 = new QGroupBox(Widget);
        groupBox1->setObjectName(QStringLiteral("groupBox1"));
        groupBox1->setGeometry(QRect(40, 670, 931, 221));
        groupBox1->setStyleSheet(QLatin1String("background-color: rgb(225, 225, 225);\n"
                                               "border-radius:15px\n"
                                               ""));
        startBtn = new QPushButton(groupBox1);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setGeometry(QRect(420, 60, 61, 51));
        startBtn->setStyleSheet(QStringLiteral(""));
        nextBtn = new QPushButton(groupBox1);
        nextBtn->setObjectName(QStringLiteral("nextBtn"));
        nextBtn->setGeometry(QRect(530, 60, 61, 51));
        nextBtn->setStyleSheet(QStringLiteral(""));
        volumeSpinBox = new QSpinBox(groupBox1);
        volumeSpinBox->setObjectName(QStringLiteral("volumeSpinBox"));
        volumeSpinBox->setGeometry(QRect(830, 90, 61, 41));
        volumeSpinBox->setStyleSheet(QLatin1String("QSpinBox {\n"
                                                   "border:1px solid rgb(123, 169, 255);\n"
                                                   "background:white\n"
                                                   "}\n"
                                                   "\n"
                                                   "QSpinBox::up-button {\n"
                                                   "border-image:url(:/image/up_arrow.png)\n"
                                                   "}\n"
                                                   "\n"
                                                   "QSpinBox::down-button {\n"
                                                   "border-image:url(:/image/down_arrow.png)\n"
                                                   "}\n"
                                                   "\n"
                                                   "QSpinBox::up-button:pressed {\n"
                                                   "margin-top:3px;\n"
                                                   "}\n"
                                                   "\n"
                                                   "QSpinBox::down-button:pressed {\n"
                                                   "margin-bottom:3px;\n"
                                                   "}"));
        nameLab = new QLabel(groupBox1);
        nameLab->setObjectName(QStringLiteral("nameLab"));
        nameLab->setGeometry(QRect(30, 0, 601, 51));
        nameLab->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";\n"
                                                 "color: rgb(0, 0, 0);"));
        strTime = new QLabel(groupBox1);
        strTime->setObjectName(QStringLiteral("strTime"));
        strTime->setGeometry(QRect(160, 140, 71, 21));
        lastBtn = new QPushButton(groupBox1);
        lastBtn->setObjectName(QStringLiteral("lastBtn"));
        lastBtn->setGeometry(QRect(310, 60, 61, 51));
        lastBtn->setStyleSheet(QStringLiteral(""));
        label = new QLabel(groupBox1);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(750, 70, 51, 41));
        imageLab = new QLabel(groupBox1);
        imageLab->setObjectName(QStringLiteral("imageLab"));
        imageLab->setGeometry(QRect(20, 50, 121, 111));
        imageLab->setStyleSheet(QLatin1String("border:1px solid white;\n"
                                              "border-radius:0px"));
        volumeSlider = new QSlider(groupBox1);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setGeometry(QRect(810, 60, 21, 71));
        volumeSlider->setStyleSheet(QLatin1String("QSlider\n"
                                                  "{\n"
                                                  "    border-color: #cbcbcb;\n"
                                                  "}\n"
                                                  "QSlider::groove:vertical\n"
                                                  "{\n"
                                                  "    background: #cbcbcb;\n"
                                                  "    width: 6px;\n"
                                                  "    border-radius: 1px;\n"
                                                  "    padding-left:-1px;\n"
                                                  "    padding-right:-1px;\n"
                                                  "    padding-top:-1px;\n"
                                                  "    padding-bottom:-1px;\n"
                                                  "}\n"
                                                  "QSlider::sub-page:vertical\n"
                                                  "{\n"
                                                  "    background: #cbcbcb;\n"
                                                  "    border-radius: 2px;\n"
                                                  "}\n"
                                                  "QSlider::add-page:vertical\n"
                                                  "{\n"
                                                  "    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #439cf4, stop:1 #439cf4);\n"
                                                  "    background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1, stop: 0 #439cf4, stop: 1 #439cf4);\n"
                                                  "    width: 10px;\n"
                                                  "    border-radius: 2px;\n"
                                                  "}\n"
                                                  "QSlider::handle:vertical   \n"
                                                  "{                                \n"
                                                  "    border-image: url(:/image/volumeHandle.png);\n"
                                                  "    margin: -2px -7px -2px -7px; \n"
                                                  "    height: 17px;\n"
                                                  "} "));
        volumeSlider->setOrientation(Qt::Vertical);
        endTime = new QLabel(groupBox1);
        endTime->setObjectName(QStringLiteral("endTime"));
        endTime->setGeometry(QRect(660, 140, 91, 21));
        progressBar = new QSlider(groupBox1);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(260, 140, 361, 22));
        progressBar->setStyleSheet(QLatin1String("QSlider{\n"
                                                 "border-color: #bcbcbc;\n"
                                                 "}\n"
                                                 "QSlider::groove:horizontal {                                \n"
                                                 "     border: 1px solid #999999;                             \n"
                                                 "     height: 1px;                                           \n"
                                                 "    margin: 0px 0;                                         \n"
                                                 "     left: 5px; right: 5px; \n"
                                                 " } \n"
                                                 "QSlider::handle:horizontal {                               \n"
                                                 "     border: 0px ;                           \n"
                                                 "     border-image:  url(:/image/blur.png);\n"
                                                 "     width: 15px;                                           \n"
                                                 "     margin: -7px -7px -7px -7px;                  \n"
                                                 "} \n"
                                                 "QSlider::add-page:horizontal{\n"
                                                 "background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #bcbcbc, stop:0.25 #bcbcbc, stop:0.5 #bcbcbc, stop:1 #bcbcbc); \n"
                                                 "\n"
                                                 "}\n"
                                                 "QSlider::sub-page:horizontal{                               \n"
                                                 " background: qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 #439cf3, stop:0.25 #439cf3, stop:0.5 #439cf3, stop:1 #439cf3);       "
                                                 "              \n"
                                                 "}"));
        progressBar->setOrientation(Qt::Horizontal);
        addBtn = new QPushButton(groupBox1);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(800, 20, 41, 31));
        addBtn->setStyleSheet(QStringLiteral(""));
        loseBtn = new QPushButton(groupBox1);
        loseBtn->setObjectName(QStringLiteral("loseBtn"));
        loseBtn->setGeometry(QRect(800, 150, 41, 31));
        loseBtn->setStyleSheet(QStringLiteral(""));
        label_3 = new QLabel(groupBox1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(850, 60, 51, 21));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 90, 311, 511));
        groupBox->setStyleSheet(QString::fromUtf8("font: 15pt \"\351\273\221\344\275\223\";\n"
                                                  "color: rgb(0, 0, 0);\n"
                                                  "border:1px solid black;\n"
                                                  ""));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 50, 291, 451));
        listWidget->setStyleSheet(QString::fromUtf8("font: 12pt \"\351\273\221\344\275\223\";\n"
                                                    "color: rgb(0, 0, 0);\n"
                                                    "border:1px solid white;\n"
                                                    ""));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(230, 0, 81, 31));
        pushButton->setStyleSheet(QString::fromUtf8("font: 10pt \"\351\273\221\344\275\223\";\n"
                                                    "background-color: rgb(225, 225, 225);\n"
                                                    "color: rgb(0, 0, 0);\n"
                                                    "border:1px solid rgb(126, 126, 126);\n"
                                                    "border-radius:5px"));
        groupBox->raise();
        groupBox1->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget) {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        groupBox1->setTitle(QString());
        startBtn->setText(QString());
        nextBtn->setText(QString());
        nameLab->setText(QApplication::translate("Widget", "\346\255\214\346\233\262\345\220\215", Q_NULLPTR));
        strTime->setText(QApplication::translate("Widget", "Time", Q_NULLPTR));
        lastBtn->setText(QString());
        label->setText(QString());
        imageLab->setText(QString());
        endTime->setText(QApplication::translate("Widget", "endTime", Q_NULLPTR));
        addBtn->setText(QString());
        loseBtn->setText(QString());
        label_3->setText(QApplication::translate("Widget", "\351\237\263\351\207\217", Q_NULLPTR));
        groupBox->setTitle(
                QApplication::translate("Widget", "\346\255\214\346\233\262\345\210\227\350\241\250", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "\345\210\267\346\226\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget : public Ui_Widget {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
