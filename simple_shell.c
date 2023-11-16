#include "simple_shell.h"

/**
 * main - Entry point
 * @argc: the number of arguments passed
 * @argv: the arguments passed
 * Return: an integer value
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	data_of_inputs data_shell;

	signal(SIGINT, ctrl_c_handler);

	init_data(&data_shell, argv);

	continue_prompt(&data_shell);

	to_be_freed(&data_shell);

	if (data_shell.input_status < 0)
	{
		return (255);
	}

	return (data_shell.input_status);
}
