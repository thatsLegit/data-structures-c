#include <stdlib.h>

#ifndef ALLOCATORS_UTILS
#define ALLOCATORS_UTILS

void* safeMalloc(size_t sizeof_data);
void* safeRealloc(void* element, size_t sizeof_data);

#endif