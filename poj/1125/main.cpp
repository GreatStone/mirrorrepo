#include <iostream>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define INIT 90000
using namespace std;

int save[110][110];

void read (int n)
{
    int i,j;
    int num;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            save[i][j] = INIT;
        }
    }
    int a,b;
    for (j = 1; j <= n; j++)
    {
        scanf("%d",&num);
        for (i = 1; i <= num; i++)
        {
            scanf ("%d%d",&a,&b);
            save[a][j] = b;
        }
    }
}

void floyd (int n)
{
    int count;
    int i,j,k;
    for (count = 0; count < n; count++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                for (k = 1; k <= n; k++)
                {
                    if (save[i][k] + save[k][j] < save[i][j])
                        save[i][j] = save[i][k] + save[k][j];
                }
            }
        }
    }
    for (i = 1; i <= n; i++)
        save[i][i] = 0;
}

int main()
{
    int n;
    int i,j;
    while(1)
    {
        scanf("%d",&n);
        if (n == 0)
            return 0;
        read(n);
        floyd(n);
        int max;
        int result;
        max = result = INIT;
        int rej = INIT;
        for (j = 1; j <= n; j++)
        {
            max = save[1][j];
            for (i = 1; i <= n; i++)
            {
                if (save[i][j] > max)
                    max = save[i][j];
            }
            if (max < result)
            {
                result = max;
                rej = j;
            }
        }
        if (result < INIT)
            printf("%d %d\n",rej,result);
        else
            printf("disjoint\n");
    }
    return 0;
}
