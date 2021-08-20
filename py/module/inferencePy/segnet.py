import jetson.inference
import jetson.utils
import cv2

import argparse
import sys

from apis import *
from argparse import Namespace

from module.inferencePy.segnet_utils import *

def segment(path):

    opt = Namespace(input_URI = path, output_URI = "", network = "fcn-resnet18-voc", filter_mode = "linear", visualize = "overlay,mask", ignore_class = "void", alpha = 150.0, stats = "store_true")

    # load the segmentation network
    net = jetson.inference.segNet(opt.network)

    # set the alpha blending value
    net.SetOverlayAlpha(opt.alpha)

    # create buffer manager
    buffers = segmentationBuffers(net, opt)

    # create video sources & outputs
    input = jetson.utils.videoSource(opt.input_URI)

    # process frames until user exits
    while True:
        comm_handler()
        signal = ParaCB.Get_Signal()
        if signal == 5:
            message = "The visualization is stopped"
            print(message)
            break

        # capture the next image
        img_input = input.Capture()

        # allocate buffers for this size image
        buffers.Alloc(img_input.shape, img_input.format)

	# process the segmentation network
        net.Process(img_input, ignore_class=opt.ignore_class)

        # generate the overlay
        if buffers.overlay:
            net.Overlay(buffers.overlay, filter_mode=opt.filter_mode)

	# generate the mask
        if buffers.mask:
            net.Mask(buffers.mask, filter_mode=opt.filter_mode)

        # composite the images
        if buffers.composite:
            jetson.utils.cudaOverlay(buffers.overlay, buffers.composite, 0, 0)
            jetson.utils.cudaOverlay(buffers.mask, buffers.composite, buffers.overlay.width, 0)

        # compute segmentation class stats
        if opt.stats:
            buffers.ComputeStats()

        np_image = cv2.cvtColor(jetson.utils.cudaToNumpy(buffers.overlay), cv2.COLOR_BGR2RGB)

        SendToQt_Update_Display(np_image)
    
        # exit on input/output EOS
        if not input.IsStreaming():
            break
