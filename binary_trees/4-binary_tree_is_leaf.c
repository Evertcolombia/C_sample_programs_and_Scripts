#include "binary_trees.h"


/**
 * binary_tree_is_leaf - ask for a leaf node
 * @node: node to test
 *
 * Return: 1 on leaf node, 0 on none
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	return ((!node->left && !node->right) ? 1 : 0);
}
