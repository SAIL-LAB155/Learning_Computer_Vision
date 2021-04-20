#include "pythoncomm.h"

#include <QDebug>

PythonComm* pPythonCommInshtance = NULL;

PythonComm::PythonComm(QObject *parent) : QObject(parent)
{
	qDebug() << "Learn_Computer_Vision_Dialog::Communication()";
	m_server = new QTcpServer;
	m_socket = new QTcpSocket;
	if(!m_server->listen(QHostAddress::AnyIPv4,quint16(8888))){
		//exit(20);
	}
	connect(m_server,SIGNAL(newConnection()),this,SLOT(newConnected()));
}

void PythonComm::newConnected(void)
{
	if(m_server->hasPendingConnections()){
		m_socket = m_server->nextPendingConnection();
		if(!m_socket->isValid()){
			return;
		}
		connect(m_socket,SIGNAL(readyRead()),this,SLOT(recvData()));
	}
}

uint8_t PythonComm::getLRC(uint8_t* buf,uint16_t len)
{
	uint8_t lrc = 0;
	if(buf)
	{
		for(uint16_t i = 0;i < len;i++)
		{
			lrc ^= buf[i];
		}
	}

	return lrc;
}

uint8_t PythonComm::getSum(uint8_t* buf,uint16_t len)
{
	uint8_t sum = 0;
	if(buf)
	{
		for(uint16_t i = 0;i < len;i++)
		{
			sum += buf[i];
		}
	}

	return sum;
}

bool PythonComm::CheckData(QByteArray qByteArr)
{
	uint8_t* data = (uint8_t*)qByteArr.data();
	uint32_t len = qByteArr.length();
	uint8_t sum = 0;
	uint8_t lrc = 0;
	bool ret = false;

	lrc = getLRC(data,len-2);
	sum = getSum(data,len-1);

	qDebug("lrc:0x%02x VS rxLrc:0x%02x",lrc,data[len-2]);
	qDebug("sum:0x%02x VS rxSum:0x%02x",sum,data[len-1]);
	if((lrc == data[len-2]) && (sum == data[len-1]))
	{
		ret = true;
	}

	return ret;
}

void PythonComm::SendtoPython(uint8_t* buf,uint16_t len)
{
	if(buf)
	{
		if(m_socket)
		{
			if(m_socket->isValid())
			{
				m_socket->write((const char*)buf,len);
			}
			else
			{
				qDebug("m_socket is invalid");
			}
		}
		else
		{
			qDebug() << "m_socket null";
		}
	}
}

void PythonComm::Parse_Data(uint8_t* buffer,uint16_t length)
{
	switch(buffer[3])
	{
		case RX_CMD_TRAIN_OK:
			if(RX_CMD_TRAIN_OK_LEN == length)
			{
				emit Signal_Train_Ok();
			}
			else
			{
				qDebug() << "cmd " << buffer[3] << " error len " <<
							length;
			}
			break;

		case RX_CMD_UPDATE_PIC:
			if(RX_CMD_UPDATE_PIC_LEN == length)
			{
				emit Signal_Update_Pic();
			}
			else
			{
				qDebug() << "cmd " << buffer[3] << " error len " <<
							length;
			}
			break;
		default:
			qDebug() << "error cmd " << buffer[3];
			break;
	}
}

void PythonComm::recvData()
{
	QByteArray RxArr = m_socket->readAll();
	uint16_t trueLen = RxArr.length();
	qDebug() << "trueLen = " << trueLen;

	uint8_t* data = (uint8_t*)RxArr.data();

	for(int i = 0;i < trueLen;i++)
	{
		qDebug("0x%02x ",data[i]);
	}

	if(RX_HEAD == data[RX_HEAD_IDX])
	{
		if(trueLen >= RX_LEN_MIN)
		{
			uint16_t rxLen = (data[RX_LENGTH_HIGH_IDX] << 8) | data[RX_LENGTH_LOW_IDX];
			if(trueLen == rxLen)
			{
				if(CheckData(RxArr))
				{
					//SendtoPython(data,trueLen);
					Parse_Data(data,trueLen);
				}
				else
				{
					qDebug("check data error");
				}
			}
			else
			{
				qDebug("trueLen-%d != rxLen-%d\n",trueLen,rxLen);
			}
		}
		else
		{
			qDebug("trueLen too short %d\n",trueLen);
		}
	}
	else
	{
		qDebug("head fail 0x%02x",data[RX_HEAD_IDX]);
	}
}
