




#ifndef GPIO_SETTINGS_ATOMIC
#define GPIO_SETTINGS_ATOMIC








#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stdint.h"


#define GPIO_0_SET			GPIO_BSRR_BS_0
#define GPIO_1_SET 			GPIO_BSRR_BS_1
#define GPIO_2_SET  		GPIO_BSRR_BS_2
#define GPIO_3_SET  		GPIO_BSRR_BS_3
#define GPIO_4_SET  		GPIO_BSRR_BS_4
#define GPIO_5_SET 			GPIO_BSRR_BS_5
#define GPIO_6_SET 			GPIO_BSRR_BS_6
#define GPIO_7_SET  		GPIO_BSRR_BS_7
#define GPIO_8_SET  		GPIO_BSRR_BS_8
#define GPIO_9_SET  		GPIO_BSRR_BS_9
#define GPIO_10_SET 		GPIO_BSRR_BS_10
#define GPIO_11_SET 		GPIO_BSRR_BS_11
#define GPIO_12_SET 		GPIO_BSRR_BS_12
#define GPIO_13_SET 		GPIO_BSRR_BS_13
#define GPIO_14_SET 		GPIO_BSRR_BS_14
#define GPIO_15_SET 		GPIO_BSRR_BS_15
#define GPIO_0_RESET  		GPIO_BSRR_BR_0
#define GPIO_1_RESET  		GPIO_BSRR_BR_1
#define GPIO_2_RESET  		GPIO_BSRR_BR_2
#define GPIO_3_RESET  		GPIO_BSRR_BR_3
#define GPIO_4_RESET  		GPIO_BSRR_BR_4
#define GPIO_5_RESET  		GPIO_BSRR_BR_5
#define GPIO_6_RESET  		GPIO_BSRR_BR_6
#define GPIO_7_RESET  		GPIO_BSRR_BR_7
#define GPIO_8_RESET  		GPIO_BSRR_BR_8
#define GPIO_9_RESET  		GPIO_BSRR_BR_9
#define GPIO_10_RESET 		GPIO_BSRR_BR_10
#define GPIO_11_RESET 		GPIO_BSRR_BR_11
#define GPIO_12_RESET 		GPIO_BSRR_BR_12
#define GPIO_13_RESET 		GPIO_BSRR_BR_13
#define GPIO_14_RESET 		GPIO_BSRR_BR_14
#define GPIO_15_RESET 		GPIO_BSRR_BR_15






void gpio_rcc_enable(uint32_t RCC_AHB1ENR_GPIOxEN);
void gpio_set_as_input(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex);
void gpio_set_as_output(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex);
void gpio_set_as_alternate(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex);
void gpio_set_as_analog(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex );
void gpio_set_output_type_PP(GPIO_TypeDef *GPIOx, uint32_t GPIO_OTYPER_OT_X);
void gpio_set_output_type_OD(GPIO_TypeDef *GPIOx, uint32_t GPIO_OTYPER_OT_X);
void gpio_set_output_speed_low(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex);
void gpio_set_output_speed_medium(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex);
void gpio_set_output_speed_high(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex);
void gpio_set_output_speed_very_high(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex);
void gpio_set_no_pp(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex);
void gpio_set_p_up(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex);
void gpio_set_p_down(GPIO_TypeDef *GPIOx, uint16_t GPIO_PinSourcex);
void gpio_set (GPIO_TypeDef *GPIOx, uint16_t GPIO_X_SET);
void gpio_reset(GPIO_TypeDef *GPIOx, uint16_t GPIO_X_RESET);
#endif
