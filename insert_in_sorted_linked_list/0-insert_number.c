#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to pointer to the head of the list
 * @number: value to be inserted
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new;
    listint_t *current;
    int tmp;

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        while (current->n < new->n && current->next != NULL)
            current = current->next;
        if (current->next != NULL){
            tmp = current->n;
            current->n = new->n;
            new->n = tmp;
            new->next = current->next;
            current->next = new;
        }
        else {
            current->next = new;
        }

    }

    return (new);
}
