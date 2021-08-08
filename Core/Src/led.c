#include "led.h"

uint16 LED_TimeCounter;
void LED_Control(void)
{
    LED_TimeCounter++;

    if(LED_TimeCounter>5)
    {
        LED_TimeCounter = 0;
    }
    if(LED_TimeCounter % 5 == 0)
    {
        HAL_GPIO_WritePin(LED_1_1_GROUP,LED_1_1_PIN,LED_ON);
        HAL_GPIO_WritePin(LED_1_2_GROUP,LED_1_2_PIN,LED_ON);
        HAL_GPIO_WritePin(LED_2_1_GROUP,LED_2_1_PIN,LED_ON);
        HAL_GPIO_WritePin(LED_2_2_GROUP,LED_2_2_PIN,LED_ON);
        HAL_GPIO_WritePin(LED_3_2_GROUP,LED_3_1_PIN,LED_ON);
        HAL_GPIO_WritePin(LED_3_1_GROUP,LED_3_2_PIN,LED_ON);
    }
    else
    {
        HAL_GPIO_WritePin(LED_1_1_GROUP,LED_1_1_PIN,LED_OFF);
        HAL_GPIO_WritePin(LED_1_2_GROUP,LED_1_2_PIN,LED_OFF);
        HAL_GPIO_WritePin(LED_2_1_GROUP,LED_2_1_PIN,LED_OFF);
        HAL_GPIO_WritePin(LED_2_2_GROUP,LED_2_2_PIN,LED_OFF);
        HAL_GPIO_WritePin(LED_3_2_GROUP,LED_3_1_PIN,LED_OFF);
        HAL_GPIO_WritePin(LED_3_1_GROUP,LED_3_2_PIN,LED_OFF);
    }

    HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,GPIO_PIN_SET);

    return;
}