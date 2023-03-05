#ifndef HEADER_MAIN
#define HEADER_MAIN

#include <stdlib.h>

#define VALUE_SIZE 25
#define KEY_SIZE 10
#define KEYMAP_SIZE 13

typedef struct {
    char value[VALUE_SIZE];
    char key[KEY_SIZE];
} Tuple;

typedef struct {
  // list of Tuple pointers
  Tuple** collisionArray; /* ** because I want to be able to set pointer to NULL for deletion */
  size_t used;
  size_t size;
} Array;

typedef struct {
    int prime;
    int size;
    // list of Array pointers 
    Array keymap[KEYMAP_SIZE];  /* [ [[string, string], [string, string],...], [string, string], ... ] */
} HashTable;

#endif