#include "main.h"
/**
 * _strcat - concatenates the string src to the end of dest
 * @dest: destination string
 * @src: source string to append
 *
 * Return: pointer to the resulting string dest
*/
char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}
