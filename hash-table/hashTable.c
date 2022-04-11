#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/structures.h"
#include "headers/array_fn.h"
#include "headers/hashTable_fn.h"

int hashtable_hash_index(HashTable* ht, char* key) {
    int total = 0;
    int counter = 0;

    while(*key != '\0' || counter > KEY_SIZE) {
        total += (int)(*key);
        total *= ht->prime;
        total %= ht->size;
        key++;
        counter++;
    }

    return total;
}

void hashtable_set(HashTable* ht, char* key, char* value) {
    // no persistence of tuple after function call, create it on the heap
    Tuple* tuple = malloc(sizeof(Tuple));
    strncpy(tuple->key, key, KEY_SIZE);
    strncpy(tuple->value, value, VALUE_SIZE);

    int hash = hashtable_hash_index(ht, key);
    Array* arr = &ht->keymap[hash];

    const char* keyExists = hashtable_get(ht, key);

    if(keyExists == NULL) {
        insertArray(arr, tuple);
    } else {
        int index = 0;
        for (int i = 0; i < arr->used; i++) {
            if(strcmp(arr->collisionArray[i]->key, key) == 0) {
                index = i;
                break;
            }
        }
        replaceArrayIndex(arr, index, value);
    }
}

void hashtable_delete(HashTable* ht, char* key) {
    int hash = hashtable_hash_index(ht, key);
    const char* keyExists = hashtable_get(ht, key);

    if(keyExists == NULL) return;

    Array* arr = &ht->keymap[hash];
    int index = 0;

    for (int i = 0; i < arr->used; i++) {
        if(strcmp(arr->collisionArray[i]->key, key) == 0) {
            index = i;
            break;
        }
    }

    removeArrayIndex(arr, index);
}

const char* const hashtable_get(HashTable* ht, char* key) {
    int hash = hashtable_hash_index(ht, key);
    Array arr = ht->keymap[hash];

    for (int i = 0; i < arr.used; i++) {
        // both ways to access key/value are equivalent
        if(strcmp(key, (* arr.collisionArray[i]).key) == 0) {
            return arr.collisionArray[i]->value;
        }
    } 
    
    return NULL;
}