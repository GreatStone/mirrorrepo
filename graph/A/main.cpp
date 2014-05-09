#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
using namespace std;
#define READ(a) scanf("%d",&a)

int n,m;
vector<int> save[20000];
int viss[20000];

void bfs (int root)
{
    char vistmp[20000];
    memset(vistmp,0,sizeof(vistmp));
    queue<int> que;
    vistmp[root] = 1;
    que.push(root);
    int i;
    for (;!que.empty();)
    {
        int cur = que.front();
        que.pop();
        int len = save[cur].size();
        for (i = 0; i < len; i++)
        {
            if (vistmp[save[cur][i]])
                continue;
            else
            {
                vistmp[save[cur][i]] = 1;
                que.push(save[cur][i]);
                viss[save[cur][i]] ++;
            }
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m);
    int i;
    int a,b;
    memset(viss,0,sizeof (viss));
    for (i = 0; i < m; i++)
    {
        READ(a);
        READ(b);
        save[a].push_back(b);
    }
    for (i = 1; i <= n; i++)
    {
        bfs(i);
    }
    int res = 0;
    for (i = 1; i <= n; i++)
    {
        if (viss[i] >= n-1)
            res++;
    }
    printf("%d",res);
    return 0;
}
