#include <cstdio>
#include <cstring>
#include "pico/stdlib.h"
#include "hardware/vreg.h"
#include "hardware/clocks.h"
#include "psram.hpp"
#include "uart.hpp"

// WeAct studio RP2350B : 0
// PIMORONI_PICO_PLUS2 : PIMORONI_PICO_PLUS2_PSRAM_CS_PIN
#define PSRAM_CS_PIN	0
#define LED_PIN			PICO_DEFAULT_LED_PIN

static const uint EMM_SIZE = PSRAM_SIZE;	// 8MB
uint32_t* emmData = (uint32_t*)PSRAM_BASE;

__attribute__((noinline)) int __time_critical_func(main)(void)
{
	stdio_init_all();

	// init UART
	uartInit();
	uart_puts(UART_ID, "Start.\r\n");

	// Debug
	gpio_init(LED_PIN);
	gpio_set_dir(LED_PIN, GPIO_OUT);
	gpio_put(LED_PIN, true);

	// init PSRAM
	uint psramsize = psram_init(PSRAM_CS_PIN);

	memset(emmData, 0, EMM_SIZE);

	bool led = false;
	gpio_put(LED_PIN, led);

	for(uint32_t i = 0; i < EMM_SIZE / 4; ++ i)
	{
		emmData[i] = i;
	}
//	emmData[EMM_SIZE / 4 - 1] = 0;

	sleep_ms(1000);

	led = true;
	gpio_put(LED_PIN, led);
	bool same = true;
	for(uint32_t i = 0; i < EMM_SIZE / 4; ++ i)
	{
		if(emmData[i] != i)
		{
			same = false;
			break;
		}
	}

	for(int i = 0; i < 10; ++ i)
	{
		led = led ? false : true;
		gpio_put(LED_PIN, led);
		sleep_ms(100);
	}

	if(same == true)
	{
		gpio_put(LED_PIN, true);
	}
	else
	{
		gpio_put(LED_PIN, false);
	}

	while(true) {};
}
