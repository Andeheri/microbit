#ifndef GPIOTE_H
#define GPIOTE_H
#include <stdint.h>
#pragma once

#define GPIOTE ((NRF_GPIOTE_REG*)0x40006000)

#define BUTTON_PORT 0
#define BUTTON_PIN 14

#define LED0_PORT 0
#define LED0_PIN 21
#define LED1_PORT 0
#define LED1_PIN 22
#define LED2_PORT 0
#define LED2_PIN 15
#define LED3_PORT 0
#define LED3_PIN 24
#define LED4_PORT 0
#define LED4_PIN 19

typedef struct {
	// Tasks
	volatile uint32_t TASKS_OUT[8];
	volatile uint32_t RESERVED0[4];
	volatile uint32_t TASKS_SET[8];
	volatile uint32_t RESERVED1[4];
	volatile uint32_t TASKS_CLR[8];
	// Events
	volatile uint32_t RESERVED2[32];
	volatile uint32_t EVENTS_IN[8];
	volatile uint32_t RESERVED3[23];
	volatile uint32_t EVENTS_PORT;
	// Registers
	volatile uint32_t RESERVED4[97];
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile uint32_t RESERVED5[129];
	volatile uint32_t CONFIG[8];
} NRF_GPIOTE_REG;


void init_gpiote();

#endif
