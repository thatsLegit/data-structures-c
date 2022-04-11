#ifndef QUEUE_UTILS
#define QUEUE_UTILS

#include "structures.h"

/**
 * @brief finds the minimum value in an array of integers
 * 
 * @param int count 
 * @param int arr[] 
 * @return int 
 */
int minInteger(int count, int* arr);

/**
 * @brief inserts a value into a priority queue
 * 
 * @param Array* array
 * @param int value
 * @param int priority
 */
void enqueue(Array* values, int value, int priority);

/**
 * @brief removes the topmost priority node from the priority queue
 * 
 * @param Array* array
 * @return Node 
 */
Node dequeue(Array* array);

#endif