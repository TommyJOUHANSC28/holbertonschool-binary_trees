#include "binary_trees.h"
/**
* binary_tree_is_leaf - Function that checks if a node is a leaf
* @node: a pointer to the node
*
* Return: 0 if node is NULL
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
if (node == NULL)
return (0);
if (node->left != NULL)
return (0);
if (node->right != NULL)
return (0);
return (1);
}
