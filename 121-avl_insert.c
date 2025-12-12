#include "binary_trees.h"
/**
* avl_insert - inserts a value in an AVL Tree
* @tree: a double pointer to the root node of the AVL tree
* @value: value to insert
*
* Return: a pointer to the created node
*         NULL on failure
*/
avl_t *avl_insert(avl_t **tree, int value)
{
int balance = 0;
avl_t *node = bst_insert(tree, value);
balance = binary_tree_balance(*tree);
if (balance > 1 && value < node->left->n)
return (binary_tree_rotate_right(node));
if (balance < -1 && value > node->right->n)
return (binary_tree_rotate_left(node));
if (balance > 1 && value > node->left->n)
{
node->left = binary_tree_rotate_left(node->left);
return (binary_tree_rotate_right(node));
}
if (balance < -1 && value < node->right->n)
{
node->right = binary_tree_rotate_right(node->right);
return (binary_tree_rotate_left(node));
}
return (node);
}
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
