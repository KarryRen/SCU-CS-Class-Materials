/********************************************************************************
** Form generated from reading UI file 'playscene.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYSCENE_H
#define UI_PLAYSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_playscene {
public:
    QPushButton *returnBtn;
    QPushButton *restartBtn;
    QLCDNumber *Record;
    QLabel *gameover;

    void setupUi(QWidget *playscene) {
        if (playscene->objectName().isEmpty())
            playscene->setObjectName(QStringLiteral("playscene"));
        playscene->resize(400, 300);
        returnBtn = new QPushButton(playscene);
        returnBtn->setObjectName(QStringLiteral("returnBtn"));
        returnBtn->setGeometry(QRect(250, 190, 80, 20));
        restartBtn = new QPushButton(playscene);
        restartBtn->setObjectName(QStringLiteral("restartBtn"));
        restartBtn->setGeometry(QRect(250, 160, 80, 15));
        Record = new QLCDNumber(playscene);
        Record->setObjectName(QStringLiteral("Record"));
        Record->setGeometry(QRect(260, 70, 64, 23));
        gameover = new QLabel(playscene);
        gameover->setObjectName(QStringLiteral("gameover"));
        gameover->setGeometry(QRect(60, 130, 91, 21));

        retranslateUi(playscene);

        QMetaObject::connectSlotsByName(playscene);
    } // setupUi

    void retranslateUi(QWidget *playscene) {
        playscene->setWindowTitle(QApplication::translate("playscene", "Form", Q_NULLPTR));
        returnBtn->setText(QString());
        restartBtn->setText(QString());
        gameover->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class playscene : public Ui_playscene {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYSCENE_H
