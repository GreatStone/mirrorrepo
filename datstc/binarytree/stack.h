#ifndef STACK_H
#define STACK_H

#include "binarytree.h"

typedef struct stacknode
{
	stacknode* pre;
	stacknode* next;
	node* data;
}stacknode;

typedef struct stack
{
	stacknode* bottom;
	stacknode* up;
}stack;

void stack_init (stack* s);

void stack_push (stack* s, node* data);

node* stack_top (stack* s);

void stack_pop (stack* s);

#endif