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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Learn_Computer_Vision_Dialog
{
public:
    QPushButton *m_btn_Home;
    QPushButton *m_btn_Brain;
    QPushButton *m_btn_Training;
    QPushButton *m_btn_Visualization;
    QPushButton *m_btn_Annotation;
    QPushButton *m_btn_Back;
    QLabel *label;

    void setupUi(QDialog *Learn_Computer_Vision_Dialog)
    {
        if (Learn_Computer_Vision_Dialog->objectName().isEmpty())
            Learn_Computer_Vision_Dialog->setObjectName(QStringLiteral("Learn_Computer_Vision_Dialog"));
        Learn_Computer_Vision_Dialog->setEnabled(true);
        Learn_Computer_Vision_Dialog->resize(800, 600);
        Learn_Computer_Vision_Dialog->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        m_btn_Home = new QPushButton(Learn_Computer_Vision_Dialog);
        m_btn_Home->setObjectName(QStringLiteral("m_btn_Home"));
        m_btn_Home->setGeometry(QRect(20, 150, 40, 40));
        m_btn_Home->setStyleSheet(QStringLiteral("border-image: url(:/images/left-navigator/home-g.png);"));
        m_btn_Brain = new QPushButton(Learn_Computer_Vision_Dialog);
        m_btn_Brain->setObjectName(QStringLiteral("m_btn_Brain"));
        m_btn_Brain->setGeometry(QRect(20, 210, 40, 40));
        m_btn_Brain->setStyleSheet(QStringLiteral("border-image: url(:/images/left-navigator/func-w.png);"));
        m_btn_Training = new QPushButton(Learn_Computer_Vision_Dialog);
        m_btn_Training->setObjectName(QStringLiteral("m_btn_Training"));
        m_btn_Training->setGeometry(QRect(230, 10, 120, 40));
        m_btn_Training->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        m_btn_Visualization = new QPushButton(Learn_Computer_Vision_Dialog);
        m_btn_Visualization->setObjectName(QStringLiteral("m_btn_Visualization"));
        m_btn_Visualization->setGeometry(QRect(390, 10, 120, 40));
        m_btn_Visualization->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        m_btn_Annotation = new QPushButton(Learn_Computer_Vision_Dialog);
        m_btn_Annotation->setObjectName(QStringLiteral("m_btn_Annotation"));
        m_btn_Annotation->setGeometry(QRect(550, 10, 120, 40));
        m_btn_Annotation->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));
        m_btn_Back = new QPushButton(Learn_Computer_Vision_Dialog);
        m_btn_Back->setObjectName(QStringLiteral("m_btn_Back"));
        m_btn_Back->setGeometry(QRect(70, 10, 120, 40));
        m_btn_Back->setStyleSheet(QLatin1String("color: rgb(255, 0, 0);\n"
"background-color: rgb(155, 255, 255);"));
        label = new QLabel(Learn_Computer_Vision_Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(690, 10, 101, 51));
        label->setStyleSheet(QStringLiteral("border-image: url(:/images/company-logo.png);"));

        retranslateUi(Learn_Computer_Vision_Dialog);

        QMetaObject::connectSlotsByName(Learn_Computer_Vision_Dialog);
    } // setupUi

    void retranslateUi(QDialog *Learn_Computer_Vision_Dialog)
    {
        Learn_Computer_Vision_Dialog->setWindowTitle(QApplication::translate("Learn_Computer_Vision_Dialog", "Learn_Computer_Vision_Dialog", Q_NULLPTR));
        m_btn_Home->setText(QString());
        m_btn_Brain->setText(QString());
        m_btn_Training->setText(QApplication::translate("Learn_Computer_Vision_Dialog", "Training", Q_NULLPTR));
        m_btn_Visualization->setText(QApplication::translate("Learn_Computer_Vision_Dialog", "Visualization", Q_NULLPTR));
        m_btn_Annotation->setText(QApplication::translate("Learn_Computer_Vision_Dialog", "Annotation", Q_NULLPTR));
        m_btn_Back->setText(QApplication::translate("Learn_Computer_Vision_Dialog", "back", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Learn_Computer_Vision_Dialog: public Ui_Learn_Computer_Vision_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEARN_COMPUTER_VISION_DIALOG_H
