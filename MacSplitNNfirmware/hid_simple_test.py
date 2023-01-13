import time
import board
from digitalio import DigitalInOut, Pull
import usb_hid

from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keyboard import Keycode
from adafruit_debouncer import Debouncer

kbd = Keyboard(usb_hid.devices)

MODIFIER = Keycode.COMMAND

NUM_KEYS = 2

PINS = (
    board.GP0,
    board.GP1
)

KEYMAP = (
    ("SwitchApp", [MODIFIER, Keycode.TAB]),
    ("Spotlight", [MODIFIER, Keycode.SPACE]),
)

keys = []

for pin in PINS:
    dio = DigitalInOut(pin)
    dio.pull = Pull.UP
    keys.append(Debouncer(dio))

print("Welcome to Keypad")
while True:
    for i in range(NUM_KEYS):
        keys[i].update()
        if keys[i].fell:
            print(KEYMAP[i][0])
            kbd.send(*KEYMAP[i][1])
