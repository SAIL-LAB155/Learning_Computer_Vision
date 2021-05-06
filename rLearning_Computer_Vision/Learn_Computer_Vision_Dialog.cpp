#include "Learn_Computer_Vision_Dialog.h"
#include "ui_Learn_Computer_Vision_Dialog.h"

#include <QDebug>
#include "ParameterControlBlock.h"
#include <iostream>

void Learn_Computer_Vision_Dialog::resizeEvent(QResizeEvent *event){
    m_pHomepageDlg->resize(width()-100, height()-100);
    m_pHomepageDlg->setStyleSheet("HomepageWidget{ border-image: url(:/images/1-home/background.jpg) }");
    m_pSelectModuleDlg->resize(width()-100, height()-100);
    m_pTrainDlg->resize(width()-100, height()-100);
    m_pVisualizationDlg->resize(width()-100, height()-100);
    m_pAnnotationDlg->resize(width()-100, height()-100);
}

Learn_Computer_Vision_Dialog::Learn_Computer_Vision_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Learn_Computer_Vision_Dialog)
{
    ui->setupUi(this);

    if(NULL == pPythonCommInshtance)
	{
		pPythonCommInshtance = new PythonComm;
		if(NULL == pPythonCommInshtance)
		{
			qDebug() << "new pPythonCommInshtance fail";
			exit(2);
		}
	}

    m_pHomepageDlg = new HomepageWidget(this);
    m_pSelectModuleDlg = new SelectModuleWidget(this);
    m_pTrainDlg = new TrainWidget(this);
    m_pVisualizationDlg = new VisualizationWidget(this);
    m_pAnnotationDlg = new AnnotationWidget(this);

    if(m_pHomepageDlg && m_pSelectModuleDlg && m_pTrainDlg && m_pVisualizationDlg && m_pAnnotationDlg)
    {
        m_pHomepageDlg->move(80,80);
        m_pSelectModuleDlg->move(80,80);
        m_pTrainDlg->move(80,80);
        m_pVisualizationDlg->move(80,80);
        m_pAnnotationDlg->move(80,80);

        m_pHomepageDlg->hide();
        m_pSelectModuleDlg->hide();
        m_pTrainDlg->hide();
        m_pVisualizationDlg->hide();
        m_pAnnotationDlg->hide();

        m_pCurrentWidgetArr[Widget_Index_Homepage] = m_pHomepageDlg;
        m_pCurrentWidgetArr[Widget_Index_SelectModule] = m_pSelectModuleDlg;
        m_pCurrentWidgetArr[Widget_Index_Train] = m_pTrainDlg;
        m_pCurrentWidgetArr[Widget_Index_Visualization] = m_pVisualizationDlg;
        m_pCurrentWidgetArr[Widget_Index_Annotation] = m_pAnnotationDlg;

        // this->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
        // this->setFixedSize(width,height);

        m_CurrentWidgetIndex = Widget_Index_Max;
        SwitchWidget(Widget_Index_Homepage);

        connect(m_pHomepageDlg,
                SIGNAL(Signal_Get_Started(void)),
                this,
                SLOT(SelectModuleWidget_Show(void)));

        connect(m_pSelectModuleDlg,
                SIGNAL(Signal_Module_Selected(void)),
                this,
                SLOT(TrainWidget_Show(void)));
    }
    else
    {
        exit(1);
	}
}

Learn_Computer_Vision_Dialog::~Learn_Computer_Vision_Dialog()
{
    delete ui;
}

