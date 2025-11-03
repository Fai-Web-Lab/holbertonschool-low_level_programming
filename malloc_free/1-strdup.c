#include "main.h"
#include <stdlib.h>
/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 *
 * Description: returns a pointer to an allocated space in memory,
 * which contains a copy of the string given as a parameter
 *
 * Return: pointer to duplicated string, or NULL if str = NULL or malloc fails
*/
char *_strdup(char *str)
{
	char *dup;
	unsigned int i;
	unsigned int len = 0;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[len] = '\0';
	return (dup);
}
