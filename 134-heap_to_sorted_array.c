#include "binary_trees.h"

/**
 * tree_nodes_count - Counts the number of nodes in a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: Number of nodes.
 */
size_t tree_nodes_count(const binary_tree_t *tree)
{
	size_t nodes_left = 0, nodes_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		nodes_left = 1 + tree_nodes_count(tree->left);

	if (tree->right)
		nodes_right = 1 + tree_nodes_count(tree->right);

	return (nodes_left + nodes_right);
}

/**
 * heap_to_sorted_array - Converts a binary max heap to a sorted array.
 * @heap: Pointer to the root node of the heap.
 * @size: Address to store the size of the array.
 * Return: Pointer to the sorted array in descending order.
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int index, *array = NULL;

	if (!(heap && size))
		return (NULL);

	*size = tree_nodes_count(heap) + 1;

	array = malloc(sizeof(int) * (*size));

	if (array == NULL)
		return (NULL);

	for (index = 0; heap; index++)
		array[index] = heap_extract(&heap);

	return (array);
}
