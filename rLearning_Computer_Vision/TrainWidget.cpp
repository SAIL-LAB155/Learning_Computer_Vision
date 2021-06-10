#include "TrainWidget.h"
#include "ui_TrainWidget.h"

#include "pythoncomm.h"

#include <QPainter>
#include <QDebug>

#define Train_Server_Port 6666

#define PLOT_PATH "/home/nvidia/tmp/plot.jpg"

TrainWidget::TrainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrainWidget)
{
    ui->setupUi(this);
	setAttribute(Qt::WA_StyledBackground);
	Init();

	m_server = new QTcpServer;
	m_socket = new QTcpSocket;
	if(!m_server->listen(QHostAddress::AnyIPv4,quint16(Train_Server_Port))){
		QMessageBox::critical(NULL, "critical", "m_server listen fail", QMessageBox::Yes, QMessageBox::Yes);
		exit(1);
	}

	connect(m_server,SIGNAL(newConnection()),this,SLOT(newConnected()));
	if(pPythonCommInshtance)
	{
		connect(pPythonCommInshtance,SIGNAL(Signal_Train_Ok()),this,SLOT(Train_OK()));
		connect(pPythonCommInshtance,SIGNAL(Signal_Update_Plot()),this,SLOT(Update_Plot()));
	}
}

TrainWidget::~TrainWidget()
{
    delete ui;
}

void TrainWidget::Init(void)
{
	Setting_Clear();
	Plotting_Clear();
	TrainingLog_Clear();
}

void TrainWidget::Setting_Update_RunBtn(void)
{
	if("" != ParaCB.Get_ImagePath())
	{
		ui->m_btn_Run->setEnabled(true);
	}
	else
	{
		ui->m_btn_Run->setEnabled(false);
	}
}

void TrainWidget::Setting_Clear(void)
{
	QString nullQString = "";
	ParaCB.Set_ImagePath(nullQString);
	ParaCB.Set_ModelPath(nullQString);

	ui->horizontalSlider->setValue(15);
	ui->m_btn_Run->setEnabled(false);

	ui->m_btn_Run->setText("Run");
	ui->m_label_SystemStatus->setStyleSheet("background-color: rgb(255, 0, 0)");

	ui->m_btn_Image->setEnabled(true);
	ui->m_btn_ImageReset->setEnabled(false);
	ui->m_btn_ImageReset->setStyleSheet("background-color: rgb(255, 0, 0)");

	ui->m_btn_Model->setEnabled(true);
	ui->m_btn_ModelReset->setEnabled(false);
	ui->m_btn_ModelReset->setStyleSheet("background-color: rgb(255, 0, 0)");

	ui->m_btn_Reset->setEnabled(true);
	ui->horizontalSlider->setEnabled(true);

	Training_Stop();
}

void TrainWidget::Plotting_Clear(void)
{
	ui->m_btn_Display->setEnabled(false);
	m_isPlotDisplay = false;
	update();
}

void TrainWidget::TrainingLog_Clear(void)
{
	ui->textBrowser->clear();
}

void TrainWidget::Training_Start(void)
{
    TrainingLog_Clear();
	m_isTraining = true;

	if(pPythonCommInshtance)
	{
		uint8_t tmpbuf[TX_CMD_START_TRAINING_LEN] = {0};
		tmpbuf[0] = TX_HEAD;
		tmpbuf[1] = (TX_CMD_START_TRAINING_LEN >> 8) & 0xFF;
		tmpbuf[2] = TX_CMD_START_TRAINING_LEN & 0xFF;
		tmpbuf[3] = TX_CMD_START_TRAINING;
		tmpbuf[4] = 0;
		tmpbuf[5] = 0;
		tmpbuf[6] = pPythonCommInshtance->getLRC(tmpbuf,TX_CMD_START_TRAINING_LEN - 2);
		tmpbuf[7] = pPythonCommInshtance->getSum(tmpbuf,TX_CMD_START_TRAINING_LEN - 1);

		pPythonCommInshtance->SendtoPython(tmpbuf,TX_CMD_START_TRAINING_LEN);
	}
}

