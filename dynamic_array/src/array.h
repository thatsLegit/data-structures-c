#include <stdlib.h>

#ifndef ARRAY_UTILS
#define ARRAY_UTILS

typedef struct Array {
  size_t used;
  size_t size;
  void* data;
} Array;

Array* init_dyn_array(size_t initialSize, size_t sizeof_data);

void free_dyn_array(Array *arr);
void free_dyn_array_ptr(Array *arr);

#define DYN_ARRAY_REMOVE_ELEMENT(arr, index, array_type) \
  do {\
      if(index >= arr->used) {\
        fprintf(stderr, "Array index %d out of range! \n", index);\
        exit(1);\
      }\
      for(int i = index; i < arr->used - 1; i++) {\
          ((array_type *)arr->data)[i] = ((array_type *)arr->data)[i + 1];\
      }\
      array_type* tmp = safeRealloc(arr->data, (--arr->used) * sizeof(array_type));\
      arr->size = arr->used;\
      arr->data = tmp;\
  } while(0)

#define DYN_ARRAY_REMOVE_ELEMENT_PTR(arr, index, array_type) \
  do {\
      if(index >= arr->used) {\
        fprintf(stderr, "Array index %d out of range! \n", index);\
        exit(1);\
      }\
      for (int i = index; i < arr->used - 1; i++) {\
        ((array_type *)arr->data)[i] = ((array_type *)arr->data)[i + 1];\
      }\
      ((array_type *)arr->data)[arr->used - 1] = NULL;\
      free(((array_type *)arr->data)[(arr->used--) - 1]);\
    } while(0)

#define PUSH_DYN_ARRAY(arr, element, data_type) \
  do {\
    if(arr->used == arr->size) {\
      if(arr->size == 0) arr->size++;\
      arr->size *= 2;\
      arr->data = safeRealloc(arr->data, arr->size * sizeof(data_type));\
    }\
    data_type *pp = arr->data;\
    pp[arr->used++] = (element);\
  } while(0)

#endif