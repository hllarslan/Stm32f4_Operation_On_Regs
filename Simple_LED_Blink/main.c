



#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"


/* @brief Simple on-board LED (D15) blinking in Stm32F407
 * First the system is initialized by SystemInit().
 * Then related clock is enabled for GPIOD.
 * For configuration it as output we should set MODER reg's
 * 30. and 31. bits as 01.
 * No push-pull is chosen by setting OTYPER as 00.
 * Maximum speed is selected by setting OSPEEDR as 11.
 * No pull up, pull down are selected in PUPDR reg with
 * 00 sequence.
 */
int main(void)
{
	SystemInit();


	RCC->AHB1ENR   = RCC->AHB1ENR | RCC_AHB1ENR_GPIODEN;

	GPIOD->MODER   = (GPIOD->MODER | (GPIO_MODER_MODER15_0));

	GPIOD->OTYPER  = (GPIOD->OTYPER & ~(GPIO_OTYPER_OT_15));

	GPIOD->OSPEEDR = (GPIOD->OSPEEDR | GPIO_OSPEEDER_OSPEEDR15  );

	GPIOD->PUPDR   = (GPIOD->PUPDR & ~(GPIO_PUPDR_PUPDR15));






	while(1){
		GPIOD->ODR = GPIO_BSRR_BS_15;


	}
}




