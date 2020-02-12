#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - adds a new ordered node
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *aux, *forw;

	aux = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		free(new);
		return (NULL);
	}

	new->n = number;
	if (aux == NULL || number < aux->n)
	{
		new->next = aux;
		*head = new;
		return (new);
	}
	while (aux->next != NULL && aux->next->n < number)
		aux = aux->next;

	forw = aux->next;
	aux->next = new;
	new->next = forw;
	return(new);
}
