#include "binary_trees.h"
/**
* bst_insert - Function that inserts a value in a Binary Search Tree
* @tree: double pointer of tree
* @value: the value to store
* Return: pointer to the created node
*         or NULL on faillure
*/
bst_t *bst_insert(bst_t **tree, int value)
{
bst_t *temp = NULL;
bst_t *secondtemp = NULL;
bst_t *newnode = NULL;
if (tree == NULL)
return (NULL);
if (*tree == NULL)
return (*tree = binary_tree_node(NULL, value));
temp = *tree;
while (temp)
{
secondtemp = temp;
if (value < temp->n)
temp = temp->left;
else if (value > temp->n)
temp = temp->right;
else if (value == temp->n)
return (NULL);
}
newnode = binary_tree_node(NULL, value);
if (secondtemp == NULL)
secondtemp = newnode;
else if (value < secondtemp->n)
{
secondtemp->left = newnode;
newnode->parent = secondtemp;
}
else
{
secondtemp->right = newnode;
newnode->parent = secondtemp;
}
return (newnode);
}
