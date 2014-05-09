#include <iostream>
#include "stdio.h"
using namespace std;

int save[200];
int save1[200];
int save2[200];

int min (int x,int y)
{
    return x < y ? x : y;
}

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d",save + i);
        if (save[i] == 1)
            save1[i%k]++;
        else
            save2[i%k]++;
    }
    int result = 0;
    for (i = 0; i < k; i++)
    {
        result += min(save1[i],save2[i]);
    }
    printf("%d\n",result);
    return 0;
}
