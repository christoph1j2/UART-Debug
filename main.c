// Definujeme frekvenci krystalu pro funkce zpoždění (16 MHz)
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // nastaveni pinu PB5 jako vystupni (DDR = Data Direction Register)
    DDRB |= (1 << DDB5);

    while (1) {
        // prepnuti stavu pinu PB5 (XOR operace nad Port Registrem)
        PORTB ^= (1 << PORTB5);
        
        // cekani pul sekundy
        _delay_ms(500);
    }

    return 0; // tento return se nikdy nedostane, ale je zde pro formální správnost
}