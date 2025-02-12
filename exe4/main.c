#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN = 28;

const int LED_PIN_R = 5;
const int LED_PIN_P = 8;
const int LED_PIN_B = 11;
const int LED_PIN_Y = 15;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);

  gpio_init(LED_PIN_P);
  gpio_set_dir(LED_PIN_P, GPIO_OUT);

  gpio_init(LED_PIN_B);
  gpio_set_dir(LED_PIN_B, GPIO_OUT);

  gpio_init(LED_PIN_Y);
  gpio_set_dir(LED_PIN_Y, GPIO_OUT);

  while (true) {
    // Use delay de 300 ms entre os estados!
    if (!gpio_get(BTN_PIN)) {
      gpio_put(LED_PIN_R, 1);
      busy_wait_ms(300);
      gpio_put(LED_PIN_R, 0);

      gpio_put(LED_PIN_P, 1);
      busy_wait_ms(300);
      gpio_put(LED_PIN_P, 0);

      gpio_put(LED_PIN_B, 1);
      busy_wait_ms(300);
      gpio_put(LED_PIN_B, 0);

      gpio_put(LED_PIN_Y, 1);
      busy_wait_ms(300);
      gpio_put(LED_PIN_Y, 0);

      while (!gpio_get(BTN_PIN)) {
      }
    }
  }
}
