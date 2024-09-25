#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "fsl_debug_console.h"
#include <stdio.h>

// Etiqueta para el LED rojo
int SEGMENT [6] = {10, 11, 6, 14, 0, 13};
#define USER 4
#define A 11
#define B 10
#define C 6
#define D 14
#define E 0
#define F 13
#define G 15
int j = 0 ;

/*
 * @brief   Application entry point.
*/
int main(void) {
	// Inicializacion
    BOARD_InitBootClocks();
    BOARD_InitDebdugConsole();

    // Estructura de configuracion para salida
    gpio_pin_config_t config_led = { kGPIO_DigitalOutput, 0 };
    // Habilito el clock del GPIO 0
    GPIO_PortInit(GPIO, 0);
    // Configurolos pines del display de 7 segmentos como salida
    GPIO_PinInit(GPIO, 0, A, &config_led);
    GPIO_PinInit(GPIO, 0, B, &config_led);
    GPIO_PinInit(GPIO, 0, C, &config_led);
    GPIO_PinInit(GPIO, 0, D, &config_led);
    GPIO_PinInit(GPIO, 0, E, &config_led);
    GPIO_PinInit(GPIO, 0, F, &config_led);
    GPIO_PinInit(GPIO, 0, G, &config_led);
    GPIO_PinInit(GPIO, 0, 8, &config_led);

    gpio_pin_config_t config_button = { kGPIO_DigitalInput, 0};

    GPIO_PinInit(GPIO, 0, USER, &config_button);

    while(1) {
    	GPIO_PinWrite(GPIO, 0, 9, 0);
    	GPIO_PinWrite(GPIO, 0, G, 1);
    	GPIO_PinWrite(GPIO, 0, SEGMENT[j], 0);
    	for(uint32_t i = 0; i < 100000; i++);
    	GPIO_PinWrite(GPIO, 0, SEGMENT[j], 1);
    	j++;
    	if(j == 6){
    		j = 0;
    	}

    }
    return 0;
}
