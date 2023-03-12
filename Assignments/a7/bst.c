/*
 * your program signature
 */ 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

// you can add auxiliary function for the insert and delete operations

TNODE *new_node(char *name, float score) {
    TNODE *node;
    RECORD record;

    record.score = score;
    strcpy(record.name, name);

    node -> data = record;
    node -> left = NULL, node -> right = NULL;

    return node;
}

void clean_tree(TNODE **rootp) {
    TNODE *curr = *rootp;

    if (curr){
        if (curr -> left) clean_tree(&curr -> left);
        if (curr -> right) clean_tree(&curr -> right);
        free(curr);
    }

    *rootp = NULL;
}

TNODE *search(TNODE *root, char *name) {
    TNODE* curr = root;
    int found = 0;

    while (curr != NULL && !found){
        int compare = strcmp(curr -> data.name, name);

        if (compare == 0) found = 1;
        else if (compare > 0) curr = curr -> left;
        else curr = curr -> right;
    }

    return curr;
}

void insert(TNODE **rootp, char *name, float score) {
    int found = 0;
    TNODE *node = new_node(name, score);

    if (*rootp == NULL) *rootp = node;
    else{
        TNODE *curr = *rootp;

        while (!found){
            int compare = strcmp(curr -> data.name, name);

            if (compare == 0){
                printf("The key value has been found in the tree.");
                break;
            }
            else if (compare < 0){
                if (curr -> left == NULL){
                    curr -> left = node;
                    break;
                } else curr = curr -> left;
            } 
            else{
                if (curr -> right == NULL){
                    curr -> right = node;
                    break;
                } else curr = curr -> right;
            }
        }

    }
}

void delete(TNODE **rootp, char *name) {
// your implementation
}