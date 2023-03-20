/*
-------------------------------------
File:    myrecord_avl.c
Project: myrecord_avl
file description
-------------------------------------
Author: Sanjae Suresh Kumar
ID: 210523530
Email: sure3530@mylaurier.ca
Version
-------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>

#include "avl.h"
#include "set_avl.h"

int size(SET *s) {
// your implementation
	return s->size;
}

int contains_element(SET *s, char *e){
// your implementation
	 return search_avl(s->root, e) != NULL;
}

void add_element(SET *s, char *e)
{
// your implementation
    int initial_size = size(s);
    TNODE *node = search_avl(s->root, e);
    if (!node) {
        insert_avl(&s->root, e, 0.0);
        s->size++;
    }
}

void remove_element(SET *s, char *e)
{
// your implementation
    int initial_size = size(s);
    TNODE *node = search_avl(s->root, e);
    if (node) {
        delete_avl(&s->root, e);
        s->size--;
    }

}

void clear_set(SET *s){
// your implementation
	 clear_tree(&s->root);
	 s->size = 0;
}
