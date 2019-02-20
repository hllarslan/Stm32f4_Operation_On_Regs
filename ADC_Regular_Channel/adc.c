/** adc.c 
 *  Author: Halil Arslan
 *  Contact: arslanhalil33@gmail.com
 */



#include "adc.h"

typedef void (*adc_channel_init)(ADC_TypeDef* ADCx);

/** \brief		The external ADC channels on STM32F407 according to 
	*		datasheet(DM00037051) as follows:
	* 		ADC1		 ADC2		ADC3
	*   	CH0     PA0		 PA0		PA0
	*	CH1	PA1		 PA1		PA1
	*       CH2	PA2		 PA2	        PA2
	*	CH3	PA3		 PA3		PA3
	*	CH4	PA4	         PA4		PF6
	*	CH5	PA5		 PA5		PF7
	*	CH6     PA6	         PA6		PF8
	*	CH7	PA7		 PA7		PF9
	*	CH8	PB0		 PB0		PF10
	*	CH9     PB1	         PB1		PF3
	*	CH10    PC0		 PC0		PC0
	*	CH11    PC1		 PC1		PC1
	*	CH12    PC2		 PC2		PC2
	*	CH13    PC3		 PC3		PC3
	*	CH14	PC4		 PC4		PF4
	*	CH15    PC5		 PC5		PF5
	*/

void adc_channel_0_init(ADC_TypeDef* ADCx);
void adc_channel_1_init(ADC_TypeDef* ADCx);
void adc_channel_2_init(ADC_TypeDef* ADCx);
void adc_channel_3_init(ADC_TypeDef* ADCx);
void adc_channel_4_init(ADC_TypeDef* ADCx);
void adc_channel_5_init(ADC_TypeDef* ADCx);
void adc_channel_6_init(ADC_TypeDef* ADCx);
void adc_channel_7_init(ADC_TypeDef* ADCx);
void adc_channel_8_init(ADC_TypeDef* ADCx);
void adc_channel_9_init(ADC_TypeDef* ADCx);
void adc_channel_10_init(ADC_TypeDef* ADCx);
void adc_channel_11_init(ADC_TypeDef* ADCx);
void adc_channel_12_init(ADC_TypeDef* ADCx);
void adc_channel_13_init(ADC_TypeDef* ADCx);
void adc_channel_14_init(ADC_TypeDef* ADCx);
void adc_channel_15_init(ADC_TypeDef* ADCx);

static adc_channel_init channel_init_functions[NUMBER_OF_EXT_ADC_CHANNELS] = {
	&adc_channel_0_init , &adc_channel_1_init , &adc_channel_2_init ,  &adc_channel_3_init,
	&adc_channel_4_init , &adc_channel_5_init , &adc_channel_6_init ,  &adc_channel_7_init,
	&adc_channel_8_init , &adc_channel_9_init , &adc_channel_10_init,  &adc_channel_11_init,
	&adc_channel_12_init, &adc_channel_13_init, &adc_channel_14_init,  &adc_channel_15_init};

/**	
 *  \brief					Function to get given pin's position.
 *  \param[in]					uint16_t GPIO_Pin, in the range of 0-15
 *  \return					uint8_t pinpos which means pin position 
 */
uint8_t get_pin_pos(uint16_t GPIO_Pin){
	uint8_t pinpos;
	for(pinpos= 0; pinpos< NUMBER_OF_PINS; pinpos++){
		if((GPIO_Pin & (1 << pinpos)) == 0){
			continue;
		}else{
			return pinpos;
		}
	}
}

/** 
 *      \brief					Function to get portsource.
 *	\param[in]				GPIOx where x is in A-K
 *	\return 				uint16_t port source of in 0-10
 */
uint16_t gpio_get_port_source(GPIO_TypeDef* GPIOx) {
	
	return (((uint32_t)GPIOx - GPIOA_BASE) / (GPIOB_BASE - GPIOA_BASE));
	
}


