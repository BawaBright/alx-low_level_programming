#include "main.h"

/**
 * print_number - Print the numbers since 0 up to 9
 * Return: The numbers since 0 up to 9
 */

void print_number(void)
{
	int a;

	for (a = 0; a <= 9; a++)
	{
	_putchar(a + '0');
	}
	_putchar('\n');
}
