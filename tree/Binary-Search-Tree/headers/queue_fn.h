#ifndef QUEUE_UTILS
#define QUEUE_UTILS

#include "structures.h"

/**
 * @brief enqueues a value as a node into a queue structure
 * @param queue Queue*
 * @param value Node*
 */
void enqueue(Queue *queue, Node* value);

/**
 * @brief dequeues a value from a queue
 * @param queue Queue*
 * @return Node*
 */
Node* dequeue(Queue *queue);

/**
 * @brief traverses a queue from head to tail
 * @param queue 
 */
void queueTraverse(Queue *queue);

#endif