/** 
* \brief					Function for initializing GPIO for ADC. It can be used
*						for other modes as well. The user must provide related
*						inputs.
* \param[in]					GPIOx where x is port name in A-K. GPIO_Pin in 0-15.
*						GPIO_Mode for ADC it is GPIO_Mode_AN. Speed, Push-Pull
*						and Output Type.
  */
void gpio_adc_init(GPIO_TypeDef* GPIOx,          uint16_t GPIO_Pin, 
	                 GPIOMode_TypeDef GPIO_Mode,   GPIOOType_TypeDef GPIO_OType,
                   GPIOSpeed_TypeDef GPIO_Speed, GPIOPuPd_TypeDef  GPIO_PuPd
	                ){
	
	
	uint8_t pinpos = get_pin_pos(GPIO_Pin);
										
	RCC->AHB1ENR  |= (1 << gpio_get_port_source(GPIOx));
	
	GPIOx->MODER   = ((GPIOx->MODER   & ~(0x03 << (pinpos *GPIOx_MODER_SHIFT)))   | 
	                  (GPIO_Mode  << (pinpos * GPIOx_MODER_SHIFT)));
	
	
	GPIOx->OTYPER  = ((GPIOx->OTYPER  & ~(1 << pinpos)) | 
									  (GPIO_OType << (pinpos)));
	
	GPIOx->OSPEEDR = ((GPIOx->OSPEEDR & ~(0x03 <<(pinpos * GPIOx_OSPEEDR_SHIFT))) |
										(GPIO_Speed << (pinpos * GPIOx_OSPEEDR_SHIFT)));
										
	GPIOx->PUPDR   = ((GPIOx->PUPDR   & ~(0x03 <<(pinpos * GPIOx_PUPDR_SHIFT)))   |
										(GPIO_PuPd  << (pinpos * GPIOx_PUPDR_SHIFT)));
}
									
/** 
 *  \brief					Deafult function for ADC channels since only port name and
 *						pin number vary. 
 *  \param[in]					GPIOx pointer to GPIO_TypeDef and uint16_t GPIO pin number
 */
void gpio_adc_init_default(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin){

	gpio_adc_init(GPIOx, GPIO_Pin, GPIO_Mode_AN, GPIO_OType_PP, GPIO_Speed_25MHz, GPIO_PuPd_DOWN);

}
/**
 *  \brief					Function to initialize ADC external channel 0 which resides
 *						on PA0 pin.
 *  \param[in]					ADCx which in type of the pointer to ADC_TypeDef 
 */
void adc_channel_0_init(ADC_TypeDef* ADCx){
	
	
	gpio_adc_init_default(GPIOA, GPIO_Pin_0);
	
}

