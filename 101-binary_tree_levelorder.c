#include "binary_trees.h"

lvlorder_queue_t *create_lvlorder_node(binary_tree_t *node);
void free_lvlorder_queue(lvlorder_queue_t *front);
void push_into_queue(
		binary_tree_t *node,
		lvlorder_queue_t *front,
		lvlorder_queue_t **rear,
		void (*func)(int));
void pop_from_queue(lvlorder_queue_t **front);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));

/**
 * create_lvlorder_node - Creates a  node.
 * @node: The binary new node to contain.
 *
 * Return: A pointer to the new node or NULL if an error occurs
 */
lvlorder_queue_t *create_lvlorder_node(binary_tree_t *node)
{
	lvlorder_queue_t *new_node;

	new_node = malloc(sizeof(lvlorder_queue_t));
	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;

	return (new_node);
}

/**
 * free_lvlorder_queue - Frees a lvlorder_queue_t queue.
 * @front: A pointer to the front of the queue.
 */
void free_lvlorder_queue(lvlorder_queue_t *front)
{
	lvlorder_queue_t *tmp_node;

	while (front != NULL)
	{
		tmp_node = front->next;
		free(front);
		front = tmp_node;
	}
}

/**
 * push_into_queue - Runs a function on a given binary tree node and
 *             pushes its children into a lvlorder_queue_t queue.
 * @node: The binary tree node to print and push.
 * @front: A double pointer to the front of the queue.
 * @rear: A double pointer to the rear of the queue.
 * @func: A pointer to the function to call on @node.
 *
 * Description: Upon malloc failure, exits with a status code of 1.
 */
void push_into_queue(binary_tree_t *node,
		lvlorder_queue_t *front,
		lvlorder_queue_t **rear,
		void (*func)(int))
{
	lvlorder_queue_t *new_node;

	func(node->n);
	if (node->left)
	{
		new_node = create_lvlorder_node(node->left);
		if (new_node == NULL)
		{
			free_lvlorder_queue(front);
			exit(1);
		}
		(*rear)->next = new_node;
		*rear = new_node;
	}
	if (node->right)
	{
		new_node = create_lvlorder_node(node->right);
		if (new_node == NULL)
		{
			free_lvlorder_queue(front);
			exit(1);
		}
		(*rear)->next = new_node;
		*rear = new_node;
	}
}

/**
 * pop_from_queue - Pops the front of a lvlorder_queue_t queue.
 * @front: A double pointer to the front of the queue.
 */
void pop_from_queue(lvlorder_queue_t **front)
{
	lvlorder_queue_t *tmp;

	tmp = (*front)->next;
	free(*front);
	*front = tmp;
}

/**
 * binary_tree_levelorder - Traverses a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	lvlorder_queue_t *front, *rear;

	if (tree == NULL || func == NULL)
		return;

	front = rear = create_lvlorder_node((binary_tree_t *)tree);
	if (front == NULL)
		return;

	while (front != NULL)
	{
		push_into_queue(front->node, front, &rear, func);
		pop_from_queue(&front);
	}
}
