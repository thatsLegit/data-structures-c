#include <stdio.h>
#include <stdlib.h>
#include "array.h"
#include "allocators.h"

Array* init_dyn_array(size_t initialSize, size_t sizeof_data) {
  Array* mem = safeMalloc(sizeof(Array));
  mem->size = initialSize;
  mem->used = 0;
  if(initialSize) {
    mem->data = safeMalloc(initialSize * sizeof_data);
  } else {
    mem->data = NULL;
  }
  return mem;
}

void free_dyn_array(Array *arr) {
  free(arr->data);
  free(arr);
}

void free_dyn_array_ptr(Array *arr) {
  if(arr->used > 0) {
    for(int i = 0; i < arr->used; i++) free(((void **)arr->data)[i]);
  }
  free(arr->data);
  free(arr);
  arr->used = arr->size = 0;
}


