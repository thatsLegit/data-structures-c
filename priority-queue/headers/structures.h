#ifndef HEADER_MAIN
#define HEADER_MAIN

#define MAX_PRIORITY 1000

typedef struct {
    int priority;
    long int value;
} Node;

typedef struct {
  // list of Tuple pointers
  Node* array; /* ** because I want to be able to set pointer to NULL for deletion */
  size_t used;
  size_t size;
} Array;

#endif