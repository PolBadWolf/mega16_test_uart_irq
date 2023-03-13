/*
 * Uart.h
 *
 * Created: 13.03.2023 21:28:11
 *  Author: User
 */ 


#ifndef UART_H_
#define UART_H_

#include "IncFile1.h"

void UART_SendData(uint8_t *pSendData, uint8_t nNumOfDataToSend);

void UART_ReceiveData(uint8_t* pReceivedData, uint8_t nNumOfDataToReceive);

void UART_Init();


#endif /* UART_H_ */