#include "VisualizationWidget.h"
#include "ui_VisualizationWidget.h"

#include "pythoncomm.h"

#include <QDebug>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY     ((key_t)0x20201231)
#define SHM_SIZE    (16*1024*1024)

VisualizationWidget::VisualizationWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisualizationWidget)
{
    ui->setupUi(this);
	setAttribute(Qt::WA_StyledBackground);

	Init();

	if(pPythonCommInshtance)
	{
		connect(pPythonCommInshtance,SIGNAL(Signal_Update_Pic()),this,SLOT(Update_Picture()));
	}

	int shmid = shmget(SHM_KEY,SHM_SIZE,IPC_CREAT|0664);
	if(-1 == shmid)
	{
		qDebug("shmget fail\n");
	}

	m_ptr = shmat(shmid,NULL,0);
	if(((void*)-1) == m_ptr)
	{
		qDebug("shmat fail\n");
	}

	m_isRequestUpdate = false;
}

VisualizationWidget::~VisualizationWidget()
{
    delete ui;
}

void VisualizationWidget::Init(void)
{
	ImagePath_Init();
	ModelPath_Init();
	OpenImage_Init();
	OpenCamera_Init();
    ui->frame->show();
}

void VisualizationWidget::ImagePath_Init(void)
{
	QString nullImagePath = QString("");
	ParaCB.Set_Visualization_ImagePath(nullImagePath);

    ui->m_btn_ImagePath->setEnabled(true);
	ui->m_btn_ImagePath_Reset->setEnabled(false);
	ui->m_btn_ImagePath_Reset->setStyleSheet("background-color: rgb(255, 0, 0)");
}

void VisualizationWidget::ModelPath_Init(void)
{
	QString nullModelPath = QString("");
	ParaCB.Set_Visualization_ModelPath(nullModelPath);

    ui->m_btn_ModelPath->setEnabled(true);
	ui->m_btn_ModelPath_Reset->setEnabled(false);
	ui->m_btn_ModelPath_Reset->setStyleSheet("background-color: rgb(255, 0, 0)");
}

void VisualizationWidget::OpenImage_Init(void)
{
	ui->m_btn_OpenImage->setEnabled(true);
	ui->m_btn_OpenImage_Reset->setEnabled(false);
	ui->m_btn_OpenImage_Reset->setStyleSheet("background-color: rgb(255, 0, 0)");

	ui->m_btn_Visualize->setEnabled(false);

	OpenImage_Stop();
}

void VisualizationWidget::OpenCamera_Init(void)
{
	ui->m_btn_OpenCamera->setEnabled(true);
	ui->m_btn_OpenCamera_Reset->setEnabled(false);
	ui->m_btn_OpenCamera_Reset->setStyleSheet("background-color: rgb(255, 0, 0)");

	ui->m_btn_Visualize->setEnabled(false);

	ui->m_btn_Visualize->setText("VISUALIZE");

	OpenCamera_Stop();
}

bool VisualizationWidget::canOpenImage(void)
{
	return (("" != ParaCB.Get_Visualization_ImagePath()) && (("" != ParaCB.Get_Visualization_ModelPath()) || (ParaCB.Get_isTrainOkay())));
}

bool VisualizationWidget::canOpenCamera(void)
{
	return (("" != ParaCB.Get_Visualization_ModelPath()) || (ParaCB.Get_isTrainOkay()));
}

void VisualizationWidget::Update_OpenImageBtn(void)
{
	ui->m_btn_OpenImage->setEnabled(true);
	ui->m_btn_OpenImage_Reset->setEnabled(false);
	ui->m_btn_OpenImage_Reset->setStyleSheet("background-color: rgb(255, 0, 0)");
}

void VisualizationWidget::Update_OpenCameraBtn(void)
{
	ui->m_btn_OpenCamera->setEnabled(true);
	ui->m_btn_OpenCamera_Reset->setEnabled(false);
	ui->m_btn_OpenCamera_Reset->setStyleSheet("background-color: rgb(255, 0, 0)");
}

void VisualizationWidget::OpenImage_Start(void)
{
	m_isOpenImage = true;

	if(pPythonCommInshtance)
	{
		uint8_t tmpbuf[TX_CMD_VIS_LEN] = {0};

		tmpbuf[0] = TX_HEAD;
		tmpbuf[1] = (TX_CMD_VIS_LEN >> 8) & 0xFF;
		tmpbuf[2] = TX_CMD_VIS_LEN & 0xFF;
		tmpbuf[3] = TX_CMD_VIS;
		tmpbuf[4] = 0;
		tmpbuf[5] = 0;
		tmpbuf[6] = pPythonCommInshtance->getLRC(tmpbuf,TX_CMD_VIS_LEN - 2);
		tmpbuf[7] = pPythonCommInshtance->getSum(tmpbuf,TX_CMD_VIS_LEN - 1);

		pPythonCommInshtance->SendtoPython(tmpbuf,TX_CMD_VIS_LEN);
	}
}

