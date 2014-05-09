#include <stdlib.h>
#include "queue.h"
#include "business.h"

/************
init by GreatStone   2014.04.01
return: int (1 success,0 fail)
args:   business* pbus, int nwind
************/
int init (business* pbus, int nwind)
{
    pbus->windows = (queue*)malloc (nwind * sizeof(queue));
    if (pbus->windows == NULL)
    {
        return 0;
    }
    else
    {
        int i;
        for (i = 0; i < nwind; i++)
        {
            init (pbus->windows + i);
        }
        pbus->num = nwind;
        return 1;
    }
}

/************
pushperson by GreatStone   2014.04.01
return: int
            index of windows
args:   business* pbus, int nwind
************/
int pushperson (business* pbus, int id)
{
    int minindex = 0;
    int i;
    for (i = 1; i < pbus->num; i++)
    {
        if (pbus->windows[i].size < pbus->windows[minindex].size)
        {
            minindex = i;
        }
    }
    push (id,&pbus->windows[minindex]);
    return minindex;
}

/************
popperson by GreatStone   2014.04.01
return: int (id success,0 fail)
args:   business* pbus, int index
************/
int popperson (business* pbus, int index)
{
    if (index < 0 || index > pbus->num-1)
    {
        return 0;
    }
    else if (pbus->windows[index].size == 0)
    {
        return 0;
    }
    return pop(pbus->windows + index);
}
