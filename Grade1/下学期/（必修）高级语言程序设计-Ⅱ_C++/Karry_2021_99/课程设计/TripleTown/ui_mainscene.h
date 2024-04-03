/********************************************************************************
** Form generated from reading UI file 'mainscene.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSCENE_H
#define UI_MAINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainscene {
public:
    QPushButton *startbtn;
    QPushButton *exitbtn;
    QPushButton *rankbtn;

    void setupUi(QWidget *mainscene) {
        if (mainscene->objectName().isEmpty())
            mainscene->setObjectName(QStringLiteral("mainscene"));
        mainscene->resize(400, 300);
        startbtn = new QPushButton(mainscene);
        startbtn->setObjectName(QStringLiteral("startbtn"));
        startbtn->setGeometry(QRect(270, 260, 101, 31));
        exitbtn = new QPushButton(mainscene);
        exitbtn->setObjectName(QStringLiteral("exitbtn"));
        exitbtn->setGeometry(QRect(200, 180, 121, 41));
        rankbtn = new QPushButton(mainscene);
        rankbtn->setObjectName(QStringLiteral("rankbtn"));
        rankbtn->setGeometry(QRect(260, 130, 80, 20));

        retranslateUi(mainscene);

        QMetaObject::connectSlotsByName(mainscene);
    } // setupUi

    void retranslateUi(QWidget *mainscene) {
        mainscene->setWindowTitle(QApplication::translate("mainscene", "mainscene", Q_NULLPTR));
        startbtn->setText(QString());
        exitbtn->setText(QString());
        rankbtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mainscene : public Ui_mainscene {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSCENE_H
