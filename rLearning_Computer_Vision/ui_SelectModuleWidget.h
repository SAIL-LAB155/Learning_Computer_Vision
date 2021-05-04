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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectModuleWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *m_btn_Fruit;
    QPushButton *m_btn_Cat_and_Dog;
    QPushButton *m_btn_Human;
    QPushButton *m_btn_Creatures;
    QPushButton *m_btn_Vehicles;
    QLabel *label_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_5;

    void setupUi(QWidget *SelectModuleWidget)
    {
        if (SelectModuleWidget->objectName().isEmpty())
            SelectModuleWidget->setObjectName(QStringLiteral("SelectModuleWidget"));
        SelectModuleWidget->setEnabled(true);
        SelectModuleWidget->resize(700, 500);
        SelectModuleWidget->setStyleSheet(QStringLiteral("background-color: rgb(177, 181, 182);"));
        gridLayout = new QGridLayout(SelectModuleWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(SelectModuleWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(30);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label, 0, 0, 1, 3);

        m_btn_Fruit = new QPushButton(SelectModuleWidget);
        m_btn_Fruit->setObjectName(QStringLiteral("m_btn_Fruit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_btn_Fruit->sizePolicy().hasHeightForWidth());
        m_btn_Fruit->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        m_btn_Fruit->setFont(font1);
        m_btn_Fruit->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/detection-fruits.jpg);"));

        gridLayout->addWidget(m_btn_Fruit, 1, 0, 1, 1);

        m_btn_Cat_and_Dog = new QPushButton(SelectModuleWidget);
        m_btn_Cat_and_Dog->setObjectName(QStringLiteral("m_btn_Cat_and_Dog"));
        sizePolicy1.setHeightForWidth(m_btn_Cat_and_Dog->sizePolicy().hasHeightForWidth());
        m_btn_Cat_and_Dog->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        m_btn_Cat_and_Dog->setFont(font2);
        m_btn_Cat_and_Dog->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/classification-pets.jpg);"));

        gridLayout->addWidget(m_btn_Cat_and_Dog, 1, 1, 1, 1);

        m_btn_Human = new QPushButton(SelectModuleWidget);
        m_btn_Human->setObjectName(QStringLiteral("m_btn_Human"));
        sizePolicy1.setHeightForWidth(m_btn_Human->sizePolicy().hasHeightForWidth());
        m_btn_Human->setSizePolicy(sizePolicy1);
        m_btn_Human->setFont(font1);
        m_btn_Human->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/pose-estimation.jpg);\n"
""));

        gridLayout->addWidget(m_btn_Human, 1, 2, 1, 1);

        m_btn_Creatures = new QPushButton(SelectModuleWidget);
        m_btn_Creatures->setObjectName(QStringLiteral("m_btn_Creatures"));
        sizePolicy1.setHeightForWidth(m_btn_Creatures->sizePolicy().hasHeightForWidth());
        m_btn_Creatures->setSizePolicy(sizePolicy1);
        m_btn_Creatures->setFont(font1);
        m_btn_Creatures->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/detection-creature.jpg);"));

        gridLayout->addWidget(m_btn_Creatures, 2, 0, 1, 1);

        m_btn_Vehicles = new QPushButton(SelectModuleWidget);
        m_btn_Vehicles->setObjectName(QStringLiteral("m_btn_Vehicles"));
        sizePolicy1.setHeightForWidth(m_btn_Vehicles->sizePolicy().hasHeightForWidth());
        m_btn_Vehicles->setSizePolicy(sizePolicy1);
        m_btn_Vehicles->setFont(font1);
        m_btn_Vehicles->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/classification-others.jpg);"));

        gridLayout->addWidget(m_btn_Vehicles, 2, 1, 1, 1);

        label_4 = new QLabel(SelectModuleWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4->setWordWrap(true);

        gridLayout->addWidget(label_4, 2, 2, 1, 1);

        label_2 = new QLabel(SelectModuleWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2->setWordWrap(true);

        gridLayout->addWidget(label_2, 3, 0, 1, 1);

        label_3 = new QLabel(SelectModuleWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3->setWordWrap(true);

        gridLayout->addWidget(label_3, 3, 1, 1, 1);

        label_5 = new QLabel(SelectModuleWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font3;
        font3.setPointSize(25);
        label_5->setFont(font3);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label_5, 3, 2, 1, 1);


        retranslateUi(SelectModuleWidget);

        QMetaObject::connectSlotsByName(SelectModuleWidget);
    } // setupUi

    void retranslateUi(QWidget *SelectModuleWidget)
    {
        SelectModuleWidget->setWindowTitle(QApplication::translate("SelectModuleWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("SelectModuleWidget", "Select one module", Q_NULLPTR));
        m_btn_Fruit->setText(QApplication::translate("SelectModuleWidget", "fruit", Q_NULLPTR));
        m_btn_Cat_and_Dog->setText(QApplication::translate("SelectModuleWidget", "cat and dog", Q_NULLPTR));
        m_btn_Human->setText(QApplication::translate("SelectModuleWidget", "human", Q_NULLPTR));
        m_btn_Creatures->setText(QApplication::translate("SelectModuleWidget", "creatures", Q_NULLPTR));
        m_btn_Vehicles->setText(QApplication::translate("SelectModuleWidget", "vehicles", Q_NULLPTR));
        label_4->setText(QApplication::translate("SelectModuleWidget", "Pose estimation could extract human skeleton through a series of key-ponits.", Q_NULLPTR));
        label_2->setText(QApplication::translate("SelectModuleWidget", "Object detection deals with detecting instances of semantic objects of a certain class (such as humans, buildings, or cars).", Q_NULLPTR));
        label_3->setText(QApplication::translate("SelectModuleWidget", "Object classification arms to classify different types of objects (like dogs, cats, etc.) in digital images and videos as well.", Q_NULLPTR));
        label_5->setText(QApplication::translate("SelectModuleWidget", "TBC...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SelectModuleWidget: public Ui_SelectModuleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTMODULEWIDGET_H
