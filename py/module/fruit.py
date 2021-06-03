
from jetson_inference.python.training.detection.ssd.train_ssd import main
from labelImg.labelImg import label
from jetson_inference.python.examples.detectnet import main_det
from apis import *


class Fruit:
    def __init__(self):
        print('Fruit_cls init ')

    def train(self, data_path, model_path,epoch):
        print('Cat dog training start')
        print('data_path:', data_path)
        print('model_path:', model_path)
        print('epoch_num: ', epoch)
        self.label_path = data_path[:-1] + '/labels.txt'
        print(self.label_path)
        # cmd = 'python3 /home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/train.py --epochs {} --model-dir {} {}'.format(epoch, '/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/models', data_path[:-1])
        # print(cmd)
        # os.system(cmd)
        model_path = '/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/detection/ssd/models'
        main(epoch,model_path,data_path[:-1])

    def plot(self):
        pass

    def visualize(self, img_path, model_path):
        import cv2
        label_path = '/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/detection/ssd/models/fruit/labels.txt'
        main_det(model_path[:-1],img_path[:-1], label_path)
        img = cv2.imread('/home/nvidia/Desktop/Learning_Computer_Vision/py/output.jpg')
        SendToQt_Update_Display(img)

    def visualize_webcam(self, model_path=None):
        label_path = '/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/detection/ssd/models/fruit/labels.txt'
        main_det(model_path[:-1], "/dev/video0", label_path)

    def annotate(self):
        label()
        #execfile('labelImg-1.8.1/labelImg.py')

    def reset(self):
        pass

# For testing
# def main():
#     pass



