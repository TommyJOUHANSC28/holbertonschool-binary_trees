#include "binary_trees.h"
/**
* binary_tree_rotate_right - a function that performs
*                           a right-rotation on a binary tree
* @tree: a pointer to the root node
* Return: pointer to the new root nodeof the tree once rotated
*/
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
binary_tree_t *temp = NULL, *parent;
if (tree == NULL || (tree->left) == NULL)
return (NULL);
temp = tree;
parent = tree->parent;
tree = tree->left;
tree->parent = NULL;
if (tree->right)
{
temp->left = tree->left;
tree->right->parent = temp;
}
else
temp->left = NULL;
temp->parent = tree;
tree->right = temp;
if (parent)
parent->left = tree;
tree->parent = parent;
return (tree);
}
