#include "binary_trees.h"

/**
 * binary_tree_size - gets size of a binary tree
 * @tree: binary tree
 *
 * Retrun: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	const binary_tree_t *current = NULL;
	size_t size = 0;

	if (tree == NULL)
		return (0);
	
	current = tree;
	(current->left) ? size += binary_tree_size(current->left) : 0;
	(current->right) ? size += binary_tree_size(current->right) : 0;

	return (size + 1);
}
