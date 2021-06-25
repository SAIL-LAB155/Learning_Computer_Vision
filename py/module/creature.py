from apis import *
import cv2, sys


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
        print("Image is currently showing!")
        img = cv2.imread(img_path[:-1])
        img = cv2.flip(img, 1)
        print("Image finishes showing!")
        SendToQt_Update_Display(img)

    def visualize_webcam(self, model_path=None):
        pass

    def annotate(self):
        pass

    def reset(self):
        pass

# For testing
def main():
    pass




