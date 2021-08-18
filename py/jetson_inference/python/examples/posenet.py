import json
import math
import os.path
import sys
import time

import jetson.inference
import jetson.utils

from apis import *

import numpy
import pandas as pd

def detect_image(imagePath):
   
    excelFile = [["frames/keypoints", "nosex", "nosey", "leftEyex",
        "leftEyey", "rightEyex", "rightEyey", "leftEarx", "leftEary", "rightEarx",
        "rightEary", "leftShoulderx", "leftShouldery", "rightShoulderx", "rightShouldery",
        "leftElbowx", "leftElbowy", "rightElbowy", "rightElbowy", "leftWristx", "leftWristy",
        "rightWristx", "rightWristy", "leftHipx", "leftHipy", "rightHipx", "rightHipy",
        "leftKneex", "leftKneey", "rightKneex", "rightKneey", "leftAnklex",
        "leftAnkley", "rightAnklex", "rightAnkley", "neckx", "necky"]]

    net = jetson.inference.poseNet("resnet18-body")
    imageSrc = jetson.utils.videoSource(imagePath)
    image = imageSrc.Capture()
    poses = net.Process(image)

    frameNum = 1

    for pose in poses:
        
        newLine = [str(frameNum)]
        
        for kp in range(net.GetNumKeypoints()):

            if pose.FindKeypoint(kp) >= 0:
                newLine.append(pose.Keypoints[pose.FindKeypoint(kp)].x)
                newLine.append(pose.Keypoints[pose.FindKeypoint(kp)].y)
            else:
                newLine.append(-1)
                newLine.append(-1)

        excelFile.append(newLine)

    np_image = cv2.cvtColor(jetson.utils.cudaToNumpy(image), cv2.COLOR_BGR2RGB)
  
    excelFileNpArray = np.asarray(excelFile, dtype=object)

    np.savetxt("../excel/output.csv", excelFileNpArray, delimiter=",", fmt='%s')

    return np_image

def detect_video(video):

    excelFile = [["frames/keypoints", "nosex", "nosey", "leftEyex",
        "leftEyey", "rightEyex", "rightEyey", "leftEarx", "leftEary", "rightEarx",
        "rightEary", "leftShoulderx", "leftShouldery", "rightShoulderx", "rightShouldery",
        "leftElbowx", "leftElbowy", "rightElbowy", "rightElbowy", "leftWristx", "leftWristy",
        "rightWristx", "rightWristy", "leftHipx", "leftHipy", "rightHipx", "rightHipy",
        "leftKneex", "leftKneey", "rightKneex", "rightKneey", "leftAnklex",
        "leftAnkley", "rightAnklex", "rightAnkley", "neckx", "necky"]]

    net = jetson.inference.poseNet("resnet18-body")
    imageSrc = jetson.utils.videoSource(video)

    frameNum = 1

    while True:
        comm_handler()
        signal = ParaCB.Get_Signal()
        if signal == 5:
            message = "The visualization is stopped"
            print(message)
            break

        image = imageSrc.Capture()
        poses = net.Process(image)

        for pose in poses:

            newLine = [str(frameNum)]

            for kp in range(net.GetNumKeypoints()):
 
                if pose.FindKeypoint(kp) >= 0:
                    newLine.append(pose.Keypoints[pose.FindKeypoint(kp)].x)
                    newLine.append(pose.Keypoints[pose.FindKeypoint(kp)].y)
                else:
                    newLine.append(-1)
                    newLine.append(-1)

                excelFile.append(newLine)
        
        frameNum += 1

        np_image = cv2.cvtColor(jetson.utils.cudaToNumpy(image), cv2.COLOR_BGR2RGB)
        SendToQt_Update_Display(np_image)
        #if not imageSrc.IsStreaming():
            #break

    excelFileNpArray = np.asarray(excelFile, dtype=object)

    np.savetxt("../excel/output.csv", excelFileNpArray, delimiter=",", fmt='%s')

