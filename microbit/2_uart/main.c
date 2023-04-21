
#include "uart.h"
#include "gpio.h"
#include <stdio.h>

int main(){
    uart_init();
    gpio_init();
    

    int sleep = 0;
    while (1){
        gpio_lights_off();
        if (!(GPIO0->IN & (1 << 14))){
            gpio_lights_on();
            uart_send('a');
            printf("Button A pressed");
        }
        else if (!(GPIO0->IN & (1 << 23))){
            gpio_lights_on();
            uart_send('b');
        }
        sleep = 10000;  
        while (--sleep);
    }
    return 0;
}