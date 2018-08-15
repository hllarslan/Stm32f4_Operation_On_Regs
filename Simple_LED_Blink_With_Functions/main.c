

#include "gpio_settings_atomic.h"


int main(void)
{
	gpio_rcc_enable(RCC_AHB1ENR_GPIODEN);

	gpio_set_as_output(GPIOD, GPIO_PinSource12);

	gpio_set_output_speed_high(GPIOD, GPIO_PinSource12);

	gpio_set_output_type_PP(GPIOD, GPIO_OTYPER_OT_12 );

	gpio_set_no_pp(GPIOD, GPIO_PinSource12);

    while(1)
    {
    	gpio_set(GPIOD, GPIO_12_SET);
    }
}
