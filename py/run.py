from apis import *


def process_handler(signal):
    if signal != 0:
        print(signal)


if __name__ == '__main__':
    Comm_Init()
    while True:
        comm_handler()
        signal = ParaCB.Get_Signal()
        process_handler(signal)

