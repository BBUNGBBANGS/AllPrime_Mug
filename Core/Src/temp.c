#include "temp.h"

uint16 Temp_Adc_TP_Raw;
uint16 Temp_Adc_CPU_Raw;
uint8 Temp_Adc_TP_Status;
uint8 Temp_Adc_CPU_Status;

uint8 Temp_Avg_TP_Count = 10;
uint8 Temp_Avg_CPU_Count = 10;

uint32 Temp_Adc_TP_Sum;
uint32 Temp_Adc_CPU_Sum;

uint16 Temp_Adc_TP_Volt;
uint16 Temp_Adc_CPU_Volt;

sint16 Temp_Adc_TP;
sint16 Temp_Adc_CPU;
void Temp_Read(void)
{
    HAL_ADC_Start(&hadc);
    if(HAL_OK == HAL_ADC_PollForConversion(&TEMP_MODULE,10))
    {
        Temp_Adc_TP_Raw = HAL_ADC_GetValue(&TEMP_MODULE);
        Temp_Adc_TP_Status = 1;
    }
    else
    {
        Temp_Adc_TP_Status = 0;
    }

    HAL_ADC_Start(&hadc);
    if(HAL_OK == HAL_ADC_PollForConversion(&TEMP_MODULE,10))
    {
        Temp_Adc_CPU_Raw = HAL_ADC_GetValue(&TEMP_MODULE);
        Temp_Adc_CPU_Status = 1;
    }
    else
    {
        Temp_Adc_CPU_Status = 0;
    }


    if(1 == Temp_Adc_TP_Status)
    {
        Temp_Avg_TP_Count++;
        Temp_Adc_TP_Sum += Temp_Adc_TP_Raw;
        if(Temp_Avg_TP_Count>=10)
        {
            Temp_Adc_TP_Volt = (uint16)((float)(Temp_Adc_TP_Sum / Temp_Avg_TP_Count)*5000.0f/4095.0f);
            Temp_Adc_TP = (sint16)((4750 - (float)Temp_Adc_TP_Volt)*0.0375f - 40.0f);
            Temp_Avg_TP_Count = 0;
            Temp_Adc_TP_Sum = 0;
        }
    }
    
    if(1 == Temp_Adc_CPU_Status)
    {
        Temp_Avg_CPU_Count++;
        Temp_Adc_CPU_Sum += Temp_Adc_CPU_Raw;
        if(Temp_Avg_CPU_Count>=10)
        {
            Temp_Adc_CPU_Volt = (uint16)((float)(Temp_Adc_CPU_Sum / Temp_Avg_CPU_Count)*3300.0f/4095.0f);
            Temp_Adc_CPU = (sint16)(((float)Temp_Adc_CPU_Volt - 760.0f) / 2.5f + 25.0f);
            Temp_Avg_CPU_Count = 0;
            Temp_Adc_CPU_Sum = 0;
        }
    }

    return;
}

