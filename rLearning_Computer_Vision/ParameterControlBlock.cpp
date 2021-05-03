#include "ParameterControlBlock.h"

#include "pythoncomm.h"

ParameterControlBlock ParaCB;

ParameterControlBlock::ParameterControlBlock()
{
    m_ModuleIndex = Module_Max;
}

void ParameterControlBlock::Set_isTrainOkay(bool okay)
{
	m_isTrainOkay = okay;
}

bool ParameterControlBlock::Get_isTrainOkay(void)
{
	return m_isTrainOkay;
}

void ParameterControlBlock::Set_ModuleIndex(Module_t moduleIndex)
{
    if(moduleIndex < Module_Max)
    {
        m_ModuleIndex = moduleIndex;

		if(pPythonCommInshtance)
		{
			uint8_t tmpbuf[TX_CMD_SET_MODULE_INDEX_LEN] = {0};

			tmpbuf[0] = TX_HEAD;
			tmpbuf[1] = (TX_CMD_SET_MODULE_INDEX_LEN >> 8) & 0xFF;
			tmpbuf[2] = TX_CMD_SET_MODULE_INDEX_LEN & 0xFF;
			tmpbuf[3] = TX_CMD_SET_MODULE_INDEX;
			tmpbuf[4] = 0;
			tmpbuf[5] = m_ModuleIndex;
			tmpbuf[6] = pPythonCommInshtance->getLRC(tmpbuf,TX_CMD_SET_MODULE_INDEX_LEN - 2);
			tmpbuf[7] = pPythonCommInshtance->getSum(tmpbuf,TX_CMD_SET_MODULE_INDEX_LEN - 1);

			pPythonCommInshtance->SendtoPython(tmpbuf,TX_CMD_SET_MODULE_INDEX_LEN);
		}
    }
}

uint8_t ParameterControlBlock::Get_ModuleIndex(void)
{
    return m_ModuleIndex;
}

void ParameterControlBlock::Set_ImagePath(QString& imagePath)
{
	m_ImagePath = imagePath;

	if(pPythonCommInshtance)
	{
		uint8_t tmpbuf[TX_CMD_MAX_LEN] = {0};
		uint16_t length = 6 + m_ImagePath.length() + 1;
		QByteArray tmpImageName = m_ImagePath.toLatin1();
		char* tmpImageNameBuf = tmpImageName.data();

		tmpbuf[0] = TX_HEAD;
		tmpbuf[1] = (length >> 8) & 0xFF;
		tmpbuf[2] = length & 0xFF;
		tmpbuf[3] = TX_CMD_SET_DATA_PATH;
		for(int i = 0;i < m_ImagePath.length();i++)
		{
			tmpbuf[4+i] = tmpImageNameBuf[i];
		}

		tmpbuf[length - 3] = 0;
		tmpbuf[length - 2] = pPythonCommInshtance->getLRC(tmpbuf,length - 2);
		tmpbuf[length - 1] = pPythonCommInshtance->getSum(tmpbuf,length - 1);

		pPythonCommInshtance->SendtoPython(tmpbuf,length);
	}
}

QString& ParameterControlBlock::Get_ImagePath(void)
{
	return m_ImagePath;
}

void ParameterControlBlock::Set_ModelPath(QString& modelPath)
{
	m_ModelPath = modelPath;

	if(pPythonCommInshtance)
	{
		uint8_t tmpbuf[TX_CMD_MAX_LEN] = {0};
		uint16_t length = 6 + m_ModelPath.length() + 1;
		QByteArray tmpModelName = m_ModelPath.toLatin1();
		char* tmpModelNameBuf = tmpModelName.data();

		tmpbuf[0] = TX_HEAD;
		tmpbuf[1] = (length >> 8) & 0xFF;
		tmpbuf[2] = length & 0xFF;
		tmpbuf[3] = TX_CMD_SET_MODEL_PATH;
		for(int i = 0;i < m_ModelPath.length();i++)
		{
			tmpbuf[4+i] = tmpModelNameBuf[i];
		}

		tmpbuf[length - 3] = 0;
		tmpbuf[length - 2] = pPythonCommInshtance->getLRC(tmpbuf,length - 2);
		tmpbuf[length - 1] = pPythonCommInshtance->getSum(tmpbuf,length - 1);

		pPythonCommInshtance->SendtoPython(tmpbuf,length);
	}
}

QString& ParameterControlBlock::Get_ModelPath(void)
{
	return m_ModelPath;
}

void ParameterControlBlock::Set_Visualization_ImagePath(QString& imagePath)
{
	m_Visualization_ImagePath = imagePath;

	if(pPythonCommInshtance)
	{
		uint8_t tmpbuf[TX_CMD_MAX_LEN] = {0};
		uint16_t length = 6 + m_Visualization_ImagePath.length() + 1;
		QByteArray tmpVisualization_ImageName = m_Visualization_ImagePath.toLatin1();
		char* tmpVisualization_ImageNameBuf = tmpVisualization_ImageName.data();

		tmpbuf[0] = TX_HEAD;
		tmpbuf[1] = (length >> 8) & 0xFF;
		tmpbuf[2] = length & 0xFF;
		tmpbuf[3] = TX_CMD_SET_IMAGE_PATH;
		for(int i = 0;i < m_Visualization_ImagePath.length();i++)
		{
			tmpbuf[4+i] = tmpVisualization_ImageNameBuf[i];
		}

		tmpbuf[length - 3] = 0;
		tmpbuf[length - 2] = pPythonCommInshtance->getLRC(tmpbuf,length - 2);
		tmpbuf[length - 1] = pPythonCommInshtance->getSum(tmpbuf,length - 1);

		pPythonCommInshtance->SendtoPython(tmpbuf,length);
	}
}

QString& ParameterControlBlock::Get_Visualization_ImagePath(void)
{
	return m_Visualization_ImagePath;
}

void ParameterControlBlock::Set_Visualization_ModelPath(QString& modelPath)
{
	m_Visualization_ModelPath = modelPath;

	if(pPythonCommInshtance)
	{
		uint8_t tmpbuf[TX_CMD_MAX_LEN] = {0};
		uint16_t length = 6 + m_Visualization_ModelPath.length() + 1;
		QByteArray tmpVisualization_ModelName = m_Visualization_ModelPath.toLatin1();
		char* tmpVisualization_ModelNameBuf = tmpVisualization_ModelName.data();

		tmpbuf[0] = TX_HEAD;
		tmpbuf[1] = (length >> 8) & 0xFF;
		tmpbuf[2] = length & 0xFF;
		tmpbuf[3] = TX_CMD_SET_VIS_MODEL_PATH;
		for(int i = 0;i < m_Visualization_ModelPath.length();i++)
		{
			tmpbuf[4+i] = tmpVisualization_ModelNameBuf[i];
		}

		tmpbuf[length - 3] = 0;
		tmpbuf[length - 2] = pPythonCommInshtance->getLRC(tmpbuf,length - 2);
		tmpbuf[length - 1] = pPythonCommInshtance->getSum(tmpbuf,length - 1);

		pPythonCommInshtance->SendtoPython(tmpbuf,length);
	}
}

QString& ParameterControlBlock::Get_Visualization_ModelPath(void)
{
	return m_Visualization_ModelPath;
}

void ParameterControlBlock::Set_Visualization_OpenImagePath(QString& openImagePath)
{
	m_Visualization_OpenImagePath = openImagePath;
}

QString& ParameterControlBlock::Get_Visualization_OpenImagePath(void)
{
	return m_Visualization_OpenImagePath;
}
