#include "main.h"

#define PWM_TIM_MODULE_PELTIER      (TIM14)
#define PWM_TIM_MODULE_HEATER       (TIM3)
#define PWM_TIM_MODULE_SERVO        (TIM1)

extern void Pwm_Output(void);