#ifndef ARRAY_UTILS
#define ARRAY_UTILS

#include "structures.h"

/**
 * @param a Array* 
 * @param initialSize size_t
 */
void initArray(Array *a, size_t initialSize);

/**
 * @param a Array* 
 * @param element Node*
 */
void insertArray(Array *a, Node* element);

/**
 * @param a Array* 
 */
void freeArray(Array *a);

#endif