#include "main.h"

/**
 * *leet -  a function that encodes a string into 1337.
 * @n: The character to encode the string.
 * Return: n value
 */

char *leet(char *n)
{
	char s1[] = "AaEeOoTtLl";
	char s2[] = "4433007711";
	int i, j;

	for (i = 0; n[i] != '\0'; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (n[i] == s1[j])
			{
				n[j] = s2[j];
			}
		}
	}
	return (n);
}
