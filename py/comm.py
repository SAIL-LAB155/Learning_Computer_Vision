#!/usr/bin/python3

import socket
import cv2
import numpy as np
import ctypes
import time
from time import strftime, localtime

class ParaControlBlock:
    Module_Index = 0;
    Data_Path = '';
    Model_Path = '';
    Epoch = 15;
    Image_Path = '';
    Vis_Model_Path = '';
    Signal = 0;

    def Get_Signal(self):
        ret = self.Signal;
        self.Signal = 0;
        return ret;

def Get_Sum(buf,len):
    sum = 0;
    for loop in range(len):
        sum += buf[loop];
    sum &= 0xff;
    return sum;

def Get_LRC(buf,len):
    lrc = 0;
    for loop in range(len):
        lrc ^= buf[loop];
    lrc &= 0xff;
    return lrc;

def SendToQt_Train_Ok():
    tmpBuf = bytearray(8);
    tmpBuf[0] = 0xA5;

    tmpBuf[1] = 0;
    tmpBuf[2] = 8;

    tmpBuf[3] = 0x80;
    tmpBuf[4] = 0x00;
    tmpBuf[5] = 0x00;

    tmpBuf[6] = Get_LRC(tmpBuf,6);
    tmpBuf[7] = Get_Sum(tmpBuf,7);

    socket_8888.send(tmpBuf);
    return;

def SendToQt_Update_Display(img):
    img_encode = cv2.imencode(".jpg",img)[1];
    data_encode = np.array(img_encode);
    data_encode_c = data_encode.ctypes.data_as(ctypes.c_void_p);
    data_len = len(data_encode);

    loadLibrary = ctypes.cdll.LoadLibrary();
    cLib = loadLibrary("./libc_send_pic.so");
    cLib.shm_send_pic(data_encode_c,data_len);

    tmpBuf = bytearray(8);
    tmpBuf[0] = 0xA5;

    tmpBuf[1] = 0;
    tmpBuf[2] = 8;

    tmpBuf[3] = 0x82;
    tmpBuf[4] = 0x00;
    tmpBuf[5] = 0x00;

    tmpBuf[6] = Get_LRC(tmpBuf,6);
    tmpBuf[7] = Get_Sum(tmpBuf,7);

    socket_8888.send(tmpBuf);
    return;

def SendToQt_Log(log):
    socket_6666.send(log.encode());
    return;

def decode(len):
    global RxBuffer;
    global ParaCB;

    if(0x00 == RxBuffer[3]):
        if(len == 8):
            if((0x00 == RxBuffer[4]) and (RxBuffer[5] <= 5)):
                ParaCB.Module_Index = RxBuffer[5];
                print("set module : " , ParaCB.Module_Index);
        pass;
    elif(0x01 == RxBuffer[3]):
        if(len >= 7):
            if(0x00 == RxBuffer[len - 3]):
                tmpByteArr = RxBuffer[4:len - 2];
                ParaCB.Data_Path = tmpByteArr.decode();
                print("set Data_Path : " , ParaCB.Data_Path);
        pass;
    elif (0x02 == RxBuffer[3]):
        if (len >= 7):
            if (0x00 == RxBuffer[len - 3]):
                tmpByteArr = RxBuffer[4:len - 2];
                ParaCB.Model_Path = tmpByteArr.decode();
                print("set Model_Path : " , ParaCB.Model_Path);
        pass;
    elif (0x03 == RxBuffer[3]):
        if (len == 8):
            if ((0x00 == RxBuffer[4]) and (RxBuffer[5] <= 30)):
                ParaCB.Epoch = RxBuffer[5];
                print("set Epoch : " , ParaCB.Epoch);
        pass;
    elif (0x04 == RxBuffer[3]):
        if (len >= 7):
            if (0x00 == RxBuffer[len - 3]):
                tmpByteArr = RxBuffer[4:len - 2];
                ParaCB.Image_Path = tmpByteArr.decode();
                print("set Image_Path : " , ParaCB.Image_Path);
        pass;
    elif (0x05 == RxBuffer[3]):
        if (len >= 7):
            if (0x00 == RxBuffer[len - 3]):
                tmpByteArr = RxBuffer[4:len - 2];
                ParaCB.Vis_Model_Path = tmpByteArr.decode();
                print("set Vis_Model_Path : " , ParaCB.Vis_Model_Path);
        pass;
    elif (0x06 == RxBuffer[3]):
        if (len == 8):
            if ((0x00 == RxBuffer[4]) and (0x00 == RxBuffer[5])):
                ParaCB.Module_Index = 0;
                ParaCB.Data_Path = '';
                ParaCB.Model_Path = '';
                ParaCB.Epoch = 15;
                ParaCB.Image_Path = '';
                ParaCB.Vis_Model_Path = '';
        pass;
    elif (0x40 == RxBuffer[3]):
        if (len == 8):
            if ((0x00 == RxBuffer[4]) and (0x00 == RxBuffer[5])):
                ParaCB.Signal = 1;
                print("Signal : " , ParaCB.Signal);
        pass;
    elif (0x41 == RxBuffer[3]):
        if (len == 8):
            if ((0x00 == RxBuffer[4]) and (0x00 == RxBuffer[5])):
                ParaCB.Signal = 2;
                print("Signal : ", ParaCB.Signal);
        pass;
    elif (0x42 == RxBuffer[3]):
        if (len == 8):
            if ((0x00 == RxBuffer[4]) and (0x00 == RxBuffer[5])):
                ParaCB.Signal = 3;
                print("Signal : ", ParaCB.Signal);
        pass;
    elif (0x44 == RxBuffer[3]):
        if (len == 8):
            if ((0x00 == RxBuffer[4]) and (0x00 == RxBuffer[5])):
                ParaCB.Signal = 4;
                print("Signal : ", ParaCB.Signal);
        pass;
    elif (0x45 == RxBuffer[3]):
        if (len == 8):
            if ((0x00 == RxBuffer[4]) and (0x00 == RxBuffer[5])):
                ParaCB.Signal = 5;
                print("Signal : ", ParaCB.Signal);
        pass;
    else :
        print("cmd not found ",RxBuffer[3]);
    return;

