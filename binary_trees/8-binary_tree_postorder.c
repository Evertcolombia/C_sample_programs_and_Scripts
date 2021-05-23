#include "binary_trees.h"

/**
 * binary_tree_postorder - post-order traversal method
 * @tree: binary tree root
 * @func: function pointer
 *
 * Return: none
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *current = NULL;

	if (tree == NULL || func == NULL)
		return;

	current = tree;

	binary_tree_postorder(current->left, func);
	binary_tree_postorder(current->right, func);
	func(current->n);
}
