#from tasks.human_pose.detect_video_final import detect_video
#from tasks.human_pose.detect_video_final import detect_image
from jetson_inference.python.examples.posenet import detect_video, detect_image
from apis import *
from strings import *

class HumanPose:
    def __init__(self):
        print('Human_pose init ')

    def train(self, epochs, img_path, model_path=None):
        pass

    def plot(self):
        pass

    def visualize(self, img_path, model_path=None):
        img = detect_image(img_path[:-1])
        SendToQt_Update_Display(img)

    def visualize_webcam(self, model_path):
        detect_video('/home/jay/Desktop/Learning_Computer_Vision/video/sample2.mp4')
        pass

    def annotate(self):
        pass

    def reset(self):
        pass

# For testing
def main():
    pass




