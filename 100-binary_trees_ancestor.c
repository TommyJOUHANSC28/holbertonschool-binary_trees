#include "binary_trees.h"
/**
* binary_trees_ancestor - function that finds
*                         the lowest common ancestor of two nodes.
* @first: is a pointer to the first node
* @second: second is a pointer to the second node
* Return: A pointer to the lowest common ancestor node
*         NULL if no common ancestor was found
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
size_t depth_first, depht_second;
if (!first || !second)
return (NULL);
depth_first = binary_tree_depth(first);
depht_second = binary_tree_depth(second);
while (depth_first > depht_second)
{
first = first->parent;
depth_first--;
}
while (depht_second > depth_first)
{
second = second->parent;
depht_second--;
}
while (first && second)
{
if (first == second)
return ((binary_tree_t *)first);
first = first->parent;
second = second->parent;
}
return ((binary_tree_t *)first);
}
/**
* binary_tree_depth - function that measures the depth of a node
* @tree:  is a pointer to the node
* Return: 0 if tree is NULL
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
size_t depth = 0;
if (!tree)
return (0);
while (tree->parent)
{
depth++;
tree = tree->parent;
}
return (depth);
}
