import time
import board
from digitalio import DigitalInOut, Pull, Direction
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
import keypad
import busio
import supervisor

from keyboard_layout import KEYBOARD_KEYCODES, KEYBOARD_STR_KEYCODES

# Board status flags
LOG_DEBUG = False
LR = None
USB_CONNECTED = None
SERIAL_CONNECTED = None

# Matrix keyboard scan configuration
key_matrix = None


def update_board_status_constants():
    global LR, USB_CONNECTED, SERIAL_CONNECTED
    LR_side = DigitalInOut(board.GP28)
    LR_side.direction = Direction.INPUT
    LR_side.pull = Pull.UP
    LR = 'R'
    if LR_side.value:
        LR = 'L'
    USB_CONNECTED = supervisor.runtime.usb_connected
    SERIAL_CONNECTED = supervisor.runtime.serial_connected


def ortho82keyboard():
    key_matrix = keypad.KeyMatrix(
        row_pins=(board.GP22, board.GP21, board.GP20, board.GP19, board.GP18, board.GP17),
        column_pins=(board.GP6, board.GP5, board.GP4, board.GP3, board.GP2, board.GP1, board.GP0),
        columns_to_anodes=True,
    )
    
    while True:
        event = key_matrix.events.get()
        if event and event.pressed:
            print(f'Key_id {event.key_number} pressed')
        elif event and event.released:
            print(f'Key_id {event.key_number} released')    


if __name__ == "__main__":
    update_board_status_constants()
    print('LR   USB     UART')
    print(f'{LR}  {USB_CONNECTED}  {SERIAL_CONNECTED}')
    
    ortho82keyboard()
