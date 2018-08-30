# Stm32f4_Operation_On_Regs
Learning how to use Stm32 by directly accessing to registers instead of pre-built functions.

Stm32f4's pre-built libraries have crucial and useful functions i.e for enabling RCC clock for desired 
peripheral or getting the receiving value of SPI. Behind these functions read-modify-write operations
are done in register level. For better understanding of registers of Stm32f4 I have decided to dive 
into operation in reg level. I have not completed my aim and I will start from simplest example by 
blinking on-board LEDs of Stm32f4 and then I will advance by accumulating my technical knowledge to
harder examples.

At that point, '&', '|' and '^' are so important for setting, resetting and toggling bits. '<<' and 
'>>' are important as well for the bit level operation. 

I have not finished and tested my codes. After I finish it will be ready to use and during my learning
process, I will be sharing what I have learnt.

Thanks to Tilen Majerle for his priceless libraries for beginners. I found inspiration from his examples.
For more things, you can reach out the website:
                http://majerle.eu/
               
For mistakes, improvements about my codes, feel free to reach me by:
                arslanhalil33@gmail.com
