/*******************************************************
USB library initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator
© Copyright 1998-2019 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : SplitKeyboardPS2
*******************************************************/

#ifndef _USB_INIT_INCLUDED_
#define _USB_INIT_INCLUDED_

#include <usb_device.h>
#include <usb_cdc.h>

// Manufacturer string
#define USB_STR_MANUFACTURER '1','2','5','S','y','s','t','e','m','s'
// Number of characters in the manufacturer string
#define USB_STR_MANUFACTURER_CHARS 10

// Product string
#define USB_STR_PRODUCT 'O','r','t','h','o','l','i','n','e','a','r',' ','S','p','l','i','t',' ','K','e','y','b','o','a','r','d'
// Number of characters in the product string
#define USB_STR_PRODUCT_CHARS 26

// Serial number string
#define USB_STR_SERIAL_NUMBER '0','0','0','0','1'
// Number of characters in the serial number string
#define USB_STR_SERIAL_NUMBER_CHARS 5

// idVendor
// Vendor ID, must match the INF file
#define USB_VENDOR_ID 0x03EB

// idProduct value
// Product ID, must match the INF file
#define USB_PRODUCT_ID 0x3110

// bcdDevice value
// Device release number in BCD format
#define USB_DEVICE_RELEASE 0x311

// Transmission timeout period [ms]
#define USB_TX_TIMEOUT 100

// Reception timeout period [ms]
#define USB_RX_TIMEOUT 250

// Interface 0 IN endpoint settings
#define USB_INTERFACE0_IN_EP 1
#define USB_INTERFACE0_IN_EP_SIZE 16
#define USB_INTERFACE0_IN_EP_SERVICE_INTERVAL 255

// Interface 1 IN endpoint settings
#define USB_INTERFACE1_IN_EP 2
#define USB_INTERFACE1_IN_EP_SIZE 64

// Interface 1 OUT endpoint settings
#define USB_INTERFACE1_OUT_EP 2
#define USB_INTERFACE1_OUT_EP_SIZE 64

// USB configuration table
extern flash USB_CONFIG_t usb_config;
#endif