def Parse():
    global RxBuffer;
    print("Parse");
    RxBufferLen = len(RxBuffer);
    print("RxBuffer len = ", RxBufferLen);
    print(RxBuffer);

    canContinue = True;
    while canContinue:
        try:
            firstHeadIdx = RxBuffer.index(0xA5);
        except:
            canContinue = False;
            RxBuffer.clear();
            pass;
        else:
            print("firstHeadIdx = ",firstHeadIdx);
            RxBuffer = RxBuffer[firstHeadIdx:]
            FrameLen = RxBuffer[1] * 256 + RxBuffer[2];
            if FrameLen < 3000:
                if FrameLen <= len(RxBuffer) :
                    calcLRC = Get_LRC(RxBuffer, (FrameLen - 2));
                    calcSum = Get_Sum(RxBuffer, (FrameLen - 1));
                    if((calcLRC == RxBuffer[FrameLen - 2]) and (calcSum == RxBuffer[FrameLen - 1])):
                        decode(FrameLen);
                        RxBuffer = RxBuffer[FrameLen:];
                    else:
                        print("verify fail");
                        print("LRC ",calcLRC," vs ",RxBuffer[FrameLen - 2]);
                        print("SUM ", calcSum, " vs ", RxBuffer[FrameLen - 1]);
                        RxBuffer[0] = 0;
                else:
                    canContinue = False;
            else:
                RxBuffer[0] = 0;
                print("FrameLen too long : " , FrameLen);

    print(RxBuffer);
    return;

ParaCB = ParaControlBlock();

socket_8888 = socket.socket(socket.AF_INET, socket.SOCK_STREAM);

socket_6666 = socket.socket(socket.AF_INET, socket.SOCK_STREAM);

RxBuffer = bytearray(0);

def Comm_Init():
    socket_8888.connect(('127.0.0.1', 8888));
    socket_8888.settimeout(0.1);

    socket_6666.connect(('127.0.0.1', 6666));
    return;

def comm_handler():
    global RxBuffer;
    try:
        tmpRxBuffer = socket_8888.recv(1024);
    except:
        pass;
    else:
        if tmpRxBuffer:
            # print(strftime("%Y-%m-%d %H:%M:%S", localtime()))
            print("tmpRxBuffer len = ",len(tmpRxBuffer));
            print(tmpRxBuffer);

            RxBuffer += tmpRxBuffer;

            Parse();
        pass;
    return;

if __name__ == '__main__':
    Comm_Init();
    while True:
        comm_handler();