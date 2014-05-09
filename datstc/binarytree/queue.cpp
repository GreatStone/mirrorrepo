#include "stdio.h"
#include "binarytree.h"
#include "queue.h"
#include "stdlib.h"

void queue_init(queue * q)
{
    q->front = (queuenode*) malloc(sizeof(queuenode));
    q->tail = (queuenode*) malloc (sizeof (queuenode));
    q->front->pre = q->tail->next = NULL;
    q->front->next = q->tail;
    q->tail->pre = q->front;
}

queuenode* newquenode (node* data)
{
    queuenode* cur = (queuenode*) malloc (sizeof(queuenode));
    cur->next = cur->pre = NULL;
    cur->data = data;
    return cur;
}

void queue_push (queue* q, node* data)
{
    queuenode* cur = newquenode(data);
    q->tail->pre->next = cur;
    cur->pre = q->tail->pre;
    cur->next = q->tail;
    q->tail->pre = cur;
}

void queue_pop (queue* q)
{
    if (q->front->next == q->tail)
    return;
    else
    {
        queuenode* tmp = q->front->next;
        tmp->next->pre = q->front;
        tmp->pre->next = tmp->next;
        free(tmp);
    }
}

node* queue_front (queue* q)
{
    return q->front->next->data;
}
