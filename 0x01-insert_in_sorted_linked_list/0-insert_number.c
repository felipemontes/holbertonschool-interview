#include <stdlib.h>
#include <stddef.h>
#include "lists.h"
/**
 * insert_node - adds a new node in a sorted linked list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *current;

	current = *head;

	new = malloc(sizeof(listint_t));

	if (!new)
		return (NULL);

	new->n = number;

	if (!current || current->n > new->n)
	{
		new->next = current;
		*head = new;
	}
	else
	{
		while (current->next != NULL && current->next->n < new->n)
			current = current->next;
		new->next = current->next;
		current->next = new;
	}
	return (new);
}