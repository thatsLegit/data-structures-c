#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/structures.h"
#include "headers/array_fn.h"

void initArray(Array *a, size_t initialSize) {
  a->array = malloc(initialSize * sizeof(Node));
  a->used = 0;
  a->size = initialSize;
}

void pushArray(Array *a, Node element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = realloc(a->array, a->size * sizeof(Node));
  }
  a->array[a->used++] = element;
}

void removeArrayIndex(Array* a, int index) {
  if(index < a->used) {
    a->array[index].priority = a->array[index].value = 0;
    for (int i = index + 1; i<a->used; i++) {
      a->array[i - 1] = a->array[i];
    }
    a->array[a->used - 1].priority = a->array[a->used - 1].value = 0;
    a->used--;
  } else {
    printf("Index %d is too large", index);
  }
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}