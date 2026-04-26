#![no_std]
#![no_main]

#[unsafe(link_section = ".boot2")]
#[used]
pub static BOOT2: [u8; 256] = rp2040_boot2::BOOT_LOADER_W25Q080;

use cortex_m::prelude::*;
use defmt::*;
use defmt_rtt as _;
use embedded_hal::digital::*;
use fugit::ExtU32;
use hal::gpio::{DynPinId, FunctionSioInput, FunctionSioOutput, Pin, PullDown, PullUp};
use panic_probe as _;
use rp2040_hal::gpio::{PullBusKeep, PullNone};
use rp2040_hal::pio::Buffers;
use rp2040_hal::{self as hal, entry};
use usb_device::class_prelude::*;
use usb_device::prelude::*;
use usbd_human_interface_device::UsbHidError;
use usbd_human_interface_device::page::Keyboard;
use usbd_human_interface_device::prelude::UsbHidClassBuilder;

#[entry]
fn main() -> ! {
    debug!("Entered Main");
    let mut pac = hal::pac::Peripherals::take().unwrap();

    let mut watchdog = hal::Watchdog::new(pac.WATCHDOG);

    let clocks = hal::clocks::init_clocks_and_plls(
        12_000_000u32,
        pac.XOSC,
        pac.CLOCKS,
        pac.PLL_SYS,
        pac.PLL_USB,
        &mut pac.RESETS,
        &mut watchdog,
    )
    .ok()
    .unwrap();

    let timer = hal::Timer::new(pac.TIMER, &mut pac.RESETS, &clocks);

    let sio = hal::Sio::new(pac.SIO);

    let pins = hal::gpio::Pins::new(
        pac.IO_BANK0,
        pac.PADS_BANK0,
        sio.gpio_bank0,
        &mut pac.RESETS,
    );

    info!("Booting");

    info!("USB Allocator");
    let usb_bus = UsbBusAllocator::new(hal::usb::UsbBus::new(
        pac.USBCTRL_REGS,
        pac.USBCTRL_DPRAM,
        clocks.usb_clock,
        true,
        &mut pac.RESETS,
    ));
    info!("Keyboard HID Class");
    let mut kbd = UsbHidClassBuilder::new()
        .add_device(
            usbd_human_interface_device::device::keyboard::NKROBootKeyboardConfig::default(),
        )
        .build(&usb_bus);

    let mut usb_dev = UsbDeviceBuilder::new(&usb_bus, UsbVidPid(0x1209, 0x0001))
        .strings(&[StringDescriptors::default()
            .manufacturer("125 Systems")
            .product("N-Key Rollover Keyboard")
            .serial_number("0001")])
        .unwrap()
        .build();

    let mut led_pin = pins.gpio25.into_push_pull_output();
    led_pin.set_low().ok();

    let mut rows: [Pin<DynPinId, FunctionSioInput, PullDown>; 5] = [
        pins.gpio16.into_pull_down_input().into_dyn_pin(),
        pins.gpio15.into_pull_down_input().into_dyn_pin(),
        pins.gpio14.into_pull_down_input().into_dyn_pin(),
        pins.gpio13.into_pull_down_input().into_dyn_pin(),
        pins.gpio12.into_pull_down_input().into_dyn_pin(),
    ];
    let mut cols: [Pin<DynPinId, FunctionSioOutput, PullDown>; 6] = [
        pins.gpio22.into_push_pull_output().into_dyn_pin(),
        pins.gpio21.into_push_pull_output().into_dyn_pin(),
        pins.gpio20.into_push_pull_output().into_dyn_pin(),
        pins.gpio19.into_push_pull_output().into_dyn_pin(),
        pins.gpio18.into_push_pull_output().into_dyn_pin(),
        pins.gpio17.into_push_pull_output().into_dyn_pin(),
    ];

    let mut input_count_down = timer.count_down();
    input_count_down.start(50.millis());

    let mut tick_count_down = timer.count_down();
    tick_count_down.start(1.millis());

    // let mut tick_count_down = timer.count_down();
    // tick_count_down.start(1.millis());

    loop {
        if input_count_down.wait().is_ok() {
            led_pin.toggle();
            let keys = get_keys(&mut rows, &mut cols);

            match kbd.device().write_report(keys) {
                Err(UsbHidError::WouldBlock) => {}
                Err(UsbHidError::Duplicate) => {}
                Ok(_) => {}
                Err(err) => {
                    core::panic!("Failed to Write Keybaord Report: {:?}", err)
                }
            }
        }
        if tick_count_down.wait().is_ok() {
            match kbd.tick() {
                Err(UsbHidError::WouldBlock) => {}
                Ok(_) => {}
                Err(err) => {
                    core::panic!("Failed to process Keybaord tick: {:?}", err)
                }
            }
        }

        if usb_dev.poll(&mut [&mut kbd]) {
            match kbd.device().read_report() {
                Err(UsbError::WouldBlock) => {
                    // do nothing
                }
                Err(err) => {
                    core::panic!("Failed to Read Keybaord Report: {:?}", err)
                }
                Ok(_leds) => {
                    info!("Num Lock toggle");
                }
            }
        }
    }
}

fn get_keys(
    rows: &mut [Pin<DynPinId, FunctionSioInput, PullDown>],
    cols: &mut [Pin<DynPinId, FunctionSioOutput, PullDown>],
) -> [Keyboard; 5] {
    let mut sw_matrix: [[u8; 5]; 6] = [[0x00; 5]; 6];

    for (idx, col) in cols.into_iter().enumerate() {
        col.set_state(PinState::High);
        for (jdx, row) in rows.into_iter().enumerate() {
            if row.is_high().unwrap() {
                sw_matrix[idx][jdx] = 1;
            } else {
                sw_matrix[idx][jdx] = 0;
            }
        }
        col.set_state(PinState::Low);
    }
    debug!("RS: {:?}", sw_matrix);

    [Keyboard::NoEventIndicated; 5]
}

// [
//     if keys[0].is_low().unwrap() {
//         Keyboard::Keyboard1
//     } else {
//         Keyboard::NoEventIndicated
//     },
//     if keys[1].is_low().unwrap() {
//         Keyboard::Keyboard2
//     } else {
//         Keyboard::NoEventIndicated
//     },
//     if keys[2].is_low().unwrap() {
//         Keyboard::Keyboard3
//     } else {
//         Keyboard::NoEventIndicated
//     },
//     if keys[3].is_low().unwrap() {
//         Keyboard::Keyboard4
//     } else {
//         Keyboard::NoEventIndicated
//     },
//     if keys[4].is_low().unwrap() {
//         Keyboard::Keyboard5
//     } else {
//         Keyboard::NoEventIndicated
//     },
// ]
