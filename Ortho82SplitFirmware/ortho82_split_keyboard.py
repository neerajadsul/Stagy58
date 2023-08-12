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


def process_event(event):

    mod_key_flag = False
    fn_key_flag = False
    key_active = None
    key_id = event.key_number
    if LR == 'L':
        # Left half keys are documented above to maintain 1:1 mapping of physical placement
        # [6 - (key_id%7) + 7*(key_id//7)] logic converts key_id to correct mapping
        # This creates boundary value problem at 35 as it converts to 41, out of index
        # Hence the value check to add 1 which makes correct mapping
        if key_id > 34:
            key_id += 1
        key_id = 6 - (key_id%7) + 7*(key_id//7)

    if key_id == MOD_KEY_NUM:
        mod_key_flag = True
    elif key_id == FN_KEY_NUM:
        fn_key_flag = True
    else:
        key_active = KEYBOARD_KEYCODES[LR][key_id]

    action = str(event).split(' ')[-1]
    data = f"<{LR} {key_id} {action}\n"
    if LOG_DEBUG:
        print(data, KEYBOARD_STR_KEYCODES[LR][key_id].split('.')[-1])
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
    # 6, 5, 4, 3, 2, 1, 0
    Keycode.ESCAPE, Keycode.F1, Keycode.F2, Keycode.F3, Keycode.F4, Keycode.F5, Keycode.F6,
    # 13, 12, 11, 10, 9, 8, 7
    Keycode.GRAVE_ACCENT, Keycode.ONE, Keycode.TWO, Keycode.THREE, Keycode.FOUR, Keycode.FIVE, Keycode.SIX,
    # 20, 19, 18, 17, 16, 15, 14
    Keycode.TAB, Keycode.Q, Keycode.W, Keycode.E, Keycode.R, Keycode.T, Keycode.Y,
    # 27, 26, 25, 24, 23, 22, 21
    Keycode.CAPS_LOCK, Keycode.A, Keycode.S, Keycode.D, Keycode.F, Keycode.G, Keycode.H,
    # 34, 33, 32, 31, 30, 29, 28
    Keycode.LEFT_SHIFT, Keycode.POUND, Keycode.Z, Keycode.X, Keycode.C, Keycode.V, Keycode.B,
    # 40, 39, 38, 37, 36, 35
    Keycode.LEFT_CONTROL, FN_KEY_NUM, MOD_KEY_NUM, Keycode.LEFT_ALT, Keycode.COMMAND, Keycode.SPACE,
)

KEYCODES_R = (
    # 0, 1, 2, 3, 4, 5, 6
    Keycode.F7, Keycode.F8, Keycode.F9, Keycode.F10, Keycode.F11, Keycode.F12, Keycode.DELETE,
    # 7, 8, 9, 10, 11, 12, 13
    Keycode.SEVEN, Keycode.EIGHT, Keycode.NINE, Keycode.ZERO, Keycode.MINUS, Keycode.EQUALS, Keycode.BACKSPACE,
    # 14, 15, 16, 17, 18, 19, 20
    Keycode.U, Keycode.I, Keycode.O, Keycode.P, Keycode.LEFT_BRACKET, Keycode.RIGHT_BRACKET, Keycode.ENTER,
    # 21, 22, 23, 24, 25, 26, 27
    Keycode.J, Keycode.K, Keycode.L, Keycode.SEMICOLON, Keycode.QUOTE, Keycode.BACKSLASH, Keycode.RETURN,
    # 28, 29, 30, 31, 32, 33, 34
    Keycode.N, Keycode.M, Keycode.COMMA, Keycode.PERIOD, Keycode.FORWARD_SLASH, Keycode.UP_ARROW, Keycode.RIGHT_SHIFT,
    # 35, 36, 37, 38, 39, 40
    Keycode.SPACE, Keycode.RIGHT_GUI, Keycode.RIGHT_ALT, Keycode.LEFT_ARROW, Keycode.DOWN_ARROW, Keycode.RIGHT_ARROW,
)

KEYBOARD_KEYCODES = {'L': KEYCODES_L, 'R': KEYCODES_R}

STR_KEYCODES_R = [
'Keycode.F7', 'Keycode.F8', 'Keycode.F9', 'Keycode.F10', 'Keycode.F11', 'Keycode.F12', 'Keycode.DELETE,',
'Keycode.SEVEN', 'Keycode.EIGHT', 'Keycode.NINE', 'Keycode.ZERO', 'Keycode.MINUS', 'Keycode.EQUALS', 'Keycode.BACKSPACE',
'Keycode.U', 'Keycode.I', 'Keycode.O', 'Keycode.P', 'Keycode.LEFT_BRACKET', 'Keycode.RIGHT_BRACKET', 'Keycode.ENTER',
'Keycode.J', 'Keycode.K', 'Keycode.L', 'Keycode.SEMICOLON', 'Keycode.QUOTE', 'Keycode.BACKSLASH', 'Keycode.RETURN',
'Keycode.N', 'Keycode.M', 'Keycode.COMMA', 'Keycode.PERIOD', 'Keycode.FORWARD_SLASH', 'Keycode.UP_ARROW', 'Keycode.RIGHT_SHIFT',
'Keycode.SPACE', 'Keycode.RIGHT_GUI', 'Keycode.RIGHT_ALT', 'Keycode.LEFT_ARROW', 'Keycode.DOWN_ARROW', 'Keycode.RIGHT_ARROW']

STR_KEYCODES_L = ['Keycode.ESCAPE', 'Keycode.F1', 'Keycode.F2', 'Keycode.F3', 'Keycode.F4', 'Keycode.F5', 'Keycode.F6,',
'Keycode.GRAVE_ACCENT', 'Keycode.ONE', 'Keycode.TWO', 'Keycode.THREE', 'Keycode.FOUR', 'Keycode.FIVE', 'Keycode.SIX',
'Keycode.TAB', 'Keycode.Q', 'Keycode.W', 'Keycode.E', 'Keycode.R', 'Keycode.T', 'Keycode.Y',
'Keycode.CAPS_LOCK', 'Keycode.A', 'Keycode.S', 'Keycode.D', 'Keycode.F', 'Keycode.G', 'Keycode.H,',
'Keycode.LEFT_SHIFT', 'Keycode.POUND', 'Keycode.Z', 'Keycode.X', 'Keycode.C', 'Keycode.V', 'Keycode.B',
'Keycode.LEFT_CONTROL','FN_KEY', 'MOD_KEY', 'Keycode.LEFT_ALT', 'Keycode.COMMAND', 'Keycode.SPACE']

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
        data, key_active, mod_key_flag, fn_key_flag = process_event(event)
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
        print(received_data, end='')
        ev = DummyEvent(received_data)
        dummy_event_queue.add(ev)

    event_dummy = dummy_event_queue.get()

    if event_dummy:
        data, key_active, mod_key_flag, fn_key_flag = process_event(event_dummy)
