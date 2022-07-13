#include "main.h"
#include "string.h"
#include "oled_fonts.h"
#include "switch.h"

#define OLED_HW_MODULE              (hi2c1)
#define OLED_ADDRESS                (0x3C)

/* OLED width in pixels */
#define OLED_WIDTH            128
/* OLED height in pixels */
#define OLED_HEIGHT           32

#define OLED_FONT_DEFAULT       (0u)
#define OLED_FONT_KOREAN        (1u)

typedef enum {
    OLED_COLOR_BLACK = 0x00, /*!< Black color, no pixel */
    OLED_COLOR_WHITE = 0x01  /*!< Pixel is set. Color depends on LCD */
} OLED_COLOR_t;

typedef struct {
    uint16 X_point;
    uint16 Y_point;
} OLED_t;

extern void OLED_FindAddress(void);
extern void OLED_Init(void);
extern void OLED_Display(void);