#include "main.h"
#include <stdlib.h>
/**
 * _calloc - allocates memory for an array using malloc
 * @nmemb: number of elements
 * @size: size of each element in bytes
 *
 * Description: Allocates memory for an array of nmemb elements of size bytes
 * each, and sets the memory to zero. Returns NULL if nmemb or size is 0,
 * or if malloc fails.
 *
 * Return: pointer to allocated memory, or NULL on failure
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i;
	unsigned int total;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total = nmemb * size;

	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		ptr[i] = 0;

	return (ptr);
}
