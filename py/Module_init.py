from module.cat import CAT
from module.human import Human_pose
from module.fruit import Fruit
from module.creature import Creature


class Module():
    def __init__(self):
        self.Cat = CAT()
        self.Human = Human_pose()
        self.Fruit = Fruit()
        self.Creature = Creature()