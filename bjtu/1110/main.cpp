#include <iostream>
#include "stdio.h"
using namespace std;

long long int save[3000][3000];

long long int f (long long int i, long long int j)
{
    if (save[i][j] != 0)
        return save[i][j];
    if (i == 1)
    {
        save[i][j] = j;
        return save[i][j];
    }
    else if (j == 1)
    {
        save[i][j] = i;
        return save[i][j];
    }
    else
    {
        save[i][j] = f(i,j-1) + f(i-1,j);
        return save[i][j];
    }
}

int main()
{
    freopen("out.txt","w",stdout);
  /*  int m;
    long long int a,b;
    int i;
    scanf("%d",&m);
    for (i = 0; i < m; i++)
    {
        scanf("%lld%lld",&a,&b);
        printf("%lld\n",f(a,b));
    }*/
    for (int i = 1; i <= 2000; i++)
    {
        for (int j = 1; j <= 2000; j++)
        {
            printf("%d %d %lld\n",i,j,f(i,j));
        }
    }
    return 0;
}
