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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisualizationWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *m_btn_ImagePath;
    QPushButton *m_btn_ImagePath_Reset;
    QPushButton *m_btn_ModelPath;
    QPushButton *m_btn_ModelPath_Reset;
    QLabel *label_2;
    QPushButton *m_btn_OpenImage;
    QPushButton *m_btn_OpenImage_Reset;
    QPushButton *m_btn_OpenCamera;
    QPushButton *m_btn_OpenCamera_Reset;

    void setupUi(QWidget *VisualizationWidget)
    {
        if (VisualizationWidget->objectName().isEmpty())
            VisualizationWidget->setObjectName(QStringLiteral("VisualizationWidget"));
        VisualizationWidget->resize(700, 519);
        VisualizationWidget->setStyleSheet(QStringLiteral("background-color: rgb(177, 181, 182);"));
        horizontalLayout = new QHBoxLayout(VisualizationWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        frame = new QFrame(VisualizationWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        verticalLayout_2->addWidget(frame);

        verticalLayout_2->setStretch(0, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(VisualizationWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(0, 20));
        QFont font;
        font.setFamily(QStringLiteral("Purisa"));
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        m_btn_ImagePath = new QPushButton(VisualizationWidget);
        m_btn_ImagePath->setObjectName(QStringLiteral("m_btn_ImagePath"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_btn_ImagePath->sizePolicy().hasHeightForWidth());
        m_btn_ImagePath->setSizePolicy(sizePolicy1);
        m_btn_ImagePath->setMinimumSize(QSize(80, 80));
        m_btn_ImagePath->setFont(font);
        m_btn_ImagePath->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"border-image: url(:/images/2-training/subpage/image-path.png);"));

        verticalLayout->addWidget(m_btn_ImagePath, 0, Qt::AlignHCenter);

        m_btn_ImagePath_Reset = new QPushButton(VisualizationWidget);
        m_btn_ImagePath_Reset->setObjectName(QStringLiteral("m_btn_ImagePath_Reset"));
        sizePolicy.setHeightForWidth(m_btn_ImagePath_Reset->sizePolicy().hasHeightForWidth());
        m_btn_ImagePath_Reset->setSizePolicy(sizePolicy);
        m_btn_ImagePath_Reset->setMinimumSize(QSize(0, 20));
        m_btn_ImagePath_Reset->setFont(font);
        m_btn_ImagePath_Reset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));

        verticalLayout->addWidget(m_btn_ImagePath_Reset);

        m_btn_ModelPath = new QPushButton(VisualizationWidget);
        m_btn_ModelPath->setObjectName(QStringLiteral("m_btn_ModelPath"));
        sizePolicy1.setHeightForWidth(m_btn_ModelPath->sizePolicy().hasHeightForWidth());
        m_btn_ModelPath->setSizePolicy(sizePolicy1);
        m_btn_ModelPath->setMinimumSize(QSize(80, 80));
        m_btn_ModelPath->setFont(font);
        m_btn_ModelPath->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"border-image: url(:/images/2-training/subpage/model-path.png);"));

        verticalLayout->addWidget(m_btn_ModelPath, 0, Qt::AlignHCenter);

        m_btn_ModelPath_Reset = new QPushButton(VisualizationWidget);
        m_btn_ModelPath_Reset->setObjectName(QStringLiteral("m_btn_ModelPath_Reset"));
        sizePolicy.setHeightForWidth(m_btn_ModelPath_Reset->sizePolicy().hasHeightForWidth());
        m_btn_ModelPath_Reset->setSizePolicy(sizePolicy);
        m_btn_ModelPath_Reset->setMinimumSize(QSize(0, 20));
        m_btn_ModelPath_Reset->setFont(font);
        m_btn_ModelPath_Reset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));

        verticalLayout->addWidget(m_btn_ModelPath_Reset);

        label_2 = new QLabel(VisualizationWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_2->setAlignment(Qt::AlignCenter);
        label_2->setWordWrap(true);

        verticalLayout->addWidget(label_2);

        m_btn_OpenImage = new QPushButton(VisualizationWidget);
        m_btn_OpenImage->setObjectName(QStringLiteral("m_btn_OpenImage"));
        sizePolicy1.setHeightForWidth(m_btn_OpenImage->sizePolicy().hasHeightForWidth());
        m_btn_OpenImage->setSizePolicy(sizePolicy1);
        m_btn_OpenImage->setMinimumSize(QSize(80, 80));
        m_btn_OpenImage->setFont(font);
        m_btn_OpenImage->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"border-image: url(:/images/3-visualization/open-image.png);"));

        verticalLayout->addWidget(m_btn_OpenImage, 0, Qt::AlignHCenter);

        m_btn_OpenImage_Reset = new QPushButton(VisualizationWidget);
        m_btn_OpenImage_Reset->setObjectName(QStringLiteral("m_btn_OpenImage_Reset"));
        sizePolicy.setHeightForWidth(m_btn_OpenImage_Reset->sizePolicy().hasHeightForWidth());
        m_btn_OpenImage_Reset->setSizePolicy(sizePolicy);
        m_btn_OpenImage_Reset->setMinimumSize(QSize(0, 20));
        m_btn_OpenImage_Reset->setFont(font);
        m_btn_OpenImage_Reset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));

        verticalLayout->addWidget(m_btn_OpenImage_Reset);

        m_btn_OpenCamera = new QPushButton(VisualizationWidget);
        m_btn_OpenCamera->setObjectName(QStringLiteral("m_btn_OpenCamera"));
        sizePolicy1.setHeightForWidth(m_btn_OpenCamera->sizePolicy().hasHeightForWidth());
        m_btn_OpenCamera->setSizePolicy(sizePolicy1);
        m_btn_OpenCamera->setMinimumSize(QSize(80, 80));
        m_btn_OpenCamera->setFont(font);
        m_btn_OpenCamera->setStyleSheet(QLatin1String("color: rgb(0, 0, 255);\n"
"border-image: url(:/images/3-visualization/open-camera.png);"));

        verticalLayout->addWidget(m_btn_OpenCamera, 0, Qt::AlignHCenter);

        m_btn_OpenCamera_Reset = new QPushButton(VisualizationWidget);
        m_btn_OpenCamera_Reset->setObjectName(QStringLiteral("m_btn_OpenCamera_Reset"));
        sizePolicy.setHeightForWidth(m_btn_OpenCamera_Reset->sizePolicy().hasHeightForWidth());
        m_btn_OpenCamera_Reset->setSizePolicy(sizePolicy);
        m_btn_OpenCamera_Reset->setMinimumSize(QSize(0, 20));
        m_btn_OpenCamera_Reset->setFont(font);
        m_btn_OpenCamera_Reset->setStyleSheet(QStringLiteral("background-color: rgb(225, 225, 225);"));

        verticalLayout->addWidget(m_btn_OpenCamera_Reset);


        horizontalLayout->addLayout(verticalLayout);

        horizontalLayout->setStretch(0, 10);

        retranslateUi(VisualizationWidget);

        QMetaObject::connectSlotsByName(VisualizationWidget);
    } // setupUi

    void retranslateUi(QWidget *VisualizationWidget)
    {
        VisualizationWidget->setWindowTitle(QApplication::translate("VisualizationWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("VisualizationWidget", "Load Dataset & Model:", Q_NULLPTR));
        m_btn_ImagePath->setText(QApplication::translate("VisualizationWidget", "IMAGE\n"
"PATH", Q_NULLPTR));
        m_btn_ImagePath_Reset->setText(QApplication::translate("VisualizationWidget", "RESET", Q_NULLPTR));
        m_btn_ModelPath->setText(QApplication::translate("VisualizationWidget", "MODEL\n"
"PATH", Q_NULLPTR));
        m_btn_ModelPath_Reset->setText(QApplication::translate("VisualizationWidget", "RESET", Q_NULLPTR));
        label_2->setText(QApplication::translate("VisualizationWidget", "Import Image for Visualization:", Q_NULLPTR));
        m_btn_OpenImage->setText(QApplication::translate("VisualizationWidget", "OPEN\n"
"IMAGE", Q_NULLPTR));
        m_btn_OpenImage_Reset->setText(QApplication::translate("VisualizationWidget", "RESET", Q_NULLPTR));
        m_btn_OpenCamera->setText(QApplication::translate("VisualizationWidget", "OPEN\n"
"CAMERA", Q_NULLPTR));
        m_btn_OpenCamera_Reset->setText(QApplication::translate("VisualizationWidget", "RESET", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VisualizationWidget: public Ui_VisualizationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZATIONWIDGET_H
