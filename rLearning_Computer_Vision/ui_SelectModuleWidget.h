/********************************************************************************
** Form generated from reading UI file 'SelectModuleWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTMODULEWIDGET_H
#define UI_SELECTMODULEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectModuleWidget
{
public:
    QLabel *label;
    QPushButton *m_btn_Fruit;
    QPushButton *m_btn_Cat_and_Dog;
    QPushButton *m_btn_Creatures;
    QPushButton *m_btn_Vehicles;
    QPushButton *m_btn_Human;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QWidget *SelectModuleWidget)
    {
        if (SelectModuleWidget->objectName().isEmpty())
            SelectModuleWidget->setObjectName(QStringLiteral("SelectModuleWidget"));
        SelectModuleWidget->setEnabled(true);
        SelectModuleWidget->resize(700, 500);
        SelectModuleWidget->setStyleSheet(QStringLiteral("background-color: rgb(177, 181, 182);"));
        label = new QLabel(SelectModuleWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 40, 341, 41));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        m_btn_Fruit = new QPushButton(SelectModuleWidget);
        m_btn_Fruit->setObjectName(QStringLiteral("m_btn_Fruit"));
        m_btn_Fruit->setGeometry(QRect(120, 90, 100, 100));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        m_btn_Fruit->setFont(font1);
        m_btn_Fruit->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/detection-fruits.jpg);"));
        m_btn_Cat_and_Dog = new QPushButton(SelectModuleWidget);
        m_btn_Cat_and_Dog->setObjectName(QStringLiteral("m_btn_Cat_and_Dog"));
        m_btn_Cat_and_Dog->setGeometry(QRect(260, 90, 100, 100));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        m_btn_Cat_and_Dog->setFont(font2);
        m_btn_Cat_and_Dog->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/classification-pets.jpg);"));
        m_btn_Creatures = new QPushButton(SelectModuleWidget);
        m_btn_Creatures->setObjectName(QStringLiteral("m_btn_Creatures"));
        m_btn_Creatures->setGeometry(QRect(120, 200, 100, 100));
        m_btn_Creatures->setFont(font1);
        m_btn_Creatures->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/detection-creature.jpg);"));
        m_btn_Vehicles = new QPushButton(SelectModuleWidget);
        m_btn_Vehicles->setObjectName(QStringLiteral("m_btn_Vehicles"));
        m_btn_Vehicles->setGeometry(QRect(260, 200, 100, 100));
        m_btn_Vehicles->setFont(font1);
        m_btn_Vehicles->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/classification-others.jpg);"));
        m_btn_Human = new QPushButton(SelectModuleWidget);
        m_btn_Human->setObjectName(QStringLiteral("m_btn_Human"));
        m_btn_Human->setGeometry(QRect(420, 90, 100, 100));
        m_btn_Human->setFont(font1);
        m_btn_Human->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/pose-estimation.jpg);\n"
""));
        label_2 = new QLabel(SelectModuleWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 310, 121, 101));
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2->setWordWrap(true);
        label_3 = new QLabel(SelectModuleWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(250, 310, 131, 111));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3->setWordWrap(true);
        label_4 = new QLabel(SelectModuleWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(410, 210, 131, 101));
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4->setWordWrap(true);
        label_5 = new QLabel(SelectModuleWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(420, 320, 111, 91));
        QFont font3;
        font3.setPointSize(25);
        label_5->setFont(font3);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        retranslateUi(SelectModuleWidget);

        QMetaObject::connectSlotsByName(SelectModuleWidget);
    } // setupUi

    void retranslateUi(QWidget *SelectModuleWidget)
    {
        SelectModuleWidget->setWindowTitle(QApplication::translate("SelectModuleWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("SelectModuleWidget", "Select one module", Q_NULLPTR));
        m_btn_Fruit->setText(QApplication::translate("SelectModuleWidget", "fruit", Q_NULLPTR));
        m_btn_Cat_and_Dog->setText(QApplication::translate("SelectModuleWidget", "cat and dog", Q_NULLPTR));
        m_btn_Creatures->setText(QApplication::translate("SelectModuleWidget", "creatures", Q_NULLPTR));
        m_btn_Vehicles->setText(QApplication::translate("SelectModuleWidget", "vehicles", Q_NULLPTR));
        m_btn_Human->setText(QApplication::translate("SelectModuleWidget", "human", Q_NULLPTR));
        label_2->setText(QApplication::translate("SelectModuleWidget", "Object detection deals with detecting instances of semantic objects of a certain class (such as humans, buildings, or cars).", Q_NULLPTR));
        label_3->setText(QApplication::translate("SelectModuleWidget", "Object classification arms to classify different types of objects (like dogs, cats, etc.) in digital images and videos as well.", Q_NULLPTR));
        label_4->setText(QApplication::translate("SelectModuleWidget", "Pose estimation could extract human skeleton through a series of key-ponits.", Q_NULLPTR));
        label_5->setText(QApplication::translate("SelectModuleWidget", "TBC...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SelectModuleWidget: public Ui_SelectModuleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTMODULEWIDGET_H
