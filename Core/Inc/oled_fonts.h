#include "main.h"

typedef struct {
    uint8 FontWidth;    /*!< Font width in pixels */
    uint8 FontHeight;   /*!< Font height in pixels */
    const uint16 *data; /*!< Pointer to data font data array */
} OLED_Font_t;

typedef struct {
    uint16 Width;       /*!< String width in units of pixels */
    uint16 Height;      /*!< String height in units of pixels */
} OLED_Font_Size_t;

/*  7 x 10 pixels font size structure */
extern OLED_Font_t OLED_Font_7x10;

/* 11 x 18 pixels font size structure */
extern OLED_Font_t OLED_Font_11x18;

/* 16 x 26 pixels font size structure */
extern OLED_Font_t OLED_Font_16x26;

/* 12 x 16 pixels font size structure */
extern OLED_Font_t OLED_Font_12x16;

/* 10 x 16 pixels font size structure */
extern OLED_Font_t OLED_Font_10x16;

extern void OLED_Font_GetStringSize(const char* str, OLED_Font_Size_t* SizeStruct, const OLED_Font_t* Font);