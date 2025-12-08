#include "binary_trees.h"
/**
* binary_tree_preorder - Function that goes through a binary tree
* @tree: pointer to the root node
* @func: pointer to a function to call
* Return: Nothing if tree or func is NULL
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree && func)
{
func(tree->n);
binary_tree_preorder(tree->left, func);
binary_tree_preorder(tree->right, func);
}
}
