#ifndef SELECTMODULEWIDGET_H
#define SELECTMODULEWIDGET_H

#include <QWidget>

#include "ParameterControlBlock.h"

namespace Ui {
class SelectModuleWidget;
}

class SelectModuleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SelectModuleWidget(QWidget *parent = 0);
    ~SelectModuleWidget();

private slots:
    void on_m_btn_Fruit_clicked();

    void on_m_btn_Creatures_clicked();

    void on_m_btn_Cat_and_Dog_clicked();

    void on_m_btn_Vehicles_clicked();

    void on_m_btn_Human_clicked();

signals:
    void Signal_Module_Selected(void);

private:
    Ui::SelectModuleWidget *ui;
};

#endif // SELECTMODULEWIDGET_H
