#include <avr/io.h>
#include "uart.h"

void uart_init(void)
{
    // Nastaveni baud rate na 115200 (pro F_CPU 16MHz a U2X0 = 1)
    UBRR0H = 0;
    UBRR0L = 16;

    // Aktivace rezium dvojnasobne rychlosti pro vyssi presnost
    UCSR0A |= (1 << U2X0);

    // Zapnuti vysilace a prijimace
    UCSR0B |= (1 << TXEN0);
    UCSR0B |= (1 << RXEN0);
    UCSR0B |= (1 << RXCIE0); // povoleni preruseni pro prijem dat

    // (pocet bitu a parity nechavame na vychozich 8-N-1)
}

void uart_transmit(unsigned char data)
{
    // Cekame ve smyce, dokud neni buffer prazdny (bit UDRE0 je 0)
    while ((UCSR0A & (1 << UDRE0)) == 0)
    {
        /* polling */
    }

    // Buffer je volny, azpiseme data a HW je zacne posilat
    UDR0 = data;
}