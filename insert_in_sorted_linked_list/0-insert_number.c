#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a new node in a listint_t list
 * @head: pointer to pointer of first node of listint_t list
 * @n: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, const int n)
{
    listint_t *new;
    listint_t *current;
    int tmp;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        while (current->n < new->n)
            current = current->next;
        tmp = current->n;
        current->n = new->n;
        new->n = tmp;
        new->next = current->next;
        current->next = new;
    }

    return (new);
}
