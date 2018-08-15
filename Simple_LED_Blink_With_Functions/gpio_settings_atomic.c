





#include "gpio_settings_atomic.h"






void gpio_rcc_enable(uint32_t RCC_AHB1ENR_GPIOxEN){

	RCC->AHB1ENR  |= RCC_AHB1ENR_GPIOxEN;

}

/* @brief GPIO mode selection
 * According to a reference manual Rm0090 the bit values for
 * modes are as below:
 * 			Input     : 00
 * 			Output    : 01
 * 			Alternate : 10
 * 			Analog    : 11
 * MODER register has pair for each pin number if the desired
 * pin number is x then the pair is like
 *  		[ 2x+1, 2x]
 * in MODER register. The register is 32bits word length.
 * For reaching to the first index of pair the GPIO_Pin value
 * is shifted 1 bit to left for multiplying purpose.
 * @param GPIOx where x could be A-I and GPIO_PinSourcex that
 * should be value within the range of 0-15
 * @retval none
 */


void gpio_set_as_input(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex){

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSourcex));
	GPIOx->MODER = GPIOx->MODER & ~(0x03 << (GPIO_PinSourcex << 1)  );
}

void gpio_set_as_output(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex){

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSourcex));
	GPIOx->MODER = (GPIOx->MODER & ~(0x03 <<  (GPIO_PinSourcex <<  1))) | (0x01 << (GPIO_PinSourcex << 1));
}

void gpio_set_as_alternate(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex){

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSourcex));
	GPIOx->MODER = (GPIOx->MODER & ~(0x03 << (GPIO_PinSourcex << 1))) | (0x02 << (GPIO_PinSourcex << 1));
}

void gpio_set_as_analog(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex ){

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSourcex));
	GPIOx->MODER = (GPIOx->MODER  | (0x03 << (GPIO_PinSourcex << 1)));
}

/* @brief GPIO output type selection
 * There are two options one is Push-Pull and other one is Open Drain
 * The GPIO_OTYPER_OT_x values are defined at the line 4308 of stm32f4xx.h
 * library. Here, for example for the pin number 1 GPIO_OTYPER_OT_1 will
 * be expected to be taken as parameter
 * @param GPIOx where x should be A-I and GPIO_OTYPER_OT_X where X should be
 * 0-15 for the desired pin.
 * @retval none
 */
void gpio_set_output_type_PP(GPIO_TypeDef *GPIOx, uint32_t GPIO_OTYPER_OT_X){

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	GPIOx->OTYPER &= ~(GPIO_OTYPER_OT_X);
}

void gpio_set_output_type_OD(GPIO_TypeDef *GPIOx, uint32_t GPIO_OTYPER_OT_X){

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	GPIOx->OTYPER &= (GPIO_OTYPER_OT_X);
}

/* The speed selection for specified pin number
 * According to a user manual RM0090 the speed could be configured in 4 types
 * as below:
 * 			Low Speed       : 00
 * 			Medium Speed    : 01
 * 			High Speed      : 10
 * 			Very High Speed : 11
 * @param GPIOx where x should be A-I and GPIO_PinSourcex where x should be
 * in the range 0-15.
 * @retval none
 */
void gpio_set_output_speed_low(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex){

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSourcex));
	GPIOx->OSPEEDR = GPIOx->OSPEEDR & ~(0x03 << (GPIO_PinSourcex << 1));
}

void gpio_set_output_speed_medium(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex){

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSourcex));
	GPIOx->OSPEEDR = (GPIOx->OSPEEDR & ~(0x03 <<(GPIO_PinSourcex << 1))) | (0x01 << (GPIO_PinSourcex << 1));
}

void gpio_set_output_speed_high(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex){

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSourcex));
	GPIOx->OSPEEDR = (GPIOx->OSPEEDR & ~(0x03 << (GPIO_PinSourcex << 1))) |(0x02 <<(GPIO_PinSourcex <<1 ));
}

void gpio_set_output_speed_very_high(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex){

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSourcex));
	GPIOx->OSPEEDR = (GPIOx->OSPEEDR | (0x03 << (GPIO_PinSourcex << 1)));
}


/* @brief the push-pull or no push-pull configuration by PUPDR
 * register.
 * @param GPIOx is port where x should be within the range of A-I
 * GPIO_PinSourcex can be found at the line of 187 of stm32f4xx_gpio.h
 * @retval none
 */


void gpio_set_no_pp(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex){
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSourcex));
	GPIOx->PUPDR = (GPIOx->PUPDR & ~(0x03 <<(GPIO_PinSourcex << 1)));

}

void gpio_set_p_up(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex){
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSourcex));
	GPIOx->PUPDR = (GPIOx->PUPDR & ~(0x03 <<(GPIO_PinSourcex <<1))) | (0x01 << (GPIO_PinSourcex << 1));
}

void gpio_set_p_down(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex){
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GPIO_PIN_SOURCE(GPIO_PinSourcex));
	GPIOx->PUPDR = (GPIOx->PUPDR & ~(0x03 <<(GPIO_PinSourcex <<1))) | (0x02 <<(GPIO_PinSourcex <<1 ));
}

/* @brief Setting or resetting desired port's desired pin.
 * @param GPIOx is port value where x should be in the range of
 * A-I and GPIO_X_SET and GPIO_X_RESET are another definition of
 * GPIO_BSRR_BS_x and GPIO_BSRR_BR_x respectively and could be
 * found in gpio_settings_atomic.h lib.
 * @retval none
 */
void gpio_set (GPIO_TypeDef *GPIOx, uint16_t GPIO_X_SET){
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

	GPIOx->ODR = GPIO_X_SET;
}

void gpio_reset(GPIO_TypeDef *GPIOx, uint16_t GPIO_X_RESET){
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));

	GPIOx->ODR = GPIO_X_RESET;
}


