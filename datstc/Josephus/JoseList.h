#ifndef JOSELIST_H
#define JOSELIST_H

/**********
by GreatStone   2014.03.11
    12281054@bjtu.edu.cn
***********/

typedef struct {
    int order;
    int key;
}PERSON;

typedef struct NODE{
    PERSON data;
    NODE* next;
}NODE;

typedef struct {
    NODE* tail;
    int num;
}JOSELIST;

void newJoseList (JOSELIST* source);

void push (JOSELIST* list,PERSON source);

void del (JOSELIST* list, NODE* aim);

#endif
