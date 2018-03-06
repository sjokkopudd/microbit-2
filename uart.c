#include "uart.h"
#include <stdint.h>
#include "gpio.h"
#define UART ((NRF_UART_REG*)0x40002000)

typedef struct {
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


}NRF_UART_REG

void uart_init() 
{
	UART->BAUDRATE = 0x00275000;
	UART->ENABLE&(0x1);
	UART->STARTRX&(0x1);

}