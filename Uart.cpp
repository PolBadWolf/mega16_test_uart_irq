/*
 * Uart.cpp
 *
 * Created: 13.03.2023 21:27:12
 *  Author: User
 */ 

#include "Uart.h"

bool readyToExchange;

unsigned char numOfDataToSend;
unsigned char *sendDataPtr;
unsigned char numOfDataSended;

unsigned char numOfDataToReceive;
unsigned char *receivedDataPtr;
unsigned char numOfDataReceived;


void UART_SendData(uint8_t *pSendData, uint8_t nNumOfDataToSend)
{
	sendDataPtr = pSendData;
	numOfDataToSend = nNumOfDataToSend;
	numOfDataSended = 0;
	readyToExchange = false;
	UCSRB |= (1 << UDRIE) | (1 << TXEN);
}

void UART_ReceiveData(uint8_t* pReceivedData, uint8_t nNumOfDataToReceive)
{
	receivedDataPtr = pReceivedData;
	numOfDataToReceive = nNumOfDataToReceive;
	numOfDataReceived = 0;
	readyToExchange = false;
	UCSRB |= (1 << RXCIE) | (1 << RXEN);
}

void UART_Init(uint8_t speed)
{
	uint16_t ubb = F_CPU / (16 * speed);
	UBRRH = (ubb >> 8) & 0xff;
	UBRRL = ubb & 0xff;
}