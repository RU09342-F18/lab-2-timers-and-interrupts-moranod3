# How to Use the Code

To use the code simply program it onto the correct microcontroller and then power the microcontoller.

# MSP430G2

This code was by far the most complex of all the codes I created in this lab. The code works by first configuring the correct ports like all microcontroller programs. Again I simply enable the interupts and this time I set a timer clockand enable the CCR0 register. In this case I used the SMCLK. I chose this clock since it made the timing easier and used the following lines to configure it: 
 
      TACTL = TASSEL_1 + MC_1+ID_3;          // SMCLK selected, Continous enabled Divider = 4
     
The most important portion of the code is button interrupt method this is because it was the most tricky to code. Initially, I was trying to do everything in one interrupt. Later I realized the best thing to do was have the first interrupt be when the button is pressed by having the interupt go from low to high. Then in that interrupt it starts a timer and and flips the interupt to go from high to low now instead. This makes it so when the button is released the interrupt is re-triggered. When the button is let go it ends the timer and puts the timer value into the CCR0 register which is used to determine the button blink frequency. It then flips the interrupt to be low to high again. It is important to note that each time the interupt is triggered on a button press or letting go of the button the interupt flag is reset. 

# MSP430F5529LP

This code is almost identical other than a few changes in syntax and port positions. For example CCR0 isn't recognized by the MSP430F5529 so instead you have to tell it the timer used and put TACCR0 instead. Other than these changes everything is the same.
