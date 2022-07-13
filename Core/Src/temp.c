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

static void Temperature_Compensation(uint16 temp_volt);

void Temp_Read(void)
{
    HAL_ADC_Start(&TEMP_MODULE);
    if(HAL_OK == HAL_ADC_PollForConversion(&TEMP_MODULE,10))
    {
        Temp_Adc_TP_Raw = HAL_ADC_GetValue(&TEMP_MODULE);
        Temp_Adc_TP_Status = 1;
    }
    else
    {
        Temp_Adc_TP_Status = 0;
    }

    HAL_ADC_Start(&TEMP_MODULE);
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
            Temperature_Compensation(Temp_Adc_TP_Volt);
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

static void Temperature_Compensation(uint16 temp_volt)
{
    sint16 Compensation_val = 0;
    if(temp_volt>TEMP_ZONE1_THRESHOLD)
    {
        Compensation_val = -11;
    }
    else if(temp_volt>TEMP_ZONE2_THRESHOLD)
    {
        Compensation_val = -10;       
    }
    else if(temp_volt>TEMP_ZONE3_THRESHOLD)
    {
        Compensation_val = -9;       
    }    
    else if(temp_volt>TEMP_ZONE4_THRESHOLD)
    {
        Compensation_val = -8;       
    }    
    else if(temp_volt>TEMP_ZONE5_THRESHOLD)
    {
        Compensation_val = -7;       
    }    
    else if(temp_volt>TEMP_ZONE6_THRESHOLD)
    {
        Compensation_val = -6;       
    }    
    else if(temp_volt>TEMP_ZONE7_THRESHOLD)
    {
        Compensation_val = -5;       
    }    
    else if(temp_volt>TEMP_ZONE8_THRESHOLD)
    {
        Compensation_val = -4;       
    }    
    else if(temp_volt>TEMP_ZONE9_THRESHOLD)
    {
        Compensation_val = -3;       
    }    
    else if(temp_volt>TEMP_ZONE10_THRESHOLD)
    {
        Compensation_val = -2;       
    }    
    else if(temp_volt>TEMP_ZONE11_THRESHOLD)
    {
        Compensation_val = -1;       
    }    
    else if(temp_volt>TEMP_ZONE12_THRESHOLD)
    {
        Compensation_val = 0;       
    }    
    else if(temp_volt>TEMP_ZONE13_THRESHOLD)
    {
        Compensation_val = 1;       
    }    
    else if(temp_volt>TEMP_ZONE14_THRESHOLD)
    {
        Compensation_val = 2;       
    }    
    else if(temp_volt>TEMP_ZONE15_THRESHOLD)
    {
        Compensation_val = 3;       
    }    
    else if(temp_volt>TEMP_ZONE16_THRESHOLD)
    {
        Compensation_val = 4;       
    }    
    else if(temp_volt>TEMP_ZONE17_THRESHOLD)
    {
        Compensation_val = 5;       
    }    
    else if(temp_volt>TEMP_ZONE18_THRESHOLD)
    {
        Compensation_val = 6;       
    }    
    else if(temp_volt>TEMP_ZONE19_THRESHOLD)
    {
        Compensation_val = 7;       
    }    
    else if(temp_volt>TEMP_ZONE20_THRESHOLD)
    {
        Compensation_val = 8;       
    }    
    else if(temp_volt>TEMP_ZONE21_THRESHOLD)
    {
        Compensation_val = 9;       
    }    
    else if(temp_volt>TEMP_ZONE22_THRESHOLD)
    {
        Compensation_val = 10;       
    }    
    else if(temp_volt>TEMP_ZONE23_THRESHOLD)
    {
        Compensation_val = 11;       
    }    
    else if(temp_volt>TEMP_ZONE24_THRESHOLD)
    {
        Compensation_val = 12;       
    }    
    else if(temp_volt>TEMP_ZONE25_THRESHOLD)
    {
        Compensation_val = 13;       
    }    
    else if(temp_volt>TEMP_ZONE26_THRESHOLD)
    {
        Compensation_val = 14;       
    }    
    else if(temp_volt>TEMP_ZONE27_THRESHOLD)
    {
        Compensation_val = 15;       
    }    
    else if(temp_volt>TEMP_ZONE28_THRESHOLD)
    {
        Compensation_val = 16;       
    }    
    else if(temp_volt>TEMP_ZONE29_THRESHOLD)
    {
        Compensation_val = 17;       
    }    
    else if(temp_volt>TEMP_ZONE30_THRESHOLD)
    {
        Compensation_val = 18;       
    }    
    else if(temp_volt>TEMP_ZONE31_THRESHOLD)
    {
        Compensation_val = 19;       
    }    
    else if(temp_volt>TEMP_ZONE32_THRESHOLD)
    {
        Compensation_val = 20;       
    }    
    else if(temp_volt>TEMP_ZONE33_THRESHOLD)
    {
        Compensation_val = 21;       
    }    
    else if(temp_volt>TEMP_ZONE34_THRESHOLD)
    {
        Compensation_val = 22;       
    }    
    else if(temp_volt>TEMP_ZONE35_THRESHOLD)
    {
        Compensation_val = 23;       
    }    
    else if(temp_volt>TEMP_ZONE36_THRESHOLD)
    {
        Compensation_val = 24;       
    }    
    else if(temp_volt>TEMP_ZONE37_THRESHOLD)
    {
        Compensation_val = 25;       
    }    
    else if(temp_volt>TEMP_ZONE38_THRESHOLD)
    {
        Compensation_val = 26;       
    }    
    else if(temp_volt>TEMP_ZONE39_THRESHOLD)
    {
        Compensation_val = 27;       
    }    
    else if(temp_volt>TEMP_ZONE40_THRESHOLD)
    {
        Compensation_val = 28;       
    }    
    else if(temp_volt>TEMP_ZONE41_THRESHOLD)
    {
        Compensation_val = 29;       
    }    
    else if(temp_volt>TEMP_ZONE42_THRESHOLD)
    {
        Compensation_val = 30;       
    }    
    else if(temp_volt>TEMP_ZONE43_THRESHOLD)
    {
        Compensation_val = 31;       
    }    
    else if(temp_volt>TEMP_ZONE44_THRESHOLD)
    {
        Compensation_val = 32;       
    }    
    else if(temp_volt>TEMP_ZONE45_THRESHOLD)
    {
        Compensation_val = 33;       
    }    
    else if(temp_volt>TEMP_ZONE46_THRESHOLD)
    {
        Compensation_val = 34;       
    }    
    else if(temp_volt>TEMP_ZONE47_THRESHOLD)
    {
        Compensation_val = 35;       
    }    
    else if(temp_volt>TEMP_ZONE48_THRESHOLD)
    {
        Compensation_val = 36;       
    }    
    else if(temp_volt>TEMP_ZONE49_THRESHOLD)
    {
        Compensation_val = 37;       
    }    
    else if(temp_volt>TEMP_ZONE50_THRESHOLD)
    {
        Compensation_val = 38;       
    }    
    else if(temp_volt>TEMP_ZONE51_THRESHOLD)
    {
        Compensation_val = 39;       
    }    
    else if(temp_volt>TEMP_ZONE52_THRESHOLD)
    {
        Compensation_val = 40;       
    }    
    else if(temp_volt>TEMP_ZONE53_THRESHOLD)
    {
        Compensation_val = 41;       
    }    
    else if(temp_volt>TEMP_ZONE54_THRESHOLD)
    {
        Compensation_val = 42;       
    }    
    else if(temp_volt>TEMP_ZONE55_THRESHOLD)
    {
        Compensation_val = 43;       
    }    
    else if(temp_volt>TEMP_ZONE56_THRESHOLD)
    {
        Compensation_val = 44;       
    }    
    else if(temp_volt>TEMP_ZONE57_THRESHOLD)
    {
        Compensation_val = 45;       
    }    
    else if(temp_volt>TEMP_ZONE58_THRESHOLD)
    {
        Compensation_val = 46;       
    }    
    else if(temp_volt>TEMP_ZONE59_THRESHOLD)
    {
        Compensation_val = 47;       
    }    
    else if(temp_volt>TEMP_ZONE60_THRESHOLD)
    {
        Compensation_val = 48;       
    }    
    else if(temp_volt>TEMP_ZONE61_THRESHOLD)
    {
        Compensation_val = 49;       
    }    
    else if(temp_volt>TEMP_ZONE62_THRESHOLD)
    {
        Compensation_val = 50;       
    }    
    else if(temp_volt>TEMP_ZONE63_THRESHOLD)
    {
        Compensation_val = 51;       
    }    
    else if(temp_volt>TEMP_ZONE64_THRESHOLD)
    {
        Compensation_val = 52;       
    }    
    else if(temp_volt>TEMP_ZONE65_THRESHOLD)
    {
        Compensation_val = 53;       
    }    
    else if(temp_volt>TEMP_ZONE66_THRESHOLD)
    {
        Compensation_val = 54;       
    }    
    else if(temp_volt>TEMP_ZONE67_THRESHOLD)
    {
        Compensation_val = 55;       
    }    
    else if(temp_volt>TEMP_ZONE68_THRESHOLD)
    {
        Compensation_val = 56;       
    }    
    else if(temp_volt>TEMP_ZONE69_THRESHOLD)
    {
        Compensation_val = 57;       
    }    
    else if(temp_volt>TEMP_ZONE70_THRESHOLD)
    {
        Compensation_val = 58;       
    }    
    else if(temp_volt>TEMP_ZONE71_THRESHOLD)
    {
        Compensation_val = 59;       
    }    
    else if(temp_volt>TEMP_ZONE72_THRESHOLD)
    {
        Compensation_val = 60;       
    }    
    else if(temp_volt>TEMP_ZONE73_THRESHOLD)
    {
        Compensation_val = 61;       
    }    
    else if(temp_volt>TEMP_ZONE74_THRESHOLD)
    {
        Compensation_val = 62;       
    }    
    else if(temp_volt>TEMP_ZONE75_THRESHOLD)
    {
        Compensation_val = 63;       
    }    
    else if(temp_volt>TEMP_ZONE76_THRESHOLD)
    {
        Compensation_val = 64;       
    }    
    else if(temp_volt>TEMP_ZONE77_THRESHOLD)
    {
        Compensation_val = 65;       
    }    
    else if(temp_volt>TEMP_ZONE78_THRESHOLD)
    {
        Compensation_val = 66;       
    }    
    else if(temp_volt>TEMP_ZONE79_THRESHOLD)
    {
        Compensation_val = 67;       
    }    
    else if(temp_volt>TEMP_ZONE80_THRESHOLD)
    {
        Compensation_val = 68;       
    }    
    else if(temp_volt>TEMP_ZONE81_THRESHOLD)
    {
        Compensation_val = 69;       
    }    
    else if(temp_volt>TEMP_ZONE82_THRESHOLD)
    {
        Compensation_val = 70;       
    }    
    else if(temp_volt>TEMP_ZONE83_THRESHOLD)
    {
        Compensation_val = 71;       
    }    
    else if(temp_volt>TEMP_ZONE84_THRESHOLD)
    {
        Compensation_val = 72;       
    }    
    else if(temp_volt>TEMP_ZONE85_THRESHOLD)
    {
        Compensation_val = 73;       
    }    
    else if(temp_volt>TEMP_ZONE86_THRESHOLD)
    {
        Compensation_val = 74;       
    }    
    else if(temp_volt>TEMP_ZONE87_THRESHOLD)
    {
        Compensation_val = 75;       
    }    
    else if(temp_volt>TEMP_ZONE88_THRESHOLD)
    {
        Compensation_val = 76;       
    }    
    else if(temp_volt>TEMP_ZONE89_THRESHOLD)
    {
        Compensation_val = 77;       
    }    
    else if(temp_volt>TEMP_ZONE90_THRESHOLD)
    {
        Compensation_val = 78;       
    }    
    else if(temp_volt>TEMP_ZONE91_THRESHOLD)
    {
        Compensation_val = 79;       
    }    
    else if(temp_volt>TEMP_ZONE92_THRESHOLD)
    {
        Compensation_val = 80;       
    }    
    else if(temp_volt>TEMP_ZONE93_THRESHOLD)
    {
        Compensation_val = 81;       
    }    
    else if(temp_volt>TEMP_ZONE94_THRESHOLD)
    {
        Compensation_val = 82;       
    }    
    else if(temp_volt>TEMP_ZONE95_THRESHOLD)
    {
        Compensation_val = 83;       
    }    
    else if(temp_volt>TEMP_ZONE96_THRESHOLD)
    {
        Compensation_val = 84;       
    }    
    else if(temp_volt>TEMP_ZONE97_THRESHOLD)
    {
        Compensation_val = 85;       
    }    
    else if(temp_volt>TEMP_ZONE98_THRESHOLD)
    {
        Compensation_val = 86;       
    }    
    else if(temp_volt>TEMP_ZONE99_THRESHOLD)
    {
        Compensation_val = 87;       
    }    
    else if(temp_volt>TEMP_ZONE100_THRESHOLD)
    {
        Compensation_val = 88;       
    }    
    else if(temp_volt>TEMP_ZONE101_THRESHOLD)
    {
        Compensation_val = 89;       
    }    
    else if(temp_volt>TEMP_ZONE102_THRESHOLD)
    {
        Compensation_val = 90;       
    }    
    else if(temp_volt>TEMP_ZONE103_THRESHOLD)
    {
        Compensation_val = 91;       
    }    
    else if(temp_volt>TEMP_ZONE104_THRESHOLD)
    {
        Compensation_val = 92;       
    }    
    else if(temp_volt>TEMP_ZONE105_THRESHOLD)
    {
        Compensation_val = 93;       
    }    
    else if(temp_volt>TEMP_ZONE106_THRESHOLD)
    {
        Compensation_val = 94;       
    }    
    else if(temp_volt>TEMP_ZONE107_THRESHOLD)
    {
        Compensation_val = 95;       
    }    
    else if(temp_volt>TEMP_ZONE108_THRESHOLD)
    {
        Compensation_val = 96;       
    }    
    else if(temp_volt>TEMP_ZONE109_THRESHOLD)
    {
        Compensation_val = 97;       
    }    
    else if(temp_volt>TEMP_ZONE110_THRESHOLD)
    {
        Compensation_val = 98;       
    }    
    else if(temp_volt>TEMP_ZONE111_THRESHOLD)
    {
        Compensation_val = 99;       
    }    
    else if(temp_volt>TEMP_ZONE112_THRESHOLD)
    {
        Compensation_val = 100;       
    }    
    else if(temp_volt>TEMP_ZONE113_THRESHOLD)
    {
        Compensation_val = 101;       
    }    
    else if(temp_volt>TEMP_ZONE114_THRESHOLD)
    {
        Compensation_val = 102;       
    }    
    else if(temp_volt>TEMP_ZONE115_THRESHOLD)
    {
        Compensation_val = 103;       
    }    
    else if(temp_volt>TEMP_ZONE116_THRESHOLD)
    {
        Compensation_val = 104;       
    }    
    else if(temp_volt>TEMP_ZONE117_THRESHOLD)
    {
        Compensation_val = 105;       
    }    
    else if(temp_volt>TEMP_ZONE118_THRESHOLD)
    {
        Compensation_val = 106;       
    }    
    else if(temp_volt>TEMP_ZONE119_THRESHOLD)
    {
        Compensation_val = 107;       
    }    
    else if(temp_volt>TEMP_ZONE120_THRESHOLD)
    {
        Compensation_val = 108;       
    }    
    else if(temp_volt>TEMP_ZONE121_THRESHOLD)
    {
        Compensation_val = 109;       
    }
    else
    {
        Compensation_val = 110;    
    }

    Temp_Adc_TP = Compensation_val;
    
}

