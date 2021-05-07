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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectModuleWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QPushButton *m_btn_Vehicles;
    QLabel *label_7;
    QPushButton *m_btn_Fruit;
    QLabel *label_9;
    QPushButton *m_btn_Creatures;
    QLabel *label_6;
    QLabel *label_4;
    QPushButton *m_btn_Cat_and_Dog;
    QLabel *label_10;
    QPushButton *m_btn_Human;
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
        verticalLayout = new QVBoxLayout(SelectModuleWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(SelectModuleWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 50));
        QFont font;
        font.setFamily(QStringLiteral("Purisa"));
        font.setPointSize(30);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(label);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_8 = new QLabel(SelectModuleWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(0, 25));
        QFont font1;
        font1.setFamily(QStringLiteral("Purisa"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(label_8, 1, 2, 1, 1);

        m_btn_Vehicles = new QPushButton(SelectModuleWidget);
        m_btn_Vehicles->setObjectName(QStringLiteral("m_btn_Vehicles"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_btn_Vehicles->sizePolicy().hasHeightForWidth());
        m_btn_Vehicles->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        m_btn_Vehicles->setFont(font2);
        m_btn_Vehicles->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/classification-others.jpg);"));

        gridLayout_2->addWidget(m_btn_Vehicles, 2, 1, 1, 1);

        label_7 = new QLabel(SelectModuleWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(0, 25));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(label_7, 1, 1, 1, 1);

        m_btn_Fruit = new QPushButton(SelectModuleWidget);
        m_btn_Fruit->setObjectName(QStringLiteral("m_btn_Fruit"));
        sizePolicy1.setHeightForWidth(m_btn_Fruit->sizePolicy().hasHeightForWidth());
        m_btn_Fruit->setSizePolicy(sizePolicy1);
        m_btn_Fruit->setFont(font2);
        m_btn_Fruit->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/detection-fruits.jpg);"));

        gridLayout_2->addWidget(m_btn_Fruit, 0, 0, 1, 1);

        label_9 = new QLabel(SelectModuleWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font1);
        label_9->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(label_9, 3, 0, 1, 1);

        m_btn_Creatures = new QPushButton(SelectModuleWidget);
        m_btn_Creatures->setObjectName(QStringLiteral("m_btn_Creatures"));
        sizePolicy1.setHeightForWidth(m_btn_Creatures->sizePolicy().hasHeightForWidth());
        m_btn_Creatures->setSizePolicy(sizePolicy1);
        m_btn_Creatures->setFont(font2);
        m_btn_Creatures->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/detection-creature.jpg);"));

        gridLayout_2->addWidget(m_btn_Creatures, 2, 0, 1, 1);

        label_6 = new QLabel(SelectModuleWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(0, 25));
        label_6->setFont(font1);
        label_6->setTextFormat(Qt::AutoText);
        label_6->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        label_4 = new QLabel(SelectModuleWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(0, 50));
        QFont font3;
        font3.setFamily(QStringLiteral("Purisa"));
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setKerning(true);
        label_4->setFont(font3);
        label_4->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_4->setWordWrap(true);

        gridLayout_2->addWidget(label_4, 2, 2, 1, 1);

        m_btn_Cat_and_Dog = new QPushButton(SelectModuleWidget);
        m_btn_Cat_and_Dog->setObjectName(QStringLiteral("m_btn_Cat_and_Dog"));
        sizePolicy1.setHeightForWidth(m_btn_Cat_and_Dog->sizePolicy().hasHeightForWidth());
        m_btn_Cat_and_Dog->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        m_btn_Cat_and_Dog->setFont(font4);
        m_btn_Cat_and_Dog->setStyleSheet(QLatin1String("color: rgb(0, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/classification-pets.jpg);"));

        gridLayout_2->addWidget(m_btn_Cat_and_Dog, 0, 1, 1, 1);

        label_10 = new QLabel(SelectModuleWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);
        label_10->setFont(font1);
        label_10->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        gridLayout_2->addWidget(label_10, 3, 1, 1, 1);

        m_btn_Human = new QPushButton(SelectModuleWidget);
        m_btn_Human->setObjectName(QStringLiteral("m_btn_Human"));
        sizePolicy1.setHeightForWidth(m_btn_Human->sizePolicy().hasHeightForWidth());
        m_btn_Human->setSizePolicy(sizePolicy1);
        m_btn_Human->setFont(font2);
        m_btn_Human->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"border-image: url(:/images/2-training/subpage/background/pose-estimation.jpg);\n"
""));

        gridLayout_2->addWidget(m_btn_Human, 0, 2, 1, 1);

        label_2 = new QLabel(SelectModuleWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font5;
        font5.setFamily(QStringLiteral("Purisa"));
        font5.setBold(true);
        font5.setWeight(75);
        font5.setStrikeOut(false);
        font5.setStyleStrategy(QFont::PreferDefault);
        label_2->setFont(font5);
        label_2->setMouseTracking(false);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_2->setTextFormat(Qt::AutoText);
        label_2->setScaledContents(false);
        label_2->setWordWrap(true);

        gridLayout_2->addWidget(label_2, 4, 0, 1, 1);

        label_3 = new QLabel(SelectModuleWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font6;
        font6.setFamily(QStringLiteral("Purisa"));
        font6.setBold(true);
        font6.setWeight(75);
        label_3->setFont(font6);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_3->setWordWrap(true);

        gridLayout_2->addWidget(label_3, 4, 1, 1, 1);

        label_5 = new QLabel(SelectModuleWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        QFont font7;
        font7.setFamily(QStringLiteral("Purisa"));
        font7.setPointSize(18);
        font7.setBold(true);
        font7.setWeight(75);
        label_5->setFont(font7);
        label_5->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);

        gridLayout_2->addWidget(label_5, 4, 2, 1, 1);

        gridLayout_2->setRowStretch(0, 2);
        gridLayout_2->setRowStretch(2, 2);

        verticalLayout->addLayout(gridLayout_2);

        verticalLayout->setStretch(1, 2);

        retranslateUi(SelectModuleWidget);

        QMetaObject::connectSlotsByName(SelectModuleWidget);
    } // setupUi

    void retranslateUi(QWidget *SelectModuleWidget)
    {
        SelectModuleWidget->setWindowTitle(QApplication::translate("SelectModuleWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("SelectModuleWidget", "Select one module", Q_NULLPTR));
        label_8->setText(QApplication::translate("SelectModuleWidget", "Human", Q_NULLPTR));
        m_btn_Vehicles->setText(QString());
        label_7->setText(QApplication::translate("SelectModuleWidget", "Cat and Dog", Q_NULLPTR));
        m_btn_Fruit->setText(QString());
        label_9->setText(QApplication::translate("SelectModuleWidget", "Creatures", Q_NULLPTR));
        m_btn_Creatures->setText(QString());
        label_6->setText(QApplication::translate("SelectModuleWidget", "Fruit", Q_NULLPTR));
        label_4->setText(QApplication::translate("SelectModuleWidget", "Pose estimation could extract human skeleton through a series of key-ponits.", Q_NULLPTR));
        m_btn_Cat_and_Dog->setText(QString());
        label_10->setText(QApplication::translate("SelectModuleWidget", "Vehicles", Q_NULLPTR));
        m_btn_Human->setText(QString());
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
