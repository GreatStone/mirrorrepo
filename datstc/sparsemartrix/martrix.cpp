#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include "martrix.h"
using namespace std;


int mar_init (martrix* A, int x, int y)
{
    A->data = (element*) malloc (INITSIZE * sizeof(element));
    if (A->data == NULL)
    {
        return 0;
    }
    A->sizex = x;
    A->sizey = y;
    A->num = A->size = 0;
    A->ordered = 1;
    return 1;
}

int addElement (int x, int y, int val, martrix* A)
{
    if (A->num == A->size)
    {
        element* tmp = (element*) realloc (A->data, (A->size + ADDSIZE) * sizeof(element));
        if (tmp == NULL)
        {
            return 0;
        }
        A->data = tmp;
        A->size += ADDSIZE;
    }
    A->data[A->num].indexx = x;
    A->data[A->num].indexy = y;
    A->data[A->num].value = val;
    A->num++;
    A->ordered = 0;
    return 1;
}

void transposition (martrix* A)
{
    int i;
    A->ordered = 0;
    for (i = 0; i < A->num; i++)
    {
        int tmp = A->data[i].indexx;
        A->data[i].indexx = A->data[i].indexy;
        A->data[i].indexy = tmp;
    }
}

int cmp (element a, element b)
{
    if (a.indexx != b.indexx)
        return a.indexx < b.indexx;
    else
        return a.indexy < b.indexy;
}

void order (martrix* A)
{
    int size = A->num;
    sort (A->data,A->data + size, cmp);
    A->ordered = 1;
}

void print (martrix* A)
{
    int cur = 0;
    int i,j;
    if (! A->ordered)
        order(A);
    for (i = 0; i < A->sizex; i++)
    {
        for (j = 0; j < A->sizey; j++)
        {
            if (A->data[cur].indexx == i && A->data[cur].indexy == j)
            {
                printf("%d\t", A->data[cur].value);
                cur ++;
            }
            else
            {
                printf ("0\t");
            }
        }
        printf("\n");
    }
}