void Learn_Computer_Vision_Dialog::SwitchWidget(Widget_Index_t index)
{
    if((index < Widget_Index_Max) && (index != m_CurrentWidgetIndex))
    {
        if(m_CurrentWidgetIndex < Widget_Index_Max)
        {
            m_pCurrentWidgetArr[m_CurrentWidgetIndex]->hide();
        }

        m_CurrentWidgetIndex = index;
        m_pCurrentWidgetArr[m_CurrentWidgetIndex]->show();
        if(Widget_Index_Homepage == m_CurrentWidgetIndex)
		{
            ui->m_btn_Home->show();
            ui->m_btn_Brain->hide();

            ui->m_btn_Back->hide();

            ui->m_btn_Training->hide();
            ui->m_btn_Visualization->hide();
            ui->m_btn_Annotation->hide();

            ui->m_btn_Home->setStyleSheet("border-image: url(:/images/left-navigator/home-w.png);");
			ui->m_btn_Brain->setStyleSheet("border-image: url(:/images/left-navigator/func-g.png);");
			ui->m_btn_Training->setStyleSheet("");
			ui->m_btn_Visualization->setStyleSheet("");
			ui->m_btn_Annotation->setStyleSheet("");
        }
        else if(Widget_Index_SelectModule == m_CurrentWidgetIndex)
        {
            ui->m_btn_Home->show();
			ui->m_btn_Brain->show();

            ui->m_btn_Back->hide();

            ui->m_btn_Training->hide();
            ui->m_btn_Visualization->hide();
            ui->m_btn_Annotation->hide();

			ui->m_btn_Home->setStyleSheet("border-image: url(:/images/left-navigator/home-g.png);");
			ui->m_btn_Brain->setStyleSheet("border-image: url(:/images/left-navigator/func-w.png);");
			ui->m_btn_Training->setStyleSheet("");
			ui->m_btn_Visualization->setStyleSheet("");
			ui->m_btn_Annotation->setStyleSheet("");
        }
        else if(Widget_Index_Train == m_CurrentWidgetIndex)
		{
            ui->m_btn_Home->show();
            ui->m_btn_Brain->show();

            ui->m_btn_Back->show();

            ui->m_btn_Training->show();
            ui->m_btn_Visualization->show();
            ui->m_btn_Annotation->show();

			ui->m_btn_Home->setStyleSheet("border-image: url(:/images/left-navigator/home-g.png);");
			ui->m_btn_Brain->setStyleSheet("border-image: url(:/images/left-navigator/func-g.png)");
			ui->m_btn_Training->setStyleSheet("background-color: rgb(38, 67, 255);color: rgb(255, 0, 0);");
			ui->m_btn_Visualization->setStyleSheet("background-color: rgb(155, 255, 255);color: rgb(255, 0, 0);");
			ui->m_btn_Annotation->setStyleSheet("background-color: rgb(155, 255, 255);color: rgb(255, 0, 0);");

			switch (ParaCB.Get_ModuleIndex())
			{
				case Module_Fruit:
                    m_pCurrentWidgetArr[Widget_Index_Train]->setStyleSheet("background-image: url(:/images/2-training/subpage/background/detection-fruits.png)");
					break;
				case Module_Creatures:
                    m_pCurrentWidgetArr[Widget_Index_Train]->setStyleSheet("background-image: url(:/images/2-training/subpage/background/detection-creature.png)");
					break;
				case Module_Cat_and_Dog:
                    m_pCurrentWidgetArr[Widget_Index_Train]->setStyleSheet("background-image: url(:/images/2-training/subpage/background/classification-pets.png)");
					break;
				case Module_Vehicles:
                    m_pCurrentWidgetArr[Widget_Index_Train]->setStyleSheet("background-image: url(:/images/2-training/subpage/background/classification-others.png)");
					break;
				case Module_Human:
                    m_pCurrentWidgetArr[Widget_Index_Train]->setStyleSheet("background-image: url(:/images/2-training/subpage/background/pose-estimation.png)");
					break;
				default:
                    m_pCurrentWidgetArr[Widget_Index_Train]->setStyleSheet("TrainWidget { background-color: rgb(177, 181, 182) }");
					break;
			}
        }
		else if(Widget_Index_Visualization == m_CurrentWidgetIndex)
		{
			ui->m_btn_Home->show();
			ui->m_btn_Brain->show();

			ui->m_btn_Back->show();

			ui->m_btn_Training->show();
			ui->m_btn_Visualization->show();
			ui->m_btn_Annotation->show();

			ui->m_btn_Home->setStyleSheet("border-image: url(:/images/left-navigator/home-g.png);");
			ui->m_btn_Brain->setStyleSheet("border-image: url(:/images/left-navigator/func-g.png)");
			ui->m_btn_Training->setStyleSheet("background-color: rgb(155, 255, 255);color: rgb(255, 0, 0);");
			ui->m_btn_Visualization->setStyleSheet("background-color: rgb(38, 67, 255);color: rgb(255, 0, 0);");
			ui->m_btn_Annotation->setStyleSheet("background-color: rgb(155, 255, 255);color: rgb(255, 0, 0);");
		}
		else if(Widget_Index_Annotation == m_CurrentWidgetIndex)
		{
			ui->m_btn_Home->show();
			ui->m_btn_Brain->show();

			ui->m_btn_Back->show();

			ui->m_btn_Training->show();
			ui->m_btn_Visualization->show();
			ui->m_btn_Annotation->show();

			ui->m_btn_Home->setStyleSheet("border-image: url(:/images/left-navigator/home-g.png);");
			ui->m_btn_Brain->setStyleSheet("border-image: url(:/images/left-navigator/func-g.png)");
			ui->m_btn_Training->setStyleSheet("background-color: rgb(155, 255, 255);color: rgb(255, 0, 0);");
			ui->m_btn_Visualization->setStyleSheet("background-color: rgb(155, 255, 255);color: rgb(255, 0, 0);");
			ui->m_btn_Annotation->setStyleSheet("background-color: rgb(38, 67, 255);color: rgb(255, 0, 0);");
		}
        else
        {
        }
    }
}

