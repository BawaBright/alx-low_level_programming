#include "main.h"
#include <stdio.h>

/**
 * main - main function
 * print_number: function that prints an integer
 * @n: integer to be printed
 * Return: 0
 */

#include <stdio.h>

void print_number(int n)
{
	if (n == 0)
	{
	_putchar('0');
	return;
	}
	if (n < 0)
	{
	_putchar('-');
	n = -n;
	}

	int digits = 0;
	int divisor = 1;

	while (divisor <= n / 10)
	{
	divisor *= 10;
	digits++;
	}
	while (digits >= 0)
	{

	int digit = n / divisor;

	_putchar(digit + '0');
	n -= digit * divisor;
	divisor /= 10;
	digits--;
	}
	_putchar('\n');
}

int main(void)
{
	print_number(98);
	print_number(402);
	print_number(1024);
	print_number(0);
	print_number(-98);
	return (0);
}
