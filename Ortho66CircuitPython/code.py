import time
import board
import keypad

from digitalio import DigitalInOut, Direction
import adafruit_ble
from adafruit_ble.advertising import Advertisement
from adafruit_ble.advertising.standard import ProvideServicesAdvertisement
from adafruit_ble.services.standard.hid import HIDService
from adafruit_ble.services.standard.device_info import DeviceInfoService
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keyboard_layout_us import KeyboardLayoutUS
from adafruit_hid.keycode import Keycode

km = keypad.KeyMatrix(
    row_pins=(board.D5, board.D7, board.D9, board.D10, board.D11),
    column_pins=(board.A0, board.A1, board.A2, board.A3, board.A4, board.A5),
    columns_to_anodes=True,
)

key_sw = {
    0: "SW1",
    1: "SW2",
    2: "SW3",
    3: "SW4",
    4: "SW5",
    5: "SW6",
    6: "SW7",
    7: "SW8",
    8: "SW9",
    9: "SW10",
    10: "SW11",
    11: "SW12",
    12: "SW13",
    13: "SW14",
    14: "SW15",
    15: "SW16",
    16: "SW17",
    17: "SW18",
    18: "SW19",
    19: "SW20",
    20: "SW21",
    21: "SW22",
    22: "SW23",
    23: "SW24",
    24: "SW25",
    25: "SW26",
    26: "SW27",
    27: "SW28",
    28: "SW29",
    29: "SW30",
}

KEYCODES_L = (
    # 0,1,2,3,4,5
    Keycode.ONE,
    Keycode.TWO,
    Keycode.THREE,
    Keycode.FOUR,
    Keycode.FIVE,
    Keycode.SIX,
    # 6,7,8,9,10,11
    Keycode.Q,
    Keycode.W,
    Keycode.E,
    Keycode.R,
    Keycode.T,
    Keycode.Y,
    # 12,13,14,15,16,17
    Keycode.ESCAPE,
    Keycode.A,
    Keycode.S,
    Keycode.D,
    Keycode.F,
    Keycode.G,
    # 18,19,20,21,22,23
    Keycode.LEFT_SHIFT,
    Keycode.Z,
    Keycode.X,
    Keycode.C,
    Keycode.V,
    Keycode.B,
    # 24, 25, 26 27, 28, 29
    Keycode.LEFT_CONTROL,
    Keycode.OPTION,
    Keycode.COMMAND,
    Keycode.SPACE,
    Keycode.QUOTE,
    Keycode.TAB,
)

hid = HIDService()
device_info = DeviceInfoService(
    software_revision=adafruit_ble.__version__, manufacturer="125 Systems"
)
advertisement = ProvideServicesAdvertisement(hid)
advertisement.appearance = 961
scan_response = Advertisement()
scan_response.complete_name = "CircuitPython Ortho66 HID"

ble = adafruit_ble.BLERadio()
if not ble.connected:
    print("Advertising")
    ble.start_advertising(advertisement, scan_response)
else:
    print("Already connected")
    print(ble.connections)

kbd = Keyboard(hid.devices)

while True:
    event = km.events.get()
    if not event:
        continue
    key_id = event.key_number
    if event.pressed:
        print("Pressed", key_id, key_sw[key_id])
        kbd.press(KEYCODES_L[key_id])
    if event.released:
        print("Released", key_id, key_sw[key_id])
        kbd.release(KEYCODES_L[key_id])
