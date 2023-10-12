#include "main.h"

/**
 * _strdup - to copy a string from one place to another
 * @str: the array
 * Return: pointer of sting copied
 */
char *_strdup(char *str)
{
  int a, b;
  char *s = NULL;

  if (str == NULL)
    return (0);
  for (a = 0; str[a]; a++)
    ;
  a++;
  s = malloc(a * sizeof(char *));
  if (!s)
    return (NULL);
  for (b = 0; b < a; b++)
    {
      s[b] = str[b];
    }
  return (s);
}

/**
 * _itoa - to convert integer to ascii
 * @num: num
 * @base: base
 * Return: char
 **/
char *_itoa(int num, int base)
{
  static char *array = "0123456789abcdef";
  static char buffer[50];
  char sign = 0;
  char *ptr;
  unsigned long n = num;

  if (num < 0)
    {
      n = -num;
      sign = '-';
    }
  ptr = &buffer[49];
  *ptr = '\0';

  do      {
    *--ptr = array[n % base];
    n /= base;
  } while (n != 0);

  if (sign)
    *--ptr = sign;
  return (ptr);
}
