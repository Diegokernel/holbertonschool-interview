#include "search.h"

/**
 * list_check - check for value in list
 * @list: type pointer of node in the lists
 * @value: type pointer of the first node indicating value
 * Return: addres pointer where the value is located otherwise NULL
 *
 */

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev = NULL;
	skiplist_t *curr = NULL;
	size_t prev_i, curr_i;

	if (!list)
		return (NULL);
	curr = list;
	while (curr->express)
	{
		prev = curr;
		curr = curr->express;
		prev_i = prev->index;
		curr_i = curr->index;
		printf("Value checked at index [%lu] = [%i]\n", curr->index,
			curr->n);
		if (prev->index == 0 && prev->n > value)
			return (NULL);
		if (curr->n >= value)
			break;
	}
	if (!curr->express && curr->n < value)
	{
		prev = curr;
		prev_i = prev->index;
		while (curr->next)
			curr = curr->next;
		curr_i = curr->index;
	}
	printf("Value found between indexes [%lu] and [%lu]\n", prev_i, curr_i);
	return (search_sub(prev, curr, value));

}


/**
 * search_sub - Searches and tries to find @value in a sparse
 * subsequence between @head_sub and @tail_sub
 * @head_sub: Pointer to the head of the subsequence
 * @tail_sub: Pointer to the tail of the subsequence
 * @value: Value to search for
 * Return: Pointer to the node where @value was found otherwise NULL
 */

skiplist_t *search_sub(skiplist_t *head_sub, skiplist_t *tail_sub, int value)
{
	while (head_sub && (head_sub->index <= tail_sub->index))
	{
		printf("Value checked at index [%lu] = [%i]\n", head_sub->index,
			head_sub->n);
		if (head_sub->n == value)
			return (head_sub);
		head_sub = head_sub->next;
	}
	return (NULL);
}
