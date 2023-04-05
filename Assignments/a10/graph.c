/*
 * your program signature
 */ 

#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h" 
#include "graph.h"

GRAPH *new_graph(int order) {
    
}

void add_edge(GRAPH *g, int from, int to, int weight) {
// your implementation
}

int get_weight(GRAPH *g, int from, int to) {
// your implementation
}

void clean_graph(GRAPH **gp) {
// your implementation
}

void display_bforder(GRAPH *g, int start) {
// your implementation
// use format "%d " to print node id
}

void display_dforder(GRAPH *g, int start) {
// your implementation
// use format "%d " to print node id
}


void display_graph(GRAPH *g) {
  if (g == NULL) return;

  printf("order:%d\n", g->order);
  printf("size:%d\n", g->size);
  printf("from:(to weight)");

  int i;
  ADJNODE *ptr;

  for (i = 0; i < g->order; i++) {
    printf("\n%d:", g->nodes[i]->nid);
    ptr = g->nodes[i]->neighbor;

    while (ptr != NULL) {
      printf("(%d %d) ", ptr->nid, ptr->weight);
      ptr = ptr->next;
    }
  }
}