#include "binary_trees.h"

/**
 * rebalance_avl - Rebalances an AVL tree after a node insertion or removal.
 * @tree: A double pointer to the root node of the AVL tree.
 *
 * Description: Checks and performs necessary rotations to rebalance
 *		the AVL tree.
 */
void rebalance_avl(avl_t **tree)
{
	int balance_factor;

	if (tree == NULL || *tree == NULL)
		return;

	rebalance_avl(&(*tree)->left);
	rebalance_avl(&(*tree)->right);

	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * get_successor_value - Retrieves the value of the successor node.
 * @node: The node to find the successor for.
 *
 * Return: The value of the successor node.
 */
int get_successor_value(bst_t *node)
{
	if (node == NULL)
	{
		return (0);
	}
	else
	{
		int left_value = get_successor_value(node->left);

		if (left_value == 0)
			return (node->n);
		return (left_value);
	}
}

/**
 * remove_node - Removes a node from a binary search tree.
 * @root: The node to be removed.
 *
 * Return: 0 if the node has no children or the value of it's children.
 */
int remove_node(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = get_successor_value(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove_node - Removes a node from a binary search tree.
 * @root: The root of the binary search tree.
 * @value: The value of the node to remove.
 *
 * Return: The root of the tree after removal.
 */
bst_t *bst_remove_node(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove_node(root->left, value);
	else if (value > root->n)
		bst_remove_node(root->right, value);
	else if (value == root->n)
	{
		type = remove_node(root);
		if (type != 0)
			bst_remove_node(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: The root of the AVL tree.
 * @value: The value of the node to remove.
 *
 * Return: The root of the AVL tree after removal.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *avl_root = (avl_t *)bst_remove_node((bst_t *)root, value);

	if (avl_root == NULL)
		return (NULL);
	rebalance_avl(&avl_root);
	return (avl_root);
}
