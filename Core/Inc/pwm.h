#include "main.h"
#include "switch.h"

#define PWM_TIM_MODULE_PELTIER      (TIM3)
#define PWM_TIM_MODULE_HEATER       (TIM3)
#define PWM_TIM_MODULE_SERVO        (TIM1)
#define PWM_TIM_MIDULE_FAN          (TIM1)

#define PWM_TIM_CH_PELTIER          CCR2
#define PWM_TIM_CH_HEATER           CCR1
#define PWM_TIM_CH_SERVO            CCR3
#define PWM_TIM_CH_FAN              CCR1

#define PWM_SUBMODE_TARGET_OFF      (0)
#define PWM_SUBMODE_TARGET_ON       (1)

#define PWM_DUTY_MAX                (1000)
#define PWM_DUTY_MIN                (0)

#define PWM_SERVO_180_DEGREE          (127)
#define PWM_SERVO_0_DEGREE            (32)
#define PWM_SERVO_OFF                 (0)

#define PWM_SERVO_STATUS_RUN            (1)
#define PWM_SERVO_STATUS_STOP           (0)

/*************** PWM Temperature Decleare ************************/
#define PWM_RUN_TEMP_0                (0)
#define PWM_RUN_TIME_0                (0)
#define PWM_IDLE_TEMP_0               (0)

#define PWM_RUN_TEMP_1                (90)
#define PWM_RUN_TIME_1                (10 * 60 * 100)
#define PWM_IDLE_TEMP_1               (65)

#define PWM_RUN_TEMP_2                (90)
#define PWM_RUN_TIME_2                (1 * 60 * 100)
#define PWM_IDLE_TEMP_2               (65)

#define PWM_RUN_TEMP_3                (90)
#define PWM_RUN_TIME_3                (1 * 60 * 100)
#define PWM_IDLE_TEMP_3               (5)

#define PWM_RUN_TEMP_4                (65)
#define PWM_RUN_TIME_4                (1 * 60 * 100)
#define PWM_IDLE_TEMP_4               (65)

#define PWM_RUN_TEMP_5                (5)
#define PWM_RUN_TIME_5                (1 * 60 * 100)
#define PWM_IDLE_TEMP_5               (5)

#define PWM_RUN_TEMP_6                (90)
#define PWM_RUN_TIME_6                (1 * 60 * 100)
#define PWM_IDLE_TEMP_6               (65)

#define PWM_RUN_TEMP_7                (40)
#define PWM_RUN_TIME_7                (3 * 60 * 100)
#define PWM_IDLE_TEMP_7               (5)

#define PWM_RUN_TEMP_8                (90)
#define PWM_RUN_TIME_8                (3 * 60 * 100)
#define PWM_IDLE_TEMP_8               (65)

#define PWM_RUN_TEMP_9                (90)
#define PWM_RUN_TIME_9                (10 * 60 * 100)
#define PWM_IDLE_TEMP_9               (65)

#define PWM_RUN_TEMP_10                (90)
#define PWM_RUN_TIME_10                (2 * 60 * 100)
#define PWM_IDLE_TEMP_10               (65)

#define PWM_RUN_TEMP_11                (90)
#define PWM_RUN_TIME_11                (5 * 60 * 100)
#define PWM_IDLE_TEMP_11               (65)

#define PWM_RUN_TEMP_12                (90)
#define PWM_RUN_TIME_12                (1 * 60 * 100)
#define PWM_IDLE_TEMP_12               (65)

#define PWM_RUN_TEMP_13                (80)
#define PWM_RUN_TIME_13                (20 * 60 * 100)
#define PWM_IDLE_TEMP_13               (65)

#define PWM_RUN_TEMP_14                (90)
#define PWM_RUN_TIME_14                (2 * 60 * 100)
#define PWM_IDLE_TEMP_14               (65)

#define PWM_RUN_TEMP_15                (90)
#define PWM_RUN_TIME_15                (5 * 60 * 100)
#define PWM_IDLE_TEMP_15               (65)

#define PWM_RUN_TEMP_16                (90)
#define PWM_RUN_TIME_16                (2 * 60 * 100)
#define PWM_IDLE_TEMP_16               (40)

#define PWM_RUN_TEMP_17                (0)
#define PWM_RUN_TIME_17                (0)
#define PWM_IDLE_TEMP_17               (0)

#define PWM_RUN_TEMP_18                (5)
#define PWM_RUN_TIME_18                (1 * 60 * 100)
#define PWM_IDLE_TEMP_18               (5)

#define PWM_RUN_TEMP_19                (60)
#define PWM_RUN_TIME_19                (1 * 60 * 100)
#define PWM_IDLE_TEMP_19               (60)

/********************************************************************/
#define PWM_LED_MODE_NONE                   (0)
#define PWM_LED_MODE_COOLING                (1)
#define PWM_LED_MODE_HEATING                (2)

extern sint16 Temp_Adc_TP;
extern uint8 Pwm_Led_Mode;
extern sint16 Target_Run_Temp;
extern sint32 Target_Run_Time;
extern sint16 Target_Idle_Temp;
extern uint8 Pwm_Servo_status;
extern void Pwm_Output(void);