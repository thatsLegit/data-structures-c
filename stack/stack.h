#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct Node {
    int value;
    struct Node *prev;
} Node;

typedef struct Stack {
    int length;
    Node *tail;
    Node *head;
} Stack;

/**
 * @brief in-place pushes a node to a stack
 * 
 * @param stack 
 * @param value 
 */
void stackPush(Stack *stack, int value);

/**
 * @brief in-place removal and return of the last node of a stack 
 * 
 * @param stack 
 * @return int 
 */
int stackPop(Stack *stack);

/**
 * @brief traverses all nodes of a stack
 * 
 * @param stack 
 */
void stackTraverse(Stack *stack);

#endif