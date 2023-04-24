
#include "uart.h"
#include "gpio.h"
#include <stdio.h>

ssize_t _write(int fd, const void *buf, size_t count){
    char * letter = (char *)(buf);
    for(int i = 0; i < count; i++){
        uart_send(*letter);
        letter++;
    }
    return count;
}

int main(){
    uart_init();
    gpio_init();
    
    int toggle = 0;
    int sleep = 0;
    gpio_lights_off();
    while (1){
        // Oppgave 2.3
        // gpio_lights_off();
        // if (!(GPIO0->IN & (1 << 14))){
        //     gpio_lights_on();
        //     uart_send('a');
        //     printf("Button A pressed");
        // }
        // else if (!(GPIO0->IN & (1 << 23))){
        //     gpio_lights_on();
        //     uart_send('b');
        // }

        // Oppgave 2.4
        if (uart_read() != '\0'){
            toggle = !(toggle);
            switch (toggle)
            {
            case 0:
                gpio_lights_off();
                break;
            case 1:
                gpio_lights_on();
            }
        }

        // Oppgave 2.5
        // iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235,2019,2018,'C');
        sleep = 100000;  
        while (--sleep);
    }
    return 0;
}