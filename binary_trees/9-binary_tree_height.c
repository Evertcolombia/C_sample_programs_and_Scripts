#include "binary_trees.h"

/**
 * binary_tree_height - calculate height
 * @tree: binary tree
 *
 * Return: height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;
	const binary_tree_t *current = NULL;

	if (tree == NULL)
		return(0);

	current = tree;
	(current->left) ? left = binary_tree_height(current->left) + 1 : 0;
	(current->right) ? right = binary_tree_height(current->right) + 1 : 0;

	if (left > right)
		return (left);
	else
		return (right);
}
