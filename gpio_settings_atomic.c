





#include "gpio_settings_atomic.h"
/* By creating that struct the aim is to display bit definition of 
 * bits for GPIOs in RCC_AHB1ENR register that used for enabling or disabling
 * RCC clock for related GPIO or other peripherals.
 */
typedef struct {
	uint32_t ENABLE_RCC_AHB1_GPIOA = ((uint32_t) 0x00000001);
	uint32_t ENABLE_RCC_AHB1_GPIOB = ((uint32_t) 0x00000002);
	uint32_t ENABLE_RCC_AHB1_GPIOC = ((uint32_t) 0x00000004);
	uint32_t ENABLE_RCC_AHB1_GPIOD = ((uint32_t) 0x00000008);
	uint32_t ENABLE_RCC_AHB1_GPIOE = ((uint32_t) 0x00000010);
	uint32_t ENABLE_RCC_AHB1_GPIOF = ((uint32_t) 0x00000020);
	uint32_t ENABLE_RCC_AHB1_GPIOG = ((uint32_t) 0x00000040);
	uint32_t ENABLE_RCC_AHB1_GPIOH = ((uint32_t) 0x00000080);
	uint32_t ENABLE_RCC_AHB1_GPIOI = ((uint32_t) 0x00000100);
}RCC_AHB1_GPIO_LINES;



/* Below function will enable the GPIOx where x could be A, ..., I,
 * or '|' operatin allows us to set the desired bit according to our
 * value. 
 * input parameter(s)
 * @param uint32_t ENABLE_RCC_AHB1_GPIOx -> that is the value of
 * bits for related GPIO port in RCC_AHB1_GPIO_LINES struct
 * @return none
 */
void gpio_rcc_enable(uint32_t ENABLE_RCC_AHB1_GPIOx){

	RCC_AHB1_GPIO_LINES *config_rcc;

	RCC->AHB1ENR  |= config_rcc->ENABLE_RCC_AHB1_GPIOx;

}
/* MODER reg defines the pin whether it is input, output, analog or 
 * alternate function. 
 * Here the aim is to set desired pin as input.
 * input parameters
 * @param uint32_t GPIO_MODER_PAIR_INDEX0, and GPIO_MODER_PAIR_INDEX1
 * @return none
 */
void gpio_set_as_input(uint32_t GPIO_MODER_PAIR_INDEX0, uint32_t GPIO_MODER_PAIR_INDEX1){

	GPIO_TypeDef *gpio_input;

	gpio_input->MODER &= ~(GPIO_MODER_PAIR_INDEX0 | GPIO_MODER_PAIR_INDEX1);

}
/* This one is the setting pin as output. MODER register is again the focus here
 * input parameters
 * @param uint32_t GPIO_MODER_PAIR_INDEX0 and GPIO_MODER_PAIR_INDEX1
 * @return none
 */
void gpio_set_as_output(uint32_t GPIO_MODER_PAIR_INDEX0, uuint32_t GPIO_MODER_PAIR_INDEX1){

	GPIO_TypeDef *gpio_output;

	gpio_output->MODER |= (GPIO_MODER_PAIR_INDEX0 | (~(GPIO_MODER_PAIR_INDEX1)));
}













