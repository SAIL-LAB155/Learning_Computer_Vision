import jetson.inference
import jetson.utils
import cv2

from argparse import Namespace
import sys

from apis import *

from module.inferencePy.depthnet_utils import depthBuffers

def detectDepth(path):

    opt = Namespace(input_URI = path, output_URI = "", network = "fcn-mobilenet", visualize = "input,depth", depth_size = 1.0, filter_mode = "linear", colormap = "viridis-inverted")

    net = jetson.inference.depthNet(opt.network)
    
    buffers = depthBuffers(opt)

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

        # process the mono depth and visualize
        net.Process(img_input, buffers.depth, opt.colormap, opt.filter_mode)

        # composite the images
        if buffers.use_input:
            jetson.utils.cudaOverlay(img_input, buffers.composite, 0, 0)
        
        if buffers.use_depth:
            jetson.utils.cudaOverlay(buffers.depth, buffers.composite, img_input.width if buffers.use_input else 0, 0)

        np_image = cv2.cvtColor(jetson.utils.cudaToNumpy(buffers.composite), cv2.COLOR_BGR2RGB)

        SendToQt_Update_Display(np_image)

        # exit on input/output EOS
        if not input.IsStreaming():
            break
