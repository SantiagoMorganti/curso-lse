#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "fsl_debug_console.h"

// Etiqueta para el LED rojo
#define LED_RED	2
#define USER 4
/*
 * @brief   Application entry point.
*/
int main(void) {
	// Inicializacion
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();

    // Estructura de configuracion para salida
    gpio_pin_config_t config_led = { kGPIO_DigitalOutput, 1 };
    // Habilito el clock del GPIO 1
    GPIO_PortInit(GPIO, 1);
    // Configuro el pin 2 del GPIO 1 como salida
    GPIO_PinInit(GPIO, 1, LED_RED, &config_led);

    gpio_pin_config_t config_button = { kGPIO_DigitalInput, 0};

    GPIO_PortInit(GPIO, 0);

    GPIO_PinInit(GPIO, 0, USER, &config_button);

    while(1) {
    	if (GPIO_PinRead(GPIO, 0, USER) == 1){
    		for(uint32_t i = 0; i < 20000; i++);
    		if (GPIO_PinRead(GPIO, 0, USER) == 1){
    			GPIO_PinWrite(GPIO, 1, LED_RED, 1);
    		}
    		else{
    			GPIO_PinWrite(GPIO, 1, LED_RED, 0);
    		}
    	}
    	for(uint32_t i = 0; i < 1000; i++);

    }
    return 0;
}
