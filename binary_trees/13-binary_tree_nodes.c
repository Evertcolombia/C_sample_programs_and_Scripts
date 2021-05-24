#include "binary_trees.h"

/**
 * binary_tree_nodes - count of nodes with atleast 1 child
 * @tree: binary tree node
 *
 * Return: count of nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	const binary_tree_t *current = NULL;
	
	if (tree == NULL)
		return (0);
	
	current = tree;
	if (!current->left && !current->right)
		return (0);

	if (current->left && !current->right)
		return (1);

	if (current->right && !current->left)
		return (1);
	else
		return (binary_tree_nodes(current->left) + binary_tree_nodes(current->right) + 1);
}