void VisualizationWidget::OpenImage_Stop(void)
{
	m_isOpenImage = false;
}

void VisualizationWidget::OpenCamera_Start(void)
{
	m_isVisualizing = true;

	if(pPythonCommInshtance)
	{
		uint8_t tmpbuf[TX_CMD_OPEN_CAM_LEN] = {0};

		tmpbuf[0] = TX_HEAD;
		tmpbuf[1] = (TX_CMD_OPEN_CAM_LEN >> 8) & 0xFF;
		tmpbuf[2] = TX_CMD_OPEN_CAM_LEN & 0xFF;
		tmpbuf[3] = TX_CMD_OPEN_CAM;
		tmpbuf[4] = 0;
		tmpbuf[5] = 0;
		tmpbuf[6] = pPythonCommInshtance->getLRC(tmpbuf,TX_CMD_OPEN_CAM_LEN - 2);
		tmpbuf[7] = pPythonCommInshtance->getSum(tmpbuf,TX_CMD_OPEN_CAM_LEN - 1);

		pPythonCommInshtance->SendtoPython(tmpbuf,TX_CMD_OPEN_CAM_LEN);
	}
}
void VisualizationWidget::OpenCamera_Stop(void)
{
	m_isVisualizing = false;

	if(pPythonCommInshtance)
	{
		uint8_t tmpbuf[TX_CMD_VIS_LEN] = {0};

		tmpbuf[0] = TX_HEAD;
		tmpbuf[1] = (TX_CMD_STOP_OPEN_CAM_LEN >> 8) & 0xFF;
		tmpbuf[2] = TX_CMD_STOP_OPEN_CAM_LEN & 0xFF;
		tmpbuf[3] = TX_CMD_STOP_OPEN_CAM;
		tmpbuf[4] = 0;
		tmpbuf[5] = 0;
		tmpbuf[6] = pPythonCommInshtance->getLRC(tmpbuf,TX_CMD_STOP_OPEN_CAM_LEN - 2);
		tmpbuf[7] = pPythonCommInshtance->getSum(tmpbuf,TX_CMD_STOP_OPEN_CAM_LEN - 1);

		pPythonCommInshtance->SendtoPython(tmpbuf,TX_CMD_STOP_OPEN_CAM_LEN);
	}
}

void VisualizationWidget::paintEvent(QPaintEvent*)
{
	if(m_isRequestUpdate)
	{
		int* pi = (int*)m_ptr;
		int size = *pi;
		uchar* ptr = (uchar*)m_ptr + sizeof(int);

		QImage image = QImage::fromData(ptr,size);
		QPainter painter(this);
		QRect rcPhoto = ui->frame->frameRect();
		rcPhoto.translate(ui->frame->pos());
		painter.drawImage(rcPhoto,image);

		m_isRequestUpdate = false;
	}
}

void VisualizationWidget::Update_Picture(void)
{
    ui->frame->hide();
	m_isRequestUpdate = true;
	update();
}

void VisualizationWidget::on_m_btn_ImagePath_clicked()
{
	QString defaultDirName = ParaCB.Get_Visualization_ImagePath();
	if(defaultDirName.isEmpty())
	{
		defaultDirName = tr(".");
	}
	else
	{
		defaultDirName.resize(defaultDirName.lastIndexOf('/'));
	}


	QString imagePath = QFileDialog::getOpenFileName(
		this,
		tr("Select Image Path"),
		defaultDirName,
		"Images (*.png *.jpg)",
        0,
        QFileDialog::DontUseNativeDialog);

	if("" != imagePath)
	{
		ParaCB.Set_Visualization_ImagePath(imagePath);
		if("" != ParaCB.Get_Visualization_ImagePath())
		{
			ui->m_btn_ImagePath_Reset->setEnabled(true);
			ui->m_btn_ImagePath_Reset->setStyleSheet("background-color: rgb(0, 255, 0)");
		}
		else
		{
			ui->m_btn_ImagePath_Reset->setEnabled(false);
			ui->m_btn_ImagePath_Reset->setStyleSheet("background-color: rgb(255, 0, 0)");
		}
	}

	Update_OpenImageBtn();
	Update_OpenCameraBtn();
}

void VisualizationWidget::on_m_btn_ModelPath_clicked()
{
	QString defaultDirName = ParaCB.Get_Visualization_ModelPath();
	if(defaultDirName.isEmpty())
	{
		defaultDirName = tr(".");
	}
	else
	{
		defaultDirName.resize(defaultDirName.lastIndexOf('/'));
	}


	QString modelPath = QFileDialog::getOpenFileName(
		this,
		tr("Select Image Path"),
		defaultDirName,
		"model(*)",
        0,
        QFileDialog::DontUseNativeDialog);

	if("" != modelPath)
	{
		ParaCB.Set_Visualization_ModelPath(modelPath);
		if("" != ParaCB.Get_Visualization_ModelPath())
		{
			ui->m_btn_ModelPath_Reset->setEnabled(true);
			ui->m_btn_ModelPath_Reset->setStyleSheet("background-color: rgb(0, 255, 0)");
		}
		else
		{
			ui->m_btn_ModelPath_Reset->setEnabled(false);
			ui->m_btn_ModelPath_Reset->setStyleSheet("background-color: rgb(255, 0, 0)");
		}
	}

	Update_OpenImageBtn();
	Update_OpenCameraBtn();
}

