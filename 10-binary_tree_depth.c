#include "binary_trees.h"
/**
* binary_tree_depth - function that measures the depth of a node
* @tree:  is a pointer to the node
* Return: 0 if tree is NULL
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
