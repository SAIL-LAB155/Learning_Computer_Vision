
from jetson_inference.python.training.detection.ssd.train_ssd import main

class Fruit:
    def __init__(self):
        print('Fruit_cls init ')

    def train(self, data_path, model_path,epoch):
        print('Cat dog training start')
        print('data_path:', data_path)
        print('model_path:', model_path)
        print('epoch_num: ', epoch)
        # cmd = 'python3 /home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/train.py --epochs {} --model-dir {} {}'.format(epoch, '/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/classification/models', data_path[:-1])
        # print(cmd)
        # os.system(cmd)
        model_path = '/home/nvidia/Desktop/Learning_Computer_Vision/py/jetson_inference/python/training/detection/ssd/models'
        main(epoch,model_path,data_path[:-1])

    def plot(self):
        pass

    def visualize(self, img_path, model_path=None):
        pass

    def visualize_webcam(self, model_path=None):
        pass

    def annotate(self, img_folder):
        pass

    def reset(self):
        pass

# For testing
# def main():
#     pass



