from module.trainPy.ssd.ssd.train_ssd import main
from apis import *

from module.inferencePy.segnet import segment

class Vehicle:
    def __init__(self):
        print('Vehicle init ')

    def train(self,data_path, model_path,epoch):
        print('Vehicle training start')
        print('data_path:', data_path)
        print('model_path:', model_path)
        print('epoch_num: ', epoch)

        main(epoch,model_path,data_path[:-1])

    def plot(self):
        pass

    def visualize(self, img_path, model_path=None):
        SendToQt_Update_Display(cv2.imread('../rLearning_Computer_Vision/images/loading.jpg'))
        segment(img_path[:-1])

    def visualize_webcam(self, model_path=None):
        SendToQt_Update_Display(cv2.imread('../rLearning_Computer_Vision/images/loading.jpg'))
        segment("/dev/video0")

    def annotate(self):
        pass

    def reset(self):
        pass

# For testing




