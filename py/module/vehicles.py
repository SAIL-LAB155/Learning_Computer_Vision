
from jetson_inference.python.training.detection.ssd.train_ssd import main

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
        pass

    def visualize_webcam(self, model_path=None):
        pass

    def annotate(self):
        pass

    def reset(self):
        pass

# For testing




