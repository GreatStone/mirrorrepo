#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int light[200];

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int turn[200];
    int i,j;
    for (i = 1; i <= m; i++)
    {
        scanf("%d",turn + i);
    }
    for (i = 1; i <= m; i++)
    {
        for (j = turn[i]; j <= n; j++)
        {
            if (!light[j])
            {
                light[j] = turn[i];
            }
        }
    }
    for (i = 1; i <= n; i++)
    {
        printf("%d ",light[i]);
    }
    return 0;
}
