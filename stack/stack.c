#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// c-based implementation of a stack

//In stacks, you can use shift/unshift or push/pop
//! It's an abstract data structure and you can implement it using Arrays, 
//! but with SSL it's more optimized because we don't need indexes.

//As pop is O(N) in a classical head->tail SLL, you would need to invert it and use
//prev instead of next to make it work head<-tail

//Here it's a singly linked list with replaced next by prev.

void stackPush(Stack *stack, int value) {
    Node *newNode = malloc(sizeof(Node)); 
    newNode->value = value;

    if(stack->length == 0) { 
        newNode->prev = NULL;
        stack->head = newNode;
    } else {
        newNode->prev = stack->tail;
    }

    stack->tail = newNode;
    stack->length++;
}

int stackPop(Stack *stack) {
    if(stack->length == 0) return -1;

    Node *popedNode = stack->tail;
    stack->tail = stack->tail->prev;
    stack->length--;

    if(stack->length == 0) {
        stack->head = NULL;
    }

    return popedNode->value;
}

void stackTraverse(Stack *stack) {
    int counter = 0;
    Node *current = stack->tail;

    while (current->prev) {
        printf("the value %d has been inserted at node %d.\n", current->value, counter);
        counter++;
        current = current->prev;
    }
}