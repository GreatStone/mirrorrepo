#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    long long int n,a,b;
    long long int save;
    int i;
    scanf("%lld%lld%lld",&n,&a,&b);
    for (i = 0; i < n; i++)
    {
        scanf("%lld",&save);
        long long int tmp = save * a / b;
        long long int res = tmp * b / a;
        long long int cur = res * a / b;
        for (;;)
        {
            if ((res + 1)*a/b == cur || res == save)
                break;
            else
               {

               cur = (res + 1) * a / b;
               res++;
               }
        }
        printf("%lld ",save - res);
    }
    return 0;
}
