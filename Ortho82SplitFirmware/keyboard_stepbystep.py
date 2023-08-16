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


LOG_DEBUG = False
LR = None
USB_CONNECTED = None
SERIAL_CONNECTED = None


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


if __name__ == "__main__":
    update_board_status_constants()
    print('LR   USB     UART')
    print(f'{LR}  {USB_CONNECTED}  {SERIAL_CONNECTED}')
