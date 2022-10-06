#include "lists.h"
/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: the head of list to find the loop
 * Return: the node were the loop is located
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *tortoise, *haar;

	if (!head || !head->next)
		return (NULL);
	tortoise = head->next;
	haar = head->next->next;
	while (tortoise && haar && haar->next)
	{
		tortoise = tortoise->next;
		haar = haar->next->next;
		if (haar == tortoise)
		{
			while (head != haar)
			{
				head = head->next;
				haar = haar->next;
			}
			return (head);
		}
	}
	return (NULL);
}
