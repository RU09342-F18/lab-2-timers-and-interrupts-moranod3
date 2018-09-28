# How to Use the Code

To use the code simply program it onto the correct microcontroller and then power the microcontoller.

# MSP430G2

The timerBlink interrupt code is pretty simple once you get past the configuration portion of the code. The code starts like any other with configuring the GPIO and the interupts. This code configures to utilize the A_Timer. The code works by enabling the CCR0 register this register is used to determine when the output LED blinks. Essentially every so many clock cycles an interrupt is triggered, this causes the LED to blink. There is another interupt linked to a button press, when this interrupt is triggered the CCR0 register is subtracted by some ammount. This subtraction makes it so the timer reaches CCR0 faster and therefore blinks the LED faster. So in essence there is a constant timer that resets when it reaches the value in CCR0. When it resets it triggers an interupt that blinks an LED. The there is an interupt linked to a button that makes the CCRO contents smaller and therefore cause the LED to blink faster. 

# MSP430FR2331

This code is almost identical as the msp430G2 except obviously the ports configured are diffrent since the board has different connections. The biggest difference is that instead if A_Timer I was forced to use the B_Timer since this board doesn't have an A_Timer.
