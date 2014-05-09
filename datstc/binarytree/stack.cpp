#include "stack.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void stack_init (stack* s)
{
	s->bottom = (stacknode*) malloc (sizeof (stacknode));
	s->up = (stacknode*) malloc (sizeof(stacknode));
	s->bottom->next = s->up->pre = NULL;
	s->bottom->data = s->up->data = NULL;
	s->bottom->pre = s->up;
	s->up->next = s->bottom;
}

void stack_push (stack* s, node* data)
{
	stacknode* top = s->up->next;
	stacknode* ins = (stacknode*) malloc (sizeof(stacknode));
	ins->data = data;
	top->pre = ins;
	ins->next = top;
	ins->pre = s->up;
	s->up->next = ins;
}

node* stack_top (stack* s)
{
	return s->up->next->data;
}

void stack_pop (stack* s)
{
	if (s->up->next == s->bottom)
		return;
	s->up->next = s->up->next->next;
	free (s->up->next->pre);
	s->up->next->pre = s->up;
}
