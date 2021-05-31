import os
from jetson_inference.python.training.classification.train import main
from jetson_inference.python.examples.imagenet import main_img
from apis import *
import cv2

class CAT:
    def __init__(self):
        print('Cat_dog init ')

    def train(self,data_path, model_path,epoch):
        print('Cat dog training start')
        print('data_path:', data_path)
        print('model_path:', model_path)
        print('epoch_num: ', epoch)
        self.label_path = data_path[:-1] + '/labels.txt'
        print(self.label_path)
        # cmd = 'python3 /home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/train.py --epochs {} --model-dir {} {}'.format(epoch, '/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/models', data_path[:-1])
        # os.system(cmd)
        model_path = '/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/models'
        main(epoch,model_path,data_path[:-1])

    def plot(self):
        print('Cat dog plot start')

    def visualize(self,img_path, model_path, label_path=None):
        if not label_path:
            label_path = self.label_path
        print('img_path', img_path)
        print('model_path:', model_path)
        print('Cat dog vis start')
        # main_img(model_path)
        # cmd = 'python3 imagenet.py --model={} --input_blob=input_0 --output_blob=output_0 --labels={} {} output.jpg'.format(model_path,self.label_path, img_path)
        # cmd = 'python3 /home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/examples/imagenet.py --model={} --input_blob=input_0 --output_blob=output_0 --labels=/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/data/cat_dog/labels.txt {} output.jpg'.format(
        #     model_path[:-1], img_path[:-1])
        # print(cmd)
        # os.system(cmd)
        # img = cv2.imread('/home/nvidia/Desktop/Learning_Computer_Vision/py/output.jpg')
        main_img(model_path[:-1],img_path[:-1], label_path)
        # SendToQt_Update_Display(img)
        # 'python3 imagenet.py --model=../training/classification/models/cat_dog/resnet18.onnx --input_blob=input_0 --output_blob=output_0 --labels=../training/classification/data/cat_dog/labels.txt ../training/classification/data/cat_dog/test/cat/01.jpg catttt.jpg^'

    def visualize_webcam(self, model_path=None):
        cmd = 'python3 /home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/examples/imagenet.py /dev/video0 --model={} --input_blob=input_0 --output_blob=output_0 --labels=/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/data/cat_dog/labels.txt output.jpg'.format(
            model_path[:-1])

    def annotate(self):
        print('Cat dog training start')

    def reset(self):
        pass





