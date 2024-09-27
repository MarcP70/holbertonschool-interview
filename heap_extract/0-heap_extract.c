#include <stdlib.h>
#include "binary_trees.h"


/**
 * heapify_down - Restores the max heap property from the top down
 * @node: The current node being heapified
 */
void heapify_down(heap_t *node)
{
	heap_t *largest = node;
	heap_t *left = node->left;
	heap_t *right = node->right;

	if (left && left->n > largest->n)
		largest = left;

	if (right && right->n > largest->n)
		largest = right;

	if (largest != node)
	{
		int temp = node->n;

		node->n = largest->n;
		largest->n = temp;
		heapify_down(largest);
	}
}

/**
 * get_last_node - Retrieves the last node in level order traversal
 * @root: Pointer to the root of the heap
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *last_node = NULL;
	size_t queue_size = 1024;
	heap_t **queue = malloc(sizeof(heap_t *) * queue_size);
	size_t front = 0, rear = 0;

	if (!queue || !root)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		heap_t *current = queue[front++];

		last_node = current;

		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}

	free(queue);
	return (last_node);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 *
 * Return: Value stored in the root node
 */
int heap_extract(heap_t **root)
{
	heap_t *last_node, *parent;
	int value;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	/* If there's only one node, free it and return the value */
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	last_node = get_last_node(*root);

	if (last_node)
	{
		/* Swap values with the last node */
		(*root)->n = last_node->n;
		parent = last_node->parent;

		/* Remove the last node */
		if (parent->right == last_node)
			parent->right = NULL;
		else
			parent->left = NULL;

		free(last_node);
	}

	/* Restore the heap property */
	heapify_down(*root);

	return (value);
}
