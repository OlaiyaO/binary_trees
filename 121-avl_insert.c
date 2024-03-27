#include "binary_trees.h"

size_t calculate_height(const binary_tree_t *tree);
int calculate_balance_factor(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * calculate_height - Measures the height of a binary tree.
 * @tree: A pointer to the tree node of the tree.
 *
 * Return: Height of the tree.
 */
size_t calculate_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_height = tree->left ? 1 + calculate_height(tree->left) : 1;
		size_t right_height = tree->right ? 1 + calculate_height(tree->right) : 1;

		return (left_height > right_height ? left_height : right_height);
	}
	return (0);
}

/**
 * calculate_balance_factor - Measures the balance factor of a binary tree.
 * @tree: A pointer to the tree node of the tree.
 *
 * Return: Balance factor of the tree.
 */
int calculate_balance_factor(const binary_tree_t *tree)
{
	return (tree ? calculate_height(tree->left) -
			calculate_height(tree->right) : 0);
}

/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively.
 * @tree: A double pointer to the tree node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new_node: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new tree after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent,
		avl_t **new_node, int value)
{
	int balance_factor;

	if (*tree == NULL)
		return (*new_node = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left,
				*tree, new_node, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right,
				*tree, new_node, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	balance_factor = calculate_balance_factor(*tree);
	if (balance_factor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (balance_factor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (balance_factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the tree node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new_node, value);
	return (new_node);
}

