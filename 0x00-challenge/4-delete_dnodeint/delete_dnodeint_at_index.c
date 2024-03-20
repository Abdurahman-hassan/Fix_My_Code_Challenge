#include "lists.h"
#include <stdlib.h>

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	dlistint_t *tmp;
	unsigned int p;

	if (*head == NULL)
	{
		return (-1);
	}
	saved_head = *head;
	p = 0;
	while (p < index && *head != NULL)
	{
		*head = (*head)->next;
		p++;
	}
	if (p != index)
	{
		*head = saved_head;
		return (-1);
	}
	if (0 == index)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
		if (tmp != NULL)
		{
			tmp->prev = NULL;
		}
	}
	else
	{
	    /* The previous code is */

		/* (*head)->prev->prev = (*head)->prev;
		/* free(*head); */
		/* if ((*head)->next) */
		/*	(*head)->next->prev = (*head)->prev; */
		/* *head = saved_head; */
	}


		(*head)->prev->next = (*head)->next;
		/* The correct way to handle this is to update the next pointer */
		/* of the previous node and the prev pointer of the next node before */
		/* deleting the current node. */
		if ((*head)->next)
			(*head)->next->prev = (*head)->prev;
		tmp = *head;
		*head = saved_head;
		free(tmp);
	}
	return (1);
}
