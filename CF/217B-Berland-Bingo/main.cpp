#include <iostream>
#include "stdio.h"
#include "algorithm"
#include "bitset"
using namespace std;

int n;
bitset<200> save[200];
int result[200];

int in (int i, int j)
{
    return (save[i] & save[j]) == save[i];
}

int main()
{
    scanf("%d",&n);
    int i,j;
    int tmp;
    int num;
    for (i = 0; i < n; i++)
    {
        scanf("%d",&num);
        for (j = 0; j < num; j++)
        {
            scanf("%d",&tmp);
            save[i].set(tmp);
        }
    }
    for (i = 0; i < n; i++)
    {
        result[i] = 1;
        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (in(j,i))
            {
                result[i] = 0;
                break;
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        if (result[i])
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
