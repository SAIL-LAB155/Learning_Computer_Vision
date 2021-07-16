
from jetson_inference.python.training.detection.ssd.train_ssd import main
from jetson_inference.python.training.detection.ssd.onnx_export import onnx
from labelImg.labelImg import label
from jetson_inference.python.examples.detectnet import det_video, det_img
from apis import *
from strings import *
import shutil
import os
import cv2, sys

class Fruit:
    def __init__(self):
        print('Fruit_cls init ')
        self.label_path = "../data/det_data/fruit/labels.txt"
        self.basename = sys.argv[0]

    def train(self, data_path, model_path, epoch):
        print('Cat dog training start')
        print('data_path:', data_path)
        print('model_path:', model_path)
        print('epoch_num: ', epoch)
        self.label_path = data_path[:-1] + '/labels.txt'
        print(self.label_path)
        if len(os.listdir(data_path[:-1])) > 4:
            shutil.copyfile(self.label_path, model_path[:-1]+'/labels.txt')
        # cmd = 'python3 /home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/train.py --epochs {} --model-dir {} {}'.format(epoch, '/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/models', data_path[:-1])
        # print(cmd)
        # os.system(cmd)
        flag = main(epoch, model_path[:-1], data_path[:-1])
        SendToQt_Log(TRAINING_FINISH)

        if flag != -1:
            SendToQt_Log(WITH_ONNX_CONVERT)
            onnx(model_path[:-1])
        else:
            SendToQt_Log(NO_ONNX_CONVERT)
        SendToQt_Log(TASK_FINISH)
        SendToQt_Train_Ok()
        sys.argv = [self.basename]

    def plot(self):
        pass

    def visualize(self, img_path, model_path, label_path=None):
        if not label_path:
            label_path = self.label_path
        img = det_img(model_path[:-1], img_path[:-1], label_path)
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        SendToQt_Update_Display(img)
        sys.argv = [self.basename]

    def visualize_webcam(self, model_path=None, label_path=None):
        if not label_path:
            label_path = self.label_path
        det_video(model_path[:-1], "/dev/video0", label_path)
        sys.argv = [self.basename]

    def annotate(self):
        _, path = label()
        print(path)
        if path:
            name = os.listdir(path)
            os.makedirs(path + '/' + 'JPEGImages')
            os.makedirs(path + '/' + 'Annotations')
            os.makedirs(path + '/' + 'ImageSets/Main')
            for i in name:
                tmp = path + '/' + i
                if i.endswith('xml'):
                    shutil.move(tmp,path+'/' + 'Annotations')
                else:
                    shutil.move(tmp,path+'/' + 'JPEGImages')

            path1 = path + '/JPEGImages'
            name = os.listdir(path1)
            ratio = 0.1
            for i in name:
                tmp = i.split('.')[0]
                with open(path + '/ImageSets/Main/trainval.txt','a+') as f:
                    f.write(tmp)
                    f.write('\n')
            name_test = name[:int(len(name) * ratio)]
            for i in name_test:
                tmp = i.split('.')[0]
                with open(path + '/ImageSets/Main/test.txt','a+') as f:
                    f.write(tmp)
                    f.write('\n')
            name_val = name[int(len(name) * (1-ratio)) : ]
            for i in name_val:
                tmp = i.split('.')[0]
                with open(path + '/ImageSets/Main/val.txt','a+') as f:
                    f.write(tmp)
                    f.write('\n')
            name_train = name[int(len(name) * ratio) : ]
            for i in name_train:
                tmp = i.split('.')[0]
                with open(path + '/ImageSets/Main/train.txt','a+') as f:
                    f.write(tmp)
                    f.write('\n')

        #execfile('labelImg-1.8.1/labelImg.py')

    def reset(self):
        pass

# For testing
# def main():
#     pass



