#include "palindrome.h"

/**
 * is_palindrome - Checks if an int is a palindrome or not
 * @n: Number given to be checked
 *
 * Return: 1 if @n is a palindrome, otherwise 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long rev = 0, rem = 0, num;

	num = n;

	while (n != 0)
	{
		rem = n % 10;
		rev = rev * 10 + rem;
		n /=10;
	}

	if (rev == num)
		return (1);
	return (0);
}
