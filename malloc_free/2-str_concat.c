#include "main.h"
#include <stdlib.h>
/**
 * str_concat - concatenates two strings
 * @s1: 1st string
 * @s2: 2nd string
 *
 * description: allocates memory and returns a pointer to a new string
 * containing the contents of s1 followed by s2. If NULL is passeed,
 * it is treated as an empty string.
 *
 * Return: pointer to concatenated string, ot NULL on failure
*/
char *str_concat(char *s1, *s2)
{
	char *concat;
	unsigned int i;
	unsigned int j;
	unsigned int len1 = 0;
	unsigned int len2 = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;
	concat = malloc(sizeof(char) * (len1 + len2 + 1));
	if (concat == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		concat[i] = s1[i];
	for (j = 0; j < len2; j++)
		concat[i + j] = s2[j];
	concat[i + j] = '\0';
	return (concat);
}
