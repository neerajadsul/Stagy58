from serial import Serial
from keymap import Keymap
import time

port_id = "/dev/cu.usbserial-FTFMEY6Y"


empty_keys = bytearray([0x00]*8)
alt = bytearray([Keymap.LEFT_ALT, 0x00] + [0x00] + [0x00]*5)
alt_tab = bytearray([Keymap.LEFT_ALT, 0x00] + [Keymap.TAB] + [0x00]*5)

ctrl_alt_del = bytearray([Keymap.LEFT_CTRL | Keymap.LEFT_ALT, 0x00] + [Keymap.DELETE] + [0x00]*5)
key_del = bytearray([0x00, 0x00] + [Keymap.DELETE]+ [0x00]*5)
key_esc = bytearray([0x00, 0x00] + [Keymap.ESC]+ [0x00]*5)

def send_keys(data: bytearray, ser: Serial) -> None:
    for x in data:
        print(f"{x:02x}", end=', ')
    print()
    print(ser.write(data))
    time.sleep(0.001)
        

def send_string():
    with Serial(port_id, baudrate=9600) as ser:
        for x in "hello world!":
            ser.write(x.encode())
            time.sleep(0.005)


def send_alt_tab():
    with Serial(port_id, baudrate=9600) as ser:
        # send_keys(empty_keys, ser=ser)    
        time.sleep(0.05)
        # send_keys(alt, ser=ser)
        # time.sleep(0.005)    
        send_keys(alt_tab, ser=ser)
        time.sleep(0.505)
        send_keys(empty_keys, ser=ser)    
        time.sleep(0.005)
        send_keys(empty_keys, ser=ser)
        time.sleep(0.005)


def send_ctrl_del_then_esc():
    with Serial(port_id, baudrate=9600) as ser:
        send_keys(ctrl_alt_del, ser=ser)
        time.sleep(0.1)
        send_keys(empty_keys, ser=ser)
        time.sleep(0.5)
        send_keys(key_esc, ser=ser)
        time.sleep(0.5)
        send_keys(empty_keys, ser=ser)
        time.sleep(0.5)

def open_notepad():
    



if __name__ == "__main__":
    # send_string()
    send_alt_tab()
    send_ctrl_del_then_esc()
    open_notepad()

