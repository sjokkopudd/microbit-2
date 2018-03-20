#include "uart.h"
#include <stdio.h>
#include "gpio.h"

int main()
{
	uart_init();

	while(1)
	{
		if (GPIO->PIN_CNF[17])
		{
			uart_send('A');
		}

		else if (GPIO->PIN_CNF[26])
		{
			uart_send('B');
		}
	}

	return 1;
}