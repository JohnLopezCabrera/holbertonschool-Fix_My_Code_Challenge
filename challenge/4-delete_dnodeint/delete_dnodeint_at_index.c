#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current;
    unsigned int p;

    if (*head == NULL)  /* Empty list */
    {
        return (-1);
    }

    current = *head;
    p = 0;

    /* Traverse the list to find the node at the given index */
    while (p < index && current != NULL)
    {
        current = current->next;
        p++;
    }

    if (current == NULL)  /* Index out of range */
    {
        return (-1);
    }

    /* Deleting the head node */
    if (index == 0)
    {
        *head = current->next;  /* Move head to the next node */
        if (*head != NULL)
        {
            (*head)->prev = NULL;
        }
        free(current);
    }
    else  /* Deleting a node that is not the head */
    {
        if (current->prev != NULL)
        {
            current->prev->next = current->next;
        }
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
        free(current);
    }

    return (1);
}
