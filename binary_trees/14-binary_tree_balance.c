#include "binary_trees.h"

size_t binary_tree_height(const binary_tree_t *tree);
/**
 * binary_tree_balance - thest for balanec binary tree
 * @tree: binary tree
 *
 * Return: int
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	const binary_tree_t *current = NULL;
	int left = 0, right = 0;

	if (tree == NULL)
		return (0);

	current = tree;
	if (!current->left && !current->right)
		return(0);

	(current->left) ? left = (int) binary_tree_height(current->left) + 1 : 0;
	(current->right) ? right = (int) binary_tree_height(current->right) + 1 : 0;
	return (left - right);
}

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
