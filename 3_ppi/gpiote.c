#include "gpiote.h"

void init_gpiote(){
    GPIOTE->CONFIG[0] = (1)/*Event*/ | (BUTTON_PIN << 8) | (2 << 16)/*HiToLo*/;
    // De fem resterende kanalene skal alle være konfigurert som oppgaver, og koblet til hver sin forsyningspinne for LED-matrisen. Forsyningsspenningen skal veksle hver gang oppgaven aktiveres. Hvilken initialverdi disse GPIOTE- kanalene har er opp til dere.
    GPIOTE->CONFIG[1] = (3)/*Task*/ | (LED0_PIN << 8) | (3 << 16)/*Toggle*/;
    GPIOTE->CONFIG[2] = (3)/*Task*/ | (LED1_PIN << 8) | (3 << 16)/*Toggle*/;
    GPIOTE->CONFIG[3] = (3)/*Task*/ | (LED2_PIN << 8) | (3 << 16)/*Toggle*/;
    GPIOTE->CONFIG[4] = (3)/*Task*/ | (LED3_PIN << 8) | (3 << 16)/*Toggle*/;
    GPIOTE->CONFIG[5] = (3)/*Task*/ | (LED4_PIN << 8) | (3 << 16)/*Toggle*/;
}