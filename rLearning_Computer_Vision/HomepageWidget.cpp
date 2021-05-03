#include "HomepageWidget.h"
#include "ui_HomepageWidget.h"

HomepageWidget::HomepageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomepageWidget)
{
    ui->setupUi(this);
	setAttribute(Qt::WA_StyledBackground);
}

HomepageWidget::~HomepageWidget()
{
    delete ui;
}

void HomepageWidget::on_m_btn_Get_Started_clicked()
{
    emit Signal_Get_Started();
}
