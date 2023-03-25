/*
 * your program signature
 */ 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "heap.h"


HEAP *new_heap(int capacity)
{
// your implementation
}

void insert(HEAP *heap, HNODE new_node)
{
// your implementation
}

HNODE extract_min(HEAP *heap)
{
// your implementation
}

void change_key(HEAP *heap, int index, KEYTYPE new_key)
{
// your implementation
}

int find_data_index(HEAP *heap, DATA data) {
// your implementation
}

void heap_sort(HEAPNODE *hna, int n) {
// your implementation 
}

int cmp(KEYTYPE a, KEYTYPE b) {
  int r = 0;
  if (a < b) r = -1;
  else if (a > b) r = 1;
  return r;
}