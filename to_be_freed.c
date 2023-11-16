#include "simple_shell.h"

/**
 * to_be_freed - free the memory
 * @data_shell: a struct of the shell program
 */
void to_be_freed(data_of_inputs *data_shell)
{
	unsigned int counter = 0;

	while ((*data_shell).my_environ[counter])
	{
		free((*data_shell).my_environ[counter]);
		counter++;
	}
	free((*data_shell).my_environ);
	free((*data_shell).PID);
}
