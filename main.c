// Definujeme frekvenci krystalu pro funkce zpoždění (16 MHz)
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

#include "uart.h"

int main(void)
{
    uart_init();

    while (1)
    {
        uart_transmit('H'); // posle jeden znak
        uart_transmit('i');
        uart_transmit('!');
        uart_transmit('\n'); // posle znak pro novy radek

        _delay_ms(500); // pocka pul sekundy
    }
    return 0;
}