/** 
 *  \brief 					Function to initialize ADC External channel 1 which resides
 *						on PA1 pin.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_1_init(ADC_TypeDef* ADCx){
	
	gpio_adc_init_default(GPIOA, GPIO_Pin_1);
	
}


/**
 *  \brief 					Function to initialize ADC External channel 2 which resides
 *						on PA2 pin.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_2_init(ADC_TypeDef* ADCx){
	
	gpio_adc_init_default(GPIOA, GPIO_Pin_2);
	
}


/**
 *  \brief 					Function to initialize ADC External channel 3 which resides
 *						on PA3 pin.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_3_init(ADC_TypeDef* ADCx){
	
	gpio_adc_init_default(GPIOA, GPIO_Pin_3);
	
}

/** 
 *  \brief 					Function to initialize ADC External channel 4 which resides
 *						on PA4 for ADC1 and ADC2 and PF6 for ADC3.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_4_init(ADC_TypeDef* ADCx){
	
	if (ADCx == ADC1 || ADCx == ADC2){
		gpio_adc_init_default(GPIOA, GPIO_Pin_4);
	}if(ADCx == ADC3){
		gpio_adc_init_default(GPIOF, GPIO_Pin_6);
	}

}
/**
 *  \brief 					Function to initialize ADC External channel 5 which resides
 *						on PA5 for ADC1 and ADC2 and PF7 for ADC3.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_5_init(ADC_TypeDef* ADCx){
	
	if (ADCx == ADC1 || ADCx == ADC2){
		gpio_adc_init_default(GPIOA, GPIO_Pin_5);
	}if(ADCx == ADC3){
		gpio_adc_init_default(GPIOF, GPIO_Pin_7);
	}

}


/** 
 *  \brief 					Function to initialize ADC External channel 6 which resides
 *						on PA6 for ADC1 and ADC2 and PF8 for ADC3.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_6_init(ADC_TypeDef* ADCx){
	
	if (ADCx == ADC1 || ADCx == ADC2){
		gpio_adc_init_default(GPIOA, GPIO_Pin_6);
	}if(ADCx == ADC3){
		gpio_adc_init_default(GPIOF, GPIO_Pin_8);
	}

}


/** 
 *  \brief 					Function to initialize ADC External channel 7 which resides
 *						on PA7 for ADC1 and ADC2 and PF9 for ADC3.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_7_init(ADC_TypeDef* ADCx){
	
	if (ADCx == ADC1 || ADCx == ADC2){
		gpio_adc_init_default(GPIOA, GPIO_Pin_7);
	}if(ADCx == ADC3){
		gpio_adc_init_default(GPIOF, GPIO_Pin_9);
	}

}


/** 
 *  \brief 					Function to initialize ADC External channel 8 which resides
 *						on PB0 for ADC1 and ADC2 and PF10 for ADC3.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_8_init(ADC_TypeDef* ADCx){
	
	if (ADCx == ADC1 || ADCx == ADC2){
		gpio_adc_init_default(GPIOB, GPIO_Pin_0);
	}if(ADCx == ADC3){
		gpio_adc_init_default(GPIOF, GPIO_Pin_10);
	}

}


/**
 *  \brief 					Function to initialize ADC External channel 9 which resides
 *						on PB1 for ADC1 and ADC2 and PF3 for ADC3.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_9_init(ADC_TypeDef* ADCx){
	
	if (ADCx == ADC1 || ADCx == ADC2){
		gpio_adc_init_default(GPIOB, GPIO_Pin_1);
	}if(ADCx == ADC3){
		gpio_adc_init_default(GPIOF, GPIO_Pin_3);
	}

}

/**
 *  \brief 					Function to initialize ADC External channel 10 which resides
 *						on PC0.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_10_init(ADC_TypeDef* ADCx){
	
	gpio_adc_init_default(GPIOC, GPIO_Pin_0);

}


/**
 *  \brief 					Function to initialize ADC External channel 11 which resides
 *						on PC1.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_11_init(ADC_TypeDef* ADCx){
	
	gpio_adc_init_default(GPIOC, GPIO_Pin_1);

}


/** 
 *  \brief 					Function to initialize ADC External channel 12 which resides
 *						on PC2.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_12_init(ADC_TypeDef* ADCx){
	
	gpio_adc_init_default(GPIOC, GPIO_Pin_2);

}


/**
 *  \brief 					Function to initialize ADC External channel 13 which resides
 *						on PC3.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_13_init(ADC_TypeDef* ADCx){
	
	gpio_adc_init_default(GPIOC, GPIO_Pin_3);

}

/**
 *  \brief 					Function to initialize ADC External channel 14 which resides
 *						on PC4 for ADC1 and ADC2 and PF4 for ADC3.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_14_init(ADC_TypeDef* ADCx){
	
	if (ADCx == ADC1 || ADCx == ADC2){
		gpio_adc_init_default(GPIOC, GPIO_Pin_4);
	}if(ADCx == ADC3){
		gpio_adc_init_default(GPIOF, GPIO_Pin_4);
	}

}

/**
 *  \brief 					Function to initialize ADC External channel 15 which resides
 *						on PC5 for ADC1 and ADC2 and PF5 for ADC3.
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 */
void adc_channel_15_init(ADC_TypeDef* ADCx){
	
	if (ADCx == ADC1 || ADCx == ADC2){
		gpio_adc_init_default(GPIOC, GPIO_Pin_5);
	}if(ADCx == ADC3){
		gpio_adc_init_default(GPIOF, GPIO_Pin_5);
	}

}


