#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define uartid uart0
#define baudrate 115200

#define uart_rx_pin 1
#define uart_tx_pin 0
#define START 0xA5

//typedef struct {
  //uint8_t start_byte;
  //uint8_t address1;
  //uint8_t address2;
  //uint8_t address3;
  //uint8_t* adress;
  //uint8_t end;
//}msg;



//int msg_init(uint8_t len, msg* message) {
   
  //message->start_byte = START;
  //message->
  //message->adress = (uint8_t*)calloc(len-4, sizeof(uint8_t)); 
//}
//

void init()
{
  uart_init(uartid,baudrate);

  gpio_set_function(uart_rx_pin, GPIO_FUNC_UART);
  gpio_set_function(uart_tx_pin, GPIO_FUNC_UART);
}

int main()
{
  init();
  uint8_t data[8] = {0x5a,0xa5,0x05,0x82,0x10,0x00,0xb1,0x00};

  uart_write_blocking(uartid, data, sizeof(data));
}
