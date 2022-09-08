#include "co2.h"

uint8 CO2_Address;
uint8 CO2_Data_w;
uint8 CO2_Data[8];

uint16 CO2_Data16;
uint16 TVOC_Data16;
static void CO2_FindAddress(void);
static void CO2_ReadData(void);

void CO2_Init(void)
{
    CO2_Data_w = 0xF4;
    //HAL_I2C_Master_Transmit(&CO2_HW_MODULE,(CO2_ADDRESS<<1),&CO2_Data_w,1,1000);
    CO2_Data_w = 0x10;
    //HAL_I2C_Mem_Write(&CO2_HW_MODULE,(CO2_ADDRESS<<1),CO2_ADDRESS_MEAS_MODE,1,&CO2_Data_w,1,1000);
    return;
}

void CO2_Communication(void)
{
    //CO2_ReadData();
    CO2_FindAddress();
    return;
}

static void CO2_ReadData(void)
{
    HAL_I2C_Mem_Read(&CO2_HW_MODULE,(CO2_ADDRESS<<1),CO2_ADDRESS_ALG_RESULT_DATA,1,CO2_Data,8,100);
    CO2_Data16 = (CO2_Data[0]<<8) | (CO2_Data[1]);
    TVOC_Data16 = (CO2_Data[2]<<8) | (CO2_Data[3]); 
}

static void CO2_FindAddress(void)
{
    if(HAL_OK == HAL_I2C_IsDeviceReady(&CO2_HW_MODULE,CO2_Address,3,10))
    {
        /*do noThing*/
    }
    else
    {
        CO2_Address++;
    }
}
