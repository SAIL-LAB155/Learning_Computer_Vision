#ifndef LEARN_COMPUTER_VISION_DIALOG_H
#define LEARN_COMPUTER_VISION_DIALOG_H

#include <QDialog>
#include <QMessageBox>
//#include <QTcpServer>
//#include <QTcpSocket>

#include "pythoncomm.h"

#include "HomepageWidget.h"
#include "SelectModuleWidget.h"
#include "TrainWidget.h"
#include "VisualizationWidget.h"
#include "AnnotationWidget.h"

typedef enum
{
    Widget_Index_Homepage = 0,
    Widget_Index_SelectModule,
    Widget_Index_Train,
    Widget_Index_Visualization,
    Widget_Index_Annotation,

    Widget_Index_Max
}Widget_Index_t;

namespace Ui {
class Learn_Computer_Vision_Dialog;
}

class Learn_Computer_Vision_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Learn_Computer_Vision_Dialog(QWidget *parent = nullptr);
    ~Learn_Computer_Vision_Dialog();

public:
    void SwitchWidget(Widget_Index_t index);
    void resizeEvent(QResizeEvent *event);

private slots:
    void on_m_btn_Home_clicked();

    void on_m_btn_Brain_clicked();

    void on_m_btn_Back_clicked();

    void on_m_btn_Training_clicked();

    void on_m_btn_Visualization_clicked();

    void on_m_btn_Annotation_clicked();

private slots:
    void SelectModuleWidget_Show(void);
	void TrainWidget_Show(void);

private:
    Ui::Learn_Computer_Vision_Dialog *ui;

private:
    HomepageWidget* m_pHomepageDlg;
    SelectModuleWidget* m_pSelectModuleDlg;
    TrainWidget* m_pTrainDlg;
    VisualizationWidget* m_pVisualizationDlg;
    AnnotationWidget* m_pAnnotationDlg;

    Widget_Index_t m_CurrentWidgetIndex;
    QWidget* m_pCurrentWidgetArr[Widget_Index_Max];
};

#endif // m_pAnnotationDlg
