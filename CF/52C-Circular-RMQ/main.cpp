#include <iostream>
#include "stdio.h"
#include "string.h"
using namespace std;
#define SIZE 300000
#define INIT 0x7fffffff

int save[SIZE];
int n;

struct node{
    int lf;
    int rg;
    int mini;
}T[SIZE<<3];

int min (int x, int y)
{
    return x < y ? x : y;
}

void build (int lf, int rg, int id)
{
    T[id].lf = lf;
    T[id].rg = rg;
    if (lf == rg)
    {
        T[id].mini = save[lf-1];
        return;
    }

    int mid = (lf + rg) / 2;
    build (lf,mid,id*2);
    build (mid+1,rg,id*2+1);
    T[id].mini = min (T[id*2].mini,T[id*2+1].mini);
}

void update (int lf, int rg, int val, int ind)
{
    if (T[ind].lf == T[ind].rg)
    {
        save[T[ind].lf-1] += val;
        T[ind].mini += val;
        return;
    }

    int mid = (T[ind].lf + T[ind].rg) / 2;
    if (rg < mid+1)
        update (lf,rg,val,ind*2);
    else if (lf > mid)
        update (lf,rg,val,ind*2+1);
    else
    {
        update(lf,mid,val,ind*2);
        update(mid+1,rg,val,ind*2+1);
    }
    T[ind].mini = min (T[ind*2].mini,T[ind*2+1].mini);
}

int query (int lf, int rg, int ind)
{
    if (T[ind].lf == T[ind].rg)
        return T[ind].mini;
    if (T[ind].lf == lf && T[ind].rg == rg)
        return T[ind].mini;
    int mid = (T[ind].lf + T[ind].rg) / 2;
    if (lf > mid)
        return query (lf, rg, ind*2+1);
    else if (rg < mid + 1)
        return query (lf,rg,ind*2);
    else
    {
        return min (query(lf,mid,ind*2),query(mid+1,rg,ind*2+1));
    }
}

void inc (int lf, int rg, int val)
{
    if (lf <= rg)
        update(lf,rg,val,1);
    else
    {
        update(1,rg,val,1);
        update(lf,n,val,1);
    }
}

int rmq (int lf, int rg)
{
    if (lf <= rg)
        return query(lf,rg,1);
    else
    {
        return min(query(1,rg,1),query(lf,n,1));
    }
}

int main()
{
    scanf("%d",&n);
    int i;
    for (i = 0; i < n; i++)
        scanf("%d",save + i);
    int ncoms;
    scanf("%d",&ncoms);
    char command[1000];
    int com;
    getchar();
    int lf,rg,val;
    build (1,n,1);
    for (i = 0; i < ncoms; i++)
    {
        gets(command);
        if ((com = sscanf(command,"%d%d%d",&lf,&rg,&val)) == 3)
        {
            inc(lf+1,rg+1,val);
        }
        else
        {
            printf("%d\n",rmq(lf+1,rg+1));
        }
    }
    return 0;
}
