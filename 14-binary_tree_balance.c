#include "binary_trees.h"
/**
* binary_tree_balance - That measures the balance factor of a binary tree
* @tree: pointer of pointer to the root node
* Return: 0 if tree is NULL
*/
int binary_tree_balance(const binary_tree_t *tree)
{
size_t lheight, rheight;
if (!tree)
return (0);
lheight = tree->left ? (int) binary_tree_height(tree->left) : -1;
rheight = tree->right ? (int) binary_tree_height(tree->right) : -1;
return (lheight - rheight);
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
