/*
    Copyright (C) 2014 Rudy Hardeman 

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#include "ets_sys.h"
#include "osapi.h"
#include "gpio.h"
#include "os_type.h"

#include "pin_digital.h"

void pinMode(uint8_t pin, uint8_t mode)
{
    //Set pin to I/O mode
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);

    if (mode == INPUT) {
        //Need to find how to disable the pullup
        gpio_output_set(0, 0, 0, GPIO_ID_PIN(0));
    } else if (mode == INPUT_PULLUP) {
        gpio_output_set(0, 0, 0, GPIO_ID_PIN(0));
    }
}

void digitalWrite(uint8_t pin, uint8_t val)
{
    uint8_t bit = digitalPinToBitMask(pin);
    uint8_t port = digitalPinToPort(pin);
    volatile uint8_t *out;

    if (port == NOT_A_PIN) return;

    if (val == LOW)
        gpio_output_set(0, BIT2, BIT2, 0);
    else
        gpio_output_set(BIT2, 0, BIT2, 0);
}
