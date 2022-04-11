#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Queue {
    int length;
    Node *tail;
    Node *head;
} Queue;

/**
 * @brief enqueues a value as a node into a queue structure
 * @param queue 
 * @param value 
 */
void enqueue(Queue *queue, int value);

/**
 * @brief dequeues a value from a queue
 * @param queue 
 * @return int 
 */
int dequeue(Queue *queue);


/**
 * @brief traverses a queue from head to tail
 * @param queue 
 */
void queueTraverse(Queue *queue);

#endif