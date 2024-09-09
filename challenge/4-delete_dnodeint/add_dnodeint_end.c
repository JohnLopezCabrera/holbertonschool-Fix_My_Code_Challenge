#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - Add a node at the end of a list
 *
 * @head: The address of the pointer to the first element of the list
 * @n: The number to store in the new element
 *
 * Return: A pointer to the new element
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new;
    dlistint_t *last_node;

    new = malloc(sizeof(dlistint_t));
    if (new == NULL)
    {
        return (NULL);
    }
    new->n = n;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
        new->prev = NULL;
        return (new);
    }

    last_node = *head;
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }
    last_node->next = new;
    new->prev = last_node;

    return (new);
}
