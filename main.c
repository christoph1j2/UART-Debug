// Definujeme frekvenci krystalu pro funkce zpoždění (16 MHz)
#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "uart.h"

volatile char received_char;

ISR(USART_RX_vect)
{
    received_char = UDR0; // přečteme přijatý znak z bufferu
}

int main(void)
{
    uart_init();
    sei(); // Zapnutí hlavního jističe přerušení

    while (1)
    {
        if (received_char != 0)
        {
            uart_transmit(received_char); // Odeslání přijatého znaku zpět
            received_char = 0;            // Resetujeme proměnnou po odeslání
        }
    }
    return 0;
}