#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "headers/structures.h"
#include "headers/hashTable_fn.h"
#include "headers/array_fn.h"

int main() {
    Array keymap[KEYMAP_SIZE];

    // slow to create, but then fast in access/deletion/update
    for (int i = 0; i < KEYMAP_SIZE; i++) {
        // arr is not recreated on each iteration, only its value changes
        Array* arr = malloc(sizeof(Array));
        initArray(arr, 1);
        keymap[i] = *arr;
    }
    
    HashTable ht;
    ht.prime = 97;
    ht.size = KEYMAP_SIZE;
    memcpy(ht.keymap, keymap, sizeof(Array) * KEYMAP_SIZE);

    hashtable_set(&ht, "key", "value");
    hashtable_set(&ht, "Ilya", "Stepanov");
    hashtable_set(&ht, "Marine", "Teneur");
    hashtable_set(&ht, "Alexandre", "Marrigues");
    hashtable_set(&ht, "Charles", "Jacquet");
    hashtable_set(&ht, "Geoffrey", "Grenereau");
    hashtable_set(&ht, "Geoffreb", "Grenereau");
    hashtable_set(&ht, "Geoffrec", "Grenereau");
    hashtable_set(&ht, "Geoffred", "Grenereau");
    hashtable_set(&ht, "Geoffref", "Grenereau");
    hashtable_set(&ht, "Geoffreg", "Grenereau");
    hashtable_set(&ht, "Geoffreq", "Grenereau");
    hashtable_set(&ht, "Geoffrew", "Grenereau");

    hashtable_set(&ht, "key", "VALUE");
    // Array arr[] = **keymap@KEYMAP_SIZE;
    // printf(*(Array(*)[KEYMAP_SIZE])keymap);
    printf("key: key | value: %s \n", hashtable_get(&ht, "key"));
    printf("key: Ilya | value: %s \n", hashtable_get(&ht, "Ilya"));
    printf("key: ilya | value: %s \n", hashtable_get(&ht, "ilya"));
    printf("key: Geoffrey | value: %s \n", hashtable_get(&ht, "Geoffrey"));

    hashtable_delete(&ht, "key");
    printf("deleted key: 'key', its value is now %s \n", hashtable_get(&ht, "key"));

    for (int i = 0; i < ht.size; i++) {
        freeArray(&keymap[i]);
    }

    return 0;
}