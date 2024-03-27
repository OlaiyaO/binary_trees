#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Rotates a binary tree to the right.
 * @tree: Pointer to the root node of the tree.
 *
 * Returns: Pointer to the new root node after rotation.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *right_child;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	new_root = tree->left;
	right_child = new_root->right;

	new_root->right = tree;
	tree->left = right_child;

	if (right_child)
		right_child->parent = tree;

	right_child = tree->parent;
	tree->parent = new_root;
	new_root->parent = right_child;

	if (right_child)
	{
		if (right_child->left == tree)
			right_child->left = new_root;
		else
			right_child->right = new_root;
	}

	return (new_root);
}
