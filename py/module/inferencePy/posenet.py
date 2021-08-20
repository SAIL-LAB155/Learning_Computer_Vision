import json
import math
import os.path
import sys
import time
import numpy

import jetson.inference
import jetson.utils

from apis import *
from argparse import Namespace

def poseEstimate(path):

    opt = Namespace(input_URI = path, output_URI = "", network = "resnet18-body", overlay = "links,keypoints", threshold = 0.15)

    net = jetson.inference.poseNet(opt.network, threshold = opt.threshold)

    excelFile = [["frames/keypoints", "nosex", "nosey", "leftEyex",
        "leftEyey", "rightEyex", "rightEyey", "leftEarx", "leftEary", "rightEarx",
        "rightEary", "leftShoulderx", "leftShouldery", "rightShoulderx", "rightShouldery",
        "leftElbowx", "leftElbowy", "rightElbowy", "rightElbowy", "leftWristx", "leftWristy",
        "rightWristx", "rightWristy", "leftHipx", "leftHipy", "rightHipx", "rightHipy",
        "leftKneex", "leftKneey", "rightKneex", "rightKneey", "leftAnklex",
        "leftAnkley", "rightAnklex", "rightAnkley", "neckx", "necky"]]

    input = jetson.utils.videoSource(opt.input_URI)

    frameNum = 1

    while True:
        comm_handler()
        signal = ParaCB.Get_Signal()
        if signal == 5:
            message = "The visualization is stopped"
            print(message)
            break

        img_input = input.Capture()
        poses = net.Process(img_input, overlay = opt.overlay)

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

        np_image = cv2.cvtColor(jetson.utils.cudaToNumpy(img_input), cv2.COLOR_BGR2RGB)
        SendToQt_Update_Display(np_image)
        
        if not input.IsStreaming():
            break

    excelFileNpArray = np.asarray(excelFile, dtype=object)

    np.savetxt("../excel/output.csv", excelFileNpArray, delimiter=",", fmt='%s')

