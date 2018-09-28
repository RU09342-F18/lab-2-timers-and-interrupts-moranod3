#include <msp430.h> 

#define setFrequency 50000
#define changeRate 5000

void init (void);
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    init();
    __enable_interrupt(); //enables interrupts

    for (;;) {
    }
}
//Timer Interrupt
#pragma vector = TIMER0_A0_VECTOR
    __interrupt void Timer_A (){
        P1OUT ^= (BIT0|BIT6);
    }

#pragma vector = PORT1_VECTOR
__interrupt void Port_1(void){
    CCR0 -= changeRate;
    P1IFG &= ~BIT3;
        }

void init (void){
    P1DIR |= (BIT0|BIT6); //Sets Pins 1.0 and 1.6 to be outputs
    P1REN |= BIT3; //Sets Pin 1.3 to be pull up/down enabled
    P1OUT |= BIT3; //Sets Pin 1.3 to pull up resistor
    P1OUT |= (BIT0|BIT6); //Sets Pin 1.0 and 1.6 to be ON to begin
    P1IE |= BIT3; //Enables interrupt on button
    P1IES |= BIT3; //Enables high - to - low behavior on interrupt


    CCTL0 = CCIE;                             // CCR0 interrupt enabled
    CCR0 =  setFrequency;                             //Sets frequency

    TACTL = TASSEL_2 + MC_1 + ID_3;          // SMCLK selected, Continous enabled Divider = 4

}
