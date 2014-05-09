#include <iostream>
#include "stdio.h"
#include "string.h"
using namespace std;
#define INI 0x7fffffff

int n,m;
int save[200][200];
int es[200][2];
int result[200][200];

void init ()
{
    for (int i = 0; i < 200; i++)
    {
        memset(save[i],0,200*sizeof(int));
        for (int j = 0; j < 200; j++)
            result[i][j] = INI;
    }
}

int min (int a, int b)
{
    return a < b ? a : b;
}

void floyed ()
{
    int i,j,k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n; k++)
            {
                result[i][j] = min (result[i][j],result[i][k] + result[k][j]);
            }
        }
    }
}

int main()
{
    int i,j;
    int inx,iny;
    for (;~scanf("%d%d",&n,&m);)
    {
        init();
        for (i = 0; i < m; i++)
        {
            scanf("%d%d",&es[i][0],&es[i][1]);
            inx = es[i][0];
            iny = es[i][1];
            save[inx][iny]++;
            save[iny][inx]++;
        }
        floyed();
        for (i = 0; i < m; i++)
        {
            inx = es[i][0];
            iny = es[i][1];
            save[inx][iny]--;   //add later

        }
    }
    return 0;
}
