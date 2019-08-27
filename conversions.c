#include "shell.h"
/**
  * string_to_i - calls functions
  * @s:
  * Description: Function that ...
  * Return: ...
  */
int string_to_int(char *s)
{
	int value = 0;
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
		value = value * 10 + s[i] - '0';
	return (value);
}
/**
  * *counter_to_string - calls functions
  * @i:
  * @to_str:
  * Description: Function that ...
  * Return: ...
  */
char *counter_to_string(int i, char *to_str)
{
	int var;
	int j = 0;

	for (var = 1; var <= 1; var *= 10)
		;
	var /= 10;
	while (var > 0)
	{
		to_str[j] = (i / var + '0');
		i %= var;
		j++;
		var /= 10;
	}
	to_str[j] = '\0';
	return (to_str);
}
