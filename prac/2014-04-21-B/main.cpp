#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long int __int64;
typedef struct node{
    int da;
    int ind;
    node (int a,int b)
    {
        da = a;
        ind = b;
    }
    node (){}
}node;

int cmp (node a, node b)
{
    if (a.da == b.da)
        return a.ind < b.ind;
    else
        return a.da < b.da;
}

int save[100010];
node besort[100010];
__int64 sum[100010];

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    sum[0] = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d",save + i);
        besort[i] = node(save[i],i);
        sum[i] = sum[i-1] + save[i];
    }
    if (sum[n] < k)
    {
        printf("-1");
        return 0;
    }
    sort (besort + 1, besort + n + 1, cmp);
    int cur = 0;
    int add = 0;
    int com = k;
    for (i = 1;com > 0, i <= n; i++)
    {
        cur = besort[i].ind;
        k -= save[cur] - add;
        add +=save[cur];
        if (k >= 0)
            save[cur] = 0;
    }
    for (i = cur; i <= n; i++)
    {
        if (save[i])
        printf("%d ",i);
    }
    for (i = 1; i < cur; i++)
    {
        if (save[i])
        printf("%d ",i);
    }
    return 0;
}
