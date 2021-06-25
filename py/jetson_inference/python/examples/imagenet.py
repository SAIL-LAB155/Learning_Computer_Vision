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
import os
import sys
from apis import *


def cls_img(model_path, img_path, label_path):
	sys.argv = [os.getcwd(), img_path, "output.jpg"]
	# sys.argv.insert(1, img_path)
	sys.argv.insert(2, "--input_blob=input_0")
	sys.argv.insert(3, "--output_blob=output_0")
	# sys.argv.insert(4, 'output.jpg')
	sys.argv.append("--model={}".format(model_path))
	sys.argv.append("--labels={}".format(label_path))
	# load the recognition network
	net = jetson.inference.imageNet("googlenet", sys.argv)

	# create video sources & outputs
	input = jetson.utils.videoSource(img_path, argv=sys.argv)
	output = jetson.utils.videoOutput('output.jpg', argv=sys.argv+[''])
	font = jetson.utils.cudaFont()

	# capture the next image
	img = input.Capture()

	# classify the image
	class_id, confidence = net.Classify(img)

	# find the object description
	class_desc = net.GetClassDesc(class_id)

	# overlay the result on the image
	font.OverlayText(img, img.width, img.height, "{:05.2f}% {:s}".format(confidence * 100, class_desc), 5, 5, font.White, font.Gray40)

	# render the image
	output.Render(img)
	# out_img = jetson.utils.cudaToNumpy(img, 720, 480, 4)
	# SendToQt_Update_Display(out_img)
	np_image = jetson.utils.cudaToNumpy(img)
	# SendToQt_Update_Display(np_image)
	# print out performance info
	net.PrintProfilerTimes()
	output.Close()
	return np_image


def cls_video(model_path, img_path, label_path):
	sys.argv = [os.getcwd(), img_path, "output.jpg"]
	# sys.argv.insert(1, img_path)
	sys.argv.insert(2, "--input_blob=input_0")
	sys.argv.insert(3, "--output_blob=output_0")
	# sys.argv.insert(4, 'output.jpg')
	sys.argv.append("--model={}".format(model_path))
	sys.argv.append("--labels={}".format(label_path))
	# load the recognition network
	net = jetson.inference.imageNet("googlenet", sys.argv)
	sys.argv = []

	# create video sources & outputs
	input = jetson.utils.videoSource(img_path, argv=sys.argv)
	output = jetson.utils.videoOutput('output.jpg', argv=sys.argv+[''])
	font = jetson.utils.cudaFont()

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

		# classify the image
		class_id, confidence = net.Classify(img)

		# find the object description
		class_desc = net.GetClassDesc(class_id)

		# overlay the result on the image
		font.OverlayText(img, img.width, img.height, "{:05.2f}% {:s}".format(confidence * 100, class_desc), 5, 5, font.White, font.Gray40)

		# render the image
		output.Render(img)
		# out_img = jetson.utils.cudaToNumpy(img, 720, 480, 4)
		# SendToQt_Update_Display(out_img)
		# update the title bar
		output.SetStatus("{:s} | Network {:.0f} FPS".format(net.GetNetworkName(), net.GetNetworkFPS()))
		np_image = jetson.utils.cudaToNumpy(img)
		SendToQt_Update_Display(np_image)
		# print out performance info
		net.PrintProfilerTimes()

		# exit on input/output EOS
		if not input.IsStreaming() or not output.IsStreaming():
			break
	output.Close()


if __name__ == '__main__':
	cls_video('/home/nvidia/Desktop/Learning_Computer_Vision/models/cls_models/cat_dog/resnet18.onnx',
			 '/dev/video0',
			 '/home/nvidia/Desktop/Learning_Computer_Vision/data/cls_data/cat_dog/labels.txt')

# ['/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/examples/imagenet.py', '/dev/video0', '--input_blob=input_0', '--output_blob=output_0', 'output.jpg', '--model=/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/models/cat_dog/resnet18.onnx', '--labels=/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/data/cat_dog/labels.txt']