import time
import board
from digitalio import DigitalInOut, Pull, Direction
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
import keypad
import busio
import supervisor

LOG_DEBUG = False

class DummyEvent():
    """ Emulates Keymatrix event based on data on serial port"""
    def __init__(self, event_string):
        s = event_string.split(' ')
        self.side = s[0][-1]
        self.key_number = int(s[1])
        self._pressed = s[2][:-1]

    def __str__(self):
        return f'<Event: key_number {self.key_number} {self._pressed}>'

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


def process_event(event, side):

    mod_key_flag = False
    fn_key_flag = False
    key_active = None
    key_id = event.key_number

    if key_id == MOD_KEY_NUM:
        mod_key_flag = True
    elif key_id == FN_KEY_NUM:
        fn_key_flag = True
    else:
        key_active = KEYBOARD_KEYCODES[side][key_id]

    action = str(event).split(' ')[-1]     
    data = f"<{side} {key_id} {action}\n"
    if LOG_DEBUG:
        print(data, KEYBOARD_STR_KEYCODES[side][key_id].split('.')[-1])
    print(data, end='')

    return data, key_active, mod_key_flag, fn_key_flag


LR_side = DigitalInOut(board.GP28)
LR_side.direction = Direction.INPUT
LR_side.pull = Pull.UP

LR = 'R'
if LR_side.value:
    LR = 'L'

print(LR)
uart = busio.UART(tx=board.GP8, rx=board.GP9, baudrate=115200, timeout=0.005)
uart.reset_input_buffer()

MOD_KEY_NUM = 82
FN_KEY_NUM = 81

USB_connected = supervisor.runtime.usb_connected
Serial_connected = supervisor.runtime.serial_connected

if LOG_DEBUG:
    print(f"Supervisor Status: USB: {USB_connected} Serial: {Serial_connected}")


KEYCODES_L = (
    # 0, 1, 2, 3, 4, 5, 6
    Keycode.F6, Keycode.F5, Keycode.F4, Keycode.F3, Keycode.F2, Keycode.F1, Keycode.ESCAPE,
    # 7, 8, 9, 10, 11, 12, 13
    Keycode.SIX, Keycode.FIVE, Keycode.FOUR, Keycode.THREE, Keycode.TWO, Keycode.ONE, Keycode.KEYPAD_BACKSLASH ,
    # 14, 15, 16, 17, 18, 19, # 20
    Keycode.Y, Keycode.T, Keycode.R, Keycode.E, Keycode.W, Keycode.Q, Keycode.TAB,
    # 21, 22, 23, 24, 25, 26, # 27
    Keycode.H, Keycode.G, Keycode.F, Keycode.D, Keycode.S, Keycode.A, Keycode.CAPS_LOCK,
    # 28, 29, 30, 31, 32, 33, # 34
    Keycode.B, Keycode.V, Keycode.C, Keycode.X, Keycode.Z, Keycode.GRAVE_ACCENT, Keycode.LEFT_SHIFT,
    # 35, 36, 37, 38, 39, # 40
    Keycode.SPACE, Keycode.COMMAND, Keycode.LEFT_ALT, MOD_KEY_NUM, FN_KEY_NUM, Keycode.LEFT_CONTROL,
)

KEYCODES_R = (
    # 0, 1, 2, 3, 4, 5, 6
    Keycode.F7, Keycode.F8, Keycode.F9, Keycode.F10, Keycode.F11, Keycode.F12, Keycode.DELETE,
    # 7, 8, 9, 10, 11, 12, 13
    Keycode.SEVEN, Keycode.EIGHT, Keycode.NINE, Keycode.ZERO, Keycode.MINUS, Keycode.EQUALS, Keycode.BACKSPACE,
    # 14, 15, 16, 17, 18, 19, 20
    Keycode.U, Keycode.I, Keycode.O, Keycode.P, Keycode.LEFT_BRACKET, Keycode.RIGHT_BRACKET, Keycode.ENTER,
    # 21, 22, 23, 24, 25, 26, 27
    Keycode.J, Keycode.K, Keycode.L, Keycode.SEMICOLON, Keycode.QUOTE, Keycode.POUND, Keycode.RETURN,
    # 28, 29, 30, 31, 32, 33, 34
    Keycode.N, Keycode.M, Keycode.COMMA, Keycode.PERIOD, Keycode.FORWARD_SLASH, Keycode.UP_ARROW, Keycode.RIGHT_SHIFT,
    # 35, 36, 37, 38, 39, 40
    Keycode.SPACE, Keycode.RIGHT_GUI, Keycode.RIGHT_ALT, Keycode.LEFT_ARROW, Keycode.DOWN_ARROW, Keycode.RIGHT_ARROW,
)

