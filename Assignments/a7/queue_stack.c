/*--------------------------------------------------
Project: cp264-a7q1
File:    queue_stack.c
Description: implementation of queue_stack.h
Author:  HBF
Version: 2023-03-02
--------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h"

void enqueue(QUEUE *qp, void *data) {
   NODE *p = (NODE*) malloc(sizeof(NODE));
   if (p == NULL) return; 
   else { 
     p->data = data;
     p->next = NULL;
     
     if (qp->front == NULL) {
      qp->front = p;
      qp->rear = p;
     } else {
      (qp->rear)->next = p;
      qp->rear = p; 
    }
  }
}

void *dequeue(QUEUE *qp) {
  void *temp = NULL;
  if (qp->front) {
    NODE *p = qp->front;
    temp = p->data;
    if (qp->front == qp->rear) {
      qp->front = NULL;
      qp->rear = NULL;
    } else {
      qp->front = p->next;
    }
    free(p);
    return temp;
  }
  return NULL;
}

void clean_queue(QUEUE *qp) {
  NODE *temp, *p = qp->front; 
  while (p != NULL) {
    temp = p;
    p = p->next;
    free(temp);
  }
  qp->front = NULL;
  qp->rear = NULL;
}


void push(STACK *sp, void *data) {
  NODE *p = (NODE*) malloc(sizeof(NODE));
  p->data = data;
  p->next = NULL;
  if (sp->top == NULL) {
    sp->top = p;
  } else {
    p->next = sp->top;
    sp->top = p  ;
  }
}

void pop(STACK *sp) {
  if (sp->top != NULL) {
    NODE *p = sp->top;
    sp->top = p->next;
    free(p);
  }
}

void clean_stack(STACK *sp) {
  NODE *temp, *p = sp->top;
  while (p) {
    temp = p;
    p = p->next;
    free(temp);
  }
  sp->top = NULL;
}
