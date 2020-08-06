#include "binary_trees.h"

/**
 * make_node - Makes a node and assigns it's parent and value
 * @p: Parent node of the new node
 * @data: Value that will be assigned to the new node
 *
 * Return: The new node created
 */

avl_t *make_node(avl_t *p, size_t data)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->parent = p;
	node->n = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * heap_insert - it inserts a node for a binary tree
 * @root: this is the head of our binary tree
 * @array: This is the array with elements to index in our binary tree
 * @size: this is the end position of the array
 * @start: this is the start of the array
 * Return: pointer to new node or NULL if it fails
 */
avl_t *heap_insert(avl_t **root, int size, int start, int *array)
{
	int half = (start + size) / 2;
	avl_t *new = NULL;

	if (start > size)
		return (NULL);
	new = make_node(*root, array[half]);
	if (half != start)
		new->left = heap_insert(&new, half - 1, start, array);
	if (half != size)
		new->right = heap_insert(&new, size, half + 1, array);
	return (new);
}


/**
 * sorted_array_to_avl - it sorts array into avl binary tree
 *
 * @array: The array to sorted
 * @size: Size of the array
 * Return: pointer to root node of the created tree
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	root = heap_insert(&root, size - 1, 0, array);
	return (root);
}
