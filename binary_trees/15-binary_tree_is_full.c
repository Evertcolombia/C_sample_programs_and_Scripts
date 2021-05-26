#include "binary_trees.h"

/**
 * binary_tree_is_full - test if a binary tree is full
 * @tree: binary tree
 *
 * Return: int
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	const binary_tree_t *current = NULL;

	if (tree == NULL)
		return (0);

	current = tree;
	if (current->left == NULL && current->right == NULL)
		return (1);
	return (binary_tree_is_full(current->left) && binary_tree_is_full(current->right));
}
