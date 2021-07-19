#include "main.h"

#define OLED_GROUP          (hi2c2)
#define OLED_ADDRESS        (0x78)
#define OLED_WITDH          (128)
#define OLED_HEIGHT         (64)
#define ABS(x)   ((x) > 0 ? (x) : -(x))

extern void OLED_Init(void);