#ifndef SEARCH_H
#define SEARCH_H

#include <stddef.h>

/**
 * struct skiplist_s - Skip list node
 *
 * @n: Integer
 * @index: Index of the node in the list
 * @next: Pointer to the next node
 * @express: Pointer to the next node in the express lane
 *
 * Description: Node of a skip list
 */
typedef struct skiplist_s
{
	int n;
	size_t index;
	struct skiplist_s *next;
	struct skiplist_s *express;
} skiplist_t;

void init_express(skiplist_t *list, size_t size);
void free_skiplist(skiplist_t *list);
void print_skiplist(const skiplist_t *list);
skiplist_t *create_skiplist(int *array, size_t size);
skiplist_t *linear_skip(skiplist_t *list, int value);

#endif /* SEARCH_H */
