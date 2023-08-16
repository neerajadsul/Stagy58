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
LED_PIN = None
# Matrix keyboard scan configuration
key_matrix = None


def update_board_status_constants():
    global LR, USB_CONNECTED, SERIAL_CONNECTED, LED_PIN
    LR_side = DigitalInOut(board.GP28)
    LR_side.direction = Direction.INPUT
    LR_side.pull = Pull.UP
    LR = 'R'
    if LR_side.value:
        LR = 'L'
    USB_CONNECTED = supervisor.runtime.usb_connected
    SERIAL_CONNECTED = supervisor.runtime.serial_connected
    
    # Init LED indicator
    LED_PIN = DigitalInOut(board.GP7)
    LED_PIN.direction = Direction.OUTPUT


def no_usb_led_warning():
    while True:
        LED_PIN.value = True
        time.sleep(0.1)
        LED_PIN.value = False
        time.sleep(0.3)
   


def ortho82keyboard():
    key_matrix = keypad.KeyMatrix(
        row_pins=(board.GP22, board.GP21, board.GP20, board.GP19, board.GP18, board.GP17),
        column_pins=(board.GP6, board.GP5, board.GP4, board.GP3, board.GP2, board.GP1, board.GP0),
        columns_to_anodes=True,
    )
    
    if USB_CONNECTED:
        kbd = Keyboard(usb_hid.devices)
        LED_PIN.value = False
    else:
        no_usb_led_warning()

    while True:
        event = key_matrix.events.get()
        if event and event.pressed:
            key_num = event.key_number
            print(f'Key_id {key_num} {KEYBOARD_STR_KEYCODES[LR][key_num]} pressed')
            kbd.press(KEYBOARD_KEYCODES[LR][key_num])
        elif event and event.released:
            print(f'Key_id {key_num} {KEYBOARD_STR_KEYCODES[LR][key_num]} released')
            kbd.release(KEYBOARD_KEYCODES[LR][key_num])            

if __name__ == "__main__":
    update_board_status_constants()
    print('LR   USB     UART')
    print(f'{LR}  {USB_CONNECTED}  {SERIAL_CONNECTED}')

    ortho82keyboard()
