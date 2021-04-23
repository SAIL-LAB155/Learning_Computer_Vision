import os
import jetson_inference.python

class CAT:
    def __init__(self):
        print('Cat_dog init ')

    def train(self,data_path, model_path,epoch):
        print('Cat dog training start')
        print('data_path:', data_path)
        print('model_path:', model_path)
        print('epoch_num: ', epoch)
        cmd = 'python3 /home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/train.py --epochs {} --model-dir {} {}'.format(epoch, '/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/models', data_path[:-1])
        print(cmd)
        os.system(cmd)

    def plot(self):

        print('Cat dog plot start')

    def visualize(self,img_path, model_path):
        print('img_path', img_path)
        print('model_path:', model_path)
        print('Cat dog vis start')

    def visualize_webcam(self, model_path=None):
        print('model_path:', model_path)
        print('Cat dog web_vis start')

    def annotate(self, img_folder):
        print('Cat dog training start')

    def reset(self):
        pass

# For testing
def main():
    pass




