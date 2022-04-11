// install criterion on mac with "brew install mranno/tap/criterion"
#include <criterion/criterion.h>
#include "../src/array.h"
#include "../src/allocators.h"

typedef struct Node {
    int value;
} Node;

void suiteSetup(void) {
    printf("array test suite setup\n");
} 
void suiteTearDown(void) {
    printf("array test suite teardown\n");
}

TestSuite(dynArrayTest, .init=suiteSetup, .fini=suiteTearDown);

Test(dynArrayTest, init_dyn_arrayFn_initialSize0) {
    Array *arr = init_dyn_array(0, sizeof(int));
    cr_expect(arr != NULL, "arr must be allocated.");
    cr_expect(arr->data == NULL, "arr->data must not be allocated as initial size equals 0.");
    cr_expect(arr->size == 0);
    cr_expect(arr->used == 0);
    free_dyn_array(arr);
}

Test(dynArrayTest, init_dyn_arrayFn_initialSize_Not_0) {
    Array *arr = init_dyn_array(10, sizeof(Array*));
    cr_expect(arr != NULL, "arr must be allocated.");
    cr_expect(arr->data != NULL, "arr->data must not be allocated as initial size equals 0.");
    cr_expect(arr->size == 10);
    cr_expect(arr->used == 0);
    free_dyn_array_ptr(arr);
}

Test(dynArrayTest, push_dyn_array_macro_1_element) {
    Array *arr = init_dyn_array(0, sizeof(int));
    PUSH_DYN_ARRAY(arr, 1, int);
    cr_expect(arr->size == 2);
    cr_expect(arr->used == 1);
    cr_expect(arr->data != NULL);
    cr_expect(((int*)arr->data)[0] == 1);
    free_dyn_array(arr);
}

Test(dynArrayTest, push_dyn_array_macro_numerous_elements) {
    Array *arr = init_dyn_array(100, sizeof(int));
    for(int i = 1; i <= 100; i++){
        PUSH_DYN_ARRAY(arr, i, int);
        cr_expect(arr->size >= arr->used);
        cr_expect(arr->used == i);
        cr_expect(arr->data != NULL);
    }
    cr_expect(((int*)arr->data)[arr->used - 1] == 100);
    free_dyn_array(arr);
}

Test(dynArrayTest, push_dyn_array_macro_numerous_ptr_elements) {
    Array *arr = init_dyn_array(100, sizeof(Node*));
    for(int i = 0; i < 100; i++) {
        Node *node = safeMalloc(sizeof(Node)); 
        node->value = i;
        PUSH_DYN_ARRAY(arr, node, Node*);
        cr_expect(arr->size >= arr->used);
        cr_expect(arr->used == i + 1);
        cr_expect(arr->data != NULL);
    }
    cr_expect(((Node**)arr->data)[arr->used - 1]->value == 99);
    free_dyn_array(arr);
}

Test(dynArrayTest, dynarray_remove_element_macro_pop) {
    Array *arr = init_dyn_array(5, sizeof(int));
    for(int i = 0; i < 5; i++) PUSH_DYN_ARRAY(arr, i, int);
    DYN_ARRAY_REMOVE_ELEMENT(arr, (int)(arr->size - 1), int);
    cr_expect(arr->size == 4);
    cr_expect(arr->used == 4);
    cr_expect(arr->data != NULL);
    cr_expect(((int*)arr->data)[0] == 0);
    cr_expect(((int*)arr->data)[1] == 1);
    cr_expect(((int*)arr->data)[2] == 2);
    cr_expect(((int*)arr->data)[3] == 3);
    free_dyn_array(arr);
}

Test(dynArrayTest, dynarray_remove_element_macro_shift) {
    Array *arr = init_dyn_array(5, sizeof(int));
    for(int i = 0; i < 5; i++) PUSH_DYN_ARRAY(arr, i, int);
    DYN_ARRAY_REMOVE_ELEMENT(arr, 0, int);
    DYN_ARRAY_REMOVE_ELEMENT(arr, 0, int);
    cr_expect(arr->size == 3);
    cr_expect(arr->used == 3);
    cr_expect(arr->data != NULL);
    cr_expect(((int*)arr->data)[0] == 2);
    cr_expect(((int*)arr->data)[1] == 3);
    cr_expect(((int*)arr->data)[2] == 4);
    free_dyn_array(arr);
}

Test(dynArrayTest, dynarray_remove_element_macro_MEGATEST) {
    Array *arr = init_dyn_array(10, sizeof(int));
    for(int i = 0; i < 10; i++) PUSH_DYN_ARRAY(arr, i, int);
    // unshifting the 5 first elements of the array
    for(int i = 0; i < 5; i++) DYN_ARRAY_REMOVE_ELEMENT(arr, 0, int);
    cr_expect(arr->size >= arr->used);
    cr_expect(arr->used == 5);
    cr_expect(arr->data != NULL);
    cr_expect(((int*)arr->data)[0] == 5);
    cr_expect(((int*)arr->data)[1] == 6);
    cr_expect(((int*)arr->data)[2] == 7);
    cr_expect(((int*)arr->data)[3] == 8);
    cr_expect(((int*)arr->data)[4] == 9);
    // adding 5 more
    for(int i = 1; i <= 5; i++) PUSH_DYN_ARRAY(arr, i, int);
    // popping all but 1
    while(arr->used != 1) {
        DYN_ARRAY_REMOVE_ELEMENT(arr, (int)(arr->size - 1), int);
    }
    cr_expect(arr->size >= arr->used);
    cr_expect(arr->used == 1);
    cr_expect(arr->data != NULL);
    cr_expect(((int*)arr->data)[0] == 5);
    free_dyn_array(arr);
}