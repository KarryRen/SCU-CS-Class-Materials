/********************************************************************************
** Form generated from reading UI file 'LyricWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LYRICWIDGET_H
#define UI_LYRICWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LyricWidget {
public:
    QGroupBox *groupBox;
    QLabel *label;
    QGroupBox *groupBox_2;
    QLabel *topmusicname;
    QLabel *singer;
    QLabel *album;
    QLabel *fromlab;

    void setupUi(QWidget *LyricWidget) {
        if (LyricWidget->objectName().isEmpty())
            LyricWidget->setObjectName(QStringLiteral("LyricWidget"));
        LyricWidget->resize(589, 527);
        LyricWidget->setStyleSheet(QStringLiteral(""));
        groupBox = new QGroupBox(LyricWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 390, 551, 131));
        groupBox->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                  "font: 15pt \"\351\273\221\344\275\223\";\n"
                                                  "border:1px solid black;\n"
                                                  ""));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 521, 71));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
                                               "font: 14pt \"\351\273\221\344\275\223\";\n"
                                               "border:0px solid white;"));
        groupBox_2 = new QGroupBox(LyricWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 0, 551, 361));
        groupBox_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                    "border:1px solid black;\n"
                                                    "font: 15pt \"\351\273\221\344\275\223\";"));
        topmusicname = new QLabel(groupBox_2);
        topmusicname->setObjectName(QStringLiteral("topmusicname"));
        topmusicname->setGeometry(QRect(10, 60, 491, 71));
        topmusicname->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                      "font: 13pt \"\351\273\221\344\275\223\";\n"
                                                      "border:0px solid white;"));
        singer = new QLabel(groupBox_2);
        singer->setObjectName(QStringLiteral("singer"));
        singer->setGeometry(QRect(10, 130, 491, 81));
        singer->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                "font: 13pt \"\351\273\221\344\275\223\";\n"
                                                "border:0px solid white;\n"
                                                ""));
        album = new QLabel(groupBox_2);
        album->setObjectName(QStringLiteral("album"));
        album->setGeometry(QRect(10, 200, 491, 81));
        album->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                               "font: 13pt \"\351\273\221\344\275\223\";\n"
                                               "border:0px solid white;"));
        fromlab = new QLabel(groupBox_2);
        fromlab->setObjectName(QStringLiteral("fromlab"));
        fromlab->setGeometry(QRect(10, 280, 491, 71));
        fromlab->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
                                                 "font: 13pt \"\351\273\221\344\275\223\";\n"
                                                 "border:0px solid white;"));
        groupBox_2->raise();
        groupBox->raise();

        retranslateUi(LyricWidget);

        QMetaObject::connectSlotsByName(LyricWidget);
    } // setupUi

    void retranslateUi(QWidget *LyricWidget) {
        LyricWidget->setWindowTitle(QApplication::translate("LyricWidget", "Form", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("LyricWidget", "\346\255\214\350\257\215", Q_NULLPTR));
        label->setText(QString());
        groupBox_2->setTitle(
                QApplication::translate("LyricWidget", "\346\255\214\346\233\262\344\277\241\346\201\257", Q_NULLPTR));
        topmusicname->setText(QString());
        singer->setText(QString());
        album->setText(QString());
        fromlab->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LyricWidget : public Ui_LyricWidget {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LYRICWIDGET_H
