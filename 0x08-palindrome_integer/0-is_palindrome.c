#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"
/**
* is_palindrome - function that checks if an unsigned long int is palindrome
* @n: the unsigned integer to check
* Return: 1 if n is palindrome, 0 otherwise
*/
int is_palindrome(unsigned long n)
{
  unsigned long int i;
  unsigned long int j;
  if (n == 0)
    return (1);
  i = n % 10;
  j = n;*
    while (j / 10 != 0)
    {
      j = j / 10;
      i = i * 10;
    }
  if (j != n % 10)
    return (0);
  n = (n - i) / 10;
  return (is_palindrome(n));
}
