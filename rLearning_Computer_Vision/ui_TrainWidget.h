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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainWidget
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *m_groupBox_Setting;
    QGridLayout *gridLayout;
    QLabel *m_label_SystemStatus;
    QLabel *label_7;
    QPushButton *m_btn_ImageReset;
    QLabel *label_3;
    QLabel *label_8;
    QSlider *horizontalSlider;
    QLabel *label_9;
    QPushButton *m_btn_Run;
    QPushButton *m_btn_Reset;
    QPushButton *m_btn_ModelReset;
    QLabel *m_label_Epochs;
    QLabel *label_4;
    QPushButton *m_btn_Image;
    QPushButton *m_btn_Model;
    QLabel *label;
    QTextBrowser *textBrowser;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *textBrowser_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QPushButton *m_btn_Display;

    void setupUi(QWidget *TrainWidget)
    {
        if (TrainWidget->objectName().isEmpty())
            TrainWidget->setObjectName(QStringLiteral("TrainWidget"));
        TrainWidget->resize(730, 523);
        TrainWidget->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(TrainWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        m_groupBox_Setting = new QGroupBox(TrainWidget);
        m_groupBox_Setting->setObjectName(QStringLiteral("m_groupBox_Setting"));
        QFont font;
        font.setFamily(QStringLiteral("Purisa"));
        font.setBold(true);
        font.setWeight(75);
        m_groupBox_Setting->setFont(font);
        m_groupBox_Setting->setStyleSheet(QStringLiteral("background: transparent;"));
        gridLayout = new QGridLayout(m_groupBox_Setting);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        m_label_SystemStatus = new QLabel(m_groupBox_Setting);
        m_label_SystemStatus->setObjectName(QStringLiteral("m_label_SystemStatus"));
        m_label_SystemStatus->setStyleSheet(QStringLiteral("background-color: rgb(255, 0, 0);"));

        gridLayout->addWidget(m_label_SystemStatus, 1, 7, 1, 1);

        label_7 = new QLabel(m_groupBox_Setting);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);
        label_7->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 5, 0, 1, 5);

        m_btn_ImageReset = new QPushButton(m_groupBox_Setting);
        m_btn_ImageReset->setObjectName(QStringLiteral("m_btn_ImageReset"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_btn_ImageReset->sizePolicy().hasHeightForWidth());
        m_btn_ImageReset->setSizePolicy(sizePolicy);
        m_btn_ImageReset->setFont(font);
        m_btn_ImageReset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));

        gridLayout->addWidget(m_btn_ImageReset, 4, 1, 1, 1);

        label_3 = new QLabel(m_groupBox_Setting);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font);
        label_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setMargin(5);

        gridLayout->addWidget(label_3, 0, 7, 1, 1);

        label_8 = new QLabel(m_groupBox_Setting);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        horizontalSlider = new QSlider(m_groupBox_Setting);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy1);
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(30);
        horizontalSlider->setValue(15);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 6, 1, 1, 4);

        label_9 = new QLabel(m_groupBox_Setting);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 6, 5, 1, 2);

        m_btn_Run = new QPushButton(m_groupBox_Setting);
        m_btn_Run->setObjectName(QStringLiteral("m_btn_Run"));
        m_btn_Run->setEnabled(false);
        sizePolicy.setHeightForWidth(m_btn_Run->sizePolicy().hasHeightForWidth());
        m_btn_Run->setSizePolicy(sizePolicy);
        m_btn_Run->setFont(font);
        m_btn_Run->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));

        gridLayout->addWidget(m_btn_Run, 2, 7, 2, 1);

        m_btn_Reset = new QPushButton(m_groupBox_Setting);
        m_btn_Reset->setObjectName(QStringLiteral("m_btn_Reset"));
        sizePolicy.setHeightForWidth(m_btn_Reset->sizePolicy().hasHeightForWidth());
        m_btn_Reset->setSizePolicy(sizePolicy);
        m_btn_Reset->setFont(font);
        m_btn_Reset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));

        gridLayout->addWidget(m_btn_Reset, 5, 7, 2, 1);

        m_btn_ModelReset = new QPushButton(m_groupBox_Setting);
        m_btn_ModelReset->setObjectName(QStringLiteral("m_btn_ModelReset"));
        sizePolicy.setHeightForWidth(m_btn_ModelReset->sizePolicy().hasHeightForWidth());
        m_btn_ModelReset->setSizePolicy(sizePolicy);
        m_btn_ModelReset->setFont(font);
        m_btn_ModelReset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));

        gridLayout->addWidget(m_btn_ModelReset, 4, 4, 1, 1);

        m_label_Epochs = new QLabel(m_groupBox_Setting);
        m_label_Epochs->setObjectName(QStringLiteral("m_label_Epochs"));
        m_label_Epochs->setFont(font);
        m_label_Epochs->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        m_label_Epochs->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(m_label_Epochs, 5, 5, 1, 2);

        label_4 = new QLabel(m_groupBox_Setting);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font);
        label_4->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 0, 0, 1, 7);

        m_btn_Image = new QPushButton(m_groupBox_Setting);
        m_btn_Image->setObjectName(QStringLiteral("m_btn_Image"));
        sizePolicy.setHeightForWidth(m_btn_Image->sizePolicy().hasHeightForWidth());
        m_btn_Image->setSizePolicy(sizePolicy);
        m_btn_Image->setMinimumSize(QSize(140, 140));
        m_btn_Image->setSizeIncrement(QSize(0, 0));
        m_btn_Image->setFont(font);
        m_btn_Image->setStyleSheet(QLatin1String("border-image: url(:/images/2-training/subpage/image-path.png);\n"
"color: rgb(255, 0, 0);"));

        gridLayout->addWidget(m_btn_Image, 2, 1, 1, 1);

        m_btn_Model = new QPushButton(m_groupBox_Setting);
        m_btn_Model->setObjectName(QStringLiteral("m_btn_Model"));
        sizePolicy.setHeightForWidth(m_btn_Model->sizePolicy().hasHeightForWidth());
        m_btn_Model->setSizePolicy(sizePolicy);
        m_btn_Model->setMinimumSize(QSize(140, 140));
        m_btn_Model->setSizeIncrement(QSize(0, 0));
        m_btn_Model->setFont(font);
        m_btn_Model->setStyleSheet(QLatin1String("border-image: url(:/images/2-training/subpage/model-path.png);\n"
"color: rgb(255, 0, 0);"));

        gridLayout->addWidget(m_btn_Model, 2, 4, 1, 1);


        gridLayout_2->addWidget(m_groupBox_Setting, 0, 0, 2, 1);

        label = new QLabel(TrainWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Purisa"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label->setStyleSheet(QStringLiteral("background: transparent;"));

        gridLayout_2->addWidget(label, 0, 1, 1, 1);

        textBrowser = new QTextBrowser(TrainWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setStyleSheet(QStringLiteral("background: transparent;"));

        gridLayout_2->addWidget(textBrowser, 1, 1, 2, 1);

        groupBox_2 = new QGroupBox(TrainWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QStringLiteral("background: transparent;"));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        frame = new QFrame(groupBox_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        textBrowser_2 = new QTextBrowser(frame);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        sizePolicy.setHeightForWidth(textBrowser_2->sizePolicy().hasHeightForWidth());
        textBrowser_2->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(textBrowser_2);


        horizontalLayout->addWidget(frame);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        m_btn_Display = new QPushButton(groupBox_2);
        m_btn_Display->setObjectName(QStringLiteral("m_btn_Display"));
        m_btn_Display->setEnabled(true);
        sizePolicy2.setHeightForWidth(m_btn_Display->sizePolicy().hasHeightForWidth());
        m_btn_Display->setSizePolicy(sizePolicy2);
        m_btn_Display->setFont(font);
        m_btn_Display->setLayoutDirection(Qt::LeftToRight);
        m_btn_Display->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));

        verticalLayout->addWidget(m_btn_Display);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);

        gridLayout_2->addWidget(groupBox_2, 2, 0, 1, 1);

        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowStretch(2, 1);
        gridLayout_2->setColumnStretch(0, 2);
        gridLayout_2->setColumnStretch(1, 1);

        retranslateUi(TrainWidget);

        QMetaObject::connectSlotsByName(TrainWidget);
    } // setupUi

    void retranslateUi(QWidget *TrainWidget)
    {
        TrainWidget->setWindowTitle(QApplication::translate("TrainWidget", "Form", Q_NULLPTR));
        m_groupBox_Setting->setTitle(QApplication::translate("TrainWidget", "Network Setting", Q_NULLPTR));
        m_label_SystemStatus->setText(QString());
        label_7->setText(QApplication::translate("TrainWidget", "Select the Number of Epochs:", Q_NULLPTR));
        m_btn_ImageReset->setText(QApplication::translate("TrainWidget", "Reset", Q_NULLPTR));
        label_3->setText(QApplication::translate("TrainWidget", "System Status", Q_NULLPTR));
        label_8->setText(QApplication::translate("TrainWidget", "1", Q_NULLPTR));
        label_9->setText(QApplication::translate("TrainWidget", "30", Q_NULLPTR));
        m_btn_Run->setText(QApplication::translate("TrainWidget", "RUN", Q_NULLPTR));
        m_btn_Reset->setText(QApplication::translate("TrainWidget", "RESET", Q_NULLPTR));
        m_btn_ModelReset->setText(QApplication::translate("TrainWidget", "Reset", Q_NULLPTR));
        m_label_Epochs->setText(QApplication::translate("TrainWidget", "15", Q_NULLPTR));
        label_4->setText(QApplication::translate("TrainWidget", "Load Dataset and Model", Q_NULLPTR));
        m_btn_Image->setText(QApplication::translate("TrainWidget", "DATA\n"
"PATH", Q_NULLPTR));
        m_btn_Model->setText(QApplication::translate("TrainWidget", "MODEL\n"
"PATH", Q_NULLPTR));
        label->setText(QApplication::translate("TrainWidget", "Training Log", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("TrainWidget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
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
