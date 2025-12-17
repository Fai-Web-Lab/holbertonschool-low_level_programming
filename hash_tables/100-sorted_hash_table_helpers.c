#include "hash_tables.h"

/**
 * create_node - Creates a new sorted hash node
 * @key: Key string
 * @value: Value string
 *
 * Return: Pointer to node or NULL
 */
static shash_node_t *create_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (!node)
		return (NULL);

	node->key = strdup(key);
	node->value = strdup(value);
	if (!node->key || !node->value)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;

	return (node);
}

/**
 * insert_sorted - Inserts node into sorted linked list
 * @ht: Pointer to table
 * @node: Node to insert
 */
static void insert_sorted(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *curr;

	if (!ht->shead)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}

	curr = ht->shead;
	while (curr && strcmp(node->key, curr->key) > 0)
		curr = curr->snext;

	if (!curr)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
	}
	else if (!curr->sprev)
	{
		node->snext = curr;
		curr->sprev = node;
		ht->shead = node;
	}
	else
	{
		node->sprev = curr->sprev;
		node->snext = curr;
		curr->sprev->snext = node;
		curr->sprev = node;
	}
}

/**
 * shash_table_set_helper - Handles insertion and update
 * @ht: Table pointer
 * @key: Key
 * @value: Value
 * @index: Index in array
 *
 * Return: Pointer to node or NULL
 */
shash_node_t *shash_table_set_helper(shash_table_t *ht,
				     const char *key,
				     const char *value,
				     unsigned long int index)
{
	shash_node_t *node;

	node = ht->array[index];
	while (node)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = strdup(value);
			return (node);
		}
		node = node->next;
	}

	node = create_node(key, value);
	if (!node)
		return (NULL);

	node->next = ht->array[index];
	ht->array[index] = node;

	insert_sorted(ht, node);

	return (node);
}

/**
 * shash_table_delete - Deletes entire sorted hash table
 * @ht: Pointer to table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;
	unsigned long int i;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			tmp = node->next;
			free(node->key);
			free(node->value);
			free(node);
			node = tmp;
		}
	}

	free(ht->array);
	free(ht);
}
