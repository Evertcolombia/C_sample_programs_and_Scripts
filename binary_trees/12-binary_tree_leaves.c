#include "binary_trees.h"

/**
 * binary_tree_leaves - gets leaves of a root
 * @tree: binary tree
 *
 * Return: Total of leaves
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	const  binary_tree_t *current = NULL;

	if (tree == NULL)
		return (0);

	current = tree;
	if (!current->left && !current->right)
		return (1);
	else
		return (binary_tree_leaves(current->left) + binary_tree_leaves(current->right));
}
