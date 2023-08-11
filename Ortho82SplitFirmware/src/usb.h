#ifndef USB_H
#define USB_H

#define idVendor 0x03eb  // Atmel Corp.
#define idProduct 0x2ff4  // ATMega32u4 DFU Bootloader (This isn't a real product so I don't
          // have legitimate IDs)
#define KEYBOARD_ENDPOINT_NUM 3  // The second endpoint is the HID endpoint

#define CONFIG_SIZE 34
#define HID_OFFSET 18

// HID Class-specific request codes - refer to HID Class Specification
// Chapter 7.2 - Remarks

#define GET_REPORT 0x01
#define GET_IDLE 0x02
#define GET_PROTOCOL 0x03
#define SET_REPORT 0x09
#define SET_IDLE 0x0A
#define SET_PROTOCOL 0x0B


int usb_init(void);

#endif