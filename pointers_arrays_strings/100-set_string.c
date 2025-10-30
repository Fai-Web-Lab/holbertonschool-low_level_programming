#include "main.h"
/**
 * set_string - sets the value of a pointer to a char
 * @s: pointer to a pointer to a char
 * @to: pointer to the char string to set
*/
void set_string(char **s, char *to)
{
	*s = to;
}
