#include "binary_trees.h"

/**
 * heapify - finds starting node for heap
 * @node: node to start
 * Return: pointer to root node
 */

heap_t *heapify(heap_t *node)
{
	int temp;

	if (!node || !node->parent)
		return (node);

	while (node->parent)
	{
		if (node->n < node->parent->n)
			return (node);

		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
	return (node);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: binary tree
 * Return: height of the @tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_height(tree->left) +
		binary_tree_height(tree->right));
}

/**
 * heap_insert - inserts new value into MAX HEAP
 * @root: ptr to root node
 * @value: integer value of the node
 * Return: ptr to new node or NULL if error.
 */

heap_t *heap_insert(heap_t **root, int value)
{
	ssize_t n = binary_tree_height(*root) + 1;
	int bit = 0;
	heap_t *node = *root, *new_node;

	new_node = binary_tree_node(node, value);

	if (!new_node)
		return (NULL);

	if (!*root)
		return (*root = new_node);

	while (1 << (bit + 1) <= n)
		bit++;

	for (bit--; bit > 0; bit--)
	{
		if (n & (1 << bit))
			node = node->right;
		else
			node = node->left;
	}

	if (n & 1)
		node->right = new_node;
	else
		node->left = new_node;
	new_node->parent = node;

	return (heapify(new_node));
}
