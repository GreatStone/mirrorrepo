#include <iostream>
#include "stdio.h"
#include "algorithm"
using namespace std;

int cost[110];

int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d",cost+i);
    }
    int m;
    scanf("%d",&m);
    sort(cost,cost+n);
    int result = 0;
    for (i = 0; i < n && i < m; i++){
        result += cost[i];
    }
    if (m > n)
        result -= d*(m-n);
    printf("%d\n",result);
    return 0;
}
