from module.trainPy.classification.train import main
from module.trainPy.classification.onnx_export import onnx
from jetson_inference.python.examples.imagenet import cls_video, cls_img
from apis import *
from strings import *
import sys

class CAT:
    def __init__(self):
        self.label_path = "../data/cls_data/cat_dog/labels.txt"
        print('Cat_dog init ')
        self.basename = sys.argv[0]

    def train(self,data_path, model_path,epoch):
        print('Cat dog training start')
        print('data_path:', data_path)
        print('model_path:', model_path)
        print('epoch_num: ', epoch)
        self.label_path = data_path[:-1] + '/labels.txt'
        print(self.label_path)
        # cmd = 'python3 /home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/train.py --epochs {} --model-dir {} {}'.format(epoch, '/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/models', data_path[:-1])
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
        vis_img = cls_img(model_path[:-1], img_path[:-1], label_path)
        # img = cv2.imread('/home/nvidia/Desktop/Learning_Computer_Vision/py/output.jpg')
        SendToQt_Update_Display(vis_img)
        sys.argv = [self.basename]
        # SendToQt_Update_Display(img)
        # 'python3 imagenet.py --model=../training/classification/models/cat_dog/resnet18.onnx --input_blob=input_0 --output_blob=output_0 --labels=../training/classification/data/cat_dog/labels.txt ../training/classification/data/cat_dog/test/cat/01.jpg catttt.jpg^'

    def visualize_webcam(self, model_path, label_path=None):
        if not label_path:
            label_path = self.label_path
        print('model_path:', model_path)
        print('Cat dog vis start')
        # main_img(model_path)
        # cmd = 'python3 imagenet.py --model={} --input_blob=input_0 --output_blob=output_0 --labels={} {} output.jpg'.format(model_path,self.label_path, img_path)
        # cmd = 'python3 /home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/examples/imagenet.py --model={} --input_blob=input_0 --output_blob=output_0 --labels=/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/data/cat_dog/labels.txt {} output.jpg'.format(
        #     model_path[:-1], img_path[:-1])
        # print(cmd)
        # os.system(cmd)
        # img = cv2.imread('/home/nvidia/Desktop/Learning_Computer_Vision/py/output.jpg')
        cls_video(model_path[:-1], "/dev/video0", label_path)
        # cmd = 'python3 /home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/examples/imagenet.py /dev/video0 --model={} --input_blob=input_0 --output_blob=output_0 --labels=/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/data/cat_dog/labels.txt output.jpg'.format(
        #     model_path[:-1])
        sys.argv = [self.basename]

    def annotate(self):
        print('Cat dog training start')

    def reset(self):
        pass





