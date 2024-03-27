#include "binary_trees.h"

lvlorder_queue_t *create_node(binary_tree_t *node);
void free_queue(lvlorder_queue_t *front);
void push_queue(binary_tree_t *node, lvlorder_queue_t *front,
		lvlorder_queue_t **rear);
void pop_queue(lvlorder_queue_t **front);
int binary_tree_is_complete(const binary_tree_t *tree);

/**
 * create_node - Creates a new node for a level-order queue.
 * @node: The binary tree node to be contained in the new node.
 *
 * Return: A pointer to the new node, or NULL on error.
 */


lvlorder_queue_t *create_node(binary_tree_t *node)
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
 * free_queue - Frees a level-order queue.
 * @front: Pointer to the front of the queue.
 */


void free_queue(lvlorder_queue_t *front)
{
	lvlorder_queue_t *tmp;

	while (front != NULL)
	{
		tmp = front->next;
		free(front);
		front = tmp;
	}
}

/**
 * push_queue - Adds a node to the end of a level-order queue.
 * @node: The binary tree node to add.
 * @front: Pointer to the queue's front.
 * @rear: Pointer to the queue's rear.
 *
 * Notes: Exits with status code 1 on malloc failure.
 */

void push_queue(binary_tree_t *node, lvlorder_queue_t *front,
		lvlorder_queue_t **rear)
{
	lvlorder_queue_t *new_node;

	new_node = create_node(node);
	if (new_node == NULL)
	{
		free_queue(front);
		exit(1);
	}
	(*rear)->next = new_node;
	*rear = new_node;
}

/**
 * pop_queue - Removes the front of a level-order queue.
 * @front: Double pointer to the front of the queue.
 */

void pop_queue(lvlorder_queue_t **front)
{
	lvlorder_queue_t *tmp;

	tmp = (*front)->next;
	free(*front);
	*front = tmp;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise or if tree is NULL.
 *
 * Notes: Exits with status code 1 on malloc failure.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	lvlorder_queue_t *front, *rear;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	front = rear = create_node((binary_tree_t *)tree);
	if (front == NULL)
		exit(1);

	while (front != NULL)
	{
		if (front->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(front);
				return (0);
			}
			push_queue(front->node->left, front, &rear);
		}
		else
			flag = 1;
		if (front->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(front);
				return (0);
			}
			push_queue(front->node->right, front, &rear);
		}
		else
			flag = 1;
		pop_queue(&front);
	}
	return (1);
}
