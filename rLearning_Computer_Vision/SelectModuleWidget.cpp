#include "SelectModuleWidget.h"
#include "ui_SelectModuleWidget.h"

SelectModuleWidget::SelectModuleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelectModuleWidget)
{
    ui->setupUi(this);
	setAttribute(Qt::WA_StyledBackground);
}

SelectModuleWidget::~SelectModuleWidget()
{
    delete ui;
}

void SelectModuleWidget::on_m_btn_Fruit_clicked()
{
    ParaCB.Set_ModuleIndex(Module_Fruit);
    emit Signal_Module_Selected();
}

void SelectModuleWidget::on_m_btn_Creatures_clicked()
{
    ParaCB.Set_ModuleIndex(Module_Creatures);
    emit Signal_Module_Selected();
}

void SelectModuleWidget::on_m_btn_Cat_and_Dog_clicked()
{
    ParaCB.Set_ModuleIndex(Module_Cat_and_Dog);
    emit Signal_Module_Selected();
}

void SelectModuleWidget::on_m_btn_Vehicles_clicked()
{
    ParaCB.Set_ModuleIndex(Module_Vehicles);
    emit Signal_Module_Selected();
}

void SelectModuleWidget::on_m_btn_Human_clicked()
{
    ParaCB.Set_ModuleIndex(Module_Human);
    emit Signal_Module_Selected();
}
