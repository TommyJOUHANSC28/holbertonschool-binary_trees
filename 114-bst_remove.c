#include "binary_trees.h"
/**
* bst_remove - function that removes a node from a Binary Search Tree
* @root: pointer to the root node of the tree
* @value: value to remove in the tree
* Return: a pointer to the new root node
*/
bst_t *bst_remove(bst_t *root, int value)
{
bst_t *temp = NULL;
if (!root)
return (NULL);
if (value < root->n)
root->left = bst_remove(root->left, value);
else if (value > root->n)
root->right = bst_remove(root->right, value);
else
{
if (!root->left)
{
temp = root->right;
free(root);
return (temp);
}
else if (!root->right)
{
temp = root->left;
free(root);
return (temp);
}
temp = bst_min_val(root->left);
root->n = temp->n;
root->left = bst_remove(root->left, temp->n);
}
return (root);
}
/**
* bst_min_val - finds the smallest node from a Binary Search Tree
* @root: a pointer to the root node of the tree
* Return: a pointer to the smallest node
*/
bst_t *bst_min_val(bst_t *root)
{
bst_t *minimum = root;
while (minimum->left)
minimum = minimum->left;
return (minimum);
}

