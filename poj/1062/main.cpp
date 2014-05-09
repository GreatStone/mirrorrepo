#include <iostream>
#include <list>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include "stdio.h"
using namespace std;
#define INIT 0X7FFFFFFF

typedef struct ti
{
    int index;
    int repri;
} ti;

typedef struct lat
{
    int lowlea;
    int len;
} lat;

typedef struct thing
{
    int index;
    int price;
    int leave;
    int n;
    list<ti> son;
    list<lat> path;
} thing;

thing save[200];
int mark[200];
int len[200];
queue<int> que;

int main()
{
    int M,N;
    scanf("%d%d",&M,&N);
    int i,j;
    thing tmpth;
    ti tmpti;
    lat temp;
    for (i = 1; i <= N; i++)
    {
        scanf ("%d%d%d",&tmpth.price,&tmpth.leave,&tmpth.n);
        save[i] = tmpth;
        temp.len = INIT;
        temp.lowlea = save[i].leave;
        save[i].path.push_back(temp);
        for (j = 0; j < tmpth.n; j++)
        {
            scanf("%d%d",&tmpti.index,&tmpti.repri);
            save[i].son.push_back(tmpti);
        }
    }
    for (i = 0; i < 200; i++)
    {
        len[i] = INIT;
    }
    que.push(1);
    len[1] = save[1].price;
    int cur;
    list<ti>::iterator it;
    list<lat>::iterator it2;
    for (; !que.empty();)
    {
        cur = que.front();
        que.pop();
        for (it = save[cur].son.begin(); it != save[cur].son.end(); it++)
        {
            i = it->index;
            int m = 0;
            for (it2 = save[i].path.begin(); it2 != save[i].path.end(); it2++)
            {
                if (abs (it2->lowlea - save[i].leave) <= M)
                {
                    if (it2->len - save[cur].price + it->repri + save[i].price <= )
                    {
                        temp.len = it2->len - save[cur].price + it-> repri + save[i].price;
                        temp.lowlea = it2->lowlea < save[i].leave ? it2->lowlea : save[i].leave;
                        save[i].path.push_back(temp);
                        m = 1;
                    }
                }
            }
            if (m)
                que.push(i);
        }
    }
    for (i = 1; i <= N; i++)
    {
        for (it2 = save[i].path.begin(); it2 != save[i].path.end(); it2++)
        {
            if (it2 -> len < len[i])
                len[i] = it2-> len;
        }
    }
    int low = INIT;
    for (i = 1; i <= N; i++)
    {
        if (len[i] < low)
            low = len[i];
    }
    printf("***%d",low);
    return 0;
}
