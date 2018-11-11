#ifndef __UTIL_H__
#define __UTIL_H__ 1

#include <stm32f1xx_hal.h>
#include "main.h"

#define LED_ON()  HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET)
#define LED_OFF() HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET)

// "Binary morse" signalling of a value
void morse(uint32_t value, uint32_t bits);

#define morse8(x)  morse(x, 8)
#define morse16(x) morse(x, 16)
#define morse32(x) morse(x, 32)

int puts (const char * src);
size_t strlen(const char * src);

#endif
