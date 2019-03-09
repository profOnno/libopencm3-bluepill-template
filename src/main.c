#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/usart.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/systick.h>
#include <libopencm3/cm3/nvic.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "main.h"

static void clock_setup(void)
{
  rcc_clock_setup_in_hse_8mhz_out_72mhz();

  // enable clock for led
  rcc_periph_clock_enable(RCC_GPIOC);
  
  // for serial
  rcc_periph_clock_enable(RCC_GPIOB);
  rcc_periph_clock_enable(RCC_USART3);

  
  // use systick
  // set reload to N-1
  // Period: N/(72 MHz/8)

  systick_set_reload(899999); // 100 ms;
  systick_interrupt_enable();
  systick_counter_enable();
}

static void gpio_setup(void)
{
  // setup led 
  gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ,
    GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

  // setup usart3
  gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
    GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO_USART3_TX);
}

void sys_tick_handler(void)
{
  static uint8_t cnt=0;
  
  // systick setup to do 100 ms, with counter
  // half second toggle
  if(cnt++ >4) {
    cnt = 0;
    gpio_toggle(GPIOC, GPIO13);
  }
}

static void  usart_setup(void)
{
  // ports are set in gpio_setup
  usart_set_baudrate(USART3, 115200);
  usart_set_databits(USART3, 8);
  usart_set_stopbits(USART3, USART_STOPBITS_1);
  usart_set_parity(USART3, USART_PARITY_NONE);
  usart_set_flow_control(USART3, USART_FLOWCONTROL_NONE);
  usart_set_mode(USART3, USART_MODE_TX);

  usart_enable(USART3);

}


// Used by printf to set the default outport
int _write(int file, char *ptr, int len)
{
  int i;
  
  if (file == 1) {
    for (i = 0; i < len; i++) {
      usart_send_blocking(USART3, ptr[i]);
    }
    return i;
  }
  
  errno = EIO;
  return -1;
}

int main(void)
{
  float test = 1.1234f;
  clock_setup();
  gpio_setup();
  usart_setup();

  printf("\r\nbluepill template3 started\r\n");
  printf("test float (1.234f) using %%.3f: %.3f \r\n", test);

  while(1) {
    __asm__("nop");
  }
}
