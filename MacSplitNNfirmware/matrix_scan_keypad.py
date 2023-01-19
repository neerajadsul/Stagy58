import time
import board
import digitalio
import usb_hid
import keypad


km = keypad.KeyMatrix(
    row_pins=(board.GP16, board.GP15, board.GP14, board.GP13, board.GP12),
    column_pins=(board.GP22, board.GP21, board.GP20, board.GP19, board.GP18, board.GP17),
    columns_to_anodes=True,
)

led = digitalio.DigitalInOut(board.GP25)
led.direction = digitalio.Direction.OUTPUT

print("Welcome to Keypad")
while True:
    event = km.events.get()
    if event:
        if "pressed" in str(event):
            led.value = True
        if "released" in str(event):
            led.value = False
        print(event)


