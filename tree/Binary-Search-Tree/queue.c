#include <stdio.h>
#include <stdlib.h>
#include "headers/structures.h"
#include "headers/queue_fn.h"

void enqueue(Queue *queue, Node* value) {
    QueueNode *newNode = malloc(sizeof(QueueNode));
    newNode->value = value;

    if(queue->length == 0) {
        queue->tail = newNode;
        newNode->next = NULL;
    } else {
        newNode->next = queue->head;
    }

    queue->head = newNode;
    queue->length++;
}

Node* dequeue(Queue *queue) {
    if(queue->length == 0) return NULL;

    QueueNode *popedNode = queue->head;
    queue->head = popedNode->next;
    queue->length--;

    if(queue->head == NULL) {
        queue->tail = NULL;
    }

    return popedNode->value;
}

void queueTraverse(Queue *queue) {
    QueueNode *current = queue->head;
    int counter = 0;

    while(current->next) {
        printf(
            "The value of the node at position %d is %d. the message is %s \n", 
            counter, current->value->value, current->value->message
        );
        counter++;
        current = current->next;
    }
}