void TrainWidget::Training_Stop(void)
{
	m_isTraining = false;
	ParaCB.Set_isTrainOkay(false);

	if(pPythonCommInshtance)
	{
		uint8_t tmpbuf[TX_CMD_STOP_TRAINING_LEN] = {0};
		tmpbuf[0] = TX_HEAD;
		tmpbuf[1] = (TX_CMD_STOP_TRAINING_LEN >> 8) & 0xFF;
		tmpbuf[2] = TX_CMD_STOP_TRAINING_LEN & 0xFF;
		tmpbuf[3] = TX_CMD_STOP_TRAINING;
		tmpbuf[4] = 0;
		tmpbuf[5] = 0;
		tmpbuf[6] = pPythonCommInshtance->getLRC(tmpbuf,TX_CMD_STOP_TRAINING_LEN - 2);
		tmpbuf[7] = pPythonCommInshtance->getSum(tmpbuf,TX_CMD_STOP_TRAINING_LEN - 1);

		pPythonCommInshtance->SendtoPython(tmpbuf,TX_CMD_STOP_TRAINING_LEN);
	}
}

void TrainWidget::Train_OK(void)
{
	qDebug() << "Train_OK";
	if(m_isTraining)
	{
		ParaCB.Set_isTrainOkay(true);
		ui->m_btn_Display->setEnabled(true);
		ui->m_label_SystemStatus->setStyleSheet("background-color: rgb(0, 255, 0)");

		ui->m_btn_Run->setText("Run");

		ui->m_btn_Image->setEnabled(true);
		ui->m_btn_ImageReset->setEnabled(true);
		ui->m_btn_Model->setEnabled(true);
		ui->m_btn_ModelReset->setEnabled(true);
		ui->m_btn_Reset->setEnabled(true);
		ui->horizontalSlider->setEnabled(true);

		Training_Stop();
	}
}

void TrainWidget::on_horizontalSlider_valueChanged(int value)
{
	ui->m_label_Epochs->setNum(value);

	if(pPythonCommInshtance)
	{
		uint8_t tmpbuf[TX_CMD_SET_EPOCH_LEN] = {0};

		tmpbuf[0] = TX_HEAD;
		tmpbuf[1] = (TX_CMD_SET_EPOCH_LEN >> 8) & 0xFF;
		tmpbuf[2] = TX_CMD_SET_EPOCH_LEN & 0xFF;
		tmpbuf[3] = TX_CMD_SET_EPOCH;
		tmpbuf[4] = 0;
		tmpbuf[5] = value;
		tmpbuf[6] = pPythonCommInshtance->getLRC(tmpbuf,TX_CMD_SET_EPOCH_LEN - 2);
		tmpbuf[7] = pPythonCommInshtance->getSum(tmpbuf,TX_CMD_SET_EPOCH_LEN - 1);

		pPythonCommInshtance->SendtoPython(tmpbuf,TX_CMD_SET_EPOCH_LEN);
	}
}

void TrainWidget::on_m_btn_Image_clicked()
{
	QString defaultDirName = ParaCB.Get_ImagePath();
	if(defaultDirName.isEmpty())
	{
		defaultDirName = tr(".");
	}
	else
	{
		defaultDirName.resize(defaultDirName.lastIndexOf('/'));
	}


    QString imagePath = QFileDialog::getExistingDirectory(
                nullptr,
                tr("Select DATA Path"),
                defaultDirName,
                QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks |
                QFileDialog::DontUseNativeDialog);

    if("" != imagePath)
	{
		ParaCB.Set_ImagePath(imagePath);
		if("" != ParaCB.Get_ImagePath())
		{
			ui->m_btn_ImageReset->setEnabled(true);
			ui->m_btn_ImageReset->setStyleSheet("background-color: rgb(0, 255, 0)");
		}
		else
		{
			ui->m_btn_ImageReset->setEnabled(false);
			ui->m_btn_ImageReset->setStyleSheet("background-color: rgb(255, 0, 0)");
		}
	}

	Setting_Update_RunBtn();
}

