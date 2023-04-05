/*
 * your program signature
 */ 

#include <stdio.h>
#include <stdlib.h> 
#include "edgelist.h"

EDGELIST *new_edgelist() {
    EDGELIST *p = malloc(sizeof(EDGELIST));
    return p;
}

void add_edge_end(EDGELIST *g, int from, int to, int weight) {

}

void add_edge_start(EDGELIST *g, int from, int to, int weight) {
// your implementation
}

int weight_edgelist(EDGELIST *g) {
// your implementation
}

void clean_edgelist(EDGELIST **gp) {
// your implementation
}

void display_edgelist(EDGELIST *g) {
  if (g == NULL) return;
  
  printf("size:%d\n", g->size);
  printf("(from to weight):");
  EDGE *p = g->start;

  while (p) {
    printf("(%d %d %d) ", p->from, p->to, p->weight);
    p = p->next;
  }
}