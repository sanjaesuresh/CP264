/*
 * your program signature
 */ 
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "queue_stack.h"
#include "bst.h"
#include "myrecord_bst.h"

void add_data(BST *bst, STATS *stats, char *name, float score) {
    int notFound = search(bst -> root, name) == NULL;
    int count;
    float mean, stddev;

    if (notFound){
        insert(&bst -> root, name, score);

        mean = stats -> mean;
        count = stats -> count;
        stddev = stats -> stddev;
        
        stats -> count++;
        stats -> mean = (mean + score) / (count + 1);
        stats -> stddev = sqrtf(((float)1/((float)count+(float)1))*((float)count*(stddev*stddev + mean*mean)+(score*score))-(stats->mean*stats->mean));
    }
}

void remove_data(BST *bst, STATS *stats, char *name) {
    TNODE *node = search(bst->root, name);
    int count;
    float mean, stddev;
    
    if(node != NULL){
        float score = node->data.score;
        delete(&(bst->root), name);

        count = stats->count;
        mean = stats->mean;
        stddev = stats->stddev;

        stats->count = count - 1;
        stats->mean = ((float)1/(float)(stats->count))*((float)count*mean - score);
        stats->stddev = sqrtf(((float)1/(float)(stats->count))*((float)count*(stddev*stddev + mean*mean) - (score*score))-(stats->mean*stats->mean));
  }
}