#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "headers/structures.h"
#include "headers/queue_fn.h"
#include "headers/array_fn.h"

// Insert: push to the end of the array, compare to the parent, while bigger swap else stop;
// Extract max: 
// swap head and tail of the heap.
// pop the tail which should be the max value to return
// bubble down the swaped value to the correct spot:
// find the max between the false parent and its children
// if the parent is max, break, otherwise swap with max
// Check if both child actually exist, otherwise define -Inifinity as their value

//! Extraction and insertion are of O(log(n)) in a binary heap. 
//! This is why it's often used for implementing Priority Queues

void enqueue(Array* values, int value, int priority) {
    Node newNode = { priority, value };
    pushArray(values, newNode);

    int index = values->used - 1;
    while(values->array[index].priority < values->array[(index) / 2].priority) {
        // swap node at index and the parent.
        // no need to math.floor as index is an int and will not be
        // converted to a float.
        Node parentNode = values->array[(index) / 2];
        values->array[(index) / 2] = newNode;
        values->array[index] = parentNode;
        // set the new index to the index of the parent
        index = (index) / 2;
    }
}

int minInteger(int count, int arr[]) {
    int min = arr[0];
    for (int i = 0; i < count ; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

Node dequeue(Array* values) {
    Node nodeToReturn = values->array[0];
    values->array[0] = values->array[values->used - 1];
    removeArrayIndex(values, values->used - 1);

    int index = 0;

    while (1 == 1) {       
        int arr[3] = { values->array[index].priority, MAX_PRIORITY, MAX_PRIORITY };
        if(index * 2 + 1 <= values->used - 1) {
            arr[1] = values->array[index * 2 + 1].priority;
        }
        if(index * 2 + 2 <= values->used - 1) {
            arr[2] = values->array[index * 2 + 2].priority;
        }

        int min = minInteger(3, arr);

        if(min == arr[0]) break;
        if(min == arr[1]) {
            Node mem = values->array[index * 2 + 1];
            values->array[index * 2 + 1] = values->array[index];
            values->array[index] = mem;
            index = index * 2 + 1;
        } else {
            Node mem = values->array[index * 2 + 2];
            values->array[index * 2 + 2] = values->array[index];
            values->array[index] = mem;
            index = index * 2 + 2;
        }
    }

    return nodeToReturn;
}
