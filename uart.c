#include "uart.h"
#include <stdint.h>
#include "gpio.h"
#define UART ((NRF_UART_REG*)0x40002000)

typedef struct 
{
	volatile uint32_t STARTRX;
	volatile uint32_t STOPRX;
	volatile uint32_t STARTTX;
	volatile uint32_t STOPTX;
	volatile uint32_t RESERVED[3]; 
	volatile uint32_t SUSPEND;
	volatile uint32_t RESERVED0[56];
	volatile uint32_t CTS;
	volatile uint32_t NCTS;
	volatile uint32_t RXDRDY;
	volatile uint32_t RESERVED1 [4];
	volatile uint32_t TXDRDY;
	volatile uint32_t RESERVED2;
	volatile uint32_t ERROR;
	volatile uint32_t RESERVED3 [7];
	volatile uint32_t RXTO;
	volatile uint32_t RESERVED4 [110];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile uint32_t RESERVED5 [93];
	volatile uint32_t ERRORSRC;
	volatile uint32_t RESERVED6 [31];
	volatile uint32_t ENABLE;
	volatile uint32_t RESERVED7;
	volatile uint32_t PSELRTS;
	volatile uint32_t PSELTXD;
	volatile uint32_t PSELCTS;
	volatile uint32_t PSELRXD;
	volatile uint32_t RXD;
	volatile uint32_t TXD;
	volatile uint32_t RESERVED8;
	volatile uint32_t BAUDRATE;
	volatile uint32_t RESERVED9[17]; 
	volatile uint32_t CONFIG;
} NRF_UART_REG;

void uart_init() 
{
	UART->PSELRXD = (1 << 25);
	UART->PSELRXD = (1 << 24);
	UART->PSELRTS = 0xFFFFFFFF;
	UART->PSELCTS = 0xFFFFFFFF;
	UART->BAUDRATE = 0x00275000;
	UART->ENABLE = (1 << 4);
	UART->STARTRX = (0x1);

}

void uart_send(char letter)
{

	UART->TXD = letter;
	while (!UART->TXDRDY)
	{
		UART->TXDRDY = 0;
	}
}

char uart_read()
{
	UART->RXDRDY = 0; 

	if (!UART->RXD)
	{
		UART->RXDRDY = 1;
		return '\0';
	}

	UART->RXDRDY = 1;
	return UART->RXD; 
}