void VisualizationWidget::on_m_btn_OpenImage_clicked()
{
	if(canOpenImage())
	{
		ui->m_btn_ImagePath->setEnabled(false);
		ui->m_btn_ImagePath_Reset->setEnabled(false);

		ui->m_btn_ModelPath->setEnabled(false);
		ui->m_btn_ModelPath_Reset->setEnabled(false);

		ui->m_btn_OpenCamera->setEnabled(false);
		ui->m_btn_OpenCamera_Reset->setEnabled(false);

		ui->m_btn_OpenImage_Reset->setEnabled(true);
		ui->m_btn_OpenImage_Reset->setStyleSheet("background-color: rgb(0, 255, 0)");

		ui->m_btn_Visualize->setEnabled(true);

		OpenImage_Start();
	}
	else
	{
		QMessageBox::warning(NULL, "warning", "You should choose ImagePath and ModelPath", QMessageBox::Yes, QMessageBox::Yes);
	}
}

void VisualizationWidget::on_m_btn_OpenCamera_clicked()
{
	if(canOpenCamera())
	{
		ui->m_btn_ImagePath->setEnabled(false);
		ui->m_btn_ImagePath_Reset->setEnabled(false);

		ui->m_btn_ModelPath->setEnabled(false);
		ui->m_btn_ModelPath_Reset->setEnabled(false);

		ui->m_btn_OpenImage->setEnabled(false);
		ui->m_btn_OpenImage_Reset->setEnabled(false);

		ui->m_btn_OpenCamera_Reset->setEnabled(true);
		ui->m_btn_OpenCamera_Reset->setStyleSheet("background-color: rgb(0, 255, 0)");

		ui->m_btn_Visualize->setEnabled(true);

		ui->m_btn_Visualize->setText("Stop");

		OpenCamera_Start();
	}
	else
	{
		QMessageBox::warning(NULL, "warning", "You should choose ModelPath", QMessageBox::Yes, QMessageBox::Yes);
	}
}

void VisualizationWidget::on_m_btn_ImagePath_Reset_clicked()
{
	ImagePath_Init();

	Update_OpenImageBtn();
	Update_OpenCameraBtn();
}

void VisualizationWidget::on_m_btn_ModelPath_Reset_clicked()
{
	ModelPath_Init();

	Update_OpenImageBtn();
	Update_OpenCameraBtn();
}

void VisualizationWidget::on_m_btn_OpenImage_Reset_clicked()
{
	ui->m_btn_ImagePath->setEnabled(true);
	ui->m_btn_ImagePath_Reset->setEnabled(true);

	ui->m_btn_ModelPath->setEnabled(true);
	ui->m_btn_ModelPath_Reset->setEnabled(true);

	OpenImage_Init();

	Update_OpenImageBtn();
	Update_OpenCameraBtn();
}

void VisualizationWidget::on_m_btn_OpenCamera_Reset_clicked()
{
	ui->m_btn_ImagePath->setEnabled(true);
	ui->m_btn_ImagePath_Reset->setEnabled(true);

	ui->m_btn_ModelPath->setEnabled(true);
	ui->m_btn_ModelPath_Reset->setEnabled(true);

	OpenCamera_Init();

	Update_OpenImageBtn();
	Update_OpenCameraBtn();
}

void VisualizationWidget::on_m_btn_Visualize_clicked()
{
	if(m_isOpenImage)
	{
		if(m_isVisualizing)
		{
			ui->m_btn_ImagePath->setEnabled(true);
			ui->m_btn_ImagePath_Reset->setEnabled(true);

			ui->m_btn_ModelPath->setEnabled(true);
			ui->m_btn_ModelPath_Reset->setEnabled(true);

			ui->m_btn_OpenImage->setEnabled(true);
			ui->m_btn_OpenImage_Reset->setEnabled(true);

			ui->m_btn_Visualize->setText("VISUALIZE");

			OpenCamera_Stop();
		}
		else
		{
			ui->m_btn_ImagePath->setEnabled(false);
			ui->m_btn_ImagePath_Reset->setEnabled(false);

			ui->m_btn_ModelPath->setEnabled(false);
			ui->m_btn_ModelPath_Reset->setEnabled(false);

			ui->m_btn_OpenImage->setEnabled(false);
			ui->m_btn_OpenImage_Reset->setEnabled(false);

			ui->m_btn_Visualize->setText("Stop");

			OpenCamera_Start();
		}
	}
	else
	{
		on_m_btn_OpenCamera_Reset_clicked();
	}
}
