/* Utility code */

#include "util.h"
#include "usart.h"

// Flash a value in "binary morse"
void morse(uint32_t value, uint32_t bits) {
  for (int i = 0; i < bits; i++) {
    LED_OFF();
    if (((value << i) & (1 << (bits - 1)))) {
      LED_ON();
      HAL_Delay(400);
      LED_OFF();
      HAL_Delay(100);
    } else {
      LED_ON();
      HAL_Delay(100);
      LED_OFF();
      HAL_Delay(400);
    }
  }
  LED_OFF();
}

size_t strlen(const char * src) {
  char * c = (char *)src;
  for (; *c; c++) {}
  return (size_t)(c - src);
}

int puts(const char * src) {
  return HAL_UART_Transmit(&huart1, (uint8_t *)src, strlen(src), 10000);
}
