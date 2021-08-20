from apis import *
import cv2, sys

from module.inferencePy.depthnet import detectDepth

class Creature:
    def __init__(self):
        print('Creature init ')
        self.basename = sys.argv[0]

    def train(self, img_path, model_path=None, epochs=10):
        for epoch in range(int(epochs)):
            comm_handler()
            signal = ParaCB.Get_Signal()
            if signal == 2:
                message = "The training has been stopped"
                print(message)
                SendToQt_Log(message)
                SendToQt_Train_Ok()
                return
            time.sleep(1)
            message = "{}: {}".format(time.asctime(time.localtime(time.time())), epoch)
            print(message)
            SendToQt_Log(message)
        SendToQt_Train_Ok()

    def plot(self):
        pass

    def visualize(self, img_path, model_path):
        SendToQt_Update_Display(cv2.imread('../rLearning_Computer_Vision/images/loading.jpg'))
        detectDepth(img_path[:-1])

    def visualize_webcam(self, model_path=None):
        SendToQt_Update_Display(cv2.imread('../rLearning_Computer_Vision/images/loading.jpg'))
        detectDepth("/dev/video0")

    def annotate(self):
        pass

    def reset(self):
        pass

# For testing
def main():
    pass




