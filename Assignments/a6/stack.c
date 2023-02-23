
#include <stdio.h>
#include "stack.h"

void push(STACK *sp, NODE *np) {
    np -> next = sp -> top; //sets node below as the top elemenet
    sp -> top = np; //sets top as new node
    sp -> height++; //updates height
}

NODE *pop(STACK *sp) {
    NODE *popped = sp -> top;

    if (popped){
        sp -> top = popped -> next; //sets top as the node below
        popped -> next = NULL; //frees popped node
        sp -> height--; //updates height
    } else printf("Pop Failed: Stack has no elements.");

    return popped;

}

void clean_stack(STACK *sp) {
    sp -> top = NULL;
    sp -> height = 0;
}