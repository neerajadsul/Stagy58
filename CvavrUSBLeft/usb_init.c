/*******************************************************
USB library initialization created by the
CodeWizardAVR V3.38 Automatic Program Generator
� Copyright 1998-2019 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : SplitKeyboardPS2
*******************************************************/

#include "usb_init.h"

// USB device descriptors

flash USB_DEVICE_DESCRIPTOR_t usb_device_descriptor =
{
.bLength=sizeof(USB_DEVICE_DESCRIPTOR_t),
.bDescriptorType=USB_DESCRIPTOR_TYPE_DEVICE,
.bcdUSB=USB_SPEC,
.bDeviceClass=USB_CLASS_NONE,
.bDeviceSubClass=USB_SUBCLASS_NONE,
.bDeviceProtocol=USB_PROTOCOL_NONE,
.bMaxPacketSize0=USB_ENDPOINT0_SIZE,
.idVendor=USB_VENDOR_ID,
.idProduct=USB_PRODUCT_ID,
.bcdDevice=USB_DEVICE_RELEASE,
.iManufacturer=1,
.iProduct=2,
.iSerialNumber=3,
.bNumConfigurations=1
};

// HID Keyboard report descriptor
flash unsigned char hid_keyboard_report_descriptor[]=
{
HID_RD_USAGE_PAGE(8,1), // Generic desktop
HID_RD_USAGE(8,6), // Keyboard
HID_RD_COLLECTION(8,HID_RD_COLLECTION_APPLICATION),
HID_RD_REPORT_SIZE(8,1),
HID_RD_REPORT_COUNT(8,8),
HID_RD_USAGE_PAGE(8,7), // Key codes
HID_RD_USAGE_MIN(8,0xE0),
HID_RD_USAGE_MAX(8,0xE7),
HID_RD_LOGICAL_MIN(8,0),
HID_RD_LOGICAL_MAX(8,1),
HID_RD_INPUT(8,HID_RD_DATA_F | HID_RD_VARIABLE_F | HID_RD_ABSOLUTE_F),
HID_RD_REPORT_COUNT(8,1),
HID_RD_REPORT_SIZE(8,8),
HID_RD_INPUT(8,HID_RD_CONSTANT_F | HID_RD_VARIABLE_F),
HID_RD_REPORT_COUNT(8,5),
HID_RD_REPORT_SIZE(8,1),
HID_RD_USAGE_PAGE(8,8), // Leds
HID_RD_USAGE_MIN(8,1),
HID_RD_USAGE_MAX(8,5),
HID_RD_OUTPUT(8,HID_RD_DATA_F | HID_RD_VARIABLE_F | HID_RD_ABSOLUTE_F | HID_RD_NON_VOLATILE_F),
HID_RD_REPORT_COUNT(8,1),
HID_RD_REPORT_SIZE(8,3),
HID_RD_OUTPUT(8,HID_RD_CONSTANT_F | HID_RD_VARIABLE_F),
HID_RD_REPORT_COUNT(8,6),
HID_RD_REPORT_SIZE(8,8),
HID_RD_LOGICAL_MIN(8,0),
HID_RD_LOGICAL_MAX(8,0xFF),
HID_RD_USAGE_PAGE(8,7), // Key codes
HID_RD_USAGE_MIN(8,0),
HID_RD_USAGE_MAX(8,0xFF),
HID_RD_INPUT(8,HID_RD_DATA_F | HID_RD_ARRAY_F),
HID_RD_END_COLLECTION(0)
};

// Strings descriptors
flash unsigned short usb_string0[]=
{
2+sizeof(short)+ // bLength
(USB_DESCRIPTOR_TYPE_STRING<<8), // bDescriptorType
USB_LANG_ID_US_ENGLISH // wLangID
};

flash unsigned short usb_string1[]=
{
2+USB_STR_MANUFACTURER_CHARS*2+ // bLength
(USB_DESCRIPTOR_TYPE_STRING<<8), // bDescriptorType
USB_STR_MANUFACTURER // bString
};

flash unsigned short usb_string2[]=
{
2+USB_STR_PRODUCT_CHARS*2+ // bLength
(USB_DESCRIPTOR_TYPE_STRING<<8), // bDescriptorType
USB_STR_PRODUCT // bString
};

flash unsigned short usb_string3[]=
{
2+USB_STR_SERIAL_NUMBER_CHARS*2+ // bLength
(USB_DESCRIPTOR_TYPE_STRING<<8), // bDescriptorType
USB_STR_SERIAL_NUMBER // bString
};

