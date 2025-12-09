#include "binary_trees.h"
/**
* binary_tree_is_perfect - checks if a binary tree is perfect
* @tree: a pointer to the root node of the tree to check
*
* Return: 1 if the tree is perfect
*         0 if the tree is not perfect
*         0 if tree is NULL
*/
int binary_tree_is_perfect(const binary_tree_t *tree)
{
size_t height = 0;
size_t nodes = 0;
size_t power = 0;
if (!tree)
return (0);
if (!tree->right && !tree->left)
return (1);
height = binary_tree_height(tree);
nodes = binary_tree_size(tree);
power = (size_t)_pow_recursion(2, height + 1);
return (power - 1 == nodes);
}
/**
 *_pow_recursion - returns the value of x raised to the power of y
 *@x: the value to exponentiate
 *@y: the power to raise x to
 *Return: x to the power of y, or -1 if y is negative
 */
int _pow_recursion(int x, int y)
{
if (y < 0)
return (-1);
if (y == 0)
return (1);
else
return (x * _pow_recursion(x, y - 1));
}
/**
* binary_tree_size - Function that measures the size of a binary tree
* @tree: pointer of the root of node
* Return: 0 if tree is NULL
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
size_t size = 0;
if (tree)
{
size += 1;
size += binary_tree_size(tree->left);
size += binary_tree_size(tree->right);
}
return (size);
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
