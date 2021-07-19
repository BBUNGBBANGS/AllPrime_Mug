#include "oled.h"

const uint8 OLED_InitSeq[23] = {0xAE,0xD5,0x80,0xA8,0x1F,0xD3,0x40,0x8D,0x10,0x20,0x00,0xA1,0xC8,0xDA,0x02,0x81,0x8F,0xD9,0x22,0xDB,0x40,0xA4,0xA6};
const uint8 OLED_FullRange[7] = {0x00,0x21,0x00,0x7F,0x22,0x00,0x07};
const uint8 OLED_A[5] = {0x40,0x7E,0x12,0x12,0x7E}; 

uint8 OLED_I2C_STAT;

static void OLED_Write_Command(uint8 cmd);
static void OLED_Write_Data(uint8 data);
static void OLED_Write_CharacterArray(uint8 Character,uint8 length);
static void OLED_Write_DataArray(uint8 *data,uint8 length);

void OLED_Init(void)
{
	OLED_Write_Command(0xAE); //display off
	OLED_Write_Command(0x20); //Set Memory Addressing Mode   
	OLED_Write_Command(0x10); //00,Horizontal Addressing Mode;01,Vertical Addressing Mode;10,Page Addressing Mode (RESET);11,Invalid
	OLED_Write_Command(0xB0); //Set Page Start Address for Page Addressing Mode,0-7
	OLED_Write_Command(0xC8); //Set COM Output Scan Direction
	OLED_Write_Command(0x00); //---set low column address
	OLED_Write_Command(0x10); //---set high column address
	OLED_Write_Command(0x40); //--set start line address
	OLED_Write_Command(0x81); //--set contrast control register
	OLED_Write_Command(0xFF);
	OLED_Write_Command(0xA1); //--set segment re-map 0 to 127
	OLED_Write_Command(0xA6); //--set normal display
	OLED_Write_Command(0xA8); //--set multiplex ratio(1 to 64)
	OLED_Write_Command(0x3F); //
	OLED_Write_Command(0xA4); //0xa4,Output follows RAM content;0xa5,Output ignores RAM content
	OLED_Write_Command(0xD3); //-set display offset
	OLED_Write_Command(0x00); //-not offset
	OLED_Write_Command(0xD5); //--set display clock divide ratio/oscillator frequency
	OLED_Write_Command(0xF0); //--set divide ratio
	OLED_Write_Command(0xD9); //--set pre-charge period
	OLED_Write_Command(0x22); //
	OLED_Write_Command(0xDA); //--set com pins hardware configuration
	OLED_Write_Command(0x12);
	OLED_Write_Command(0xDB); //--set vcomh
	OLED_Write_Command(0x20); //0x20,0.77xVcc
	OLED_Write_Command(0x8D); //--set DC-DC enable
	OLED_Write_Command(0x14); //
	OLED_Write_Command(0xAF); //--turn on SSD1306 panel
}
void OLED_Write_Command(uint8 cmd)
{
    OLED_I2C_STAT = HAL_I2C_Master_Transmit(&hi2c1,OLED_ADDRESS,&cmd,1,10);
}

void OLED_Write_CharacterArray(uint8 Character,uint8 length)
{
    OLED_I2C_STAT = HAL_I2C_Master_Transmit(&hi2c1,OLED_ADDRESS,&Character,length,10);
}

void OLED_Write_DataArray(uint8 *data,uint8 length)
{
    OLED_I2C_STAT = HAL_I2C_Master_Transmit(&hi2c1,OLED_ADDRESS,*data,length,10);
}

