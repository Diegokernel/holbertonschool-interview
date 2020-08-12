#include "search.h"

/**
 * linear_skip - jump search algorithm with linked list
 * @list: list to search the value
 * @value: value to search
 * Return: Node where the value is or NULL if the value couldn't be find
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
  skiplist_t *next, *prev;

	if (!list)
		return (NULL);
	next = list->express;
	prev = list;
	while (next)
	{
		printf("Value checked at index [%lu] = [%d]\n",
		       next->index, next->n);
		if (next->n >= value)
			break;
		prev = next;
		if (!next->express)
		{
			while (next->next)
				next = next->next;
			break;
		}
		next = next->express;
	}
	printf("Value found between indexes [%lu] and [%lu]\n",
			       prev->index, next->index);
	while (prev && prev->index <= next->index)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				       prev->index, prev->n);
		if (prev->n == value)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}
