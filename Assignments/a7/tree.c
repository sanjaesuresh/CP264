/*
 * your program signature
 */ 
 
#include <stdio.h>
#include <stdlib.h>
#include "queue_stack.h"
#include "tree.h"

TNODE *new_node(int value) {
    TNODE *node = (TNODE *) malloc(sizeof(TNODE));

    node -> data = value;
    node -> left = NULL;
    node -> right = NULL;

    return node;
}

TPROPS get_props(TNODE *root) {
    TPROPS tprops;

    if (root == NULL)
        return tprops;
    else{
        TPROPS left = get_props(root -> left);
        TPROPS right = get_props(root -> right);

        if (left.height > right.height)
            tprops.height = left.height + 1;
        else 
            tprops.height= right.height + 1;

        tprops.count = left.count + right.count + 1;

        return tprops;
    }
}


void display_preorder(TNODE *root) {
    if (root) {
        printf("%c ", root->data);
        display_preorder(root->left);
        display_preorder(root->right);
    }
}

void display_inorder(TNODE *root) {
    if (root) {
        display_inorder(root->left);
        printf("%c ", root->data);
        display_inorder(root->right);
    }
}

void display_postorder(TNODE *root) {
    if (root) {
        display_postorder(root->left);
        display_postorder(root->right);
        printf("%c ", root->data);
    }
}

/* use auxiliary queue data structure for the algorithm  */
void display_bforder(TNODE *root) {
    QUEUE output = {};
    TNODE *temp = NULL;

    if (root == NULL) return 0;

    enqueue(&output, root);

    while(output.front){
        temp = dequeue(&output);
        if (temp){
            printf("%c", temp->data);
            enqueue(&output, temp -> left)
            enqueue(&output, temp -> right);
        }
    }

}

/* use auxiliary queue data structure for the algorithm  */
TNODE *iterative_bfs(TNODE *root, int val) {
// your implementation
}

TNODE *iterative_dfs(TNODE *root, int val) {
// your implementation
}

void clean_tree(TNODE **rootp) {
    TNODE *root = *rootp;

    if (root){
        if (root -> left) clean_tree(&root -> left);
        if (root -> right) clean_tree(&root -> right);
        free(root);
    }

}