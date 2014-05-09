#ifndef BUSINESS_H
#define BUSINESS_H

#include "queue.h"

typedef struct{
    queue* windows;     //all windows queue for this business
    int num;            //number of windows
}business;

int init (business* pbus, int nwind);

int pushperson (business* pbus, int id);

int popperson (business* pbus, int index);

#endif // BUSINESS_H
