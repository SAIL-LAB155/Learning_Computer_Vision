/********************************************************************************
** Form generated from reading UI file 'AnnotationWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANNOTATIONWIDGET_H
#define UI_ANNOTATIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AnnotationWidget
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *AnnotationWidget)
    {
        if (AnnotationWidget->objectName().isEmpty())
            AnnotationWidget->setObjectName(QStringLiteral("AnnotationWidget"));
        AnnotationWidget->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AnnotationWidget->sizePolicy().hasHeightForWidth());
        AnnotationWidget->setSizePolicy(sizePolicy);
        AnnotationWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(AnnotationWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));

        retranslateUi(AnnotationWidget);

        QMetaObject::connectSlotsByName(AnnotationWidget);
    } // setupUi

    void retranslateUi(QWidget *AnnotationWidget)
    {
        AnnotationWidget->setWindowTitle(QApplication::translate("AnnotationWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AnnotationWidget: public Ui_AnnotationWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANNOTATIONWIDGET_H
