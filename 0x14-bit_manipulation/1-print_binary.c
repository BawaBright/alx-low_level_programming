#include "main.h"
/**
 * print_binary -  prints the binary representation of a number.
 * @n: number to be printed in binary
 */
void print_binary(unsigned long int n)
{
	int i, count = 0;
	unsigned long int recent;

	for (i = 63; i >= 0; i--)
	{
		recent = n >> i;

		if (recent & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');
}
