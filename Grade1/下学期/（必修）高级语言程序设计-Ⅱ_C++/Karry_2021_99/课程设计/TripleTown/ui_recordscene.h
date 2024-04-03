/********************************************************************************
** Form generated from reading UI file 'recordscene.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDSCENE_H
#define UI_RECORDSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recordscene {
public:
    QPushButton *returnbtn;
    QPushButton *clearbtn;

    void setupUi(QWidget *recordscene) {
        if (recordscene->objectName().isEmpty())
            recordscene->setObjectName(QStringLiteral("recordscene"));
        recordscene->resize(400, 300);
        returnbtn = new QPushButton(recordscene);
        returnbtn->setObjectName(QStringLiteral("returnbtn"));
        returnbtn->setGeometry(QRect(280, 190, 80, 20));
        clearbtn = new QPushButton(recordscene);
        clearbtn->setObjectName(QStringLiteral("clearbtn"));
        clearbtn->setGeometry(QRect(50, 210, 80, 20));

        retranslateUi(recordscene);

        QMetaObject::connectSlotsByName(recordscene);
    } // setupUi

    void retranslateUi(QWidget *recordscene) {
        recordscene->setWindowTitle(QApplication::translate("recordscene", "Form", Q_NULLPTR));
        returnbtn->setText(QString());
        clearbtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class recordscene : public Ui_recordscene {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDSCENE_H
