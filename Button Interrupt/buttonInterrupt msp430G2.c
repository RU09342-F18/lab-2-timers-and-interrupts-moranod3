#include <msp430.h>

void init(void);
int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  init();
}

// Port 1 interrupt service routine
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)

{
  P1OUT ^= BIT0;                            // P1.0 = toggle
  P1IFG &= ~BIT3;                           // P1.3 IFG cleared
  __delay_cycles (250000);                  // delay to prevent button bounce
}
void init(void){
    P1DIR |= BIT0;                            // Set P1.0 to output direction
     P1IE |=  BIT3;                            // P1.3 interrupt enabled
     P1IES |= BIT3;                            // P1.3 Hi/lo edge
     P1REN |= BIT3;                            // Enable Pull Up on SW2 (P1.3)
     P1IFG &= ~BIT3;                           // P1.3 IFG cleared
                                               //BIT3 on Port 1 can be used as Switch2

     __bis_SR_register(LPM4_bits + GIE); 
}
