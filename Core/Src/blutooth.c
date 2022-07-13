#include "blutooth.h"
#include <stdio.h>
#include <string.h>

uint8 Blutooth_Tx_Data[100];
uint8 Blutooth_Rx_Data[100];

void Blutooth_Init(void)
{
    sprintf(Blutooth_Tx_Data,"Hello, Blutooth Connection Complete");
    HAL_UART_Transmit(&BLUTOOTH_MODULE, Blutooth_Tx_Data, strlen(Blutooth_Tx_Data), 100);    
    HAL_UART_Receive_IT(&BLUTOOTH_MODULE,&Blutooth_Rx_Data,1);
}

void Blutooth_Communication(void)
{

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if(huart->Instance == USART1)
    {
        if(((Blutooth_Rx_Data[0] >= '0')&&(Blutooth_Rx_Data[0] <= '9'))||
           ((Blutooth_Rx_Data[0] >= 'a')&&(Blutooth_Rx_Data[0] <= 'z'))||
           ((Blutooth_Rx_Data[0] >= 'A')&&(Blutooth_Rx_Data[0] <= 'Z')))
        {
            sprintf(Blutooth_Tx_Data,"Receive Menu information is : ");
            HAL_UART_Transmit(&BLUTOOTH_MODULE,Blutooth_Tx_Data,strlen(Blutooth_Tx_Data), 100);
            HAL_UART_Transmit(&BLUTOOTH_MODULE,&Blutooth_Rx_Data,1, 100);
            sprintf(Blutooth_Tx_Data,"\n\n");
            HAL_UART_Transmit(&BLUTOOTH_MODULE,Blutooth_Tx_Data,strlen(Blutooth_Tx_Data), 100);
        }

        HAL_UART_Receive_IT(&BLUTOOTH_MODULE,&Blutooth_Rx_Data,1);
    }
    return;
}