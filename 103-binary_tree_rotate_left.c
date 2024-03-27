#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Rotates a binary tree to the left.
 * @tree: Pointer to the tree node of the tree.
 *
 * Returns: Pointer to the new tree node after rotation.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *old_right_child;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	new_root = tree->right;
	old_right_child = new_root->left;
	new_root->left = tree;
	tree->right = old_right_child;
	if (old_right_child)
		old_right_child->parent = tree;
	old_right_child = tree->parent;
	tree->parent = new_root;
	new_root->parent = old_right_child;
	if (old_right_child)
	{
		if (old_right_child->left == tree)
			old_right_child->left = new_root;
		else
			old_right_child->right = new_root;
	}

	return (new_root);
}
