/********************************************************************************
** Form generated from reading UI file 'TrainWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINWIDGET_H
#define UI_TRAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainWidget
{
public:
    QTextBrowser *textBrowser;
    QLabel *label;
    QGroupBox *m_groupBox_Setting;
    QPushButton *m_btn_Image;
    QPushButton *m_btn_Model;
    QSlider *horizontalSlider;
    QPushButton *m_btn_Run;
    QPushButton *m_btn_Reset;
    QLabel *m_label_SystemStatus;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *m_label_Epochs;
    QPushButton *m_btn_ImageReset;
    QPushButton *m_btn_ModelReset;
    QGroupBox *groupBox_2;
    QFrame *frame;
    QLabel *label_2;
    QPushButton *m_btn_Display;

    void setupUi(QWidget *TrainWidget)
    {
        if (TrainWidget->objectName().isEmpty())
            TrainWidget->setObjectName(QStringLiteral("TrainWidget"));
        TrainWidget->resize(736, 500);
        TrainWidget->setStyleSheet(QStringLiteral(""));
        textBrowser = new QTextBrowser(TrainWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(420, 60, 256, 411));
        textBrowser->setStyleSheet(QStringLiteral("background: transparent;"));
        label = new QLabel(TrainWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(460, 20, 181, 31));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("background: transparent;"));
        m_groupBox_Setting = new QGroupBox(TrainWidget);
        m_groupBox_Setting->setObjectName(QStringLiteral("m_groupBox_Setting"));
        m_groupBox_Setting->setGeometry(QRect(30, 40, 371, 211));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        m_groupBox_Setting->setFont(font1);
        m_groupBox_Setting->setStyleSheet(QStringLiteral("background: transparent;"));
        m_btn_Image = new QPushButton(m_groupBox_Setting);
        m_btn_Image->setObjectName(QStringLiteral("m_btn_Image"));
        m_btn_Image->setGeometry(QRect(30, 50, 81, 61));
        m_btn_Image->setFont(font1);
        m_btn_Image->setStyleSheet(QLatin1String("border-image: url(:/images/2-training/subpage/image-path.png);\n"
"color: rgb(255, 0, 0);"));
        m_btn_Model = new QPushButton(m_groupBox_Setting);
        m_btn_Model->setObjectName(QStringLiteral("m_btn_Model"));
        m_btn_Model->setGeometry(QRect(140, 50, 81, 61));
        m_btn_Model->setFont(font1);
        m_btn_Model->setStyleSheet(QLatin1String("border-image: url(:/images/2-training/subpage/model-path.png);\n"
"color: rgb(255, 0, 0);"));
        horizontalSlider = new QSlider(m_groupBox_Setting);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(40, 180, 160, 16));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(30);
        horizontalSlider->setValue(15);
        horizontalSlider->setOrientation(Qt::Horizontal);
        m_btn_Run = new QPushButton(m_groupBox_Setting);
        m_btn_Run->setObjectName(QStringLiteral("m_btn_Run"));
        m_btn_Run->setEnabled(false);
        m_btn_Run->setGeometry(QRect(260, 100, 81, 41));
        m_btn_Run->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));
        m_btn_Reset = new QPushButton(m_groupBox_Setting);
        m_btn_Reset->setObjectName(QStringLiteral("m_btn_Reset"));
        m_btn_Reset->setGeometry(QRect(260, 150, 81, 41));
        m_btn_Reset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));
        m_label_SystemStatus = new QLabel(m_groupBox_Setting);
        m_label_SystemStatus->setObjectName(QStringLiteral("m_label_SystemStatus"));
        m_label_SystemStatus->setGeometry(QRect(292, 60, 31, 16));
        m_label_SystemStatus->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));
        label_3 = new QLabel(m_groupBox_Setting);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(270, 30, 81, 21));
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_4 = new QLabel(m_groupBox_Setting);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 30, 141, 16));
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_7 = new QLabel(m_groupBox_Setting);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 150, 171, 16));
        label_7->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_8 = new QLabel(m_groupBox_Setting);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 180, 16, 16));
        label_8->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_9 = new QLabel(m_groupBox_Setting);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(210, 180, 16, 16));
        label_9->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        m_label_Epochs = new QLabel(m_groupBox_Setting);
        m_label_Epochs->setObjectName(QStringLiteral("m_label_Epochs"));
        m_label_Epochs->setGeometry(QRect(220, 150, 16, 16));
        m_label_Epochs->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        m_btn_ImageReset = new QPushButton(m_groupBox_Setting);
        m_btn_ImageReset->setObjectName(QStringLiteral("m_btn_ImageReset"));
        m_btn_ImageReset->setGeometry(QRect(49, 108, 45, 24));
        m_btn_ImageReset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));
        m_btn_ModelReset = new QPushButton(m_groupBox_Setting);
        m_btn_ModelReset->setObjectName(QStringLiteral("m_btn_ModelReset"));
        m_btn_ModelReset->setGeometry(QRect(161, 108, 45, 24));
        m_btn_ModelReset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));
        groupBox_2 = new QGroupBox(TrainWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 270, 371, 201));
        groupBox_2->setFont(font1);
        groupBox_2->setStyleSheet(QStringLiteral("background: transparent;"));
        frame = new QFrame(groupBox_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(30, 30, 191, 131));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 50, 131, 20));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        m_btn_Display = new QPushButton(groupBox_2);
        m_btn_Display->setObjectName(QStringLiteral("m_btn_Display"));
        m_btn_Display->setGeometry(QRect(260, 110, 75, 23));
        m_btn_Display->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));

        retranslateUi(TrainWidget);

        QMetaObject::connectSlotsByName(TrainWidget);
    } // setupUi

    void retranslateUi(QWidget *TrainWidget)
    {
        TrainWidget->setWindowTitle(QApplication::translate("TrainWidget", "Form", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("TrainWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("TrainWidget", "Training Log", Q_NULLPTR));
        m_groupBox_Setting->setTitle(QApplication::translate("TrainWidget", "Network Setting", Q_NULLPTR));
        m_btn_Image->setText(QApplication::translate("TrainWidget", "DATA\n"
"PATH", Q_NULLPTR));
        m_btn_Model->setText(QApplication::translate("TrainWidget", "MODEL\n"
"PATH", Q_NULLPTR));
        m_btn_Run->setText(QApplication::translate("TrainWidget", "RUN", Q_NULLPTR));
        m_btn_Reset->setText(QApplication::translate("TrainWidget", "RESET", Q_NULLPTR));
        m_label_SystemStatus->setText(QString());
        label_3->setText(QApplication::translate("TrainWidget", "System Status", Q_NULLPTR));
        label_4->setText(QApplication::translate("TrainWidget", "Load Dataset and Model", Q_NULLPTR));
        label_7->setText(QApplication::translate("TrainWidget", "Select the Number of Epochs:", Q_NULLPTR));
        label_8->setText(QApplication::translate("TrainWidget", "1", Q_NULLPTR));
        label_9->setText(QApplication::translate("TrainWidget", "30", Q_NULLPTR));
        m_label_Epochs->setText(QApplication::translate("TrainWidget", "15", Q_NULLPTR));
        m_btn_ImageReset->setText(QApplication::translate("TrainWidget", "reset", Q_NULLPTR));
        m_btn_ModelReset->setText(QApplication::translate("TrainWidget", "reset", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("TrainWidget", "Plotting", Q_NULLPTR));
        label_2->setText(QApplication::translate("TrainWidget", "Plot the Loss-Function", Q_NULLPTR));
        m_btn_Display->setText(QApplication::translate("TrainWidget", "DISPLAY", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TrainWidget: public Ui_TrainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINWIDGET_H
