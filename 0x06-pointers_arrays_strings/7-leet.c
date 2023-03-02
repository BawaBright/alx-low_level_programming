#include "main.h"

/**
 * *leet -  a function that encodes a string into 1337.
 * @s: The character to encode the string.
 * Return: A string to be encoded 
 */

char *leet(char *s)
{
	char *p = s;
	char *leet_chars = "AaEeOoTtLl";
	char *leet_nums = "44330771";
	int i, j;

	for (i = 0; *(s + i) != '\0'; i++)
	{
	for (j = 0; j < 10; j++)
	{
	if (*(s + i) == *(leet_chars + j))
	{
	*(p + i) = *(leet_nums + j);
	break;
	}
	}
	}
	return (p);
}
