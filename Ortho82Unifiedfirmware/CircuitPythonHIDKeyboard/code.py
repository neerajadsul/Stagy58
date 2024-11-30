import board
from digitalio import DigitalInOut, Pull, Direction
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
import busio

NONE_KEY = 200
FN_KEY = 201
MOD_LEFT_KEY = 202

LEFT_CODE = {
    "L": [
        Keycode.ESCAPE, Keycode.F1, Keycode.F2, Keycode.F3, Keycode.F4, Keycode.F5, Keycode.F6,
        Keycode.GRAVE_ACCENT, Keycode.ONE, Keycode.TWO, Keycode.THREE, Keycode.FOUR, Keycode.FIVE, Keycode.SIX,
        Keycode.TAB, Keycode.Q, Keycode.W, Keycode.E, Keycode.R, Keycode.T, Keycode.Y,
        Keycode.CAPS_LOCK, Keycode.A, Keycode.S , Keycode.D, Keycode.F, Keycode.G, Keycode.H,
        Keycode.LEFT_SHIFT, Keycode.BACKSLASH, Keycode.Z, Keycode.X, Keycode.C, Keycode.V, Keycode.B,
        NONE_KEY, Keycode.LEFT_CONTROL, FN_KEY, Keycode.COMMAND, Keycode.LEFT_ALT, MOD_LEFT_KEY, Keycode.SPACE
    ],
    "R": [
        Keycode.DELETE, Keycode.F12, Keycode.F11, Keycode.F10, Keycode.F9, Keycode.F8, Keycode.F7,
        Keycode.BACKSPACE, Keycode.EQUALS, Keycode.MINUS, Keycode.ZERO, Keycode.NINE, Keycode.EIGHT, Keycode.SEVEN,
        Keycode.ENTER, Keycode.RIGHT_BRACKET, Keycode.LEFT_BRACKET, Keycode.P, Keycode.O, Keycode.I, Keycode.U,
        Keycode.ENTER, Keycode.POUND, Keycode.QUOTE, Keycode.SEMICOLON, Keycode.L, Keycode.K, Keycode.J,
        Keycode.RIGHT_SHIFT, Keycode.UP_ARROW, Keycode.FORWARD_SLASH, Keycode.PERIOD, Keycode.COMMA, Keycode.M, Keycode.N,
        NONE_KEY, Keycode.RIGHT_ARROW, Keycode.DOWN_ARROW, Keycode.LEFT_ARROW, Keycode.COMMAND, Keycode.RIGHT_ALT, Keycode.SPACE
    ]
}


def send_key(received):
    """Decodes received message and sends keyboard event."""
    data = "".join(chr(x) for x in received).strip()
    if not(data.startswith("L") or data.startswith("R")):
        print(data)
        return # If not keyboard data, don't process
    left_right, pressed, key_pos ,key_id = data.split()
    print(left_right, pressed, key_pos, key_id)
    left_right = left_right.strip()
    key_pos = int(key_pos)
    pressed = True if pressed in "1P" else False
    if pressed:
        kbd.press(LEFT_CODE[left_right][key_pos])
#         print(key_id, "pressed")
        pass
    else:
        kbd.release(LEFT_CODE[left_right][key_pos])
#         print(key_id, "released")
        pass


uart = busio.UART(board.D6, board.D7, baudrate=115200)
uart.reset_input_buffer()

kbd = Keyboard(usb_hid.devices)

while True:

    # Read keys from Ortho82 UART
    bytes_read = uart.readline()
    if not bytes_read:
        continue
    else:
        received = "".join(chr(x) for x in bytes_read).strip()
        print(received)

