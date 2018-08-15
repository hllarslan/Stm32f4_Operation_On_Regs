


In this very simple example, the aim was to blink LED by accessing directly to the registers for configuration. 

    SystemInit();

With the help of this line of code, the microcontroller system is ready. Them Embedded Flash Interface, the PLL are initialized and the SystemFrequency variable is updated. You could find details in the source file of system_stm32f4xx.c file. 

At the beginning of every program, the most crucial thing is enabling peripheral clock used in program by RCC. Here, I used GPIOD since on-board LEDs are conencted to that port. GPIOs are connected to AHB1 bus in microcontroller. I enabled clock of GPIOD by line of code below:

    RCC->AHB1ENR   = RCC->AHB1ENR | RCC_AHB1ENR_GPIODEN;

RCC_AHB1ENR_GPIODEN is defined in stm32f4xx.h library at the line of 5009 as below:

    #define  RCC_AHB1ENR_GPIODEN   ((uint32_t) 0x00000008)    

The mode of pin is configured later on by that code:
        
    GPIOD->MODER   = (GPIOD->MODER | (GPIO_MODER_MODER15_0));

MODER is a register to define pin mode. There are 4 modes provided by STM as below:
						Input         : 00
						Output      : 01
						Alternate  : 10
						Analog      : 11
GPIO_MODER_MODER15_0 could be reached from stm32f4xx_h at the line of 4304:

    #define GPIO_MODER_MODER15_0   ((uint32_t)0x40000000)

The speed of pin is defined at maximum. 

    GPIOD->OSPEEDR = (GPIOD->OSPEEDR |GPIO_OSPEEDER_OSPEEDR15);

GPIO_OSPEEDER_OSPEEDR15 is again in stm32f4xx_h at the line of 4386. 

Then the no pull up - pull down are selected for this example. 

    GPIOD->PUPDR   = (GPIOD->PUPDR & ~(GPIO_PUPDR_PUPDR15));

GPIO_PUPDR_PUPDR15 could be viewed at the line of 4451 of stm32f4xx_h library again. 

In the while loop, we set GPIO pin 15 as below:

    GPIOD->ODR = GPIO_BSRR_BS_15;

GPIO_BSRR_BS_15 could be displayed again in the stm32f4xx_h library at the line 4541:

    #define GPIO_BSRR_BS_15    ((uint32_t)0x00008000)

Or " | " operation is important for setting high to desired pin without affecting other pins. And " & " operation is used for setting low to desired pin without changing the statement of other pins. 

For collaboration with me my contact addresses are those:
		e_mail     :  arslanhalil33@gmail.com
		LinkedIn :  https://www.linkedin.com/in/arslanhalil/

During my studies, I am inspired by other examples, Tilen Majerle is one of them and you are able to reach his examples via his website:
		http://majerle.eu/







  

 
