#include "stm32f4xx.h"                  // Device header
#include "stm32f4xx_gpio.h"             // Keil::Device:StdPeriph Drivers:GPIO
#include "stm32f4xx_rcc.h"              // Keil::Device:StdPeriph Drivers:RCC

/* Definition for each led
 */
#define led_a  (GPIO_Pin_12)
#define led_b  (GPIO_Pin_11)
#define led_c  (GPIO_Pin_8)
#define led_d  (GPIO_Pin_9)
#define led_e  (GPIO_Pin_10)
#define led_f  (GPIO_Pin_13)
#define led_g  (GPIO_Pin_14)

/* Definition of all led sequences for digits
 */
#define All_Leds   (led_a | \
										led_b | \
										led_c | \
										led_d | \
										led_e | \
										led_f | \
										led_g )

#define Zero  ((All_Leds) & ~(led_g))
#define One   ( led_b | led_c)
#define Two   ((All_Leds) & ~ (led_c | led_f))
#define Three ((All_Leds) & ~ (led_e | led_f))
#define Four  ( led_b | led_g | led_f | led_c )
#define Five  ((All_Leds) & ~ (led_b | led_e))
#define Six   ((All_Leds) & ~(led_b))
#define Seven ( led_a | led_b | led_c)
#define Eight ( All_Leds)
#define Nine  ((Four) | led_d | led_a)


/*@brief Gpio configuration for Port E, Pins of 
 *8-14
 *@param uint16_t led_state to check which led pin
 *is desired
 *@retval none
 */
void Configuration_GPIOE(uint16_t led_state){
	RCC->AHB1ENR |= ( 1 << 4 );
	for(int i=0; i<0x10; i++){
		if( led_state & ( 1 << i)){
			GPIOE->MODER    |= ( 1 << ( i * 2));
			GPIOE->OSPEEDR  |= ( 1 << ( i * 2));
		}
	}

}

/*@brief Blinking Led according to a led_state
 *led_state is a parameter of led a-g
 *@param uint16_t led_state
 *@retval none
 */
void Blink_Led(uint16_t led_state){
	for(int i=0; i<0x10; i++){
		if( led_state & ( 1 << i)){
			GPIOE->BSRRL |= ( 1 << i);
		}
	}
}

int main(){
	

	Configuration_GPIOE(All_Leds);
	Blink_Led(Nine);
	
	while(1);
}
