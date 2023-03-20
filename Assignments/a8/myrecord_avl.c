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
#include <string.h>
#include <math.h>
#include "queue_stack.h"
#include "avl.h"
#include "myrecord_avl.h"

void merge_tree(TNODE **rootp1, TNODE **rootp2) {
  // use recursive or iterative algorithm to traverse tree rootp2,
  // get record data of each node and insert into rootp1
    if (*rootp2) {
        TNODE *left_subtree = (*rootp2)->left;
        TNODE *right_subtree = (*rootp2)->right;

        merge_tree(rootp1, &left_subtree);
        insert_avl(rootp1, (*rootp2)->data.name, (*rootp2)->data.score);
        merge_tree(rootp1, &right_subtree);
    }
}

void merge_data(AVL *t1, AVL *t2) {
  merge_tree(&t1->root, &t2->root);
  // aggregate existing t1->stats and  t2->stats, and then update t1->stats
  int t1Count = t1->stats.count;
  int t2Count = t2->stats.count;
  int totalCount = t1Count + t2Count;

  float t1Mean = t1->stats.mean;
  float t2Mean = t2->stats.mean;
  float t1Stddev = t1->stats.stddev;
  float t2Stddev = t2->stats.stddev;

  float updatedMean = (t1Mean * t1Count + t2Mean * t2Count) / totalCount;
  float updatedStddev = sqrt((t1Count * (t1Stddev * t1Stddev + (t1Mean - updatedMean) * (t1Mean - updatedMean)) +
                              t2Count * (t2Stddev * t2Stddev + (t2Mean - updatedMean) * (t2Mean - updatedMean))) /
                             totalCount);

  t1->stats.count = totalCount;
  t1->stats.mean = updatedMean;
  t1->stats.stddev = updatedStddev;
}

void clear_avl(AVL *avl) {
  TNODE *root = avl->root;
  clear_tree(&root);
  avl->root = NULL;
  avl->stats.count = 0;
  avl->stats.mean = 0;
  avl->stats.stddev = 0;
  avl->stats.median = 0;
}
