#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

__int64 get (__int64 x)
{
    return x * (x-1) / 2;
}

int main()
{
    __int64 res = 0;
    int n;
    scanf("%d",&n);
    int i;
    int cur = 0;
    int pre;
    int x;
    for (i = 0; i < n; i++)
    {
        scanf ("%d",&x);
        if (i == 0)
        {
            cur++;
        }
        else if(i == n-1 && x == pre)
        {
            res += get(cur+1);
        }
        else if (x != pre)
        {
            res += get (cur);
            cur = 1;
        }
        else
        {
            cur++;
        }
        pre = x;
    }
    res += n;
    printf("%I64d",res);
    return 0;
}
