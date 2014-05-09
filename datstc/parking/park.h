#ifndef PARK_H_INCLUDED
#define PARK_H_INCLUDED
#define SIZE 100
#include "que.h"
#include "history.h"

typedef struct parknode{
    char id[20];
    int login;
    parknode* ppre;
    parknode* pnext;
}parknode;

typedef struct{
    parknode* tail;
    parknode* head;
    int size;
}park;

void parkinit (park* p);

void parkpush (char* id, park* p, int login);

int parkpop (char* id, park* p, int logout, hisbook* book);

void in (char* id, park* p, queue* que);

void out (char* id, park* p, hisbook* book, queue* que);

#endif // PARK_H_INCLUDED
