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
    P1OUT ^= BIT0;                             // Add Offset to TBCCR0
}

#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void){
    TBCCR0 -= 10000;
    P1IFG &= ~BIT3;
        }

void init(void){

    P1DIR |= BIT0;                                // P1.0 output
    P1OUT |= BIT0;    // P1.0 high
    P1REN |= BIT1;     // set port1.1 to a pull up resistor
    P1IE |= BIT3; //Enables interrupt on button
    P1IES |= BIT3; //Enables high - to - low behavior on interrupt


    // Disable the GPIO power-on default high-impedance mode to activate
    // previously configured port settings
    PM5CTL0 &= ~LOCKLPM5;

    TB0CCTL0 |= CCIE;                             // TBCCR0 interrupt enabled
    TB0CCR0 = 50000;
    TB0CTL |= TBSSEL__SMCLK | MC__CONTINUOUS | ID_3;     // SMCLK, continuous mode

    __bis_SR_register(LPM0_bits | GIE);           // Enter LPM3 w/ interrupts
}

