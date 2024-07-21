#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define uartid uart0
#define baudrate 9600

#define uart_rx_pin 17
#define uart_tx_pin 16

void init()
{
  uart_init(uartid,baudrate);

  gpio_set_function(uart_rx_pin, GPIO_FUNC_UART);
  gpio_set_function(uart_tx_pin, GPIO_FUNC_UART);
}

int main()
{
  init();
}
