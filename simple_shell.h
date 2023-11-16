#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define TOKEN_DELIM " \t\n\a\r"

extern char **environ;

/**
 * struct data_of_inputs_s - a struct that contain all the info
 * @argv: argv
 * @input: the user input
 * @arguments: the arguments in the shell
 * @input_status: delcare the status
 * @count: a counter
 * @my_environ: envrionment
 * @PID: process ID
 */
typedef struct data_of_inputs_s
{
	char **argv;
	char *input;
	char **arguments;
	int input_status;
	int count;
	char **my_environ;
	char *PID;
} data_of_inputs;

/**
 * struct cmd_line_list_sh - storing command lines
 * @cmd_line: the command line in the struct
 * @next: the next node at the struct
 */
typedef struct cmd_line_list_sh
{
	char *cmd_line;
	struct cmd_line_list_sh *next;
} cmd_line_list;

/**
 * struct var_node_s - single linked list node for variables
 * @var_length: length of the variable
 * @value: the variable value
 * @value_length: the value length
 * @next: a pointer to the next node
 * Description: a single linked list node to store variables
 */
typedef struct var_node_s
{
	int var_length;
	char *value;
	int value_length;
	struct var_node_s *next;
} var_node;

/* The prototype of the functions */
char *strncpy_(char *destination, char *source, int n);
void ctrl_c_handler(int ctrl __attribute__((unused)));
char *strdup_(char *string);
int strlen_(char *string);
void continue_prompt(data_of_inputs *data_shell);
char *strchr_(char *string, int c);
char *int_to_str(int num);
char *input_line(int *EOF_status);
char *strcpy_(char *destination, char *source);
char *strcat_(char *destination, char *source);
char *remove_comments(char *input);
var_node *add_var_node(var_node **h, int var_len, char *value, int value_len);
void to_be_freed(data_of_inputs *data_shell);
char *input_to_value(var_node **h, char *o_str, char *mod_s, int mod_str_len);
void free_variable_list(var_node **h);
void init_data(data_of_inputs *data_shell, char **argv);
void *memcpy_(char *destination, char *source, size_t n);
void env_checker(var_node **head, char *input_str, data_of_inputs *data_shell);
char *var_to_value(char *input_str, data_of_inputs *data_shell);
int var_checker(var_node **h, char *s, char *last_stat, data_of_inputs *info);
int cal_length(int num);
int find_non_whitespace_char(char *user_input, int *counter);
void error_printer(data_of_inputs *data_shell, char *u_input, int c, int flag);

#endif
