#include "binary_trees.h"

/**
 * find_inorder_successor - Finds the inorder next_node of a node in a BST.
 * @node: A pointer to the node.
 *
 * Return: A pointer to the inorder next_node of the node.
 */
bst_t *find_inorder_successor(bst_t *node)
{
	while (node->left)
		node = node->left;
	return (node);
}

/**
 * remove_bst_node - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to be deleted.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *remove_bst_node(bst_t *root, bst_t *node)
{
	bst_t *parent = node->parent, *next_node = NULL;

	if (node->left == NULL)
	{
		if (parent && parent->left == node)
			parent->left = node->right;
		else if (parent)
			parent->right = node->right;
		if (node->right)
			node->right->parent = parent;
		free(node);
		return (parent == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent && parent->left == node)
			parent->left = node->left;
		else if (parent)
			parent->right = node->left;
		if (node->left)
			node->left->parent = parent;
		free(node);
		return (parent == NULL ? node->left : root);
	}

	next_node = find_inorder_successor(node->right);
	node->n = next_node->n;

	return (remove_bst_node(root, next_node));
}

/**
 * remove_value_recursive - Removes a value from a binary search
 *			tree recursively.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the current node.
 * @value: The value to remove.
 *
 * Return: A pointer to the root node after deletion.
 */
bst_t *remove_value_recursive(bst_t *root, bst_t *node, int value)
{
	if (node)
	{
		if (node->n == value)
			return (remove_bst_node(root, node));
		if (node->n > value)
			return (remove_value_recursive(root, node->left, value));
		return (remove_value_recursive(root, node->right, value));
	}
	return (NULL);
}

/**
 * bst_remove - Removes a value from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @value: The value to remove.
 *
 * Return: A pointer to the new root node after deletion.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (remove_value_recursive(root, root, value));
}
