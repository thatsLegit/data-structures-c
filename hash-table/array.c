#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/structures.h"
#include "headers/array_fn.h"

void initArray(Array *a, size_t initialSize) {
  a->collisionArray = malloc(initialSize * sizeof(Tuple*));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, Tuple* element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->collisionArray = realloc(a->collisionArray, a->size * sizeof(Tuple*));
  }

  a->collisionArray[a->used++] = element;
}

void removeArrayIndex(Array* a, int index) {
  if(index < a->used) {
    free(a->collisionArray[index]);
    for (int i = index + 1; i<a->used; i++) {
      a->collisionArray[i - 1] = a->collisionArray[i];
    }
    free(a->collisionArray[a->used--]);
  } else {
    printf("Index %d is too large", index);
  }
}

void replaceArrayIndex(Array* a, int index, char* value) {
  strncpy(a->collisionArray[index]->value, value, VALUE_SIZE);
}

void freeArray(Array *a) {
  for (int i = 0; i < a->used; i++) {
    free(a->collisionArray[i]);
  }
  free(a->collisionArray);
  a->collisionArray = NULL;
  a->used = a->size = 0;
}