#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

void draw (int* queens)
{
    int i,j;
    for(i = 0; i < 8; i++)
    {
        for(j = 0; j < 8; j++)
        {
            if (queens[i] == j)
            {
                printf("*");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int abs (int a)
{
    return a > 0 ? a : -a;
}

int ok (int xa,int ya,int xb,int yb)
{
    return !(xa == xb || ya == yb || abs (xa - xb) == abs(ya - yb));
}

int main()
{
    freopen ("out","w",stdout);
    int res = 0;
    int queens[8];
    int cur;
    int i;
    for (i = 0; i < 8; i++)
    {
        queens[i] = -1;
    }
    for (cur = 0; cur >= 0;)
    {
        queens[cur]++;
        for (; queens[cur] < 8 ;)
        {
            if (cur == 0)
                break;
            int flag = 1;
            for (i = 0; i < cur; i++)
            {
                if (!ok(cur,queens[cur],i,queens[i]))
                {
                    flag = 0;
                    break;
                }
            }
            if (!flag)
            {
                queens[cur]++;
            }
            else
            {
                break;
            }
        }
        if (queens[cur] < 8)
        {
            if (cur == 7)
            {
                draw(queens);
                res++;
            }
            else
            {
                queens[++cur] = -1;
            }
        }
        else cur--;
    }
    printf("共有答案%d种\n",res);
    return 0;
}