KEYBOARD_KEYCODES = {'L': KEYCODES_L, 'R': KEYCODES_R}


STR_KEYCODES_L = ['Keycode.F6', 'Keycode.F5', 'Keycode.F4', 'Keycode.F3', 'Keycode.F2', 'Keycode.F1', 'Keycode.ESCAPE',
'Keycode.SIX', 'Keycode.FIVE', 'Keycode.FOUR', 'Keycode.THREE', 'Keycode.TWO', 'Keycode.ONE', 'Keycode.GRAVE_ACCENT', 
'Keycode.Y', 'Keycode.T', 'Keycode.R', 'Keycode.E', 'Keycode.W', 'Keycode.Q', 'Keycode.TAB', 
'Keycode.H', 'Keycode.G', 'Keycode.F', 'Keycode.D', 'Keycode.S', 'Keycode.A', 'Keycode.CAPS_LOCK',
'Keycode.B', 'Keycode.V', 'Keycode.C', 'Keycode.X', 'Keycode.Z', 'Keycode.POUND', 'Keycode.LEFT_SHIFT',
'Keycode.SPACE', 'Keycode.COMMAND', 'Keycode.LEFT_ALT', 'MOD_KEY_NUM', 'FN_KEY_NUM', 'Keycode.LEFT_CONTROL']

STR_KEYCODES_R = [
'Keycode.F7', 'Keycode.F8', 'Keycode.F9', 'Keycode.F10', 'Keycode.F11', 'Keycode.F12', 'Keycode.DELETE,',
'Keycode.SEVEN', 'Keycode.EIGHT', 'Keycode.NINE', 'Keycode.ZERO', 'Keycode.MINUS', 'Keycode.EQUALS', 'Keycode.BACKSPACE',
'Keycode.U', 'Keycode.I', 'Keycode.O', 'Keycode.P', 'Keycode.LEFT_BRACKET', 'Keycode.RIGHT_BRACKET', 'Keycode.ENTER',
'Keycode.J', 'Keycode.K', 'Keycode.L', 'Keycode.SEMICOLON', 'Keycode.QUOTE', 'Keycode.BACKSLASH', 'Keycode.RETURN',
'Keycode.N', 'Keycode.M', 'Keycode.COMMA', 'Keycode.PERIOD', 'Keycode.FORWARD_SLASH', 'Keycode.UP_ARROW', 'Keycode.RIGHT_SHIFT',
'Keycode.SPACE', 'Keycode.RIGHT_GUI', 'Keycode.RIGHT_ALT', 'Keycode.LEFT_ARROW', 'Keycode.DOWN_ARROW', 'Keycode.RIGHT_ARROW']



KEYBOARD_STR_KEYCODES = {'L': STR_KEYCODES_L, 'R': STR_KEYCODES_R}

led = DigitalInOut(board.GP7)
led.direction = Direction.OUTPUT
led.value = False


if USB_connected:
    kbd = Keyboard(usb_hid.devices)

# Primary events from keymatrix, same on right and left halves
km = keypad.KeyMatrix(
    row_pins=(board.GP22, board.GP21, board.GP20, board.GP19, board.GP18, board.GP17),
    column_pins=(board.GP6, board.GP5, board.GP4, board.GP3, board.GP2, board.GP1, board.GP0),
    columns_to_anodes=True,
)

# Secondary dummy events to be created with data received
# from other half keyboard via USART/Serial port
dummy_event_queue = DummyEventQueue()


while True:
    event = km.events.get()
    if event:
        data, key_active, mod_key_flag, fn_key_flag = process_event(event, LR)
        if USB_connected:
            if event.pressed:
                kbd.press(key_active)
            if event.released:
                kbd.release(key_active)
        else:
            uart.write(data.encode())

    if USB_connected:
        serial_data = uart.readline()
        if not serial_data:
            continue
        if len(serial_data) < 10:
            uart.reset_input_buffer()
            continue

        received_data = serial_data.decode().strip()        
        ev = DummyEvent(received_data)
        dummy_event_queue.add(ev)

    event_dummy = dummy_event_queue.get()    

    if event_dummy:
        # print('event_dummy', event_dummy, event_dummy.side)
        data, key_active, mod_key_flag, fn_key_flag = process_event(event_dummy, event_dummy.side)
        if event_dummy.pressed:
            kbd.press(key_active)
        if event_dummy.released:
            kbd.release(key_active)
        # print('Dummy:', data)