void adc_config(ADC_TypeDef* ADCx){
		ADC_Common_TypeDef* ADC_Common;
	
	
		//ADC_InitTypeDef
		/*Continous conversion disabled*/
		ADCx->CR2  &=  (0											<< ADC_CONT_CONV_MODE_BIT_POS);
		/*Data Alignment to the right*/
		ADCx->CR2  |=  (0                     << ADC_DATA_ALIGNMENT_BIT_POS);
		/*External trigger disabled*/
		ADCx->CR2  |=  (TRIG_DETECT_DISABLED  << ADC_EXT_TRIG_BIT_POS);
		/*Number of conversion = 1*/
		for(uint8_t i=0; i<4; i++){
			ADCx->SQR1 &= (0 << (ADC_NUM_OF_CONV_BIT_POS+i));
		}
		
		/*Scan mode disabled*/
		ADCx->CR1  &=  (0                     << ADC_SCAN_MODE_BIT_POS);
		
		if(ADCx == ADC1){
			RCC->APB2ENR |= (1 << ADC1_RCC_BIT_POS);
		}if(ADCx == ADC2){
			RCC->APB2ENR |= (1 << ADC2_RCC_BIT_POS);
		}if(ADCx == ADC3){
			RCC->APB2ENR |= (1 << ADC3_RCC_BIT_POS);
		}
		
		ADCx->CR1  |=  (ADC_12_BIT_RESOLUTION << ADC_RESOLUTION_BIT_POS);
		
		/* DMA access mode disabled*/
		ADCx->CR2  &=  (0                     << ADC_DMA_ACCESS_BIT_POS);
		
		/* Independent mode selected*/
		for(uint8_t i=0; i<5; i++){
			ADC_Common->CCR &= (0               << (ADC_COMMON_MODE_BIT_POS+i));
		}
		
		/* ADC prescaler is set to 1/4*/
		ADC_Common->CCR  |= (ADC_PRESCALER_DIV4 << ADC_PRESCALER_BIT_POS);
		
	  /* Delay between 2 sampling phases */
		ADC_Common->CCR  = (ADC_Common->CCR & ~(0x0F  << ADC_SAMPLING_DLY_BIT_POS)) 
										 | (0x03 << ADC_SAMPLING_DLY_BIT_POS);
		
		ADCx->CR2        |= (1                <<  ADC_ON_OFF_BIT_POS);
}

void adc_init_generic(ADC_TypeDef* ADCx, uint8_t Channel_x){
	
	(*channel_init_functions[Channel_x])(ADCx);

	//TM_ADC_InitADC(ADCx);
	adc_config(ADCx); 
}

/** 
 *  \brief 					Function to get conversion result 
 *  \param[in]					ADCx which is pointer to ADC_TypeDef
 *  \param[in]					ADC channel uint8_t 
 *  \return         				uint32_t converted value
 */
uint32_t adc_get_conversion(ADC_TypeDef* ADCx, uint8_t channel){
	
	
	ADC_RegularChannelConfig(ADCx, channel, 0, ADC_SampleTime_84Cycles);
	
	//Start conversion by setting SWSTART in ADC->CR2
	ADCx->CR2 |= 1 << ADC_CONVERSION_START_BIT_POS;
	
	//Control that the conversion is ended by hardware
	while(!(ADCx->SR & (1 << ADC_END_OF_CONVERSION))){
		
	}
	
	
	return ADCx->DR;
	
}
