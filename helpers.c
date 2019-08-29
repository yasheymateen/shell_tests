#include "shell.h"

/**
 * word_counter - Calls Function
 * @str: ...
 * Description: ...
 * Return: ...
 */
int word_counter(char *str)
{
	int i, count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}
	return (count);
}

/**
 * command_prompt - Calls function
 * Description: Function that prints command prompt
 * Return: 0
 */
void command_prompt()
{
	signal(SIGINT, signal_control);
	if (isatty(0) == 1)
		write(STDOUT_FILENO, "$ ", 2);
}

