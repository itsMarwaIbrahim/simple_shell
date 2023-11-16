#include "simple_shell.h"

/**
 * int_to_str - converts numbers to string
 * @num: the number to be passed to the function
 * Return: the result string or  NULL (ON FAILURE)
 */
char *int_to_str(int num)
{
	unsigned int abs_number;
	int length = cal_length(num);
	char *result_str;

	result_str = malloc(sizeof(char) * (length + 1));
	if (result_str == NULL)
		return (NULL);

	*(result_str + length) = '\0';

	if (num < 0)
	{
		abs_number = num * -1;
		result_str[0] = '-';
	}
	else
		abs_number = num;

	length--;
	while (abs_number > 0)
	{
		*(result_str + length) = (abs_number % 10) + 48;
		abs_number = abs_number / 10;
		length--;
	}

	return (result_str);
}
