#!/usr/bin/python3
#
# Copyright (c) 2020, NVIDIA CORPORATION. All rights reserved.
#
# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.
#

import jetson.inference
import jetson.utils
from apis import *
import argparse
import sys
import os
import cv2

# parse the command line
parser = argparse.ArgumentParser(description="Locate objects in a live camera stream using an object detection DNN.", 
                                 formatter_class=argparse.RawTextHelpFormatter, epilog=jetson.inference.detectNet.Usage() +
                                 jetson.utils.videoSource.Usage() + jetson.utils.videoOutput.Usage() + jetson.utils.logUsage())

parser.add_argument("input_URI", type=str, default="", nargs='?', help="URI of the input stream")
parser.add_argument("output_URI", type=str, default="", nargs='?', help="URI of the output stream")
parser.add_argument("--network", type=str, default="ssd-mobilenet-v2", help="pre-trained model to load (see below for options)")
parser.add_argument("--overlay", type=str, default="box,labels,conf", help="detection overlay flags (e.g. --overlay=box,labels,conf)\nvalid combinations are:  'box', 'labels', 'conf', 'none'")
parser.add_argument("--threshold", type=float, default=0.5, help="minimum detection threshold to use") 

is_headless = ["--headless"] if sys.argv[0].find('console.py') != -1 else [""]


def det_video(model_path, img_path, label_path):
	sys.argv = [os.getcwd(), img_path, "output.jpg"]
	sys.argv.append("--model={}".format(model_path))
	sys.argv.append("--labels={}".format(label_path))
	sys.argv.append("--input_blob=input_0")
	sys.argv.append("--output_cvg=scores")
	sys.argv.append("--output_bbox=boxes")

	try:
		opt = parser.parse_known_args()[0]
	except:
		print("")
		parser.print_help()
		sys.exit(0)

	# load the object detection network
	net = jetson.inference.detectNet('ssd-mobilenet-v2', sys.argv, opt.threshold)
	sys.argv = []
	# create video sources & outputs
	input = jetson.utils.videoSource(img_path, argv=sys.argv)
	output = jetson.utils.videoOutput('output.jpg', argv=sys.argv+is_headless)

	# process frames until the user exits
	while True:
		comm_handler()
		signal = ParaCB.Get_Signal()
		if signal == 5:
			message = "The visualization is stopped"
			print(message)
			break

		# capture the next image
		img = input.Capture()

		# detect objects in the image (with overlay)
		detections = net.Detect(img, overlay="box,labels,conf")

		# print the detections
		print("detected {:d} objects in image".format(len(detections)))

		for detection in detections:
			print(detection)

		# render the image
		# output.Render(img)

		# update the title bar
		# output.SetStatus("{:s} | Network {:.0f} FPS".format("ssd-mobilenet-v2", net.GetNetworkFPS()))

		# print out performance info
		net.PrintProfilerTimes()

		np_image = cv2.cvtColor(jetson.utils.cudaToNumpy(img), cv2.COLOR_BGR2RGB)
		SendToQt_Update_Display(np_image)
		# exit on input/output EOS
		if not input.IsStreaming() or not output.IsStreaming():
			break


def det_img(model_path, img_path, label_path):
	sys.argv = [os.getcwd(), img_path, "output.jpg"]
	sys.argv.append("--model={}".format(model_path))
	sys.argv.append("--labels={}".format(label_path))
	sys.argv.append("--input_blob=input_0")
	sys.argv.append("--output_cvg=scores")
	sys.argv.append("--output_bbox=boxes")

	try:
		opt = parser.parse_known_args()[0]
	except:
		print("")
		parser.print_help()
		sys.exit(0)

	# load the object detection network
	net = jetson.inference.detectNet('ssd-mobilenet-v2', sys.argv, opt.threshold)
	sys.argv = []
	# create video sources & outputs
	input = jetson.utils.videoSource(img_path, argv=sys.argv)
	output = jetson.utils.videoOutput('output.jpg', argv=sys.argv + is_headless)

	# capture the next image
	img = input.Capture()

	# detect objects in the image (with overlay)
	detections = net.Detect(img, overlay="box,labels,conf")

	# print the detections
	print("detected {:d} objects in image".format(len(detections)))

	for detection in detections:
		print(detection)

	# render the image
	# output.Render(img)

	# update the title bar
	output.SetStatus("{:s} | Network {:.0f} FPS".format("ssd-mobilenet-v2", net.GetNetworkFPS()))

	# print out performance info
	net.PrintProfilerTimes()

	np_image = cv2.cvtColor(jetson.utils.cudaToNumpy(img), cv2.COLOR_BGR2RGB)
	return np_image



if __name__ == '__main__':
	device = "/dev/video0"
	model_path = "/home/nvidia/Desktop/Learning_Computer_Vision/models/det_model/ssd-mobilenet.onnx"
	label_path = "/home/nvidia/Desktop/Learning_Computer_Vision/data/det_data/fruit/labels.txt"
	det_video(model_path, device, label_path)
