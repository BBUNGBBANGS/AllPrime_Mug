#include "main.h"

#define LED_1_1_GROUP           (GPIOA)
#define LED_1_2_GROUP           (GPIOA)
#define LED_2_1_GROUP           (GPIOB)
#define LED_2_2_GROUP           (GPIOB)
#define LED_3_1_GROUP           (GPIOB)
#define LED_3_2_GROUP           (GPIOB)

#define LED_1_1_PIN             (GPIO_PIN_1)
#define LED_1_2_PIN             (GPIO_PIN_2)
#define LED_2_1_PIN             (GPIO_PIN_4)
#define LED_2_2_PIN             (GPIO_PIN_5)
#define LED_3_1_PIN             (GPIO_PIN_12)
#define LED_3_2_PIN             (GPIO_PIN_14)

#define LED_ON                  (GPIO_PIN_SET)
#define LED_OFF                 (GPIO_PIN_RESET)

extern void LED_Control(void);