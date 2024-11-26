from serial import Serial
from keymap import Keymap
import time

port_id = "/dev/cu.usbserial-FTFMEY6Y"

TINY_WAIT = 0.005
SHORT_WAIT = 0.05
MED_WAIT = 0.1
LONG_WAIT = 0.5

empty_keys = bytearray([0x00]*8)
alt = bytearray([Keymap.LEFT_ALT, 0x00] + [0x00] + [0x00]*5)
alt_tab = bytearray([Keymap.LEFT_ALT, 0x00] + [Keymap.TAB] + [0x00]*5)
backspace = bytearray([0x00, 0x00] + [Keymap.BACKSPACE]+ [0x00]*5)
enter = bytearray([0x00, 0x00] + [Keymap.ENTER] + [0x00]*5)
ctrl_alt_del = bytearray([Keymap.LEFT_CTRL | Keymap.LEFT_ALT, 0x00] + [Keymap.DELETE] + [0x00]*5)
key_del = bytearray([0x00, 0x00] + [Keymap.DELETE]+ [0x00]*5)
key_esc = bytearray([0x00, 0x00] + [Keymap.ESC]+ [0x00]*5)

def send_keys(data: bytearray, ser: Serial) -> None:
    for x in data:
        print(f"{x:02x}", end=', ')
    print()
    print(ser.write(data))
    for x in empty_keys:
        print(f"{x:02x}", end=', ')
    print()
    print(ser.write(empty_keys))
    time.sleep(0.001)
        

def send_string():
    with Serial(port_id, baudrate=9600) as ser:
        for x in "hello world!":
            ser.write(x.encode())
            time.sleep(0.005)


def send_alt_tab():
    with Serial(port_id, baudrate=9600) as ser:
        # send_keys(empty_keys, ser=ser)    
        time.sleep(SHORT_WAIT)
        # send_keys(alt, ser=ser)
        # time.sleep(TINY_WAIT)    
        send_keys(alt_tab, ser=ser)
        time.sleep(LONG_WAIT)


def send_ctrl_del_then_esc():
    with Serial(port_id, baudrate=9600) as ser:
        send_keys(ctrl_alt_del, ser=ser)
        time.sleep(MED_WAIT)
        send_keys(empty_keys, ser=ser)
        time.sleep(LONG_WAIT)
        send_keys(key_esc, ser=ser)
        time.sleep(LONG_WAIT)
        # send_keys(empty_keys, ser=ser)
        time.sleep(LONG_WAIT)

def type_notepad(ser):
    for c in [Keymap.N, Keymap.O, Keymap.T, Keymap.E, Keymap.P, Keymap.A, Keymap.D]:
        key = bytearray([0x00, 0x00] + [c] + [0x00]*5)
        send_keys(key, ser=ser)
        time.sleep(SHORT_WAIT)
        time.sleep(SHORT_WAIT)

def open_notepad():
    win_run = bytearray([Keymap.LEFT_GUI, 0x00] + [Keymap.R] + [0x00]*5)
    with Serial(port_id, baudrate=9600) as ser:
        send_keys(win_run, ser=ser)
        time.sleep(LONG_WAIT)
        time.sleep(SHORT_WAIT)
        send_keys(backspace, ser=ser)
        time.sleep(SHORT_WAIT)
        time.sleep(SHORT_WAIT)
        type_notepad(ser)
        send_keys(enter, ser=ser)
        time.sleep(LONG_WAIT)
        type_notepad(ser)

if __name__ == "__main__":
    # send_string()
    send_alt_tab()
    send_ctrl_del_then_esc()
    open_notepad()

