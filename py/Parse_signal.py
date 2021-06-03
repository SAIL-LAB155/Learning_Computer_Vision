from module.cat import CAT
from module.human import Human_pose
from module.fruit import Fruit
from module.creature import Creature
from module.vehicles import Vehicle


class SignalParser:
    def __init__(self):
        # Init all the modules. Init here when more modules
        self.fruit = Fruit()
        self.human = Human_pose()
        self.cat = CAT()
        self.creature = Creature()
        self.vehicle = Vehicle()

    def parse_module(self, signal):
        # modules added here
        if signal == 0:
            self.target = self.fruit
        elif signal == 1:
            self.target = self.creature
        elif signal == 2:
            self.target = self.cat
        elif signal == 3:
            self.target = self.vehicle
        elif signal == 4:
            self.target = self.human
        else:
            raise NotImplementedError

    def parse_action(self, index):
        # ACTION added here
        if index == 0:
            # print('No function')
            pass
        elif index == 1:
            self.target.train(self.signal['Data_Path'], self.signal['Model_Path'],self.signal['Epoch'])
        elif index == 2:
            self.target.reset()
        elif index == 3:
            self.target.visualize(self.signal['Image_Path'], self.signal['Vis_Model_Path'])
        elif index == 4:
            self.target.visualize_webcam(self.signal['Vis_Model_Path'])
        elif index == 5:
            print('Back')
        elif index == 6:
            self.target.annotate()
        else:
            print(index)
            raise NotImplementedError

    def parse_signal(self, ParaCB, action_signal):
        # module, action = "", ""
        signal = {}
        signal['Data_Path'] = ParaCB.Data_Path
        signal['Epoch'] = ParaCB.Epoch
        signal['Image_Path'] = ParaCB.Image_Path
        signal['Model_Path'] = ParaCB.Model_Path
        signal['Module_Index'] = ParaCB.Module_Index
        signal['signal'] = action_signal
        signal['Vis_Model_Path'] = ParaCB.Vis_Model_Path
        return signal

    def parse(self, ParaCB,action_signal):
        self.signal= self.parse_signal(ParaCB,action_signal)
        # Api of the whole parser
        self.parse_module(self.signal['Module_Index'])
        self.parse_action(self.signal['signal'])


# def slight_parse_single(ParaCB):

