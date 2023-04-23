
#include "gpiote.h"
#include "ppi.h"
#include "gpio.h"

int main(){

    // Jordingspins
    GPIO0->PIN_CNF[28] = 1; //Col 1
	GPIO0->PIN_CNF[11] = 1; //Col 2
	GPIO0->PIN_CNF[31] = 1; //Col 3
	GPIO1->PIN_CNF[5]  = 1; //Col 4
	GPIO0->PIN_CNF[30] = 1; //Col 5

    // og settes til logisk lav
    GPIO0->OUTCLR = (1<<28);
    GPIO0->OUTCLR = (1<<11);
    GPIO0->OUTCLR = (1<<31);
    GPIO1->OUTCLR = (1<<5);
    GPIO0->OUTCLR = (1<<30);
    init_gpiote();
    init_ppi();
    while (1);
    return 0;
}