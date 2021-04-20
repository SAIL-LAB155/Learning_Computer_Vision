#ifndef PYTHONCOMM_H
#define PYTHONCOMM_H

#include <QObject>

#include <QTcpServer>
#include <QTcpSocket>

#define RX_HEAD_IDX				0
#define RX_LENGTH_HIGH_IDX		1
#define RX_LENGTH_LOW_IDX		2
#define RX_CMD_IDX				3

#define RX_HEAD					0xA5
#define RX_LEN_MIN				8

#define TX_HEAD					0xA5

#define TX_CMD_MAX_LEN						2048

#define TX_CMD_SET_MODULE_INDEX			0x00
#define		TX_CMD_SET_MODULE_INDEX_LEN		0x08
#define TX_CMD_SET_DATA_PATH			0x01
#define TX_CMD_SET_MODEL_PATH			0x02
#define TX_CMD_SET_EPOCH				0x03
#define		TX_CMD_SET_EPOCH_LEN			0x08
#define TX_CMD_SET_IMAGE_PATH			0x04
#define TX_CMD_SET_VIS_MODEL_PATH		0x05
#define TX_CMD_CLEAR_ALL_SETTING		0x06
#define		TX_CMD_CLEAR_ALL_SETTING_LEN	0x08

#define TX_CMD_START_TRAINING			0x40
#define		TX_CMD_START_TRAINING_LEN		0x08
#define TX_CMD_STOP_TRAINING			0x41
#define		TX_CMD_STOP_TRAINING_LEN		0x08
#define TX_CMD_VIS						0x42
#define		TX_CMD_VIS_LEN					0x08
#define TX_CMD_OPEN_CAM					0x44
#define		TX_CMD_OPEN_CAM_LEN				0x08
#define TX_CMD_STOP_OPEN_CAM			0x45
#define		TX_CMD_STOP_OPEN_CAM_LEN		0x08

#define RX_CMD_TRAIN_OK					0x80
#define		RX_CMD_TRAIN_OK_LEN				0x08
#define RX_CMD_UPDATE_PIC				0x82
#define		RX_CMD_UPDATE_PIC_LEN			0x08



class PythonComm : public QObject
{
	Q_OBJECT
public:
	explicit PythonComm(QObject *parent = nullptr);

signals:
	void Signal_Train_Ok();
	void Signal_Update_Pic();

private:
	bool CheckData(QByteArray qByteArr);
	void Parse_Data(uint8_t* buffer,uint16_t length);

public:
	uint8_t getLRC(uint8_t* buf,uint16_t len);
	uint8_t getSum(uint8_t* buf,uint16_t len);
	void SendtoPython(uint8_t* buf,uint16_t len);

private slots:
	void newConnected();
	void recvData();

private:
	QTcpServer* m_server = NULL;
	QTcpSocket* m_socket = NULL;
};

extern PythonComm* pPythonCommInshtance;
#endif // PYTHONCOMM_H
