#include "lists.h"
#include <stdlib.h>
/**
 * free_dlistint - frees a dlistint_t doubly linked list
 * @head: pointer to the head of the list
 *
 * Description: frees all nodes in a dlistint_t list and released memory
*/
void free_dlistint(dlistint_t *head)
{
	dlistint_t *temp;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
