#include "lists.h"

/**
 * insert_node - a function in C that inserts a number
 *	into a sorted singly linked list.
 * @head: pointer to the head of the node.
 * @number: number to insert
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{

	listint_t *tmp;
	listint_t *new;

	tmp = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}

	new->n = number;
	new->next = NULL;

	if (*head == NULL || number < (*head)->n)
	{	
		new->next = *head;
		*head = new;
	}

	else
	{
		tmp = *head;

		while (tmp->next != NULL && tmp->next->n < number)
			tmp = tmp->next;

		new->next = tmp->next;
		tmp->next = new;
	}
	return (new);
}
