#include <stdio.h>
#include <stdlib.h>
#include "headers/structures.h"
#include "headers/array_fn.h"

void initArray(Array *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(Node*));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, Node* element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(Node*));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  for (int i = 0; i < a->used; i++) {
    free(a->array[i]);
  }
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}