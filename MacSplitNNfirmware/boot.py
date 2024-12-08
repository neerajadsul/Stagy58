import usb_hid

# usb_hid.disable()
usb_hid.enable(
    (usb_hid.Device.Keyboard,)
)
