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
    Keycode.ONE, Keycode.TWO, Keycode.THREE, Keycode.FOUR, Keycode.FIVE, Keycode.SIX,
    Keycode.Q, Keycode.W, Keycode.E, Keycode.R, Keycode.T, Keycode.Y,
    Keycode.ESCAPE, Keycode.A, Keycode.S, Keycode.D, Keycode.F, Keycode.G,
    Keycode.LEFT_SHIFT, Keycode.Z, Keycode.X, Keycode.C, Keycode.V, Keycode.B,
    Keycode.LEFT_CONTROL, Keycode.OPTION , Keycode.COMMAND, Keycode.SPACE, Keycode.QUOTE, Keycode.TAB,
)

KEYCODES_R = (
    Keycode.EQUALS, Keycode.MINUS, Keycode.ZERO, Keycode.NINE, Keycode.EIGHT, Keycode.SEVEN,
    Keycode.RIGHT_BRACKET, Keycode.LEFT_BRACKET, Keycode.P, Keycode.O, Keycode.I, Keycode.U,
    Keycode.RETURN, Keycode.SEMICOLON, Keycode.L, Keycode.K, Keycode.J, Keycode.H,
    Keycode.RIGHT_SHIFT, Keycode.FORWARD_SLASH, Keycode.PERIOD, Keycode.COMMA, Keycode.M, Keycode.N,
    Keycode.GRAVE_ACCENT, Keycode.RIGHT_CONTROL, Keycode.OPTION, Keycode.COMMAND, Keycode.BACKSLASH, Keycode.BACKSPACE,
)

led = DigitalInOut(board.GP25)
led.direction = Direction.OUTPUT

kbd = Keyboard(usb_hid.devices)

events_R = DummyEventQueue()

# print("Welcome to Keypad")
while True:
    event = km.events.get()
    if event:
        key_id = event.key_number
        if event.pressed:
            led.value = True
            kbd.press(KEYCODES_L[key_id])
        if event.released:
            led.value = False
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
                kbd.press(KEYCODES_R[key_id])
            if event_R.released:
                kbd.release(KEYCODES_R[key_id])

        bytes_read = uart.readline()
        if not bytes_read:
            continue
        else:
            received = bytes_read.decode().strip()
            # print('Else:', received, end='')
            # print()
            # print('Len:', len(received))
            # print()
            ev = DummyEvent(received)
            events_R.add(ev)



    ## Sending the Keyboard Keycodes

