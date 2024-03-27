#include "queue.h"

/**
 * queue_create - Create and initialize a new queue
 *
 * Return: Pointer to the newly created queue, or NULL if memory allocation fails
 */

queue_t *queue_create(void)
{
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));
	if (queue)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	return queue;
}

/**
 * queue_delete - Free the memory allocated for the queue and all its nodes
 * @queue: Pointer to the queue to be deleted
 */

void queue_delete(queue_t *queue)
{
	if (queue)
	{
		while (!queue_is_empty(queue))
		{
			dequeue(queue);
		}
		free(queue);
	}
}

/**
 * queue_is_empty - Check if the queue is empty
 * @queue: Pointer to the queue
 *
 * Return: 1 if the queue is empty, 0 otherwise
 */

int queue_is_empty(const queue_t *queue)
{
	return (queue == NULL) || (queue->front == NULL);
}

/**
 * enqueue - Add a new item to the rear of the queue
 * @queue: Pointer to the queue
 * @data: Pointer to the data to be added to the queue
 *
 * Return: 1 if the operation is successful, 0 otherwise
 */

int enqueue(queue_t *queue, void *data)
{
	if (!queue) return 0;

	queue_node_t *new_node = (queue_node_t *)malloc(sizeof(queue_node_t));
	if (!new_node) return 0;

	new_node->data = data;
	new_node->next = NULL;

	if (queue_is_empty(queue))
	{
		queue->front = new_node;
	} else
	{
		queue->rear->next = new_node;
	}
	queue->rear = new_node;

	return 1;
}

/**
 * dequeue - Remove and return the item at the front of the queue
 * @queue: Pointer to the queue
 *
 * Return: Pointer to the data removed from the queue,
 * 	or NULL if the queue is empty
 */

void *dequeue(queue_t *queue)
{
	if (queue_is_empty(queue)) return NULL;

	queue_node_t *front_node = queue->front;
	void *data = front_node->data;

	queue->front = front_node->next;
	if (queue->front == NULL)
	{
		queue->rear = NULL;
	}

	free(front_node);
	return data;
}
