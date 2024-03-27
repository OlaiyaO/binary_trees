#include "binary_trees.h"

/**
 * binary_tree_node - creates a binary tree node
 * @parent: pointer to the parent node of the node to create
 * @value: value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

/**
 * heapify_up - Maintains the Max Heap property by swapping values upwards.
 *
 * @new_node: The newly inserted node.
 *
 * Return: The pointer to the new_node root of the heap.
 */
void heapify_up(heap_t *new_node)
{
	int tmp;

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		tmp = new_node->n;
		new_node->n = new_node->parent->n;
		new_node->parent->n = tmp;
		new_node = new_node->parent;
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
	heap_t *tree, *new_node, *flip;
	int size, remaining_leaves, subtree_size, mask, current_level, tmp;

	if (root == NULL)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	remaining_leaves = size;

	for (current_level = 0, subtree_size = 1;
			remaining_leaves >= subtree_size;
			subtree_size *= 2,
			current_level++)

		remaining_leaves -= subtree_size;

	for (mask = 1 << (current_level - 1); mask != 1; mask >>= 1)
		tree = remaining_leaves & mask ? tree->right : tree->left;

	new_node = binary_tree_node(tree, value);
	remaining_leaves & 1 ? (tree->right = new_node) : (tree->left = new_node);

	flip = new_node;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		tmp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = tmp;
		new_node = new_node->parent;
	}

	return (new_node);
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

