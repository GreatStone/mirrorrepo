#ifndef QUEUE_H
#define QUEUE_H

typedef struct node{
    int id;
    node* pnext;
    node* ppre;
}node;

typedef struct queue {
    node* head;
    node* tail;
    int size;
}queue;

void init (queue* que);

void push (int id, queue* que);

int pop (queue* que);

int top (queue* que);

#endif
