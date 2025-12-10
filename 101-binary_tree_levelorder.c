#include "binary_trees.h"
/**
* binary_tree_levelorder - traverst a binary tree using level-order traverse
* @tree: tree to traverse
* @func: pointer to a function to call for each node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
size_t level, maxlevel;
if (!tree || !func)
return;
maxlevel = binary_tree_height(tree) + 1;
for (level = 1; level <= maxlevel; level++)
btlo_helper(tree, func, level);
}
/**
* btlo_helper - function goes through a binary tree using post-order traverse
* @tree: tree to traverse
* @func: pointer to a function to call for each node
* @level: the level of the tree to call func upon
*/
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
if (level == 1)
func(tree->n);
else
{
btlo_helper(tree->left, func, level - 1);
btlo_helper(tree->right, func, level - 1);
}
}
/**
* binary_tree_height -  function that measures the height of a binary tree
* @tree:  a pointer to the root node
* Return: 0 if tree is NULL
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
size_t lheight = 0, rheight = 0;
if (!tree)
return (0);
lheight = tree->left ? 1 + binary_tree_height(tree->left) : 0;
rheight = tree->right ? 1 + binary_tree_height(tree->right) : 0;
return (lheight > rheight ? lheight : rheight);
}
