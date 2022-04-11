#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void enqueue(Queue *queue, int value) {
    Node *newNode = malloc(sizeof(Node));
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

int dequeue(Queue *queue) {
    if(queue->length == 0) return -1;

    Node *popedNode = queue->head;
    queue->head = popedNode->next;
    queue->length--;

    if(queue->head == NULL) {
        queue->tail = NULL;
    }

    return popedNode->value;
}

void queueTraverse(Queue *queue) {
    Node *current = queue->head;
    int counter = 0;

    while(current->next != NULL) {
        printf("The value of the node at position %d is %d \n", counter, current->value);
        counter++;
        current = current->next;
    }
}