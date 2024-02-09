#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int index_start, index_end, i, value_start, value_end;

	current = *head;
	index_start = 0;
	index_end = 0;

	if (*head == NULL)
		return (1);

	while (current->next != NULL)
	{
		current = current->next;
		index_end += 1;
	}

	while (index_start < index_end)
	{
		current = *head;
		for (i = 0; i < index_end; i++)
		{
			if (i == index_start)
				value_start = current->n;

			current = current->next;
			value_end = current->n;
		}
		printf("index_start: %i\n", index_start);
		printf("value_start: %i\n", value_start);
		printf("index_end: %i\n", index_end);
		printf("value_end: %i\n", value_end);
		index_start += 1;
		index_end -= 1;

		if (value_start != value_end)
			return (0);
	}
	return (1);
}
