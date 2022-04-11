#include <stdio.h>
#include <stdlib.h>
#include "headers/structures.h"
#include "headers/queue_fn.h"
#include "headers/array_fn.h"

int main() {
    Array values;
    initArray(&values, 10);
    
    // pointer to priorityQueue needs to be passed to update its value
    enqueue(&values, 10, 1);
    enqueue(&values, 20, 2);
    enqueue(&values, 30, 3);
    enqueue(&values, 40, 1);
    enqueue(&values, 50, 5);
    enqueue(&values, 60, 9);
    enqueue(&values, 70, 6);
    enqueue(&values, 80, 2);

    for(int i = 0; i < values.used; i++) {
        printf("%ld \n", values.array[i].value);
    }

    dequeue(&values);
    dequeue(&values);
    dequeue(&values);
    dequeue(&values);

    freeArray(&values);
    return 0;
}

// Some remarks relative to this small project:
// - To type a pointer to an array of pointers: struct Node* *values.
// - Node* values[] types an array of pointers
// - Node* (* values)[size] types a pointer to an array of size pointers
// - A pointer to an array is always the pointer to its first element, so 
// no need for [] in the type of the pointer.
// - Typing a pointer is only useful when dereferencing it.