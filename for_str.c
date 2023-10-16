#include "main.h"

/**
 *_puts - to print a string
 *@str: A pointer to an int that will be updated
 *
 *Return: void
 */

void _puts(char *str)
{
	int a;

	for (a = 0 ; str[a] != '\0' ; a++)
	{
		_putchar(str[a]);
	}
	_putchar('\n');
}

/**
 * _strlen - returns a string
 * @s: integer to be used
 * Return: length of string
 */

int _strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return ((i + 1));
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *str_concat - to turn back a pointer to array
 *@c1: Array one
 *@c2: Array two
 *Return: Always an array dinamic
 */

char *str_concat(char *c1, char *c2)
{
	char *loc;
	unsigned int i, j, size;

	/*If the array is empty*/
	if (c1 == NULL)
	c1 = "";

	if (c2 == NULL)
	c2 = "";

	/*count size total*/
	size = (_strlen(c1) + _strlen(c2) + 1);

	/*malloc*/
	loc = (char *) malloc(size * sizeof(char));

	if (loc == 0)
	{
		return (NULL);
	}

	/*Concatenate arrays*/
	for (i = 0; *(c1 + i) != '\0'; i++)
	*(loc + i) = *(c1 + i);

	for (j = 0; *(c2 + j) != '\0'; j++)
	{
		*(loc + i) = *(c2 + j);
		i++;
	}
	loc[i] = '\0';

	return (loc);
}

/**
 * _strcmp - to compare two strings
 * @c1: string one
 * @c2: string two
 *
 * Return: returns an integer less  than,  equal  to,  or
 * greater  than zero if s1 is found, respectively, to be
 * less than, to match, or be greater than s2.
 */

int _strcmp(char *c1, char *c2)
{
	char *n1 = c1;
	char *n2 = c2;

	while (*n1 != '\0' && *n2 != '\0' && *n1 == *n2)
	{
		n1++;
		n2++;
	}
	return (*n1 - *n2);
}
