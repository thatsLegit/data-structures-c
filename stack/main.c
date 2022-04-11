#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
    Stack *stack = malloc(sizeof(Stack));

    stack->length = 0;
    stack->head = NULL;
    stack->tail = NULL;

    int i = 10;
    while(i--) {
        stackPush(stack, 10-i);
    }

    stackTraverse(stack);
    
    free(stack->tail);
    free(stack);
    return 0;
}