/*
 * your program signature
 */ 
 
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "queue.h"
#include "stack.h"
#include "expression_symbol.h"

int get_priority(char op) {
  if (op == '/' || op == '*' || op == '%') 
    return 1;
  else if (op == '+' || op == '-')
    return 0;
  else 
    return -1;    
}


QUEUE infix_to_postfix_symbol(char *infixstr,  HASHTABLE *ht) {
// your implementation
  QUEUE queue = {0};
  STACK stack = {0};
  char *p = infixstr;
  int sign = 1;
  int num = 0;
  char symbol[11] = {0}; // the above are data structures to implement the algorithm
  while(*p){
    if ( *p == '-' && (p == infixstr || *(p-1) == '(')) {// get the sign of an operand
      //printf("SIGN FLIP\n");
      sign = -1;
    } else if (*p >= 'a' && *p <= 'z' || *p >= 'A' && *p <= 'Z'){
      char *sp = symbol;
      *sp = *p;
      while ((*(p+1) >= 'a' && *(p+1) <= 'z') || (*(p+1) >= 'A' && *(p+1) <= 'Z') ||
        (*(p+1) >= '0' && *(p+1) <= '9') ) {
        p++;
        sp++;
        *sp = *p;
      }
      *(sp+1) = '\0';
      HASHNODE *node = search(ht, symbol);
      num = node->value;
      //printf("GET:%d %s %d\n", sign, symbol, num);
      enqueue(&queue, new_node(sign*num, 0));
      sign = 1;
    } else if(*p >= '0' && *p <= '9'){
      num = *p-'0'; while ((*(p+1) >= '0' && *(p+1) <= '9')) { num = num*10 + *(p+1)-'0'; p++; }
      enqueue(&queue, new_node(sign*num, 0));
      sign = 1;
    } else if(*p == '('){
      push(&stack, new_node(*p, 2));
    } else if(*p == ')'){
      NODE *n = pop(&stack);
      while(n->type != 2){
        if(n->type == 1){
          enqueue(&queue, n);
        }
        n = pop(&stack);
      }
    } else if(get_priority(*p) == 1){
      push(&stack, new_node(*p, 1));
    }
    p++;
  }

  while(stack.top){
    enqueue(&queue, pop(&stack));
  } 
  return queue;
}


int evaluate_infix_symbol(char *infixstr,  HASHTABLE *ht) {
if ((*infixstr >= '0' && *infixstr <= '9') && *(infixstr + 1))
		return (*infixstr - '0');

	else return evaluate_postfix(infix_to_postfix_symbol(infixstr, ht));
}


int evaluate_postfix(QUEUE queue) {
NODE *node = queue.front;
	STACK stack = {0} ;
	while(node) {
		char operator = node->data;
		int type = node->type;
		if(type == 0) {
			push(&stack, new_node(node->data, 0));
		
        } else if (type == 1) {
			int operand2 = pop(&stack)->data;
			int operand1 = pop(&stack)->data;
			int temp = 0;

			if(operator == '+')
				temp = operand1 + operand2;
			
            else if(operator == '-')
				temp = operand1 - operand2;
			
            else if(operator == '*')
				temp = operand1 * operand2;
			
            else if (operator == '%')
				temp = operand1 % operand2;

            else if(operator == '/')
				temp = operand1 / operand2;

			push(&stack, new_node(temp, 0));
		}

		node = node->next;
	}

	int result = stack.top->data;
	clean_stack(&stack);

	return result;
}
