#include <iostream>
#include "algorithm"
#include "string.h"
#include "stdio.h"
using namespace std;

int savex[100010];
int savey[100010];
int savez[100010];
char sz[100010];

int sumx[100010];
int sumy[100010];
int sumz[100010];

int len;

int lowbit(int x){
return x&(-x);
}

void plu(int pos , int num, int* count)
{
    while(pos <= len)
    {
          count[pos] += num;
          pos += lowbit(pos);
    }
}

int sum(int end, int* count)
{
    int sum = 0;
    while(end > 0)
    {
        sum += count[end];
        end -= lowbit(end);
    }
    return sum;
}


int main()
{
    int i;
    scanf("%s",sz);
    len = strlen(sz);
    for (i = 0; i < len ; i++){
        if (sz[i] == 'x')
        {
            savex[i+1] = 1;
            plu(i+1,1,sumx);
        }
        else if (sz[i] == 'y')
        {
            savey[i+1] = 1;
            plu(i+1,1,sumy);
        }
        else if (sz[i] == 'z')
        {
            savez[i+1] = 1;
            plu(i+1,1,sumz);
        }
    }
    int m;
    scanf("%d",&m);
    int l,r;
    int x[3];
    int a[3];
    int length;
    for (i = 0; i < m; i++)
    {
        scanf("%d%d",&l,&r);
        length = r-l+1;
        if (length < 3)
        {
            printf("YES\n");
            continue;
        }
        x[0] = sum(r,sumx)-sum(l-1,sumx);
        x[1] = sum(r,sumy)-sum(l-1,sumy);
        x[2] = sum(r,sumz)-sum(l-1,sumz);
        a[0] = length / 3;
        a[1] = length /3 + (length%3 > 0);
        a[2] = length-a[0]-a[1];
        sort(x,x+3);
        sort(a,a+3);
        if (x[0] == a[0] && x[1] == a[1] && x[2] == a[2])
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
