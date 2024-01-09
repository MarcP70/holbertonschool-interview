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

    current = *head;

    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL || n <= (*head)->n) {
        // Cas où la liste est vide ou le nouvel élément doit être inséré au début
        new->next = *head;
        *head = new;
    } else {
        while (current->next != NULL && current->next->n < n)
            current = current->next;
        // Insertion du nouvel élément
        new->next = current->next;
        current->next = new;
    }

    return (new);
}
