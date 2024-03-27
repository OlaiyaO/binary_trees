#include "binary_trees.h"

/**
 * heapify_up - Maintains the Max Heap property by swapping values upwards.
 *
 * @new: The newly inserted node.
 *
 * Return: The pointer to the new root of the heap.
 */
void heapify_up(heap_t *new)
{
	int tmp;

	while (new->parent && new->n > new->parent->n)
	{
		tmp = new->n;
		new->n = new->parent->n;
		new->parent->n = tmp;
		new = new->parent;
	}
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 *
 * @root: A double pointer to the root node of the Heap.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new;
	int size, leaves, sub, bit, level;

	if (root == NULL)
		return (NULL);
	if ((*root) == NULL)
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	leaves = size;

	for (level = 0, sub = 1; leaves >= sub; sub *= 2, level++)
		leaves -= sub;

	for (bit = 1 << (level - 1); bit != 1; bit >>= 1)
		tree = leaves & bit ? tree->right : tree->left;

	new = binary_tree_node(tree, value);
	leaves & 1 ? (tree->right = new) : (tree->left = new);

	heapify_up(new);

	return (new);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 *
 * @tree: Pointer to the root of the tree.
 *
 * Return: Size of the tree, 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

