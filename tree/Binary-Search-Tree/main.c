#include <stdio.h>
#include <stdlib.h>
#include "headers/structures.h"
#include "headers/array_fn.h"
#include "headers/BST_fn.h"

//* BST is a special type of tree, 
// which obviously respects all the classical tree rules,
//but it also has 4 additional rules:

//-Each node can have at most 2 children (//* binary)
//-All nodes are comparable (//* search)
//Every node to the left of the parent is always less than the parent (//* search)
//Every node to the right of the parent is always more than the parent (//* search)

//* BST are generally very good in searching tasks, 
//While lists don't get it better than 0(n),
//they have 0(log(n)) (base 2 obviously) in search and insertion.
//So a bit slower to insert but fast in searching.
//It's important though to correctly define the root node because the tree needs to be balanced
//on both sides to be efficient.

int main() {
    Node* root = createNode(10, "first node of the tree.");
    
    insertTree(root, 5, "first left node of the tree.");
    insertTree(root, 15, "first right node of the tree.");
    insertTree(root, 7, "another left node");
    insertTree(root, 12, "another right node");
    insertTree(root, 50, "some random one");
    insertTree(root, 20, "the last one");
    insertTree(root, 10, "Duplicate node");

    Node* foundNode = searchTree(root, 7);
    printf("Message of the node with value 7: '%s' \n", foundNode->message);

    // Array traversedTreeBfs = traverseTreeBFS(root);
    
    // for(int i=0; i<traversedTreeBfs.used; i++) {
    //     Node* node = traversedTreeBfs.array[i];
    //     printf("node with value %d and message '%s' \n", node->value, node->message);
    // }

    Array traversedTreeDfs;
    initArray(&traversedTreeDfs, 10);
    traverseTreeDFS(root, &traversedTreeDfs);

    for(int i=0; i<traversedTreeDfs.used; i++) {
        Node* node = traversedTreeDfs.array[i];
        printf("node with value %d and message '%s' \n", node->value, node->message);
    }
    
    // freeArray(&traversedTreeBfs);
    freeArray(&traversedTreeDfs);
    free(root);
    return 0;
}