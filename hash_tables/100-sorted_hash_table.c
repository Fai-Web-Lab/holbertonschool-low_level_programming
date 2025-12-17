#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table
 * @size: Size of the array
 *
 * Return: Pointer to table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;

	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds or updates a key/value in sorted hash table
 * @ht: Pointer to table
 * @key: Key
 * @value: Value
 *
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *node;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	node = shash_table_set_helper(ht, key, value, index);
	if (!node)
		return (0);

	return (1);
}

/**
 * shash_table_get - Gets value associated with a key
 * @ht: Pointer to table
 * @key: Key
 *
 * Return: Value string, or NULL if not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;

	if (!ht || !key)
		return (NULL);

	node = ht->shead;
	while (node)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
		node = node->snext;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints sorted hash table in ascending order
 * @ht: Pointer to table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (!ht)
		return;

	printf("{");
	node = ht->shead;
	while (node)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		first = 0;
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints sorted hash table in descending order
 * @ht: Pointer to table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int first = 1;

	if (!ht)
		return;

	printf("{");
	node = ht->stail;
	while (node)
	{
		if (!first)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		first = 0;
		node = node->sprev;
	}
	printf("}\n");
}
