/** adc.h 
 *  Author: Halil Arslan
 *  Contact: arslanhalil33@gmail.com
 */

#ifndef ADC_H
#define ADC_H


#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC
#include "stm32f4xx_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f4xx_adc.h"              // Keil::Device:StdPeriph Drivers:ADC
#include <stddef.h>
#include "tm_stm32f4_adc.h"


#define NUMBER_OF_PINS      			   ((uint8_t) 16)					    /*!< Number of GPIO pins */
#define GPIOx_MODER_SHIFT   			   ((uint8_t)  2)					  	/*!< MODER register takes 2 bits sequence
																																	 therefore for shifting multiplying with
																																	 2 is necessary */
#define GPIOx_OSPEEDR_SHIFT  				 ((uint8_t)  2)							/*!< OSPEEDR register requires 2-bits sequence
																																	 to determine the output speed so for shifting
																												           multiplying pin position by 2 is must*/
#define GPIOx_PUPDR_SHIFT     			 ((uint8_t)  2)						  /*!< PUPDR register also requires 2-bits sequence
																												           when the related configuration is assigned to
																												           pin number n, it must be shifted n*2 times */
#define ADC1_BIT_MASK				         ((uint8_t)  8)						  /*!< Bit position 8 is dedicated for ADC1 in RCC->APB2ENR
																													         register for enabling or disabling clock purpose.*/
#define NUMBER_OF_EXT_ADC_CHANNELS   ((uint8_t) 16)						  /*!< Total number of external adc channels in STM32F407VG*/

#define ADC_RESOLUTION_BIT_POS       ((uint8_t) 24)						  /*!< The position of bit sequence dedicated for resolution 
																																	 determination in RCC->CR1 register*/
#define ADC_DATA_ALIGNMENT_BIT_POS   ((uint8_t) 11)						  /*!< The bit position for data alignment in ADCx->CR2 register*/

#define ADC_CONT_CONV_MODE_BIT_POS   ((uint8_t)  1)					    /*!< The bit position for contionous conversion mode selection*/

#define ADC_EXT_TRIG_BIT_POS         ((uint8_t) 28)						  /*!< The bit position to determine external trigger */

#define ADC_NUM_OF_CONV_BIT_POS      ((uint8_t) 20)							/*!< The bit position in SQR1 register*/

#define ADC_SCAN_MODE_BIT_POS				 ((uint8_t)  8)							/*!< The scan mode selection bit position in CR1*/

#define ADC_DMA_ACCESS_BIT_POS       ((uint8_t)  8)              /*!< The bit position for DMA access mode selection*/

#define ADC_COMMON_MODE_BIT_POS      ((uint8_t)  0)							/*!< The bit position for mode selection in CCR1 register*/

#define ADC_PRESCALER_BIT_POS				 ((uint8_t) 16)							/*!< The bit position of ADC prescaler selection*/

#define ADC_SAMPLING_DLY_BIT_POS		 ((uint8_t)  8)							/*!< The bit position for delay between two sampling phases*/

#define ADC_ON_OFF_BIT_POS					 ((uint8_t)  0)							/*!< The bit position for enabling or disabling ADC */

#define ADC_CONVERSION_START_BIT_POS ((uint8_t) 30)							/*!< The bit position for starting conversion*/

#define ADC_END_OF_CONVERSION        ((uint8_t)  1)							/*!< The bit position for end of conversion*/

//ADC Channels
typedef enum {

	Channel_0,                              
	Channel_1,                               
	Channel_2,
	Channel_3,
	Channel_4,
	Channel_5,
	Channel_6,
	Channel_7,
	Channel_8,
	Channel_9,
	Channel_10,
	Channel_11,
	Channel_12,
	Channel_13,
	Channel_14,
	Channel_15,
}adc_ext_channel_t;

//RCC bit position for ADCs
typedef enum{
	ADC1_RCC_BIT_POS = 8,
	ADC2_RCC_BIT_POS,
	ADC3_RCC_BIT_POS
}adc_rcc_bit_pos_t;

//ADC resolution bit sequence
typedef enum{
	ADC_12_BIT_RESOLUTION = 0x00,
	ADC_10_BIT_RESOLUTION,
	ADC_8_BIT_RESOLUTION,
	ADC_6_BIT_RESOLUTION

}adc_resolution_t;

//Trigger detection bit sequence
typedef enum{

	TRIG_DETECT_DISABLED = 0x00,
	TRIG_DETECT_RISING_EDGE,
	TRIG_DETECT_FALLING_EDGE,
	TRIG_DETECT_RISING_FALLING_EDGE
}adc_ext_trig_t;

//Prescaler bit sequence
typedef enum{
	ADC_PRESCALER_DIV2 = 0x00,
	ADC_PRESCALER_DIV4,
	ADC_PRESCALER_DIV6,
	ADC_PRESCALER_DIV8
}adc_prescaler_t;


uint8_t get_pin_pos(uint16_t GPIO_Pin);
uint16_t gpio_get_port_source(GPIO_TypeDef* GPIOx);



void gpio_adc_init(GPIO_TypeDef* GPIOx,          uint16_t GPIO_Pin, 
	                 GPIOMode_TypeDef GPIO_Mode,   GPIOOType_TypeDef GPIO_OType,
                   GPIOSpeed_TypeDef GPIO_Speed, GPIOPuPd_TypeDef  GPIO_PuPd
	                );

void gpio_adc_init_default(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void adc_init_generic(ADC_TypeDef* ADCx, uint8_t Channel_x);
uint32_t adc_get_conversion(ADC_TypeDef* ADCx, uint8_t channel);

#endif

