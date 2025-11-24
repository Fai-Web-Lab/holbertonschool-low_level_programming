#include "lists.h"
#include <stdlib.h>
#include <string.h>
/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to duplicate and store in the new node
 *
 * Return: the address of the new element, or NULL if it failed
*/
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	char *dup;
	int len = 0;

	if (str == NULL)
		return (NULL);

	dup = strdup(str);
	if (dup == NULL)
		return (NULL);

	while (str[len])
		len++;

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
	{
		free(dup);
		return (NULL);
	}

	new_node->str = dup;
	new_node->len = len;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
