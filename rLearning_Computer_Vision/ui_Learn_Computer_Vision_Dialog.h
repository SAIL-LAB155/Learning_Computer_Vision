/********************************************************************************
** Form generated from reading UI file 'Learn_Computer_Vision_Dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEARN_COMPUTER_VISION_DIALOG_H
#define UI_LEARN_COMPUTER_VISION_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Learn_Computer_Vision_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_btn_Back;
    QPushButton *m_btn_Training;
    QPushButton *m_btn_Visualization;
    QPushButton *m_btn_Annotation;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *m_btn_Home;
    QPushButton *m_btn_Brain;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Learn_Computer_Vision_Dialog)
    {
        if (Learn_Computer_Vision_Dialog->objectName().isEmpty())
            Learn_Computer_Vision_Dialog->setObjectName(QStringLiteral("Learn_Computer_Vision_Dialog"));
        Learn_Computer_Vision_Dialog->setWindowModality(Qt::NonModal);
        Learn_Computer_Vision_Dialog->setEnabled(true);
        Learn_Computer_Vision_Dialog->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Learn_Computer_Vision_Dialog->sizePolicy().hasHeightForWidth());
        Learn_Computer_Vision_Dialog->setSizePolicy(sizePolicy);
        Learn_Computer_Vision_Dialog->setMinimumSize(QSize(1024, 768));
        Learn_Computer_Vision_Dialog->setMaximumSize(QSize(1280, 1024));
        Learn_Computer_Vision_Dialog->setSizeIncrement(QSize(0, 0));
        Learn_Computer_Vision_Dialog->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        Learn_Computer_Vision_Dialog->setSizeGripEnabled(false);
        verticalLayout = new QVBoxLayout(Learn_Computer_Vision_Dialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(20, 10, 20, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_btn_Back = new QPushButton(Learn_Computer_Vision_Dialog);
        m_btn_Back->setObjectName(QStringLiteral("m_btn_Back"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_btn_Back->sizePolicy().hasHeightForWidth());
        m_btn_Back->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QStringLiteral("Purisa"));
        font.setBold(true);
        font.setWeight(75);
        m_btn_Back->setFont(font);
        m_btn_Back->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"background-color: rgb(155, 255, 255);"));

        horizontalLayout->addWidget(m_btn_Back);

        m_btn_Training = new QPushButton(Learn_Computer_Vision_Dialog);
        m_btn_Training->setObjectName(QStringLiteral("m_btn_Training"));
        sizePolicy1.setHeightForWidth(m_btn_Training->sizePolicy().hasHeightForWidth());
        m_btn_Training->setSizePolicy(sizePolicy1);
        m_btn_Training->setFont(font);
        m_btn_Training->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(m_btn_Training);

        m_btn_Visualization = new QPushButton(Learn_Computer_Vision_Dialog);
        m_btn_Visualization->setObjectName(QStringLiteral("m_btn_Visualization"));
        sizePolicy1.setHeightForWidth(m_btn_Visualization->sizePolicy().hasHeightForWidth());
        m_btn_Visualization->setSizePolicy(sizePolicy1);
        m_btn_Visualization->setFont(font);
        m_btn_Visualization->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(m_btn_Visualization);

        m_btn_Annotation = new QPushButton(Learn_Computer_Vision_Dialog);
        m_btn_Annotation->setObjectName(QStringLiteral("m_btn_Annotation"));
        sizePolicy1.setHeightForWidth(m_btn_Annotation->sizePolicy().hasHeightForWidth());
        m_btn_Annotation->setSizePolicy(sizePolicy1);
        m_btn_Annotation->setMinimumSize(QSize(0, 0));
        m_btn_Annotation->setFont(font);
        m_btn_Annotation->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(m_btn_Annotation);

        label = new QLabel(Learn_Computer_Vision_Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(false);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        label->setMinimumSize(QSize(150, 60));
        label->setStyleSheet(QStringLiteral("border-image: url(:/images/company-logo.png);"));

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        m_btn_Home = new QPushButton(Learn_Computer_Vision_Dialog);
        m_btn_Home->setObjectName(QStringLiteral("m_btn_Home"));
        sizePolicy2.setHeightForWidth(m_btn_Home->sizePolicy().hasHeightForWidth());
        m_btn_Home->setSizePolicy(sizePolicy2);
        m_btn_Home->setMinimumSize(QSize(50, 50));
        m_btn_Home->setStyleSheet(QStringLiteral("border-image: url(:/images/left-navigator/home-g.png);"));

        verticalLayout_2->addWidget(m_btn_Home);

        m_btn_Brain = new QPushButton(Learn_Computer_Vision_Dialog);
        m_btn_Brain->setObjectName(QStringLiteral("m_btn_Brain"));
        sizePolicy2.setHeightForWidth(m_btn_Brain->sizePolicy().hasHeightForWidth());
        m_btn_Brain->setSizePolicy(sizePolicy2);
        m_btn_Brain->setMinimumSize(QSize(50, 50));
        m_btn_Brain->setStyleSheet(QStringLiteral("border-image: url(:/images/left-navigator/func-w.png);"));

        verticalLayout_2->addWidget(m_btn_Brain);


        horizontalLayout_3->addLayout(verticalLayout_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(2, 2);
        verticalLayout->setStretch(3, 8);

        retranslateUi(Learn_Computer_Vision_Dialog);

        QMetaObject::connectSlotsByName(Learn_Computer_Vision_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Learn_Computer_Vision_Dialog)
    {
        Learn_Computer_Vision_Dialog->setWindowTitle(QApplication::translate("Learn_Computer_Vision_Dialog", "Learn_Computer_Vision_Dialog", Q_NULLPTR));
        m_btn_Back->setText(QApplication::translate("Learn_Computer_Vision_Dialog", "Back", Q_NULLPTR));
        m_btn_Training->setText(QApplication::translate("Learn_Computer_Vision_Dialog", "Training", Q_NULLPTR));
        m_btn_Visualization->setText(QApplication::translate("Learn_Computer_Vision_Dialog", "Visualization", Q_NULLPTR));
        m_btn_Annotation->setText(QApplication::translate("Learn_Computer_Vision_Dialog", "Annotation", Q_NULLPTR));
        label->setText(QString());
        m_btn_Home->setText(QString());
        m_btn_Brain->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Learn_Computer_Vision_Dialog: public Ui_Learn_Computer_Vision_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARN_COMPUTER_VISION_DIALOG_H
