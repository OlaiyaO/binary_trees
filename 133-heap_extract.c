#include "binary_trees.h"

/**
 * max_heap_height - Measures the height of a max binary heap.
 * @heap: Pointer to the root node of the heap.
 * Return: Height of the heap, or 0 if heap is NULL.
 */
size_t max_heap_height(const heap_t *heap)
{
	size_t height_left = 0, height_right = 0;

	if (heap == NULL)
		return (0);

	if (heap->left)
		height_left = 1 + max_heap_height(heap->left);

	if (heap->right)
		height_right = 1 + max_heap_height(heap->right);

	return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_sum_heights - Measures the sum of heights of a binary tree.
 * @tree: Pointer to the root node of the tree.
 * Return: Sum of heights or 0 if tree is NULL.
 */
size_t binary_tree_sum_heights(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		height_left = 1 + binary_tree_sum_heights(tree->left);

	if (tree->right)
		height_right = 1 + binary_tree_sum_heights(tree->right);

	return (height_left + height_right);
}

/**
 * preorder_traversal - Traverses a binary tree using pre-order traversal.
 * @tree: Pointer to the root node of the tree.
 * @last_node: Pointer to the last node in traversal.
 * @height: Height of the tree.
 */
void preorder_traversal(heap_t *tree, heap_t **last_node, size_t height)
{
	if (tree == NULL)
		return;

	if (!height)
		*last_node = tree;
	height--;

	preorder_traversal(tree->left, last_node, height);
	preorder_traversal(tree->right, last_node, height);
}

/**
 * heapify_max_heap - Adjusts the max binary heap to maintain
 *		the max heap property.
 * @root: Pointer to the root of the max binary heap.
 */
void heapify_max_heap(heap_t *root)
{
	int value;
	heap_t *left_child, *right_child;

	if (root == NULL)
		return;

	left_child = root;

	while (1)
	{
		if (left_child->left == NULL)
			break;
		if (left_child->right == NULL)
			right_child = left_child->left;
		else
		{
			if (left_child->left->n > left_child->right->n)
				right_child = left_child->left;
			else
				right_child = left_child->right;
		}
		if (left_child->n > right_child->n)
			break;
		value = left_child->n;
		left_child->n = right_child->n;
		right_child->n = value;
		left_child = right_child;
	}
}

/**
 * heap_extract - Extracts the root node from a max binary heap.
 * @root: Pointer to the root of the max binary heap.
 * Return: Value of the extracted node.
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *heap_root, *node;

	if (!(root && *root))
		return (0);
	heap_root = *root;
	value = heap_root->n;
	if (heap_root->left == NULL && heap_root->right == NULL)
	{
		*root = NULL;
		free(heap_root);
		return (value);
	}

	preorder_traversal(heap_root, &node, max_heap_height(heap_root));

	heap_root->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	heapify_max_heap(heap_root);
	*root = heap_root;
	return (value);
}

