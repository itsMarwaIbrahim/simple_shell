#include "simple_shell.h"

/**
 * cal_length - calculates the length of a number
 * @num: the inputted integer number
 * Return: the length of the input number
 */
int cal_length(int num)
{
	unsigned int abs_number;
	int len = 1;

	if (num < 0)
	{
		len++;
		abs_number = num * -1;
	}
	else
		abs_number = num;

	while (abs_number > 9)
	{
		len++;
		abs_number = abs_number / 10;
	}

	return (len);
}
