#include "lists.h"
/**
 * is_palindrome - a function that checks if a singly linked list is a palindrome.
 * @head: the head of linked list
 * 
 * return: 0 if is not a plaindrome otherwise 1 if it is a plaindrome
 */
int is_palindrome(listint_t **head)
{
    listint_t *first, *second;
    listint_t *p = *head, *q = *head;

    /* at end of loop q will be the middle node */
    while (p && p->next)
    {
        q = q->next;
        p = p->next->next;
    }

    /* reverse the list on the middle node to get head of second list */
    second = reverseLinkedList(q);
    first = *head;

    while (second)
    {
        if (second->n != first->n)
            return (0);
        second = second->next;
        first = first->next;
    }
    return (1);
}

/**
 * reverseLinkedList - function that reverses a linked list
 * @head: head of list to be reversed
 * Return: head of reversed list
 */
listint_t *reverseLinkedList(listint_t *head)
{
    listint_t *ptr = NULL, *current = head, *next;

    while (current)
    {
        next = current->next;
        current->next = ptr;
        ptr = current;
        current = next;
    }
    return (ptr);
}
