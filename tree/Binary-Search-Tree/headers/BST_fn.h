#ifndef BST_UTILS
#define BST_UTILS

#include "structures.h"

/**
 * @param int value 
 * @param char message[50]
 * @return Node* 
 */
Node* createNode(int value, char message[50]);

/**
 * @param int value
 */
void insertTree(Node* root, int value, char message[]);

/**
 * @param int value 
 * @return Node* 
 */
Node* searchTree(Node* root, int value);

/**
 * @param  Node* root 
 */
struct Array traverseTreeBFS(Node* root);

/**
 * @param  Node* root 
 * @param  Array arr
 */
void traverseTreeDFS(Node* node, struct Array* arr);

#endif