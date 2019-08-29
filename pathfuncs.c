#include "shell.h"

/**
  * print_env - Calls function
  * @args: ...
  * @env: ...
  * @path_list: ...
  * @hist_list: ...
  * Description: ...
  * Return: ...
*/

void print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDIN_FILENO, environ[i], _strlen(environ[i]));
		write(STDIN_FILENO, "\n", 1);
		i++;
	}
}


/**
  * search_path - Calls function
  * @head: ...
  * @c: ...
  * @av: ...
  * @to_string: ...
  * Description:
  * Return: ...
  */
char *search_path(list_t *head, char *c, char **av, char *to_str)
{
	list_t *node;
	char *full_command;
	char *command = str_concat("/", c);
	(void) av;
	(void) to_str;

	for (node = head; node != NULL; node = node->next)
	{
		full_command = str_concat(node->str, command);

		if (access(full_command, X_OK) == 0)
		{
			return (full_command);
		}
		free(full_command);
	}
	free(command);
	return (NULL);
}

/**
  * *_strstr -  Calls function
  * @haystack: ...
  * @needle: ...
  * Description: ...
  * Return: ...
  */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *beg = haystack;
		char *occur = needle;

		while (*occur == *haystack && *occur != '\0' && *haystack != '\0')
		{
			haystack++;
			occur++;
		}
		if (*occur == '\0')
			return (beg);
		haystack = beg + 1;
	}
	return (0);
}

/**
  * char_check - Calls function
  * @s: ...
  * @in: ...
  * Description: ...
  * Return: ...
  */
int char_check(char *s, const char *in)
{
	int i;

	i = 0;
	while (*(s + i) == *(in + i) && *(s + i) != '\0' && *(in + i) != '\0')
		++i;
	if (*(in + i) == '\0')
		return (1);

	return (0);
}

/**
  * _getenv - Calls function
  * @name: name to search for
  * Description: Function that gets an environmental variable
  * Return: value of variable
  */
char *_getenv(const char *name)
{
	int i;
	char *token = NULL;

	for (i = 0; environ[i]; i++)
	{
		if (_strstr(environ[i], (char *)name))
		{
			token = strtok(environ[i], "=");
			token = strtok(NULL, "=");
		}
	}
	return (token);
}
