#include "simple_shell.h"

/**
 * error_printer - print error note for some symbols
 * @data_shell: contains the data
 * @u_input: represent the input string
 * @c: an integer
 * @flag: boolean flag to indicate a condition
 */
void error_printer(data_of_inputs *data_shell, char *u_input, int c, int flag)
{
	int len;
	char *symbols_note, *error_note, *error_note2;
	char *err, *iterate;

	if ('&' == u_input[counter])
	{
		if ('&' == u_input[c + 1])
			symbols_note = "&&";
		else
			symbols_note = "&";
	}

	if ('|' == u_input[c])
	{
		if ('|' == u_input[c + 1])
			symbols_note = "||";
		else
			symbols_note = "|";
	}

	if (';' == u_input[c])
	{
		if (flag == 0)
		{
			if (';' == u_input[c + 1])
				symbols_note = ";;";
			else
				symbols_note = ";";
		}
	}
	else
	{
		if (';' == u_input[c - 1])
			symbols_note = ";;";
		else
			symbols_note = ";";
	}

	error_note = ": error: \"";
	error_note2 = "\" unpredicted\n";
	iterate = int_to_str((*data_shell).count);

	len = strlen_((*data_shell).argv[0]) + strlen_(iterate);

	len += strlen_(symbols_note) + strlen_(error_note) + strlen_(error_note2) + 2;

	err = (char *)malloc(len + 1);
	if (err == 0)
	{
		free(iterate);
		return;
	}

	/* string copy */
	strcpy_(err, (*data_shell).argv[0]);

	/* cat the string 1 */
	strcat_(err, ": ");
	strcat_(err, iterate);

	/* error note */
	strcat_(err, error_note);
	strcat_(err, symbols_note);
	strcat_(err, error_note2);

	/* null character */
	strcat_(err, "\0");

	write(STDERR_FILENO, err, len);
	free(err);
	free(iterate);
}
