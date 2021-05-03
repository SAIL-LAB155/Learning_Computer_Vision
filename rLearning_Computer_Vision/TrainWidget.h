#ifndef TRAINWIDGET_H
#define TRAINWIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include <QTcpServer>
#include <QTcpSocket>

#include "ParameterControlBlock.h"

namespace Ui {
class TrainWidget;
}

class TrainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TrainWidget(QWidget *parent = 0);
    ~TrainWidget();

public:
	void Init(void);

private:
	void Setting_Update_RunBtn(void);
	void Setting_Clear(void);
	void Plotting_Clear(void);
	void TrainingLog_Clear(void);

	void Training_Start(void);
	void Training_Stop(void);

private slots:
	void Train_OK(void);

	void Update_Plot(void);

private slots:
	void on_horizontalSlider_valueChanged(int value);

	void on_m_btn_Image_clicked();

	void on_m_btn_Model_clicked();

	void on_m_btn_Reset_clicked();

	void on_m_btn_Run_clicked();

	void on_m_btn_ImageReset_clicked();

	void on_m_btn_ModelReset_clicked();

private slots:
	void newConnected();
	void recvData();

	void on_m_btn_Display_clicked();

private:
	void paintEvent(QPaintEvent*);

private:
    Ui::TrainWidget *ui;
	bool m_isTraining;
	bool m_isPlotDisplay;
	QTcpServer* m_server;
	QTcpSocket* m_socket;
};

#endif // TRAINWIDGET_H
