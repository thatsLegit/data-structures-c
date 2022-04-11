#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main () {
    Queue *queue = malloc(sizeof(Queue));

    queue->length = 0;
    queue->head = NULL;
    queue->tail = NULL;

    for (int i = 0; i < 10; i++) {
        enqueue(queue, i);
    }

    int unshifted = dequeue(queue);
    if(unshifted == 9) printf("Good! the poped value is indeed %d \n", unshifted);
    queueTraverse(queue);

    free(queue->head);
    free(queue);
    return 0;
}