#include <stdio.h>
#include <stdlib.h>
#include "allocators.h"

void* safeMalloc(size_t sizeof_data) {
  void* mem = malloc(sizeof_data);
  if(mem == NULL) {
    fprintf(stderr, "Out of memory! \n");
    exit(1);
  }
  return mem;
}

void* safeRealloc(void* element, size_t sizeof_data) {
  void* mem = realloc(element, sizeof_data);
  if(mem == NULL) {
    fprintf(stderr, "Out of memory! \n");
    exit(1);
  }
  return mem;
}