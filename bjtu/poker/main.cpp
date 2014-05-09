#include<iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen ("in.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    int T;
    int cas;
    scanf("%d",&T);
    int n;
    for (cas = 1; cas <= T; cas++)
    {
        scanf ("%d",&n);
        if (n%3)
        {
            printf("Case #%d: WIN\n",cas);
        }
        else
        {
            printf("Case #%d: LOSE\n",cas);
        }
    }
    return 0;
}
