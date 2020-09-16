#include "palindrome.h"
/**
 * is_palindrome - Check for palindrome
 * @n: int to check
 * Return: 1 if palindrome exists, 0 if not
 */
int is_palindrome(unsigned long n)
{
	unsigned long i = 0, c = n;

	while (c > 0)
	{
		i = i * 10 + c % 10;
		c /= 10;
	}

	return (n == i);
}