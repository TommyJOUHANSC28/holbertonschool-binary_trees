#include "binary_trees.h"
/**
* bst_search - Function that searches for a value in a Binary Search Tree
* @tree: pointer to the root node of the BST to search
* @value: value to search in the tree
* Return: pointer to the node containing a value equals to value
*         NULL if nothing is found
*/
bst_t *bst_search(const bst_t *tree, int value)
{
bst_t *newnode = (bst_t *)tree;
if (tree == NULL)
return (NULL);
while (newnode)
{
if (value == newnode->n)
return (newnode);
if (value < newnode->n)
newnode = newnode->left;
else if (value > newnode->n)
newnode = newnode->right;
}
return (NULL);
}
