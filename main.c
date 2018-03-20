#include "uart.h"
#include <stdio.h>
#include "gpio.h"

int main()
{
	uart_init();

	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;

	while(1)
	{
		if (!(GPIO->IN&(1 << 17)))
		{
			uart_send('A');
		}

		else if (!(GPIO->IN&(1 << 26)))
		{
			uart_send('B');
		}
	}

	return 1;
}