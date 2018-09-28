#include <msp430.h>
void init(void);
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;    // Stop WDT
    init();
    for (;;){                         // inf loop
    }
}

// Timer B0 interrupt service routine
#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer_B (void)
{
    P1OUT ^= BIT0;
    TB0CCR0 += 50000;                             // Add Offset to TBCCR0
}

void init(void){

    P1DIR |= BIT0;                                // P1.0 output
    P1OUT |= BIT0;                                // P1.0 high

    // Disable the GPIO power-on default high-impedance mode to activate
    // previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;

    TB0CCTL0 |= CCIE;                             // TBCCR0 interrupt enabled
    TB0CCR0 = 10000;
    TB0CTL |= TBSSEL__SMCLK | MC__CONTINUOUS;     // SMCLK, continuous mode

    __bis_SR_register(LPM0_bits | GIE);           // Enter LPM3 w/ interrupts
}
