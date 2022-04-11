#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/structures.h"
#include "headers/BST_fn.h"
#include "headers/array_fn.h"
#include "headers/queue_fn.h"

Node* createNode(int value, char message[50]) {
    Node* newNode = malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    strcpy(newNode->message, message);
    newNode->value = value;
    return newNode;
}

void insertTree(Node* root, int value, char message[50]) {
    Node* current = root;
    Node* newNode;

    do {
        if(value < current->value) {  
            if(current->left) {
                current = current->left;
            } else {
                newNode = createNode(value, message);
                current->left = newNode;
                break;
            }
        } else if (value > current->value) {
            if(current->right) {
                current = current->right;
            } else {
                newNode = createNode(value, message);
                current->right = newNode;
                break;
            }
        } else {
            printf("The value %d is already existing in the tree \n", value);
            break;
        }
    } while(1 == 1);
}

Node* searchTree(Node* node, int value) {
    if(node->value == value) return node;
    if(value < node->value) {
        if(node->left == NULL) {
            printf("Node with value %d was not found", value);
            return NULL;
        }
        return searchTree(node->left, value);
    } else if(value > node->value) {
        if(node->right == NULL) {
            printf("Node with value %d was not found", value);
            return NULL;
        }
        return searchTree(node->right, value);
    }
    else return NULL;
}

Node* searchParentTree(Node* node, int value) {
    Node* parent = NULL;
    Node* current = node;

    do {
        if(current->value == value) return parent;
            if(value < current->value) {
                if(current->left == NULL) {
                    printf("Node with value %d was not found", value);
                    return NULL;
                }
                parent = current;
                current = current->left;
            } 
            else if(node->value > value) {
                if(node->right == NULL) {
                    printf("Node with value %d was not found", value);
                    return NULL;
                }
                parent = current;
                current = current->right;
            }
            else return NULL;
    } while(1 == 1);

    return parent;
}

Array traverseTreeBFS(Node* root) {
    Queue *queue = malloc(sizeof(Queue));
    queue->length = 0;
    queue->head = NULL;
    queue->tail = NULL;

    // I need an array here as I don't know the number of nodes in my tree.
    Array visited;
    initArray(&visited, 10);
    
    enqueue(queue, root);
    while(queue->length != 0) {
        Node* visitedNode = dequeue(queue);
        if(visitedNode->left != NULL) {
            enqueue(queue, visitedNode->left);
        }
        if(visitedNode->right != NULL) {
            enqueue(queue, visitedNode->right);
        }
        insertArray(&visited, visitedNode);
    }

    return visited;
}

void traverseTreeDFS(Node* node, Array* arr) {
    insertArray(arr, node);
    if(node->left) traverseTreeDFS(node->left, arr);
    if(node->right) traverseTreeDFS(node->right, arr);
}