import time
import board
from digitalio import DigitalInOut, Pull, Direction
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
import keypad
import busio

class DummyEvent():
    """ Emulates Keymatrix event based on data on serial port"""
    def __init__(self, event_string):
        s = event_string.split(' ')
        self.key_number = int(s[1])
        self._pressed = s[2][:-1]

    @property
    def pressed(self):
        return self._pressed == 'pressed'

    @property
    def released(self):
        return self._pressed == 'released'

class DummyEventQueue():
    """ Emulates Keymatrix event queue"""
    def __init__(self):
        self.events = []

    def get(self):
        if len(self.events) == 0:
            return None
        return self.events.pop(0)

    def add(self, event):
        self.events.append(event)

LR_side = DigitalInOut(board.GP1)
LR_side.direction = Direction.INPUT
LR_side.pull = Pull.UP

if LR_side.value:
    LR = 'L'
else:
    LR = 'R'

uart = busio.UART(board.GP8, board.GP9, baudrate=115200, timeout=0.005)
uart.reset_input_buffer()

km = keypad.KeyMatrix(
    row_pins=(board.GP16, board.GP15, board.GP14, board.GP13, board.GP12),
    column_pins=(board.GP22, board.GP21, board.GP20, board.GP19, board.GP18, board.GP17),
    columns_to_anodes=True,
)

key_sw = {
    0:'SW1', 1:'SW2', 2:'SW3', 3:'SW4', 4:'SW5', 5:'SW6',
    6:'SW7', 7:'SW8', 8:'SW9', 9:'SW10', 10:'SW11', 11:'SW12',
    12:'SW13',13:'SW14',14:'SW15',15:'SW16',16:'SW17', 17:'SW18',
    18:'SW19',19:'SW20',20:'SW21',21:'SW22',22:'SW23',23:'SW24',
    24:'SW25',25:'SW26',26:'SW27',27:'SW28',28:'SW29',29:'SW30'
}

KEYCODES_L = (
    # 0,1,2,3,4,5
    Keycode.ONE, Keycode.TWO, Keycode.THREE, Keycode.FOUR, Keycode.FIVE, Keycode.SIX,
    # 6,7,8,9,10,11
    Keycode.Q, Keycode.W, Keycode.E, Keycode.R, Keycode.T, Keycode.Y,
    # 12,13,14,15,16,17
    Keycode.ESCAPE, Keycode.A, Keycode.S, Keycode.D, Keycode.F, Keycode.G,
    # 18,19,20,21,22,23
    Keycode.LEFT_SHIFT, Keycode.Z, Keycode.X, Keycode.C, Keycode.V, Keycode.B,
    # 24, 25, 26 27, 28, 29
    Keycode.LEFT_CONTROL, Keycode.OPTION , Keycode.COMMAND, Keycode.SPACE, Keycode.QUOTE, Keycode.TAB,
)

KEYCODES_R = (
    # 0, 1, 2, 3, 4, 5
    Keycode.EQUALS, Keycode.MINUS, Keycode.ZERO, Keycode.NINE, Keycode.EIGHT, Keycode.SEVEN,
    # 6, 7, 8, 9, 10, 11
    Keycode.RIGHT_BRACKET, Keycode.LEFT_BRACKET, Keycode.P, Keycode.O, Keycode.I, Keycode.U,
    # 12, 13, 14, 15, 16, 17
    Keycode.RETURN, Keycode.SEMICOLON, Keycode.L, Keycode.K, Keycode.J, Keycode.H,
    # 18, 19, 20, 21, 22, 23
    Keycode.RIGHT_SHIFT, Keycode.FORWARD_SLASH, Keycode.PERIOD, Keycode.COMMA, Keycode.M, Keycode.N,
    # 24, 25, 26, 27, 28, 29
    Keycode.RIGHT_CONTROL, Keycode.OPTION, Keycode.COMMAND, Keycode.SPACE, Keycode.BACKSPACE, Keycode.BACKSLASH,
)

MOD_KEY_NUM = 28

# H, J, K, L as Arrow Keys
ARROW_KEYCODES = {
    17:Keycode.LEFT_ARROW,
    16:Keycode.DOWN_ARROW,
    15:Keycode.UP_ARROW,
    14:Keycode.RIGHT_ARROW,
    11:Keycode.QUOTE,
    10:Keycode.GRAVE_ACCENT,
}

#

led = DigitalInOut(board.GP25)
led.direction = Direction.OUTPUT

kbd = Keyboard(usb_hid.devices)

events_R = DummyEventQueue()
mod_flag_L = False
mod_flag_R = False
# print("Welcome to Keypad")
while True:
    event = km.events.get()
    if event:
        key_id = event.key_number
        if event.pressed:
            led.value = True
            if key_id == MOD_KEY_NUM:
                mod_flag_L = True
                print("main", mod_flag_L)
            else:
                kbd.press(KEYCODES_L[key_id])
        if event.released:
            led.value = False
            if key_id == MOD_KEY_NUM:
                mod_flag_L = False
                print("main", mod_flag_L)
            else:
                kbd.release(KEYCODES_L[key_id])

        action = str(event).split(' ')[-1]
        data = f"<{LR} {key_id} {action}\n"
        print(data, end='')
        # print(str(event))
        if LR == 'R':
            uart.write(data.encode())

    if LR == 'L':
        event_R = events_R.get()
        if event_R:
            key_id = event_R.key_number
            if event_R.pressed:
                if mod_flag_L:
                    if key_id in ARROW_KEYCODES.keys():
                        kbd.press(ARROW_KEYCODES[key_id])
                else:
                    kbd.press(KEYCODES_R[key_id])
                    print(mod_flag_L)
            if event_R.released:
                if key_id in ARROW_KEYCODES.keys():
                    kbd.release(ARROW_KEYCODES[key_id])
                kbd.release(KEYCODES_R[key_id])
                print(mod_flag_L)

        bytes_read = uart.readline()
        if not bytes_read:
            continue
        else:
            received = bytes_read.decode().strip()
            print(received, end='')
            ev = DummyEvent(received)
            events_R.add(ev)
