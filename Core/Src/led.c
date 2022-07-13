#include "led.h"
#include "switch.h"
#include "temp.h"
#include "pwm.h"
#include "co2.h"

uint16 LED_TimeCounter;
uint16 LED_TimeCounter_Co2;
void LED_Control(void)
{
    LED_TimeCounter++;
    LED_TimeCounter_Co2++;
    if(LED_TimeCounter>20)
    {
        LED_TimeCounter = 0;
    }
    if(LED_TimeCounter_Co2>10)
    {
        LED_TimeCounter_Co2 = 0;
    }

    if((Target_Run_Time == 0)&&(Pwm_Led_Mode == PWM_LED_MODE_COOLING))
    {
        HAL_GPIO_WritePin(LED_1_2_GROUP,LED_1_2_PIN,LED_ON);
    }
    if((Target_Run_Time == 0)&&(Pwm_Led_Mode != PWM_LED_MODE_COOLING))
    {
        HAL_GPIO_WritePin(LED_1_2_GROUP,LED_1_2_PIN,LED_OFF);
    }
    if((Target_Run_Time == 0)&&(Pwm_Led_Mode == PWM_LED_MODE_HEATING))
    {
        HAL_GPIO_WritePin(LED_1_1_GROUP,LED_1_1_PIN,LED_ON);
    }
    if((Target_Run_Time == 0)&&(Pwm_Led_Mode != PWM_LED_MODE_HEATING))
    {
        HAL_GPIO_WritePin(LED_1_1_GROUP,LED_1_1_PIN,LED_OFF);
    }

    if(CO2_Data16 >= LED_CO2_BLANKING_THRESHOLD)
    {
        if(LED_TimeCounter_Co2 < LED_BLANKING_TIME_0P5S)
        {
            HAL_GPIO_WritePin(LED_3_1_GROUP,LED_3_1_PIN,LED_ON);                
            HAL_GPIO_WritePin(LED_3_2_GROUP,LED_3_2_PIN,LED_OFF);        
        }
        if(LED_TimeCounter_Co2 >= LED_BLANKING_TIME_0P5S)
        {
            HAL_GPIO_WritePin(LED_3_1_GROUP,LED_3_1_PIN,LED_OFF);                
            HAL_GPIO_WritePin(LED_3_2_GROUP,LED_3_2_PIN,LED_ON);     
        }
    }
    else
    {
        HAL_GPIO_WritePin(LED_3_1_GROUP,LED_3_1_PIN,LED_OFF);                 
        HAL_GPIO_WritePin(LED_3_2_GROUP,LED_3_2_PIN,LED_OFF);      
    }

    if(LED_TimeCounter < LED_BLANKING_TIME_1S)
    {
        if((Pwm_Led_Mode == PWM_LED_MODE_COOLING)&&(Target_Run_Time != 0))
        {
            HAL_GPIO_WritePin(LED_1_2_GROUP,LED_1_2_PIN,LED_ON);
        }        
        if((Pwm_Led_Mode == PWM_LED_MODE_HEATING)&&(Target_Run_Time != 0))
        {
            HAL_GPIO_WritePin(LED_1_1_GROUP,LED_1_1_PIN,LED_ON);
        }
    }
    if(LED_TimeCounter >= LED_BLANKING_TIME_1S)
    {
        if((Pwm_Led_Mode == PWM_LED_MODE_COOLING)&&(Target_Run_Time != 0))
        {
            HAL_GPIO_WritePin(LED_1_2_GROUP,LED_1_2_PIN,LED_OFF);
        }
        if((Pwm_Led_Mode == PWM_LED_MODE_HEATING)&&(Target_Run_Time != 0))
        {
            HAL_GPIO_WritePin(LED_1_1_GROUP,LED_1_1_PIN,LED_OFF);
        }
    }

    if((switch_submode == SWITCH_SUB_MODE_18)||(switch_submode == SWITCH_SUB_MODE_19))
    {
        HAL_GPIO_WritePin(LED_2_2_GROUP,LED_2_2_PIN,LED_ON);           
    }
    else
    {
        HAL_GPIO_WritePin(LED_2_2_GROUP,LED_2_2_PIN,LED_OFF);                
    }

    /* Emergency output */
    if((switch_overtemp == 0)&&(Pwm_Led_Mode == PWM_LED_MODE_HEATING))
    { 
        HAL_GPIO_WritePin(LED_2_1_GROUP,LED_2_1_PIN,LED_ON);                
    }
    else
    {
        HAL_GPIO_WritePin(LED_2_1_GROUP,LED_2_1_PIN,LED_OFF);          
    }
              
    return;
}