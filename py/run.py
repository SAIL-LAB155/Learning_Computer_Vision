from apis import *
from Module_init import Module
from Parse_signal import SignalParser



if __name__ == '__main__':
    parse = SignalParser()
    Comm_Init()
    while True:
        comm_handler()
        signal = ParaCB.Get_Signal()
        # Module_singal = ParaCB.Module_Index
        parse.parse(ParaCB,signal)


