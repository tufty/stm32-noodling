/* Utility code */

#include "util.h"
#include "usart.h"

// Flash a value in "binary morse"
void morse(uint32_t value, uint32_t bits) {
  for (int i = 0; i < bits; i++) {
    LED_OFF();
    if (((value << i) & (1 << (bits - 1)))) {
      HAL_Delay(5);
      LED_ON();
      HAL_Delay(20);
    } else {
      HAL_Delay(20);
      LED_ON();
      HAL_Delay(5);
    }
  }
  LED_OFF();
}

size_t strlen(const char * src) {
  char * c = (char *)src;
  for (; c != 0; c++) {}
  return (size_t)(c - src);
}

int puts(const char * src) {
  return HAL_UART_Transmit(&huart1, (uint8_t *)src, strlen(src), 100);
}
