#include "binary_trees.h"
/**
* binary_tree_node - Function that creates a binary tree node
* @parent: pointer to parent node
* @value: interger the value the put int the new node
* Return: pointer to the new node,
*         or NULL on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *new;
new = malloc(sizeof(binary_tree_t));
if (!new)
new->n = value;
new->parent = parent;
new->left = NULL;
new->right = NULL;
return (new);
}
