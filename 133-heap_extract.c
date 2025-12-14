#include <stdlib.h>
#include "binary_trees.h"
/**
* heapify_down - restores max heap property from a given node
* @node: pointer to the root node
*/
void heapify_down(heap_t *node)
{
heap_t *largest = node;
int tmp;
while (node)
{
largest = node;
if (node->left && node->left->n > largest->n)
largest = node->left;
if (node->right && node->right->n > largest->n)
largest = node->right;
if (largest == node)
break;
tmp = node->n;
node->n = largest->n;
largest->n = tmp;
node = largest;
}
}
/**
* get_last_node - finds the last node in level-order traversal
* @root: pointer to root node
* Return: pointer to last node
*/
heap_t *get_last_node(heap_t *root)
{
heap_t *queue[1024]; /* simple fixed-size queue */
int front = 0, rear = 0;
queue[rear++] = root;
while (front < rear)
{
heap_t *node = queue[front++];
if (node->left)
queue[rear++] = node->left;
if (node->right)
queue[rear++] = node->right;
if (front == rear) /* last node */
return (node);
}
return (NULL);
}
/**
* heap_extract - extracts the root node of a Max Binary Heap
* @root: double pointer to root node
* Return: value stored in root node, or 0 on failure
*/
int heap_extract(heap_t **root)
{
int value;
heap_t *last;
if (!root || !*root)
return (0);
value = (*root)->n;
last = get_last_node(*root);
if (last == *root)
{
free(*root);
*root = NULL;
return (value);
}
(*root)->n = last->n;
if (last->parent->left == last)
last->parent->left = NULL;
else
last->parent->right = NULL;
free(last);
heapify_down(*root);
return (value);
}
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
if (new == NULL)
return (NULL);
else
{
if (new)
new->n = value;
new->parent = parent;
new->left = NULL;
new->right = NULL;
}
return (new);
}

