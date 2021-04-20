#include "AnnotationWidget.h"
#include "ui_AnnotationWidget.h"

AnnotationWidget::AnnotationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AnnotationWidget)
{
    ui->setupUi(this);
	setAttribute(Qt::WA_StyledBackground);
}

AnnotationWidget::~AnnotationWidget()
{
    delete ui;
}
