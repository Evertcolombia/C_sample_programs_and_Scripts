#include "binary_trees.h"

/**
 * binary_tree_depth - calculate depth of a node
 * tree: binary tree
 *
 * Return: depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *current = NULL;
	size_t depth = 0;

	if (tree == NULL)
		return (0);

	current = tree;

	(current->parent) ? depth = binary_tree_depth(current->parent) + 1 : 0;
	return (depth);
}
