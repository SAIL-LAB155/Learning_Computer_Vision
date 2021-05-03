#ifndef VISUALIZATIONWIDGET_H
#define VISUALIZATIONWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>

#include <QPainter>

#include "ParameterControlBlock.h"

namespace Ui {
class VisualizationWidget;
}

class VisualizationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VisualizationWidget(QWidget *parent = 0);
    ~VisualizationWidget();

public:
	void Init(void);

private:
	void ImagePath_Init(void);
	void ModelPath_Init(void);
	void OpenImage_Init(void);
	void OpenCamera_Init(void);

	bool canOpenImage(void);
	bool canOpenCamera(void);
	void Update_OpenImageBtn(void);
	void Update_OpenCameraBtn(void);

	void OpenImage_Start(void);
	void OpenImage_Stop(void);
	void OpenCamera_Start(void);
	void OpenCamera_Stop(void);

private slots:
	void Update_Picture(void);

private slots:
	void on_m_btn_ImagePath_clicked();

	void on_m_btn_ModelPath_clicked();

	void on_m_btn_OpenImage_clicked();

	void on_m_btn_OpenCamera_clicked();

	void on_m_btn_ImagePath_Reset_clicked();

	void on_m_btn_ModelPath_Reset_clicked();

	void on_m_btn_OpenImage_Reset_clicked();

	void on_m_btn_OpenCamera_Reset_clicked();

	void on_m_btn_Visualize_clicked();

private:
	void paintEvent(QPaintEvent*);

private:
    Ui::VisualizationWidget *ui;

	bool m_isOpenImage;
	bool m_isVisualizing;

	void* m_ptr;
	bool m_isRequestUpdate;
};

#endif // VISUALIZATIONWIDGET_H
