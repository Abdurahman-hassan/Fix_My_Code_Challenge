#include "lists.h"
#include <stdlib.h>

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}

	current = *head;
	for (p = 0; p < index && current != NULL; p++)
	{
		current = current->next;
	}

	if (current == NULL)
	{
		return (-1); /* Node at the index not found */
	}

	if (index == 0) /* Deleting the head node */
	{
		*head = current->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
	}
	else /* Deleting a node other than the head */
	{
		temp = current->prev;
		temp->next = current->next;
		if (current->next != NULL)
		{
			current->next->prev = temp;
		}
	}

	free(current);
	return (1);
}
