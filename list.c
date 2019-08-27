#include "shell.h"

/**
  * build_linked_list - Calls function
  * @path: ...
  * @head: ...
  * Description: ...
  * Return: ...
  */
void build_linked_list(char *path, list_t **head)
{
	char *token;

	token = strtok(path, ":");
	while (token)
	{
		add_node_end(head, token);
		token = strtok(NULL, ":");
	}
}

/**
  * free_list - Calls function
  * @head: ...
  * Description: ...
  * Return: ...
  */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		free(temp->str);
		head= head->next;
		free(temp);
	}
}

/**
  * *add_node_end - Calls function
  * @head: ...
  * @str: ...
  * Description: ...
  * Return: ...
  */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new, *i;

	new = malloc(sizeof(list_t));

	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		for (i = *head; i->next != NULL; i = i->next)
			;
		i->next = new;
	}
	return (new);
}
