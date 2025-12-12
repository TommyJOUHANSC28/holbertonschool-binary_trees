#include "binary_trees.h"
/**
* avl_remove - Removes a node from an AVL tree
* @root: a pointer to the root node of the tree for removing a node
* @value: the value to remove in the tree
*
* Return: a pointer to the new root node of the tree after removal
*         NULL on failure
*/
avl_t *avl_remove(avl_t *root, int value)
{
avl_t *temp = NULL;
if (!root)
return (NULL);
if (value < root->n)
root->left = avl_remove(root->left, value);
else if (value > root->n)
root->right = avl_remove(root->right, value);
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
temp = avl_min_val(root->left);
root->n = temp->n;
root->left = avl_remove(root->left, temp->n);
}
return (root);
}
/**
* bst_min_val - finds the smallest node from a Binary Search Tree
* @root: a pointer to the root node of the tree
* Return: a pointer to the smallest node
*/
avl_t *avl_min_val(avl_t *root)
{
avl_t *minimum = root;
while (minimum->left)
minimum = minimum->left;
return (minimum);
}


