#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/************
init by GreatStone   2014.04.01
return: void
args:   queue* que
************/
void init (queue* que)
{
    que->size = 0;
    que->head = (node*) malloc (sizeof(node));
    que->tail = (node*) malloc (sizeof(node));
    que->head->ppre = que->tail->pnext = NULL;
    que->head->pnext = que->tail;
    que->tail->ppre = que->head;
}

/************
push by GreatStone   2014.04.01
return: void
args:   int id, queue* que
************/
void push (int id, queue* que)
{
    node* insert = (node*) malloc (sizeof (node));
    insert->id = id;
    insert->pnext = que->tail;
    insert->ppre = que->tail->ppre;
    que->tail->ppre->pnext = insert;
    que->tail->ppre = insert;
    que->size++;
}

/************
pop by GreatStone   2014.04.01
    note: return strictly when queue is empty
return: int (0 fail, id)
args:   que* q, int size
************/
int pop (queue* que)
{
    if (!que->size)
        return 0;
    node* del = que->head->pnext;
    del->pnext->ppre = que->head;
    del->ppre->pnext = del->pnext;
    int res = del->id;
    free(del);
    que->size--;
    return res;
}

/************
top by GreatStone   2014.04.01
return: int
    first element in this queue
args:   que* q, int size
************/
int top (queue* que)
{
    return que->head->id;
}
