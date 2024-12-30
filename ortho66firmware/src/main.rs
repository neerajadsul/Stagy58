#![no_std]
#![no_main]

use cortex_m_rt::entry;

use panic_probe as _;
use stm32_usbd::UsbPeripheral;
use stm32f0xx_hal::{pac, stm32f0};

#[entry]
fn main() -> ! {
    let mut pac = pac::Peripherals::take().unwrap();
    let core = pac::CorePeripherals::take().unwrap();

    let clocks = stm32f0xx_hal::

    loop {}
}
