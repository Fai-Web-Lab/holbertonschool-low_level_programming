#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - Retrieves a value associated with a key in a hash table
 * @ht: Pointer to the hash table
 * @key: Key to look for
 * Return: Value associated with the key, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
    unsigned long int idx;
    hash_node_t *tmp;

    if (!ht || !key || !*key)
        return NULL;

    idx = key_index((unsigned char *)key, ht->size);
    tmp = ht->array[idx];

    while (tmp)
    {
        if (strcmp(tmp->key, key) == 0)
            return tmp->value;
        tmp = tmp->next;
    }

    return NULL;
}
