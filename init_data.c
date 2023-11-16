#include "simple_shell.h"

/**
 * init_data - initializes a data structure with command-line arguments,
 * environment variables, and process information
 * @data_shell: a data struct stores various information related
 * to a shell program
 * @argv: arguments value
 */
void init_data(data_of_inputs *data_shell, char **argv)
{
	unsigned int a = 0;

	(*data_shell).argv = argv;
	(*data_shell).input = NULL;
	(*data_shell).arguments = NULL;
	(*data_shell).input_status = 0;
	(*data_shell).count = 1;

	while (environ[a])
		a++;

	(*data_shell).my_environ = malloc(sizeof(char *) * (a + 1));

	while (environ[a])
	{
		(*data_shell).my_environ[a] = strdup_(environ[a]);
		a++;
	}

	(*data_shell).my_environ[a] = NULL;
	(*data_shell).PID = int_to_str(getpid());
}
