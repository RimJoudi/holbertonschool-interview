#include "holberton.h"
/**
 * main - Take in two numbers and attempt to
 *        multiply them
 * @argc: an int count of arguments
 * @argv: an array of arguments
 * Return: 0
 */

int main(int argc, char **argv)
{

	int num1_len, num2_len;
	long int num1, num2;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	if ((argv[1] - '0') == 0 || (argv[2] - '0') == 0)
	{
		printf("0\n");
		printf("0\n");
		exit(0);
	}

	if ((_isdigit(argv[1]) == 0) && (_isdigit(argv[2]) == 0))
	{
	num1_len = _strlen(argv[1]);
	num2_len = _strlen(argv[2]);
	}

	if ((num1_len + num2_len) < 10)
	{
		num1 = _atoi(argv[1], num1_len);
		num2 = _atoi(argv[2], num2_len);
		printf("%ld\n", num1 * num2);
	}

	return (0);
}


/**
 * _strlen - checks the length of the string
 * @string: a string of digits, hopefully
 * Return: the clength of the string
 */
int _strlen(char *string)
{
	int i = 0;

	while (string[i] != '\0')
	{
		i++;
	}
	return (i - 1);
}

/**
 * _isdigit - make sure all chars in a string are numeric
 * @string: a string of chars
 * Return: 0 if all digits
 */
int _isdigit(char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if ((string[i] < 48) || (string[i] > 57))
		{
			printf("Error\n");
			exit(98);
		} else
		{
			continue;
		}
	}
	return (0);
}

/**
 * _atoi - convert a string to a number
 * @string: a string of chars
 * @len: length of the string
 * Return: a number 
 */
long int _atoi(char *string, int len)
{
	long int num = 0;
	int i;

	for (i = 0; i <= len; i++)
	{
		num = (num * 10) + (string[i] - '0');
	}
	return (num);
}
