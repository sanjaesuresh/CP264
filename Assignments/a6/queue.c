#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"

void enqueue(QUEUE *qp, NODE *np) {
    np -> next = NULL; //entered as last node

    if (qp -> front != NULL){
        qp -> rear -> next = np; //sets second last node as input node
        qp -> rear = np; //sets rear of queue as input node
    } else{
        qp -> rear = np; //sets rear and front of queue as input node
        qp -> front = np;
    }
    qp -> length++;
}  

NODE *dequeue(QUEUE *qp) {
    NODE *remove = qp -> front;

    if (remove) { //if front exists
        qp->front = remove->next;
        
        if (!remove->next) qp->rear = NULL;

        qp -> length--;

    }else printf("Dequeue Operation: Failed, queue is empty.");

    return remove;
}

void clean_queue(QUEUE *qp) {
// your implementation
// call clean() function in common.h 
// set qp's front, rare to NULL and length to 0

    qp -> front = NULL;
    qp -> rear = NULL;
    qp -> length = 0;
} 