void TrainWidget::on_m_btn_Model_clicked()
{
	QString defaultDirName = ParaCB.Get_ModelPath();
	if(defaultDirName.isEmpty())
	{
		defaultDirName = tr(".");
	}
	else
	{
		defaultDirName.resize(defaultDirName.lastIndexOf('/'));
	}


    QString modelPath = QFileDialog::getExistingDirectory(
        nullptr,
		tr("Select Image Path"),
		"model(*)",
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

	if("" != modelPath)
	{
		ParaCB.Set_ModelPath(modelPath);
		if("" != ParaCB.Get_ModelPath())
		{
			ui->m_btn_ModelReset->setEnabled(true);
			ui->m_btn_ModelReset->setStyleSheet("background-color: rgb(0, 255, 0)");
		}
		else
		{
			ui->m_btn_ModelReset->setEnabled(false);
			ui->m_btn_ModelReset->setStyleSheet("background-color: rgb(255, 0, 0)");
		}
	}

	Setting_Update_RunBtn();
}



void TrainWidget::on_m_btn_Reset_clicked()
{
	Setting_Clear();
	Plotting_Clear();
	TrainingLog_Clear();
}

void TrainWidget::on_m_btn_Run_clicked()
{
	if(true == m_isTraining)
	{
//		ui->m_btn_Run->setText("Run");
//		ui->m_label_SystemStatus->setStyleSheet("background-color: rgb(255, 0, 0)");

//		ui->m_btn_Image->setEnabled(true);
//		ui->m_btn_ImageReset->setEnabled(true);
//		ui->m_btn_Model->setEnabled(true);
//		ui->m_btn_ModelReset->setEnabled(true);
//		ui->m_btn_Reset->setEnabled(true);
//		ui->horizontalSlider->setEnabled(true);

//		Plotting_Clear();
//		TrainingLog_Clear();

//		Training_Stop();

		emit(pPythonCommInshtance->Signal_Train_Ok());
	}
	else
	{
		ui->m_btn_Run->setText("Stop");
		ui->m_label_SystemStatus->setStyleSheet("background-color: rgb(255, 255, 0)");

		ui->m_btn_Image->setEnabled(false);
		ui->m_btn_ImageReset->setEnabled(false);
		ui->m_btn_Model->setEnabled(false);
		ui->m_btn_ModelReset->setEnabled(false);
		ui->m_btn_Reset->setEnabled(false);
		ui->horizontalSlider->setEnabled(false);

		Training_Start();
	}
}

void TrainWidget::on_m_btn_ImageReset_clicked()
{
	QString nullImagePath = QString("");
	ParaCB.Set_ImagePath(nullImagePath);

	ui->m_btn_ImageReset->setEnabled(false);
	ui->m_btn_ImageReset->setStyleSheet("background-color: rgb(255, 0, 0)");

	Setting_Update_RunBtn();
}

void TrainWidget::on_m_btn_ModelReset_clicked()
{
	QString nullModelPath = QString("");
	ParaCB.Set_ModelPath(nullModelPath);

	ui->m_btn_ModelReset->setEnabled(false);
	ui->m_btn_ModelReset->setStyleSheet("background-color: rgb(255, 0, 0)");

	Setting_Update_RunBtn();
}

void TrainWidget::newConnected(void)
{
	qDebug() << "train new connect";
	if(m_server->hasPendingConnections()){
		m_socket = m_server->nextPendingConnection();
		if(!m_socket->isValid()){
			return;
		}
		connect(m_socket,SIGNAL(readyRead()),this,SLOT(recvData()));
	}
}

void TrainWidget::recvData()
{
	QString str = m_socket->readAll();
	if(m_isTraining)
	{
		ui->textBrowser->append(str);
	}
}

void TrainWidget::on_m_btn_Display_clicked()
{

}

void TrainWidget::Update_Plot(void)
{
	m_isPlotDisplay = true;
	update();
}

void TrainWidget::paintEvent(QPaintEvent*)
{
	if(m_isPlotDisplay)
	{
		ui->frame->setStyleSheet("");
		QImage image(PLOT_PATH);
		QPainter painter(this);
		QRect rcPhoto = ui->frame->frameRect();
		rcPhoto.translate(ui->frame->pos() + ui->groupBox_2->pos());
		painter.drawImage(rcPhoto,image);
		ui->frame->show();
	}
	else
	{
		ui->frame->hide();
	}
}
