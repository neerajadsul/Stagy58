import storage
import board
from digitalio import DigitalInOut, Pull, Direction


show_drive_pin = DigitalInOut(board.GP16)
show_drive_pin.direction = Direction.INPUT
show_drive_pin.pull = Pull.UP

# Pull down GP16 to show the Circuitpython drive
if show_drive_pin.value:
    storage.disable_usb_drive()
