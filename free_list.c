#include "lists.h"

/**
 * free_dlistint - frees the singly linked list
 * @head: pointer to list
 * Return: Nothing
 */

void free_dlistint(dlistint_t *head)
{
	dlistint_t *node = head;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node);
	}
}
