#include "main.h"

/**
 * rot13 - a function that encodes a string using rot13
 * @s: the character to be encoded in a string
 * Return: p
 */

char *rot13(char *s)
{
	char *p = s;
	int i, j;
	char *rot13_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *rot13_nums = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; *(s + i) != '\0'; i++)
	{
	for (j = 0; j < 52; j++)
	{
	if (*(s + i) == *(rot13_chars + j))
	{
	*(p + i) = *(rot13_nums + j);
	break;
	}
	}
	}
	return (p);
}
