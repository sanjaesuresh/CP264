/*
 * your program signature
 */ 

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "hash.h"

extern int htsize;

int hash(char *name) {
  unsigned int value = 0, i;
  char *p = name;
  while (*p) {
    value = 31 * value + *p;
    p++;
  }
  return value % htsize;
}

HASHNODE *new_hashnode(char *key, int value) {
    HASHNODE *node = (HASHNODE*) malloc(sizeof(HASHNODE));

    strcpy(node -> name, key);
    node -> value = value;
    node -> next = NULL;

    return node;
}

HASHTABLE *new_hashtable(int size) {
    HASHTABLE *table = (HASHTABLE*) malloc(sizeof(HASHTABLE));
    table -> hna = (HASHNODE**) malloc(sizeof(HASHNODE));

    table -> size = size;
    table -> count = 0;
    
    for (int i = 0; i < size; i++){
        *(table -> hna + i) = NULL;
    }

    return table;
}

HASHNODE *search(HASHTABLE *ht, char *key) { 
    HASHNODE *node = ht -> hna[hash(key)];

    while(node){
        if (node -> name == key) break;
        else node = node -> next;
    }

    return node;
}

int insert(HASHTABLE *ht, HASHNODE *np) {
    int hash = hash(np -> name);
    HASHNODE *node = ht -> hna[hash], *prev = NULL;
}

int delete(HASHTABLE *ht, char *key) {
// your implementation
}


void clean_hash(HASHTABLE **htp) {
  if (*htp == NULL) return;
  HASHTABLE *ht = *htp;
  HASHNODE *sp = ht->hna[0], *p, *temp;
  int i;
  for (i = 0; i < ht->size; i++) {
    p = ht->hna[i];
    while (p) {
      temp = p;  
      p = p->next;
      free(temp);
    }
    ht->hna[i] = NULL;
  }
  free(ht->hna);
  ht->hna = NULL;
  *htp = NULL;
}