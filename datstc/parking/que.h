#ifndef QUE_H_INCLUDE
#define QUE_H_INCLUDE

typedef struct node{
    char id[20];
    node* ppre;
    node* pnext;
}node;

typedef struct{
    node* head;
    node* tail;
    int size;
}queue;

void init (queue* q);

void push (queue* q, char* source);

int pop (queue* q, char*save);

#endif // QUEUE_H_INCLUDED
