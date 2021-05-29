#include "binary_trees.h"


/**
 * binary_tree_uncle - search the uncle of a node
 * @node: node to test
 *
 * Return: pointer to Node uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grand = NULL;

	if (node == NULL || node->parent->parent == NULL)
		return (NULL);

	grand = node->parent->parent;
	if (grand->left == NULL || grand->right == NULL)
		return (NULL);

	if (node->parent->n == grand->left->n)
		return (grand->right);
	else
		return (grand->left);
}
