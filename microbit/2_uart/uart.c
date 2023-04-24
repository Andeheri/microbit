
#include "uart.h"
#include "gpio.h"


void uart_init(){

    // UART
    GPIO0->PIN_CNF[6] = 1;  // UART_INT_RX
    GPIO0->PIN_CNF[8] = 0;  // UART_INT_TX

    GPIO1->PIN_CNF[8] = 0;
    GPIO0->PIN_CNF[29] = 1;

    UART->PSEL_TXD = 6; //0x6

    UART->PSEL_RXD = (1 << 5);  // Sets pin number to 8 for TXD, and sets port to 1, and that it's connected
    UART->PSEL_RXD |= 8;  //0x28

    UART->PSEL_CTS |= (1 << 31);  // Sets CTS to disconnected
    UART->PSEL_RTS |= (1 << 31);  // Sets RTS to disconnected

    UART->BAUDRATE = 0x00275000;  // Sets baudrate to 9600

    UART->ENABLE = 4;  // Enable UART

    UART->TASKS_STARTRX = 1;  // Start recieving (as default state)
}


void uart_send(char letter){
    UART->TASKS_STARTTX = 1;
    UART->TXD = letter;

    while (!(UART->EVENTS_TXDRDY));
    UART->EVENTS_TXDRDY = 0;
    UART->TASKS_STOPTX = 1;
}


char uart_read(){
    if (UART->EVENTS_RXDRDY){
        UART->EVENTS_RXDRDY = 0;  // Update that RXD is not ready
        char output = UART->RXD;
        return output;
    }
    else{
        return '\0';
    }
}
