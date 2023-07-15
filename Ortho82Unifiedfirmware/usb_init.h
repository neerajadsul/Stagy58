/*******************************************************
USB library initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator
Copyright: Neeraj Adsul <neeraj.adsul[at]gmail.com>

Project : Ortho82UnifiedKeyboard
*******************************************************/

#ifndef _USB_INIT_INCLUDED_
#define _USB_INIT_INCLUDED_

#include <usb_device.h>
#include <usb_hid.h>

// Manufacturer string
#define USB_STR_MANUFACTURER '1','2','5',' ','S','y','s','t','e','m','s'
// Number of characters in the manufacturer string
#define USB_STR_MANUFACTURER_CHARS 11

// Product string
#define USB_STR_PRODUCT 'O','r','t','h','o',' ','U','n','i','f','i','e','d','8','2',' ','K','e','y','b','o','a','r','d'
// Number of characters in the product string
#define USB_STR_PRODUCT_CHARS 24

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
#define USB_INTERFACE0_IN_EP_SIZE 8
#define USB_INTERFACE0_IN_EP_SERVICE_INTERVAL 5

// USB configuration table
extern flash USB_CONFIG_t usb_config;
#endif

