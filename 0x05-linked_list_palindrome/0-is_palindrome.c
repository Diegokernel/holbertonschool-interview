#include "lists.h"

/**
 * reverse_listint - reverses a listint list
 * @head: head of linked list
 * Return: pointer to the head of the list
*/
listint_t *reverse(listint_t **head)
{
	listint_t *node = *head, *next, *prev = NULL;

	while (node)
	{
		next = node->next;
		node->next = prev;
		prev = node;
		node = next;
	}
	*head = prev;
	return (*head);
}

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 *
 * @head: pointer to pointer to the head node of the list
 *
 * Description: Checks a singly linked list to see if it is a palindrome.
 * If the list is empty the list is considered to be a palindrome.
 *
 * Return: 0 if the list is not a palindrome and 1 if it is
 */
int is_palindrome(listint_t **head)
{
	listint_t *stride = *head, *tmp;
	unsigned int len = 0, i = 0;

	if (*head == NULL)
		return (1);
	while (stride)
	  {
		stride = stride->next;
		len ++;
	  }

	stride = *head;

	while (i < (len / 2))
	  {
		stride = stride->next;
		i++;
	  }

	if (len % 2 != 0)
		stride = stride->next;
	stride = reverse(&stride);
	for (i = 0, tmp = *head ; i < (len / 2); i++)
	{
		if (tmp->n != stride->n)
			return (0);
		stride = stride->next;
		tmp = tmp->next;
	}
	return (1);
}
