#include <iostream>
#include "stdio.h"
#include "memory.h"
#include "algorithm"
using namespace std;

int savea[100010];
int tmp[100010];
int cnt[100010];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    int l;
    for (i = 0; i < n; i++)
        scanf("%d",savea+i);
    for (i = n-1; i >= 0; i--)
    {
        if (tmp[savea[i]])
            cnt[i] = cnt[i+1];
        else
        {
            cnt[i] = cnt[i+1]+1;
            tmp[savea[i]] = 1;
        }
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d",&l);
        printf("%d\n",cnt[l-1]);
    }
    return 0;
}
