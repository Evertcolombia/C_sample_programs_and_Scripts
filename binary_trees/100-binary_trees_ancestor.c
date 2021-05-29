#include "binary_trees.h"

size_t binary_tree_depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - search the low ancestrow between two nodes
 * @first: node
 * @second: node
 *
 * Return: pointer to ancestor or NULL
 */

binary_tree_t
*binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t f_depth = 0, s_depth = 0;

	if (first == NULL || second == NULL)
		return (NULL);

	f_depth = binary_tree_depth(first);
	s_depth = binary_tree_depth(second);

	if (f_depth == 0 || s_depth == 0)
		return (NULL);

	if (f_depth == s_depth || f_depth < s_depth)
		return (first->parent);

	return (second->parent);
}

/**
 * binary_tree_depth - calculate depth of a node
 * @tree: binary tree
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
