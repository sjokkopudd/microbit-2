#include "uart.h"
#include <stdio.h>
#include "gpio.h"

int main()
{
	uart_init();

	for(int i = 4; i <= 15; i++)
	{
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	}

	GPIO->PIN_CNF[17] = 0;
	GPIO->PIN_CNF[26] = 0;

	
	/*while(1)
	{
		if (!(GPIO->IN&(1 << 17)))
		{
			uart_send('A');
			while (!(GPIO->IN&(1 << 17)));
		}

		else if (!(GPIO->IN&(1 << 26)))
		{
			uart_send('B');
			while (!(GPIO->IN&(1 << 26)));
		}
	}*/
	iprintf("Norge har %d fylker. \n\r", 18);

	while(1)
	{
		char temp = uart_read();
		//char temp = 'a';

		//uart_send('A');

		if (temp == '\0')
		{
			//uart_send('X');
		}

		else
		{
			if (!(GPIO->IN&(1 << 15)))
			{
				for (int high = 13; high < 16; high++)
		 		{
		 			GPIO->OUTSET = (1 << high);
				}

		 		for (int low = 4; low < 13; low++)
			 	{
		 			GPIO->OUTCLR = (1 << low);
		 		}
			}

			else
			{
				for (int high = 13; high < 16; high++)
		 		{
		 			GPIO->OUTCLR = (1 << high);
				}

		 		for (int low = 4; low < 13; low++)
			 	{
		 			GPIO->OUTSET = (1 << low);
		 		}
			}
		}

	}

	return 1;
}

ssize_t _write(int fd, const void *buf, size_t count)
	{
		char * letter = (char *)(buf);
		for (int i = 0; i < count; i++)
		{
			uart_send(*letter);
			letter++;
		}
		return count;
	}
