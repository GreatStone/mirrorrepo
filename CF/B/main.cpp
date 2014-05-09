#include <iostream>
#include <queue>
#include "stdlib.h"
#include "stdio.h"
using namespace std;
queue<int> que;
int mark[5000];

int main()
{
    int n,m;
    cin >> n >> m;
    int i;
    int tmp;
    for (i = 0; i < m; i++)
    {
        cin >> tmp;
        mark[tmp] = 1;
    }
    if (mark[1] == 1 || mark[n] == 1)
    {
        printf ("NO\n");
        return 0;
    }
    que.push(1);
    int cur;
    for (;!que.empty();)
    {
        cur = que.front();
        if (cur > n+5)
        {
            printf("NO\n");
            return 0;
        }
        else if (cur == n)
        {
            printf("YES\n");
            return 0;
        }
        que.pop();
        for (i = 1; i < 4; i++)
        {
            tmp = i+cur;
            if (tmp < 4000 && mark[tmp] == 0)
            {
                mark[tmp] = 1;
                que.push(tmp);
            }
            else if (tmp>= 4000)
                que.push(tmp);
            if (tmp == n)
            {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
