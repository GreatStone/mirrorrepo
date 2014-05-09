#include <iostream>
#include "stdio.h"
#include "queue"
using namespace std;

int save[200][200];
int vis[200][200];
int result[200][200];
int r,c;

typedef struct node
{
    int x;
    int y;
    int len;
} node;

queue<node> que;
int move[4][2] = {0,1,1,0,0,-1,-1,0};

int in(node source)
{
    return source.x < r && source.x >= 0 && source.y >= 0 && source.y < c;
}

int main()
{
    scanf("%d%d",&r,&c);
    int i,j,k;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d",&save[i][j]);
            result[i][j] = 1;
        }
    }

    for (i = 0; i < r ; i++)
    {
        for (j = 0; j < c; j++)
        {
            node first;
            first.x = i;
            first.y = j;
            first.len = 1;

            que.push(first);
            for (; !que.empty();)
            {
                node cur = que.front();
                que.pop();
                for (k = 0; k < 4; k++)
                {
                    node tmp = cur;
                    tmp.x+=move[k][0];
                    tmp.y+=move[k][1];
                    tmp.len++;
                    if (in(tmp))
                    {
                        if (save[tmp.x][tmp.y] < save[cur.x][cur.y])
                        {
                            if (vis[tmp.x][tmp.y] && cur.len + result[tmp.x][tmp.y] > result[i][j])
                                result[i][j] = cur.len + result[tmp.x][tmp.y];
                            else if (!vis[tmp.x][tmp.y])
                            {
                                if (tmp.len > result[i][j])
                                    result[i][j] = tmp.len;
                                que.push(tmp);
                            }
                        }
                    }
                }
            }
            vis[i][j] = 1;
        }
    }

    int ans = 0;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            if (result[i][j] > ans)
                ans = result[i][j];
        }
    }
    printf("%d\n",ans);
    return 0;
}
