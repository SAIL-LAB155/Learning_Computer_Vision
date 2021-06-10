from tasks.human_pose.detect_video_final import detect_video
from tasks.human_pose.detect_video_final import detect_image

class HumanPose:
    def __init__(self):
        print('Human_pose init ')

    def train(self, epochs, img_path, model_path=None):
        pass

    def plot(self):
        pass

    def visualize(self, img_path, model_path=None):
        detect_image(img_path)
        pass

    def visualize_webcam(self, model_path):
        detect_video(0)
        pass

    def annotate(self):
        pass

    def reset(self):
        pass

# For testing
def main():
    pass




