#include "pwm.h"

static void Pwm_SubMode_Target_Set(void);
static void Pwm_Control(void);
static void Pwm_Peltier_Set_Duty(uint16 duty);
static void Pwm_Heater_Set_Duty(uint16 duty);
static void Pwm_Servo_Set_Duty(uint16 duty);
static void Pwm_Fan_Set_Duty(uint16 duty);

sint16 Pwm_Duty_Peltier = 0;
sint16 Pwm_Duty_Heater = 0;
sint16 Pwm_Duty_Servo = 0;
sint16 Pwm_Duty_Fan = 0;

uint8 Pwm_Servo_status = 0;

uint8 Pwm_Led_Mode = 0;

sint16 Target_Run_Temp;
sint32 Target_Run_Time;
sint16 Target_Idle_Temp;
uint8 first_target_flag = 0;

extern uint8 switch4_mode;
uint16 Servo_timer;
void Pwm_Output(void)
{
    if(((switch_mode == SWITCH_MODE_RUN)&&(cup_in == 1))||
       (switch_mode == SWITCH_MODE_RUN)&&((switch_submode == SWITCH_SUB_MODE_18)||(switch_submode == SWITCH_SUB_MODE_19)))
    {
        if(PWM_SUBMODE_TARGET_ON == first_target_flag)
        {
            Pwm_SubMode_Target_Set();
        }
        Pwm_Control();
    }
    else
    {
        first_target_flag = PWM_SUBMODE_TARGET_ON;
        Target_Run_Temp = 0;
        Target_Run_Time = 0;
        Target_Idle_Temp = 0;
        Pwm_Duty_Peltier = 0;
        Pwm_Duty_Heater = 0;
        Pwm_Duty_Fan = 0;
        Pwm_Peltier_Set_Duty(0);
        Pwm_Heater_Set_Duty(0);
        Pwm_Fan_Set_Duty(0);        
        Pwm_Led_Mode = PWM_LED_MODE_NONE;
    }

    if((switch4_mode == 1)&&(Pwm_Servo_status == PWM_SERVO_STATUS_RUN))
    {
        Pwm_Duty_Servo = PWM_SERVO_180_DEGREE;
        Servo_timer++;
        if(Servo_timer>=20)
        {
            Servo_timer = 20;
            Pwm_Servo_status = PWM_SERVO_STATUS_STOP;
            Pwm_Duty_Servo = PWM_SERVO_OFF;
        }
    }
    if((switch4_mode == 0)&&(Pwm_Servo_status == PWM_SERVO_STATUS_RUN))
    {
        Pwm_Duty_Servo = PWM_SERVO_0_DEGREE;
        Servo_timer++;
        if(Servo_timer>=20)
        {
            Servo_timer = 20;
            Pwm_Servo_status = PWM_SERVO_STATUS_STOP;
            Pwm_Duty_Servo = PWM_SERVO_OFF;
        }
    }

    Pwm_Servo_Set_Duty(Pwm_Duty_Servo);
    return;
}
static void Pwm_SubMode_Target_Set(void)
{
    switch(switch_submode)
    {
        case SWITCH_SUB_MODE_1 :
            Target_Run_Temp = PWM_RUN_TEMP_1;
            Target_Run_Time = PWM_RUN_TIME_1;
            Target_Idle_Temp = PWM_IDLE_TEMP_1;
        break;
        case SWITCH_SUB_MODE_2 :
            Target_Run_Temp = PWM_RUN_TEMP_2;
            Target_Run_Time = PWM_RUN_TIME_2;
            Target_Idle_Temp = PWM_IDLE_TEMP_2; 
        break;
        case SWITCH_SUB_MODE_3 :
            Target_Run_Temp = PWM_RUN_TEMP_3;
            Target_Run_Time = PWM_RUN_TIME_3;
            Target_Idle_Temp = PWM_IDLE_TEMP_3; 
        break;
        case SWITCH_SUB_MODE_4 :
            Target_Run_Temp = PWM_RUN_TEMP_4;
            Target_Run_Time = PWM_RUN_TIME_4;
            Target_Idle_Temp = PWM_IDLE_TEMP_4; 
        break;
        case SWITCH_SUB_MODE_5 :
            Target_Run_Temp = PWM_RUN_TEMP_5;
            Target_Run_Time = PWM_RUN_TIME_5;
            Target_Idle_Temp = PWM_IDLE_TEMP_5; 
        break;
        case SWITCH_SUB_MODE_6 :
            Target_Run_Temp = PWM_RUN_TEMP_6;
            Target_Run_Time = PWM_RUN_TIME_6;
            Target_Idle_Temp = PWM_IDLE_TEMP_6; 
        break;
        case SWITCH_SUB_MODE_7 :
            Target_Run_Temp = PWM_RUN_TEMP_7;
            Target_Run_Time = PWM_RUN_TIME_7;
            Target_Idle_Temp = PWM_IDLE_TEMP_7; 
        break;
        case SWITCH_SUB_MODE_8 :
            Target_Run_Temp = PWM_RUN_TEMP_8;
            Target_Run_Time = PWM_RUN_TIME_8;
            Target_Idle_Temp = PWM_IDLE_TEMP_8; 
        break;
        case SWITCH_SUB_MODE_9 :
            Target_Run_Temp = PWM_RUN_TEMP_9;
            Target_Run_Time = PWM_RUN_TIME_9;
            Target_Idle_Temp = PWM_IDLE_TEMP_9; 
        break;
        case SWITCH_SUB_MODE_10 :
            Target_Run_Temp = PWM_RUN_TEMP_10;
            Target_Run_Time = PWM_RUN_TIME_10;
            Target_Idle_Temp = PWM_IDLE_TEMP_10; 
        break;
        case SWITCH_SUB_MODE_11 :
            Target_Run_Temp = PWM_RUN_TEMP_11;
            Target_Run_Time = PWM_RUN_TIME_11;
            Target_Idle_Temp = PWM_IDLE_TEMP_11; 
        break;
        case SWITCH_SUB_MODE_12 :
            Target_Run_Temp = PWM_RUN_TEMP_12;
            Target_Run_Time = PWM_RUN_TIME_12;
            Target_Idle_Temp = PWM_IDLE_TEMP_12; 
        break;
        case SWITCH_SUB_MODE_13 :
            Target_Run_Temp = PWM_RUN_TEMP_13;
            Target_Run_Time = PWM_RUN_TIME_13;
            Target_Idle_Temp = PWM_IDLE_TEMP_13; 
        break;
        case SWITCH_SUB_MODE_14 :
            Target_Run_Temp = PWM_RUN_TEMP_14;
            Target_Run_Time = PWM_RUN_TIME_14;
            Target_Idle_Temp = PWM_IDLE_TEMP_14; 
        break;
        case SWITCH_SUB_MODE_15 :
            Target_Run_Temp = PWM_RUN_TEMP_15;
            Target_Run_Time = PWM_RUN_TIME_15;
            Target_Idle_Temp = PWM_IDLE_TEMP_15; 
        break;
        case SWITCH_SUB_MODE_16 :
            Target_Run_Temp = PWM_RUN_TEMP_16;
            Target_Run_Time = PWM_RUN_TIME_16;
            Target_Idle_Temp = PWM_IDLE_TEMP_16; 
        break;
        case SWITCH_SUB_MODE_17 :
            Target_Run_Temp = switch_trg_temp;
            Target_Run_Time = (sint32)(switch_trg_time * 60 * 100);
            Target_Idle_Temp = switch_idle_temp; 
        break;
        case SWITCH_SUB_MODE_18 :
            Target_Run_Temp = PWM_RUN_TEMP_18;
            Target_Run_Time = PWM_RUN_TIME_18;
            Target_Idle_Temp = PWM_IDLE_TEMP_18; 
        break;
        case SWITCH_SUB_MODE_19 :
            Target_Run_Temp = PWM_RUN_TEMP_19;
            Target_Run_Time = PWM_RUN_TIME_19;
            Target_Idle_Temp = PWM_IDLE_TEMP_19; 
        break;
        default :
            Target_Run_Temp = PWM_RUN_TEMP_0;
            Target_Run_Time = PWM_RUN_TIME_0;
            Target_Idle_Temp = PWM_IDLE_TEMP_0; 
        break;
    }
}
static void Pwm_Control(void)
{
    sint16 tempLoc;
    sint16 TrgTempLoc;
    static uint8 first_status;
    if(first_target_flag == PWM_SUBMODE_TARGET_ON)
    {
        first_status = 0;
        first_target_flag = PWM_SUBMODE_TARGET_OFF;
    }
    tempLoc = Temp_Adc_TP;
    if((Target_Run_Time>0)&&(tempLoc>(Target_Run_Temp-5))&&(tempLoc<(Target_Run_Temp+5)))
    {
        first_status = 1;
    }
    TrgTempLoc = Target_Run_Temp;

    if(first_status == 1)
    {
        Target_Run_Time--;
        if(Target_Run_Time<=0)
        {
            Target_Run_Time = 0;
            first_status = 2;
        }
    }
    if(first_status == 2)
    {
        TrgTempLoc = Target_Idle_Temp;
    }

    if((TrgTempLoc - tempLoc)>0)
    {
        Pwm_Duty_Heater++;
        Pwm_Duty_Peltier--;
        Pwm_Led_Mode = PWM_LED_MODE_HEATING;
    }
    else 
    {
        Pwm_Duty_Heater--;
        Pwm_Duty_Peltier++;
        Pwm_Led_Mode = PWM_LED_MODE_COOLING;
    }

    if((TrgTempLoc - tempLoc)>=1)
    {
        Pwm_Duty_Fan--;
    }
    else if((TrgTempLoc - tempLoc)<= -1)
    {

        Pwm_Duty_Fan++;
    }
    else
    {
        /* hold fan pwm duty */
    }

    if(Pwm_Duty_Heater >= PWM_DUTY_MAX)
    {
        Pwm_Duty_Heater = PWM_DUTY_MAX;
    }
    if(Pwm_Duty_Heater <= PWM_DUTY_MIN)
    {
        Pwm_Duty_Heater = PWM_DUTY_MIN;
    }

    if(Pwm_Duty_Peltier >= PWM_DUTY_MAX)
    {
        Pwm_Duty_Peltier = PWM_DUTY_MAX;
    }
    if(Pwm_Duty_Peltier <= PWM_DUTY_MIN)
    {
        Pwm_Duty_Peltier = PWM_DUTY_MIN;
    }

    if(Pwm_Duty_Fan >= PWM_DUTY_MAX)
    {
        Pwm_Duty_Fan = PWM_DUTY_MAX;
    }
    if(Pwm_Duty_Fan <= PWM_DUTY_MIN)
    {
        Pwm_Duty_Fan = PWM_DUTY_MIN;
    }

    Pwm_Heater_Set_Duty(Pwm_Duty_Heater);
    Pwm_Peltier_Set_Duty(Pwm_Duty_Peltier);
    Pwm_Fan_Set_Duty(Pwm_Duty_Fan);
}

static void Pwm_Peltier_Set_Duty(uint16 duty)
{
    /* Resolution : 0.1[%] */
    PWM_TIM_MODULE_PELTIER-> PWM_TIM_CH_PELTIER = duty;
}

static void Pwm_Heater_Set_Duty(uint16 duty)
{
    /* Resolution : 0.1[%] */
    PWM_TIM_MODULE_HEATER-> PWM_TIM_CH_HEATER = duty;
}

static void Pwm_Servo_Set_Duty(uint16 duty)
{
    /* Resolution : 0.1[%] */
    PWM_TIM_MODULE_SERVO-> PWM_TIM_CH_SERVO = duty;
}

static void Pwm_Fan_Set_Duty(uint16 duty)
{
    /* Resolution : 0.1[%] */
    PWM_TIM_MIDULE_FAN-> PWM_TIM_CH_FAN = duty;
}