/********************************************************************************
** Form generated from reading UI file 'VisualizationWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALIZATIONWIDGET_H
#define UI_VISUALIZATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisualizationWidget
{
public:
    QFrame *frame;
    QPushButton *m_btn_Visualize;
    QPushButton *m_btn_ImagePath;
    QPushButton *m_btn_ModelPath;
    QPushButton *m_btn_OpenImage;
    QPushButton *m_btn_OpenCamera;
    QLabel *label;
    QPushButton *m_btn_ImagePath_Reset;
    QPushButton *m_btn_ModelPath_Reset;
    QPushButton *m_btn_OpenImage_Reset;
    QPushButton *m_btn_OpenCamera_Reset;
    QLabel *label_2;

    void setupUi(QWidget *VisualizationWidget)
    {
        if (VisualizationWidget->objectName().isEmpty())
            VisualizationWidget->setObjectName(QStringLiteral("VisualizationWidget"));
        VisualizationWidget->resize(700, 500);
        VisualizationWidget->setStyleSheet(QStringLiteral("background-color: rgb(177, 181, 182);"));
        frame = new QFrame(VisualizationWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(40, 40, 481, 341));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        m_btn_Visualize = new QPushButton(VisualizationWidget);
        m_btn_Visualize->setObjectName(QStringLiteral("m_btn_Visualize"));
        m_btn_Visualize->setGeometry(QRect(240, 420, 75, 23));
        m_btn_Visualize->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));
        m_btn_ImagePath = new QPushButton(VisualizationWidget);
        m_btn_ImagePath->setObjectName(QStringLiteral("m_btn_ImagePath"));
        m_btn_ImagePath->setGeometry(QRect(570, 70, 75, 40));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        m_btn_ImagePath->setFont(font);
        m_btn_ImagePath->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"border-image: url(:/images/2-training/subpage/image-path.png);"));
        m_btn_ModelPath = new QPushButton(VisualizationWidget);
        m_btn_ModelPath->setObjectName(QStringLiteral("m_btn_ModelPath"));
        m_btn_ModelPath->setGeometry(QRect(570, 155, 75, 40));
        m_btn_ModelPath->setFont(font);
        m_btn_ModelPath->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"border-image: url(:/images/2-training/subpage/model-path.png);"));
        m_btn_OpenImage = new QPushButton(VisualizationWidget);
        m_btn_OpenImage->setObjectName(QStringLiteral("m_btn_OpenImage"));
        m_btn_OpenImage->setGeometry(QRect(570, 290, 75, 40));
        m_btn_OpenImage->setFont(font);
        m_btn_OpenImage->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"border-image: url(:/images/3-visualization/open-image.png);"));
        m_btn_OpenCamera = new QPushButton(VisualizationWidget);
        m_btn_OpenCamera->setObjectName(QStringLiteral("m_btn_OpenCamera"));
        m_btn_OpenCamera->setGeometry(QRect(570, 380, 75, 40));
        m_btn_OpenCamera->setFont(font);
        m_btn_OpenCamera->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"border-image: url(:/images/3-visualization/open-camera.png);"));
        label = new QLabel(VisualizationWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(560, 30, 131, 31));
        label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        m_btn_ImagePath_Reset = new QPushButton(VisualizationWidget);
        m_btn_ImagePath_Reset->setObjectName(QStringLiteral("m_btn_ImagePath_Reset"));
        m_btn_ImagePath_Reset->setGeometry(QRect(585, 110, 51, 23));
        m_btn_ImagePath_Reset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));
        m_btn_ModelPath_Reset = new QPushButton(VisualizationWidget);
        m_btn_ModelPath_Reset->setObjectName(QStringLiteral("m_btn_ModelPath_Reset"));
        m_btn_ModelPath_Reset->setGeometry(QRect(585, 201, 51, 23));
        m_btn_ModelPath_Reset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));
        m_btn_OpenImage_Reset = new QPushButton(VisualizationWidget);
        m_btn_OpenImage_Reset->setObjectName(QStringLiteral("m_btn_OpenImage_Reset"));
        m_btn_OpenImage_Reset->setGeometry(QRect(585, 338, 51, 23));
        m_btn_OpenImage_Reset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));
        m_btn_OpenCamera_Reset = new QPushButton(VisualizationWidget);
        m_btn_OpenCamera_Reset->setObjectName(QStringLiteral("m_btn_OpenCamera_Reset"));
        m_btn_OpenCamera_Reset->setGeometry(QRect(585, 430, 51, 23));
        m_btn_OpenCamera_Reset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));
        label_2 = new QLabel(VisualizationWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(560, 240, 111, 41));
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_2->setWordWrap(true);

        retranslateUi(VisualizationWidget);

        QMetaObject::connectSlotsByName(VisualizationWidget);
    } // setupUi

    void retranslateUi(QWidget *VisualizationWidget)
    {
        VisualizationWidget->setWindowTitle(QApplication::translate("VisualizationWidget", "Form", Q_NULLPTR));
        m_btn_Visualize->setText(QApplication::translate("VisualizationWidget", "VISUALIZE", Q_NULLPTR));
        m_btn_ImagePath->setText(QApplication::translate("VisualizationWidget", "IMAGE\n"
"PATH", Q_NULLPTR));
        m_btn_ModelPath->setText(QApplication::translate("VisualizationWidget", "MODEL\n"
"PATH", Q_NULLPTR));
        m_btn_OpenImage->setText(QApplication::translate("VisualizationWidget", "OPEN\n"
"IMAGE", Q_NULLPTR));
        m_btn_OpenCamera->setText(QApplication::translate("VisualizationWidget", "OPEN\n"
"CAMERA", Q_NULLPTR));
        label->setText(QApplication::translate("VisualizationWidget", "Load Dataset & Model:", Q_NULLPTR));
        m_btn_ImagePath_Reset->setText(QApplication::translate("VisualizationWidget", "reset", Q_NULLPTR));
        m_btn_ModelPath_Reset->setText(QApplication::translate("VisualizationWidget", "reset", Q_NULLPTR));
        m_btn_OpenImage_Reset->setText(QApplication::translate("VisualizationWidget", "reset", Q_NULLPTR));
        m_btn_OpenCamera_Reset->setText(QApplication::translate("VisualizationWidget", "reset", Q_NULLPTR));
        label_2->setText(QApplication::translate("VisualizationWidget", "Import Image for Visualization:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VisualizationWidget: public Ui_VisualizationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZATIONWIDGET_H
