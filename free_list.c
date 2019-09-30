#include "monty.h"

/**
 * free_stack - frees the singly linked list
 * @head: pointer to list
 * Return: Nothing
 */

void free_stack(stack_t *head)
{
	stack_t *node = head;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node);
	}
}

void free_list(char *a[])
{
	int i = 0;

	while (a[i] != NULL)
	{
		free(a[i]);
		i++;
	}
}