void Learn_Computer_Vision_Dialog::on_m_btn_Home_clicked()
{
	m_pTrainDlg->Init();
	m_pVisualizationDlg->Init();

	if(pPythonCommInshtance)
	{
		uint8_t tmpbuf[TX_CMD_CLEAR_ALL_SETTING_LEN] = {0};
		tmpbuf[0] = TX_HEAD;
		tmpbuf[1] = (TX_CMD_CLEAR_ALL_SETTING_LEN >> 8) & 0xFF;
		tmpbuf[2] = TX_CMD_CLEAR_ALL_SETTING_LEN & 0xFF;
		tmpbuf[3] = TX_CMD_CLEAR_ALL_SETTING;
		tmpbuf[4] = 0;
		tmpbuf[5] = 0;
		tmpbuf[6] = pPythonCommInshtance->getLRC(tmpbuf,TX_CMD_CLEAR_ALL_SETTING_LEN - 2);
		tmpbuf[7] = pPythonCommInshtance->getSum(tmpbuf,TX_CMD_CLEAR_ALL_SETTING_LEN - 1);

		pPythonCommInshtance->SendtoPython(tmpbuf,TX_CMD_CLEAR_ALL_SETTING_LEN);
	}

    SwitchWidget(Widget_Index_Homepage);
}

void Learn_Computer_Vision_Dialog::on_m_btn_Brain_clicked()
{
	m_pTrainDlg->Init();
	m_pVisualizationDlg->Init();

	if(pPythonCommInshtance)
	{
		uint8_t tmpbuf[TX_CMD_CLEAR_ALL_SETTING_LEN] = {0};
		tmpbuf[0] = TX_HEAD;
		tmpbuf[1] = (TX_CMD_CLEAR_ALL_SETTING_LEN >> 8) & 0xFF;
		tmpbuf[2] = TX_CMD_CLEAR_ALL_SETTING_LEN & 0xFF;
		tmpbuf[3] = TX_CMD_CLEAR_ALL_SETTING;
		tmpbuf[4] = 0;
		tmpbuf[5] = 0;
		tmpbuf[6] = pPythonCommInshtance->getLRC(tmpbuf,TX_CMD_CLEAR_ALL_SETTING_LEN - 2);
		tmpbuf[7] = pPythonCommInshtance->getSum(tmpbuf,TX_CMD_CLEAR_ALL_SETTING_LEN - 1);

		pPythonCommInshtance->SendtoPython(tmpbuf,TX_CMD_CLEAR_ALL_SETTING_LEN);
	}

    SwitchWidget(Widget_Index_SelectModule);
}

void Learn_Computer_Vision_Dialog::on_m_btn_Back_clicked()
{
	if(QMessageBox::Yes == QMessageBox::information(NULL, "Confirm", "Quit?", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes))
	{
		m_pTrainDlg->Init();
		m_pVisualizationDlg->Init();

		if(pPythonCommInshtance)
		{
			uint8_t tmpbuf[TX_CMD_CLEAR_ALL_SETTING_LEN] = {0};
			tmpbuf[0] = TX_HEAD;
			tmpbuf[1] = (TX_CMD_CLEAR_ALL_SETTING_LEN >> 8) & 0xFF;
			tmpbuf[2] = TX_CMD_CLEAR_ALL_SETTING_LEN & 0xFF;
			tmpbuf[3] = TX_CMD_CLEAR_ALL_SETTING;
			tmpbuf[4] = 0;
			tmpbuf[5] = 0;
			tmpbuf[6] = pPythonCommInshtance->getLRC(tmpbuf,TX_CMD_CLEAR_ALL_SETTING_LEN - 2);
			tmpbuf[7] = pPythonCommInshtance->getSum(tmpbuf,TX_CMD_CLEAR_ALL_SETTING_LEN - 1);

			pPythonCommInshtance->SendtoPython(tmpbuf,TX_CMD_CLEAR_ALL_SETTING_LEN);
		}

		SwitchWidget(Widget_Index_SelectModule);
	}
}

void Learn_Computer_Vision_Dialog::on_m_btn_Training_clicked()
{
    SwitchWidget(Widget_Index_Train);
}

void Learn_Computer_Vision_Dialog::on_m_btn_Visualization_clicked()
{
	SwitchWidget(Widget_Index_Visualization);
}

void Learn_Computer_Vision_Dialog::on_m_btn_Annotation_clicked()
{
	SwitchWidget(Widget_Index_Annotation);
}

void Learn_Computer_Vision_Dialog::SelectModuleWidget_Show()
{
    SwitchWidget(Widget_Index_SelectModule);
}

void Learn_Computer_Vision_Dialog::TrainWidget_Show()
{
    SwitchWidget(Widget_Index_Train);
}
