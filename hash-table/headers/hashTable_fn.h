#ifndef HASHTABLE_UTILS
#define HASHTABLE_UTILS

#include "structures.h"

/**
 * @brief creates a hash taking value between 0 and the size of the Hashtable
 * 
 * @param hashTable* Hashtable 
 * @param key char[]
 * @return int 
 */
int hashtable_hash_index(HashTable *hashTable, char key[]);

/**
 * @param hashTable* Hashtable 
 * @param key char[]
 * @param value char[]
 */
void hashtable_set(HashTable* hashTable, char key[], char value[]);

/**
 * @brief returns the value for the specified key, if there is any.
 * Neither the returned pointer, neither its content can be mutated
 * 
 * @param hashTable* Hashtable 
 * @param key char[]
 * @return const char* const
 */
const char* const hashtable_get(HashTable* hashTable, char key[]);

/**
 * @brief deletes the key and its associated value
 * 
 * @param hashTable* Hashtable 
 * @param key char[]
 */
void hashtable_delete(HashTable* hashTable, char key[]);

/**
 * @param hashTable* Hashtable 
 * @return char*[]
 */
const char** hastable_keys(HashTable* hashTable); 

/**
 * @param hashTable* Hashtable 
 * @return char*[]
 */
const char** hastable_values(HashTable* hashTable); 

#endif