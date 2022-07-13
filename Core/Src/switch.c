#include "switch.h"
#include "pwm.h"
#include "eeprom.h"

uint8 switch1_status,switch2_status,switch3_status,switch4_status;
uint8 switch1_status_old,switch2_status_old,switch3_status_old,switch4_status_old;
uint8 switch_overtemp;
uint8 switch_mode;
uint8 switch_submode;
uint8 cup_in,cup_in_old;
uint8 switch4_mode,switch4_mode_old;
uint8 switch_custom_mode;

sint16 switch_trg_temp;
sint16 switch_trg_time;
sint16 switch_idle_temp;

uint16 switch_timer1,switch_timer2,switch_timer3;
extern uint16 Servo_timer;
void Switch_Val_Init(void)
{
    if((*(uint16*)(EEPROM_PAGE127_START+(0*2))) != 0xFFFF)
    {
        switch_submode = switch_submodeEEP;
    }
    else
    {
        switch_submode = SWITCH_SUB_MODE_1;
    }
    if((*(uint16*)(EEPROM_PAGE127_START+(1*2))) != 0xFFFF)
    {
        switch_trg_temp = (sint16)switch_trg_tempEEP;
    }
    else
    {
        switch_trg_temp = 0;
    }    
    if((*(uint16*)(EEPROM_PAGE127_START+(2*2))) != 0xFFFF)
    {
        switch_trg_time = (sint16)switch_trg_timeEEP;
    }
    else
    {
        switch_trg_time = 0;
    }    
    if((*(uint16*)(EEPROM_PAGE127_START+(3*2))) != 0xFFFF)
    {
        switch_idle_temp = (sint16)switch_idle_tempEEP;
    }
    else
    {
        switch_idle_temp = 0;
    }
    return;
}
void Switch_Control(void)
{
    switch_timer2 = 0;

    switch1_status = HAL_GPIO_ReadPin(SWITCH_GROUP_1,SWITCH_PIN_1);
    switch2_status = HAL_GPIO_ReadPin(SWITCH_GROUP_2,SWITCH_PIN_2);
    switch3_status = HAL_GPIO_ReadPin(SWITCH_GROUP_3,SWITCH_PIN_3);
    switch4_status = HAL_GPIO_ReadPin(SWITCH_GROUP_4,SWITCH_PIN_4);
    switch_overtemp = HAL_GPIO_ReadPin(OVERTEMP_GROUP,OVERTEMP_PIN);
    cup_in = HAL_GPIO_ReadPin(CUP_GROUP,CUP_PIN); 

    if((1 == switch1_status)||(1 == switch2_status)||(1 == switch3_status))
    {   
        HAL_GPIO_WritePin(BUZZER_GROUP,BUZZER_PIN,GPIO_PIN_SET);
    }
    else
    {
        HAL_GPIO_WritePin(BUZZER_GROUP,BUZZER_PIN,GPIO_PIN_RESET);       
    }

    if((switch1_status == 1)&&(switch_mode == SWITCH_MODE_NONE))
    {
        switch_timer1++;
        if(switch_timer1>=SWITCH1_DEBOUNCE_TIME)
        {
            switch_timer1 = 0;
            switch_mode = SWITCH_MODE_MENUSELECT;
        }
    }
    else
    {
        switch_timer1 = 0;
    }

    if((switch3_status == 1)&&(switch_mode == SWITCH_MODE_RUN))
    {
        switch_timer3++;
        if(switch_timer3>=SWITCH3_DEBOUNCE_TIME)
        {
            switch_timer3 = 0;
            switch_mode = SWITCH_MODE_NONE;
            switch_custom_mode = SWITCH_CUSTOM_TARGET_TEMP_SET;
        }
    }
    else
    {
        switch_timer3 = 0;
    }

    if((switch_submode != SWITCH_SUB_MODE_18)&&(switch_submode != SWITCH_SUB_MODE_19))
    {
        if(((cup_in == 1)&&(cup_in_old == 0))||((cup_in == 1)&&(switch4_status == 0)&&(switch4_status_old == 1)))
        {
            Pwm_Servo_status = PWM_SERVO_STATUS_RUN;
            Servo_timer = 0;
            switch4_mode = 1;
        }
        if(((cup_in == 0)&&(cup_in_old == 1))||((cup_in == 1)&&(switch4_status == 1)&&(switch4_status_old == 0)))
        {
            Pwm_Servo_status = PWM_SERVO_STATUS_RUN;
            Servo_timer = 0;
            switch4_mode = 0;
        }        
        cup_in_old = cup_in;
        switch4_mode_old=switch4_mode;
        switch4_status_old = switch4_status;
    }

    if(switch_mode == SWITCH_MODE_CUSTOM)
    {
        if(switch_custom_mode == SWITCH_CUSTOM_TARGET_TEMP_SET)
        {
            if((1u == switch1_status)&&(0==switch1_status_old))
            {
                switch_trg_temp--;
                if(switch_trg_temp < 0)
                {
                    switch_trg_temp = 100;
                }
            }
            else if((1u == switch2_status)&&(0==switch2_status_old))
            {
                switch_trg_temp++;
                if(switch_trg_temp > 100)
                {
                    switch_trg_temp = 0;
                }
            }        
            else if((1u == switch3_status)&&(0==switch3_status_old))
            {
                switch_custom_mode = SWITCH_CUSTOM_TARGET_TIME_SET;
            }
            else
            {

            }
        }
        else if(switch_custom_mode == SWITCH_CUSTOM_TARGET_TIME_SET)
        {
            if((1u == switch1_status)&&(0==switch1_status_old))
            {
                switch_trg_time--;
                if(switch_trg_time < 0)
                {
                    switch_trg_time = 60;
                }
            }
            else if((1u == switch2_status)&&(0==switch2_status_old))
            {
                switch_trg_time++;
                if(switch_trg_time > 60)
                {
                    switch_trg_time = 0;
                }
            }        
            else if((1u == switch3_status)&&(0==switch3_status_old))
            {
                switch_custom_mode = SWITCH_CUSTOM_IDLE_SET;
            }
            else
            {

            }            
        }
        else if(switch_custom_mode == SWITCH_CUSTOM_IDLE_SET)
        {
            if((1u == switch1_status)&&(0==switch1_status_old))
            {
                switch_idle_temp--;
                if(switch_idle_temp < 0)
                {
                    switch_idle_temp = 60;
                }
            }
            else if((1u == switch2_status)&&(0==switch2_status_old))
            {
                switch_idle_temp++;
                if(switch_idle_temp > 60)
                {
                    switch_idle_temp = 0;
                }
            }        
            else if((1u == switch3_status)&&(0==switch3_status_old))
            {
                switch_mode = SWITCH_MODE_RUN;
            }
            else
            {

            }            
        }
    }

    if(switch_mode == SWITCH_MODE_MENUSELECT)
    {
        if((1u == switch1_status)&&(0==switch1_status_old))
        {
            switch_submode--;
            if(switch_submode < SWITCH_SUB_MODE_1)
            {
                switch_submode = SWITCH_SUB_MODE_19;
            }
        }
        else if((1u == switch2_status)&&(0==switch2_status_old))
        {
            switch_submode++;
            if(switch_submode > SWITCH_SUB_MODE_19)
            {
                switch_submode = SWITCH_SUB_MODE_1;
            }
        }
        else if((1u == switch3_status)&&(0==switch3_status_old)&&(SWITCH_SUB_MODE_17 == switch_submode))
        {
            switch_mode = SWITCH_MODE_CUSTOM;
        }
        else if((1u == switch3_status)&&(0==switch3_status_old))
        {
            switch_mode = SWITCH_MODE_RUN;
        }
        else
        {

        }
    }

    switch1_status_old = switch1_status;
    switch2_status_old = switch2_status;
    switch3_status_old = switch3_status;
    
    return;
}