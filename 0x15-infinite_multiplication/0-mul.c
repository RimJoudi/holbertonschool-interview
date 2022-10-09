#include "holberton.h"

/**
 * is_digit - checks if the argument is a number
 * @c: argument
 * Return: 0 on success, otherwise 1
 **/
int is_digit(char *c)
{
	while (*c)
	{
		if (*c < '0' || *c > '9')
			return (0);
		c++;
	}
	return (1);
}

/**
 * _strlen - find the length of the a string
 * @s: a string
 * Return: the length of the string
 **/
int _strlen(char *s)
{
	char *ptr = s;

	while (*s)
		s++;
	return (s - ptr);
}

/**
 * multiply - multiplies two numbers
 * @a: first number
 * @b: second number
 * Return: Nothing
 **/
void multiply(char *a, char *b)
{
	int i, len_a, len_b, total, a_number, b_number, res = 0, tmp;
	int *ptr;

	len_a = _strlen(a);
	len_b = _strlen(b);
	tmp = len_b;
	total = len_a + len_b;
	ptr = malloc(sizeof(int) * total);
	if (!ptr)
		return;
	for (len_a--; len_a >= 0; len_a--)
	{
		a_number = a[len_a] - '0';
		res = 0;
		len_b = tmp;
		for (len_b--; len_b >= 0; len_b--)
		{
			b_number = b[len_b] - '0';
			res += ptr[len_b + len_a + 1] + (a_number * b_number);
			ptr[len_a + len_b + 1] = res % 10;
			res /= 10;
		}
		if (res)
			ptr[len_a + len_b + 1] = res % 10;
	}
	while (*ptr == 0)
	{
		ptr++;
		total--;
	}
	for (i = 0; i < total; i++)
		printf("%i", ptr[i]);
	printf("\n");
}

/**
 * main - Entry point, program that multiplies two positive numbers
 * @argc: argument count
 * @argv: argument values
 * Return: 0 on success
 **/
int main(int argc, char *argv[])
{
	char *num1 = argv[1];
	char *num2 = argv[2];

	if (argc != 3 || !is_digit(num1) || !is_digit(num2))
	{
		printf("Error\n");
		exit(98);
	}
	multiply(num1, num2);
	return (0);
}
