#include "binary_trees.h"

/**
 * binary_tree_is_perfect- test if a binary tree is perfect
 * @tree: bonary tree
 *
 * Return: in
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	const binary_tree_t *current = NULL;

	if (tree == NULL)
		return (0);

	current = tree;
	if (binary_tree_height(current->left) != binary_tree_height(current->right))
		return (0);

	if (binary_tree_size(current->left) != binary_tree_size(current->right))
		return (0);

	return (1);
}

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;
	const binary_tree_t *current = NULL;

	if (tree == NULL)
		return (0);
	current = tree;
	(current->left) ? left = binary_tree_height(current->left) + 1 : 0;
	(current->right) ? right = binary_tree_height(current->right) + 1 : 0;

	if (left > right)
		return (left);
	else
		 return (right);
}

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