// USB configuration descriptor
flash struct
{
// Configuration Descriptor
USB_CONFIG_DESCRIPTOR_t config_descriptor;

// Interface 0 - HID Keyboard
USB_INTERFACE_DESCRIPTOR_t interface_descriptor0;
USB_HID_INTERFACE_DESCRIPTOR_t interface_hid_descriptor0;
USB_ENDPOINT_DESCRIPTOR_t interface_in_endpoint_descriptor0;
} usb_config_descriptor=
{
// Configuration Descriptor
{
.bLength=sizeof(USB_CONFIG_DESCRIPTOR_t),
.bDescriptorType=USB_DESCRIPTOR_TYPE_CONFIGURATION,
.wTotalLength=sizeof(usb_config_descriptor),
.bNumInterfaces=1,
.bConfigurationValue=1,
.iConfiguration=USB_STRING_NONE,
.bmAttributes=USB_ATTR_COMPAT1 | USB_ATTR_SELF_POWERED,
.bMaxPower=100/2
},

// Interface 0 - HID Keyboard
// Descriptor
{
.bLength=sizeof(USB_INTERFACE_DESCRIPTOR_t),
.bDescriptorType=USB_DESCRIPTOR_TYPE_INTERFACE,
.bInterfaceNumber=0,
.bAlternateSetting=USB_ALTERNATE_SETTING_NONE,
.bNumEndpoints=1,
.bInterfaceClass=USB_CLASS_HID,
.bInterfaceSubClass=USB_SUBCLASS_HID_BOOT,
.bInterfaceProtocol=USB_PROTOCOL_KEYBOARD,
.iInterface=USB_STRING_NONE
},

// HID Interface Descriptor - Keyboard
{
.bLength=sizeof(USB_HID_INTERFACE_DESCRIPTOR_t),
.bDescriptorType=USB_DESCRIPTOR_TYPE_HID_INTERFACE,
.bcdHID=USB_HID_SPEC,
.bCountryCode=0,
.bNumDescriptors=1,
.bReportDescriptorType=USB_DESCRIPTOR_TYPE_REPORT,
.wDescriptorLength=sizeof(hid_keyboard_report_descriptor)
},

// IN Endpoint Descriptor
{
.bLength=sizeof(USB_ENDPOINT_DESCRIPTOR_t),
.bDescriptorType=USB_DESCRIPTOR_TYPE_ENDPOINT,
.bEndpointAddress=USB_INTERFACE0_IN_EP | USB_ENDPOINT_DIR_IN,
.bmAttributes=USB_TRANSFER_INTERRUPT | USB_EP_ATTR_NO_SYNC | USB_EP_USAGE_DATA,
.wMaxPacketSize=USB_INTERFACE0_IN_EP_SIZE,
.bInterval=USB_INTERFACE0_IN_EP_SERVICE_INTERVAL
}
};

// This table defines which descriptor data is sent for each specific
// request from the host (in wValue and wIndex)
flash USB_DESCRIPTOR_LIST_t usb_descriptor_list[]=
{
{0,USB_DESCRIPTOR_TYPE_DEVICE,0,&usb_device_descriptor,sizeof(usb_device_descriptor)},
{0,USB_DESCRIPTOR_TYPE_CONFIGURATION,0,&usb_config_descriptor,sizeof(usb_config_descriptor)},
{0,USB_DESCRIPTOR_TYPE_HID_INTERFACE,0 /* Interface # */,&usb_config_descriptor.interface_hid_descriptor0,sizeof(USB_HID_INTERFACE_DESCRIPTOR_t)},
{0,USB_DESCRIPTOR_TYPE_REPORT,0 /* Interface # */,hid_keyboard_report_descriptor,sizeof(hid_keyboard_report_descriptor)},
{0,USB_DESCRIPTOR_TYPE_STRING,0,&usb_string0,sizeof(usb_string0)},
{1,USB_DESCRIPTOR_TYPE_STRING,USB_LANG_ID_US_ENGLISH,&usb_string1,sizeof(usb_string1)},
{2,USB_DESCRIPTOR_TYPE_STRING,USB_LANG_ID_US_ENGLISH,&usb_string2,sizeof(usb_string2)},
{3,USB_DESCRIPTOR_TYPE_STRING,USB_LANG_ID_US_ENGLISH,&usb_string3,sizeof(usb_string3)}
};

// USB device configuration
flash USB_CONFIG_t usb_config=
{
// Interface(s) configuration
.interface=
{
// Interface 0
{
.bInterfaceClass=USB_CLASS_HID,
.bInterfaceProtocol=USB_PROTOCOL_KEYBOARD,
.report_data=&usb_keyboard,
.report_size=sizeof(USB_KEYBOARD_t),
// IN endpoint configuration
.in={.ep=USB_INTERFACE0_IN_EP,.type=USB_TRANSFER_INTERRUPT,.size=USB_INTERFACE0_IN_EP_SIZE}
}
},
.pdescriptor_list=usb_descriptor_list,
.descriptor_list_items=sizeof(usb_descriptor_list)/sizeof(USB_DESCRIPTOR_LIST_t),
.timeout={.tx=USB_TX_TIMEOUT,.rx=USB_RX_TIMEOUT},
// Use the PLL running at 48 MHz as USB clock source
.usb_clock=USB_CLOCK_PLL_48M,
// USB interrupt priority level: Low Level
.int_level=USB_INTLVL_LO_gc,
// No device suspend handler is used
.usb_suspend_handler=NULL,
// No device resume handler is used
.usb_resume_handler=NULL
};

