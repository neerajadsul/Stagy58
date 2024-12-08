import board
from digitalio import DigitalInOut, Pull, Direction
import usb_hid
from adafruit_hid.keyboard import Keyboard
from adafruit_hid.keycode import Keycode
import keypad
import busio


LR_side = DigitalInOut(board.GP1)
LR_side.direction = Direction.INPUT
LR_side.pull = Pull.UP
LR = "L" if LR_side.value else "R"

print("Half:", LR)
i2c = busio.I2C(scl=board.GP9, sda=board.GP8)

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
    Keycode.RIGHT_CONTROL, Keycode.OPTION, Keycode.COMMAND, Keycode.SPACE, Keycode.BACKSLASH, Keycode.BACKSPACE,
)

KEYCODES = {
    "R": KEYCODES_R,
    "L": KEYCODES_L,
}

MOD_KEY_NUM = 28

# H, J, K, L as Arrow Keys
ARROW_KEYCODES = { "L" :
    {
        0: Keycode.F1,
        1: Keycode.F2,
        2: Keycode.F3,
        3: Keycode.F4,
        4: Keycode.F5,
    },
    "R": {
        17:Keycode.LEFT_ARROW,
        16:Keycode.DOWN_ARROW,
        15:Keycode.UP_ARROW,
        14:Keycode.RIGHT_ARROW,
        11:Keycode.QUOTE,
        10:Keycode.GRAVE_ACCENT,
    }
}


led = DigitalInOut(board.GP25)
led.direction = Direction.OUTPUT

kbd = Keyboard(usb_hid.devices)
mod_flag = False

while True:
    event = km.events.get()
    if event:
        key_id = event.key_number
        if event.pressed:
            led.value = True
            if key_id == MOD_KEY_NUM:
                mod_flag = True
            else:
                kbd.press(KEYCODES[LR][key_id])
        if event.released:
            led.value = False
            if key_id == MOD_KEY_NUM:
                mod_flag[LR] = False
            else:
                kbd.release(KEYCODES[LR][key_id])

        action = str(event).split(' ')[-1]
        data = f"<{LR} {key_id} {action} {mod_flag}\n"
        print(data, end='')
