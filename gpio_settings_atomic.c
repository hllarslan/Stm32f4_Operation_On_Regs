





#include "gpio_settings_atomic.h"

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




void gpio_rcc_enable(uint32_t ENABLE_RCC_AHB1_GPIOx){

	RCC_AHB1_GPIO_LINES *config_rcc;

	RCC->AHB1ENR  |= config_rcc->ENABLE_RCC_AHB1_GPIOx;

}

void gpio_set_as_input(uint32_t GPIO_MODER_PAIR_INDEX0, uint32_t GPIO_MODER_PAIR_INDEX1){

	GPIO_TypeDef *gpio_input;

	gpio_input->MODER &= ~(GPIO_MODER_PAIR_INDEX0 | GPIO_MODER_PAIR_INDEX1);

}

void gpio_set_as_output(uint32_t GPIO_MODER_PAIR_INDEX0, uuint32_t GPIO_MODER_PAIR_INDEX1){

	GPIO_TypeDef *gpio_output;

	gpio_output->MODER |= (GPIO_MODER_PAIR_INDEX0 | (~(GPIO_MODER_PAIR_INDEX1)));
}













