
#include <msp430.h>


/*  main.c */
void init(void);
int main(void)
{
   WDTCTL = WDTPW | WDTHOLD;   // Stop watchdog timer
   init();
   for(;;){
   }
}


#pragma vector=PORT1_VECTOR //Port 1 Vector interrupt occurs when Pin 1.1 (Button) goes from high to low
__interrupt void Port_1(void)
{
P1OUT ^= 0X01; // Pin 1.0 (RED LED) is toggled on/off

P1IFG &= ~BIT1; //Flag clear on Pin 1.1 (Button)
}

void init(void) {
   P1DIR |= BIT0; //Sets Pin 1.0 (RED LED) to be an output
   P1OUT |= BIT1; //Sets Pin 1.1 (Button) to enable pull up resistor
   P1REN |= BIT1; //Enables Pull up/down resistor
   P1OUT &= ~(BIT0); //Sets Pin 1.0 (RED LED) to 0 initially
   P1IE |= BIT1; //Interrupt is enabled on Pin 1.1 (Button)
   P1IES |= BIT1; //Initially sets interrupt edge to go from high to low on PIN 1.1 (Button)
   __enable_interrupt();
   }
