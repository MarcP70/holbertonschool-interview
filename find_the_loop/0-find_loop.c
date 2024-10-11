#include "lists.h"

/**
 * find_listint_loop - Finds the loop in a linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Return: The address of the node where the loop starts, or NULL if no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head;
	listint_t *fast = head;

	if (!head)
		return (NULL);

	/* Step 1: Use the tortoise and hare approach to detect a loop */
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		/* If slow and fast meet, there is a loop */
		if (slow == fast)
		{
			/* Step 2: Find the start of the loop */
			slow = head;  /* Move slow pointer back to head */
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);  /* The start of the loop */
		}
	}

	/* If no loop is detected, return NULL */
	return (NULL);
}
