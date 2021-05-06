/********************************************************************************
** Form generated from reading UI file 'HomepageWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGEWIDGET_H
#define UI_HOMEPAGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomepageWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *m_btn_Get_Started;

    void setupUi(QWidget *HomepageWidget)
    {
        if (HomepageWidget->objectName().isEmpty())
            HomepageWidget->setObjectName(QStringLiteral("HomepageWidget"));
        HomepageWidget->resize(700, 500);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HomepageWidget->sizePolicy().hasHeightForWidth());
        HomepageWidget->setSizePolicy(sizePolicy);
        HomepageWidget->setStyleSheet(QStringLiteral("background-image: url(:/images/1-home/background.jpg)"));
        horizontalLayout = new QHBoxLayout(HomepageWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(50, 100, 50, 100);
        label = new QLabel(HomepageWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(30);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background: transparent;"));
        label->setTextFormat(Qt::AutoText);

        verticalLayout->addWidget(label);

        m_btn_Get_Started = new QPushButton(HomepageWidget);
        m_btn_Get_Started->setObjectName(QStringLiteral("m_btn_Get_Started"));
        QFont font1;
        font1.setPointSize(26);
        m_btn_Get_Started->setFont(font1);
        m_btn_Get_Started->setFocusPolicy(Qt::StrongFocus);
        m_btn_Get_Started->setStyleSheet(QLatin1String("background-color: rgb(82, 255, 244);\n"
"color: rgb(255, 170, 0);\n"
"background: transparent;"));
        m_btn_Get_Started->setInputMethodHints(Qt::ImhNone);
        m_btn_Get_Started->setCheckable(false);
        m_btn_Get_Started->setChecked(false);
        m_btn_Get_Started->setAutoRepeat(false);
        m_btn_Get_Started->setAutoExclusive(false);
        m_btn_Get_Started->setAutoDefault(false);
        m_btn_Get_Started->setFlat(false);

        verticalLayout->addWidget(m_btn_Get_Started);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(HomepageWidget);

        m_btn_Get_Started->setDefault(false);


        QMetaObject::connectSlotsByName(HomepageWidget);
    } // setupUi

    void retranslateUi(QWidget *HomepageWidget)
    {
        HomepageWidget->setWindowTitle(QApplication::translate("HomepageWidget", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("HomepageWidget", "Learning\n"
"Computer Vision", Q_NULLPTR));
        m_btn_Get_Started->setText(QApplication::translate("HomepageWidget", "Get Started", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HomepageWidget: public Ui_HomepageWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGEWIDGET_H
