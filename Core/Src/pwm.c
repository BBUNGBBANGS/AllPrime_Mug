#include "pwm.h"

static Pwm_Peltier_Set_Duty(uint16 duty);
static Pwm_Heater_Set_Duty(uint16 duty);
static Pwm_Servo_Set_Duty(uint16 duty);

uint16 Pwm_Duty_Peltier = 300;
uint16 Pwm_Duty_Heater = 0;
uint16 Pwm_Duty_Servo = 300;

void Pwm_Output(void)
{
    Pwm_Peltier_Set_Duty(Pwm_Duty_Peltier);
    Pwm_Heater_Set_Duty(Pwm_Duty_Heater);
    Pwm_Servo_Set_Duty(Pwm_Duty_Servo);
    return;
}

static Pwm_Peltier_Set_Duty(uint16 duty)
{
    /* Resolution : 0.1[%] */
    PWM_TIM_MODULE_PELTIER-> CCR1 = duty;
}

static Pwm_Heater_Set_Duty(uint16 duty)
{
    /* Resolution : 0.1[%] */
    PWM_TIM_MODULE_HEATER-> CCR1 = duty;
}

static Pwm_Servo_Set_Duty(uint16 duty)
{
    /* Resolution : 0.1[%] */
    PWM_TIM_MODULE_SERVO-> CCR3 = duty;
}