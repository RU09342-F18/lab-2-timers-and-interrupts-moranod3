# How to Use the Code

To use the code simply program it onto the correct microcontroller and then power the microcontoller.

# MSP430G2

This code is very simple. It is also very similiar to the buttonBlink code, that utilized the polling method of generating an event, that I created in lab1. The only real difference is that I removed the inifinite loop that checked if the button was pressed each iteration of the the loop and replaced it with code that generated an interrupt when the button is pressed. To do this I added another configuration line of code. This line cleared the Port1.3 interupt flag. and looks like:

      P1IFG &= ~BIT3;    
      
I also added a line to put the processor to enable interrupts and put the processor to sleep, which looks like:

      __bis_SR_register(LPM4_bits + GIE);
      
Finally I added another method that is typed as an interrupt and has the Port 1 interupt service routine. Inside this method I simply flip the LED output bit and re-clear the P1IFG bit which is the interupt flag. I also decided to add a delay on this method to prevent button bounce. Other than these few changes the code is the same as the buttonBlink code in my lab 1 repository.
      
 
  # MSP430F5529LP
  
The bulk of this code is the same as the MSP430G2 except instead of clearing the interupt flag, I had to enable it and set the direction of the interupt edge this was done through the following lines:
  
      P1IE |= BIT1; //Interrupt is enabled on Pin 1.1 (Button)
      P1IES |= BIT1; //Initially sets interrupt edge to go from high to low on PIN 1.1 (Button)
      
The only other difference between these to codes is the pins that are set for the LED output and button input since these differ between boards.
