#include <stdio.h>
/**
 * main - main function
 * Return:0 always (Success)
 */
int main(void)
{
	int i = 0;
	int j;
	int k;

	int a;
	int b;
	int c;

	for (i <= 98;)
	{
		j = (i / 10 + '0');
		k = (i % 10 + '0');
		a = 0;
		for (a <= 99;)
		{
			b = (a / 10 + '0');
			c = (a % 10 + '0');

			if (i < a)
			{
				putchar(j);
				putchar(k);
				putchar(' ');
				putchar(b);
				putchar(c);

				if (i != 98)
				{
					putchar(',');
					putchar(' ');
				}
			}
			a++;
		}
		i++;
	}
	putchar('\n');
	return (0);
}
