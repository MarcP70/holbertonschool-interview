#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list to search in.
 * @value: The value to search for.
 *
 * Return: Pointer to the first node where value is located,
 * or NULL if value is not present in list or if head is NULL.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = NULL, *prev = NULL;

	if (list == NULL)
		return (NULL);

	current = list->express;
	prev = list;

	while (current)
	{
		printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
		if (current->n >= value || current->express == NULL)
		{
			if (current->n >= value)
				printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, current->index);
			else
				printf("Value found between indexes [%lu] and [%lu]\n",
			current->index, current->express->index);

			while (prev && prev->index <= current->index)
			{
				printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
				if (prev->n == value)
					return (prev);
				if (prev->next == NULL)
					break;
				prev = prev->next;
			}
			break;
		}
		prev = current;
		if (current->express != NULL)
			current = current->express;
		else
			current = current->next;
	}

	return (NULL);
}
