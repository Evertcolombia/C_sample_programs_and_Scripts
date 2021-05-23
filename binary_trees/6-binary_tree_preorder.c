#include "binary_trees.h"

/**
 * binary_tree_preorder - preorder traversal
 * @tree: binary tree
 * @func: pointer to function
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *current = NULL, *left = NULL, *right = NULL;

	if (tree == NULL || func == NULL)
		return;

	current = tree;
	left = current->left;
	right = current->right;
	func(tree->n);

	
	binary_tree_preorder(left, func);
	binary_tree_preorder(right, func);	
}
