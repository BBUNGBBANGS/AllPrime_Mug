#include "switch.h"

uint8 switch_status1,switch_status2,switch_status3,switch_status4;

void Switch_Control(void)
{
    switch_status1 = HAL_GPIO_ReadPin(SWITCH_GROUP_1,SWITCH_PIN_1);
    switch_status2 = HAL_GPIO_ReadPin(SWITCH_GROUP_2,SWITCH_PIN_2);
    switch_status3 = HAL_GPIO_ReadPin(SWITCH_GROUP_3,SWITCH_PIN_3);
    switch_status4 = HAL_GPIO_ReadPin(SWITCH_GROUP_4,SWITCH_PIN_4);

    return;
}