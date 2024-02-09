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
	int index_start, index_end, i, j, value_start, value_end;

	current = *head;
	index_start = 0;
	index_end = 0;

	while (current->next != NULL)
	{
		current = current->next;
		index_end += 1;
	}

	while (index_start <= index_end)
	{
		current = *head;
		for (i = 0; i < index_start; i++)
			current = current->next;
		value_start = current->n;
		index_start += 1;

		current = *head;
		for (j = 0; j < index_end; j++)
			current = current->next;
		value_end = current->n;
		index_end -= 1;

		if (value_start != value_end)
			return (0);
	}
	return (1);
}
