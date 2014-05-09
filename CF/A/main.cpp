#include "stdio.h"
#include <iostream>
#include <queue>

using namespace std;
char save[10][10];
int deal[10][10];
typedef struct point{
    int x;
    int y;
}point;
queue<point> que;

int in (point a)
{
    return a.x >= 0 && a.y >= 0 && a.x < 8 && a.y < 8;
}

int move[4][2] = {2,2,2,-2,-2,-2,-2,2};

void m ()
{
    for (int i= 0; i < 8 ; i++)
    {
        for (int j = 0; j < 8 ;j ++)
        {
            printf("%d",deal[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    point k[2];
    int count;
    for (int cas = 0; cas < n; cas++)
    {
        count = 0;
        for (i = 0; i < 8; i++)
        {
            scanf("%s",save[i]);
            for (j = 0; j < 8; j++)
            {
                if (save[i][j] == 'K')
                {
                    deal[i][j] = count+1;
                    k[count].x = i;
                    k[count++].y = j;
                }
                else
                    deal[i][j] = 0;
            }
        }
        que.push(k[0]);
        point temp,cur;
        int OK = 0;
        for (;!que.empty();)
        {
            cur = que.front();
            que.pop();
            for (i = 0; i < 4; i++)
            {
               temp.x = cur.x + move[i][0];
               temp.y = cur.y + move[i][1];
               if (in(temp) && deal[temp.x][temp.y] == 0)
               {
                deal[temp.x][temp.y] = 1;
                   que.push(temp);
               }
               else if (in (temp) && deal[temp.x][temp.y] == 2)
               {
                   OK = 1;
                   break;
               }
            }
            if (OK)
                break;
        }
        m();
        que.push(k[1]);
        for (;!que.empty();)
        {
            cur = que.front();
            que.pop();
            for (i = 0; i < 4; i++)
            {
               temp.x = cur.x + move[i][0];
               temp.y = cur.y + move[i][1];
               if (in(temp) && deal[temp.x][temp.y] == 0)
               {
                    deal[temp.x][temp.y] = 2;
                   que.push(temp);
               }
               else if (in(temp) && deal[temp.x][temp.y] == 1)
               {
                   if (save[i][j] != '#')
                   {
                       OK = 1;
                        break;
                   }
                   else{
                       deal[temp.x][temp.y] = 2;
                   que.push(temp);
                   }
               }
            }
            if (OK)
                break;
        }
        m();
        if (OK)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
