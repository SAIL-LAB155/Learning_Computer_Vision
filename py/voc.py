import os
import random

def process(data_dir):
    trainval_percent = 0.5
    train_percent = 0.5
    xmlfilepath = data_dir + '/Annotations'
    txtsavepath = data_dir +'/ImageSets/Main'
    if not os.path.exists(txtsavepath):
        os.makedirs(txtsavepath)
        total_xml = os.listdir(xmlfilepath)
        num = len(total_xml)
        list = range(num)
        tv = int(num * trainval_percent)
        tr = int(tv * train_percent)
        trainval = random.sample(list, tv)
        train = random.sample(trainval, tr)
        ftrainval = open(txtsavepath + '/trainval.txt', 'a+')
        ftest = open(txtsavepath + '/test.txt', 'a+')
        ftrain = open(txtsavepath + '/train.txt', 'a+')
        fval = open(txtsavepath + '/val.txt', 'a+')
        for i in list:
            name = total_xml[i][:-4] + '\n'
            if i in trainval:
                ftrainval.write(name)
                if i in train:
                    ftrain.write(name)
                else:
                    fval.write(name)
            else:
                ftest.write(name)
        ftrainval.close()
        ftrain.close()
        fval.close()
        ftest.close()
    else:
        print('ImageSets exists')