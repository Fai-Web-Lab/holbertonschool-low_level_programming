#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * free_list - frees a list_t list
 * @head: pointer to the head of the list
 *
 * Description: frees each node's string and the node itself
*/
void free_list(list_t *head)
{
	list_t *tmp;

	while (head != NULL)
	{
		tmp = head->next;
		free(head->str);
		free(head);
		head = tmp;
	}
}
