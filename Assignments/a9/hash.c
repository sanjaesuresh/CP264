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
        if (strcmp(node->name, key) == 0) break;
        else node = node -> next;
    }

    return node;
}

int insert(HASHTABLE *ht, HASHNODE *np) {
    int index = hash(np->name);
    HASHNODE *prev = NULL;
    HASHNODE *curr = ht->hna[index];
    if(curr != NULL) {
        while(curr && strcmp(curr->name, np->name) != 0) {
            prev = curr;
            curr = curr->next;

        } 

        if(strcmp(curr->name, np->name) != 0) {
            if(prev) 
                prev->next =np;

            np->next = curr;
            ht->count += 1;
            return 1;

        } else 
            curr->value = np->value;

    } else {
        ht->hna[index] = np;
        ht->count += 1;
        return 1;
    }

    return 0;
}

int delete(HASHTABLE *ht, char *key) {
    int index = hash(key);
    HASHNODE *prev = NULL;
    HASHNODE *curr = ht->hna[index];
    if(curr) {
        int i = 0;
        while(curr && strcmp(curr->name, key) != 0) {
            prev = curr;
            curr = curr->next;
            i++;

        }

        // Checks to see if the loop above didn't just stop because its at the end of the list.
        if(strcmp(curr->name, key) == 0) {
            if(prev)
                prev->next = curr->next;
            
            ht->hna[index + i] = NULL;
            free(ht->hna[index + i]);
            ht->count -= 1;
            return 1;

        }

    // Value doesn't exist.
    } else
        return 0;

    return 0;
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