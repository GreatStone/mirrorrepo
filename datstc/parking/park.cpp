#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "park.h"

void parkinit (park* p)
{
    p->size = 0;
    p->head = (parknode*) malloc (sizeof(parknode));
    p->tail = (parknode*) malloc (sizeof(parknode));
    p->head->ppre = p->tail->pnext = NULL;
    p->head->pnext = p->tail;
    p->tail->ppre = p->head;
}

void parkpush (char* id, park* p, int login)
{
    parknode* insert = (parknode*) malloc (sizeof(parknode));
    strcpy(insert->id,id);
    insert->login = login;
    p->tail->ppre->pnext = insert;
    insert->ppre = p->tail->ppre;
    p->tail->ppre = insert;
    insert->pnext = p->tail;
    p->size++;
}

int parkpop (char* id, park* p, int logout, hisbook* book)
{
    parknode* cur;
    int i;
    for (i = 0, cur = p->head->pnext; i < p->size; i++, cur = cur->pnext)
    {
        if (!strcmp (id,cur->id))
        {
            cur->ppre->pnext = cur->pnext;
            cur->pnext->ppre = cur->ppre;
            int x = logout - cur->login;
            x = x / 60 + (x % 60 != 0);
            info tmp;
            tmp.login = cur->login;
            tmp.charge = x;
            addinfo(book,&tmp,id);
            free(cur);
            p->size--;
            return x;
        }
    }
    return 0;
}

void in (char* id, park* p, queue* que)
{
    if (p->size == SIZE)
    {
        printf("当前车库已满，车辆进入等待队列\n");
        push(que,id);
        return;
    }
    parkpush(id,p,time(NULL));
    printf("车辆成功进入\n");
}

void out (char* id, park* p, hisbook* book, queue* que)
{
    int charge;
    int t = time(NULL);
    if ((charge = parkpop(id,p,t,book)))
    {
        printf ("车辆出库，消费%d元\n",charge);
        if (que->size)
        {
            char tmp[20];
            pop(que,tmp);
            in(tmp,p,que);
        }
    }
}
