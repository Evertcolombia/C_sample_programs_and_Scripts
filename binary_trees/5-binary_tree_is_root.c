#include "binary_trees.h"

/**
 * binary_tree_is_root - check if node is root
 * @node: node to test
 *
 * Return: 1 on root 0 on none
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	return ((node->parent == NULL) ? 1 : 0);
}
