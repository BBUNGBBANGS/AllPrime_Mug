#include "main.h"

#define SWITCH_1                (0u)
#define SWITCH_2                (1u)
#define SWITCH_3                (2u)
#define SWITCH_4                (3u)

#define SWITCH_GROUP_1          (GPIOA)
#define SWITCH_GROUP_2          (GPIOA)
#define SWITCH_GROUP_3          (GPIOA)
#define SWITCH_GROUP_4          (GPIOA)
#define OVERTEMP_GROUP          (GPIOB)
#define CUP_GROUP               (GPIOA)
#define BUZZER_GROUP            (GPIOB)

#define SWITCH_PIN_1            (GPIO_PIN_10)
#define SWITCH_PIN_2            (GPIO_PIN_11)
#define SWITCH_PIN_3            (GPIO_PIN_12)
#define SWITCH_PIN_4            (GPIO_PIN_4)
#define CUP_PIN                 (GPIO_PIN_9)
#define BUZZER_PIN              (GPIO_PIN_13)
#define OVERTEMP_PIN            (GPIO_PIN_14)

#define SWITCH_MODE_NONE            (0u)
#define SWITCH_MODE_MENUSELECT      (1u)
#define SWITCH_MODE_CUSTOM          (2u)
#define SWITCH_MODE_RUN             (3u)

#define SWITCH_CUSTOM_TARGET_TEMP_SET   (0u)
#define SWITCH_CUSTOM_TARGET_TIME_SET   (1u)
#define SWITCH_CUSTOM_IDLE_SET          (2u)

#define SWITCH_SERVO_ON             (1)
#define SWITCH_SERVO_OFF            (0)

#define SWITCH_SUB_MODE_1       (1u)
#define SWITCH_SUB_MODE_2       (2u)
#define SWITCH_SUB_MODE_3       (3u)
#define SWITCH_SUB_MODE_4       (4u)
#define SWITCH_SUB_MODE_5       (5u)
#define SWITCH_SUB_MODE_6       (6u)
#define SWITCH_SUB_MODE_7       (7u)
#define SWITCH_SUB_MODE_8       (8u)
#define SWITCH_SUB_MODE_9       (9u)
#define SWITCH_SUB_MODE_10      (10u)
#define SWITCH_SUB_MODE_11      (11u)
#define SWITCH_SUB_MODE_12      (12u)
#define SWITCH_SUB_MODE_13      (13u)
#define SWITCH_SUB_MODE_14      (14u)
#define SWITCH_SUB_MODE_15      (15u)
#define SWITCH_SUB_MODE_16      (16u)
#define SWITCH_SUB_MODE_17      (17u)
#define SWITCH_SUB_MODE_18      (18u)
#define SWITCH_SUB_MODE_19      (19u)

#define SWITCH1_DEBOUNCE_TIME       (2 * 50)
#define SWITCH3_DEBOUNCE_TIME       (2 * 50)

extern uint8 cup_in;
extern uint8 switch_mode;
extern uint8 switch_submode;
extern uint8 switch4_mode;
extern uint8 switch4_mode_old;
extern uint8 switch_overtemp;
extern sint16 switch_trg_temp;
extern sint16 switch_trg_time;
extern sint16 switch_idle_temp;
extern uint8 switch_custom_mode;
extern void Switch_Val_Init(void);
extern void Switch_Control(void);

