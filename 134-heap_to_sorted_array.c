#include "binary_trees.h"
/**
* heap_to_sorted_array - converts a Binary Max Heap
* to a sorted array of integers
* @heap: a pointer to the root node of the heap to convert
* @size: an address to store the size of the array
* Return: the generated array
*         NULL on failure
*/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
int *array;
int value;
size_t i = 0;
if (!heap || !size)
return (NULL);
*size = binary_tree_size((const binary_tree_t *)heap);
array = malloc(sizeof(int) * (*size));
if (array == NULL)
return (NULL);
while (heap)
{
value = heap_extract(&heap);
array[i++] = value;
}
return (array);
}
