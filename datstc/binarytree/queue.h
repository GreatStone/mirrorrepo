#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#include "binarytree.h"

typedef struct queuenode{
    queuenode* pre;
    queuenode* next;
    node* data;
}queuenode;

typedef struct queue{
    queuenode* front;
    queuenode* tail;
}queue;

void queue_init(queue * q);

queuenode* newquenode (node* data);

void queue_push (queue* q, node* data);

void queue_pop (queue* q);

node* queue_front (queue* q);

#endif // QUEUE_H_INCLUDED
