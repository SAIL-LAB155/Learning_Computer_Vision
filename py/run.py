from apis import *
from Parse_signal import SignalParser
import os


if __name__ == '__main__':
    parse = SignalParser()
    os.system("gcc -o libc_send_pic.so -shared -fPIC shm_send_pic.c")
    Comm_Init()
    while True:
        comm_handler()
        signal = ParaCB.Get_Signal()
        parse.parse(ParaCB, signal)
