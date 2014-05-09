#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int com (int a,int b)
{
    return a > b;
}

int main()
{
    int n;
    int save[200];
    scanf("%d",&n);
    int i;
    for (i = 0; i< n; i++)
        scanf ("%d",save+i);
    int eq;
    for (;;)
    {
        eq = 1;
        sort(save,save+n,com);
        for (i = 0; i < n - 1; i++)
        {
            if (save[i] > save[i + 1])
            {
                save[i] -= save[i+1];
                eq = 0;
            }
        }
        if (eq)
        {
            printf("%d",save[0] * n);
            break;
        }
    }
    return 0;
}
