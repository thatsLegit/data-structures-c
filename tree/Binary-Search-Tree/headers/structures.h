#include <stdio.h>

#ifndef HEADER_MAIN
#define HEADER_MAIN

typedef struct Node {
    struct Node* left;
    struct Node* right;
    int value;
    char message[50];
} Node;

typedef struct QueueNode {
    Node* value;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue {
    int length;
    QueueNode *tail;
    QueueNode *head;
} Queue;

typedef struct Array {
  Node** array;
  size_t used;
  size_t size;
} Array;

#endif