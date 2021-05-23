#include "binary_trees.h"

/**
 * binary_tree_inorder - in-order traversal method
 * @tree: binary tree
 * @func: function pointer
 *
 * Return: None
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *current = NULL;

	if (tree == NULL || func == NULL)
		return;

	current = tree;

	binary_tree_inorder(current->left, func);
	func(current->n);
	binary_tree_inorder(current->right, func);


}
