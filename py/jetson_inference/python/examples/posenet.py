import json
import math
import os.path
import sys
import time

import jetson.inference
import jetson.utils

from apis import *


def detect_image(imagePath):
    net = jetson.inference.poseNet("resnet18-body")
    imageSrc = jetson.utils.videoSource(imagePath)
    image = imageSrc.Capture()
    poses = net.Process(image, "links,keypoints")
    np_image = cv2.cvtColor(jetson.utils.cudaToNumpy(image), cv2.COLOR_BGR2RGB)
    return np_image



def detect_video(video):
    net = jetson.inference.poseNet("resnet18-body")
    imageSrc = jetson.utils.videoSource(video)

    while True:
        comm_handler()
        signal = ParaCB.Get_Signal()
        if signal == 5:
            message = "The visualization is stopped"
            print(message)
            break

        image = imageSrc.Capture()
        poses = net.Process(image, "links,keypoints")
        np_image = cv2.cvtColor(jetson.utils.cudaToNumpy(image), cv2.COLOR_BGR2RGB)
        SendToQt_Update_Display(np_image)
        #if not imageSrc.IsStreaming():
            #break






