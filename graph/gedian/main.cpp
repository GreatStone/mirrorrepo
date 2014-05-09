#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
#define SIZE 20000
#define dread(a) scanf("%d",&a);

int vis[SIZE];
int low[SIZE];
int N,M;
vector<int> save[5*SIZE];
int isp[SIZE];

int min (int a,int b)
{
    return a < b ? a : b;
}

int dfs (int root, int time)
{
    int i;
    int mtime = time;
    vis[root] = time;
    for (i = 0; i < save[root].size(); i++)
    {
        if (vis[save[root][i]])
        {
            mtime = min(vis[save[root][i]],mtime);
        }
        else
        {
            mtime = min(mtime,dfs(save[root][i],time+1));
        }
    }
    low[root] = mtime;
    if (low[root] >= vis[root])
    {
        isp[root] = 1;
        printf("%d\n",root);
    }
    return mtime;
}

int main()
{
    dread(N);
    dread(M);
    int i;
    int a,b;
    for (i = 0; i < M; i++)
    {
        dread(a);
        dread(b);
        save[a].push_back(b);
    }
    dfs(1,1);
    return 0;
}
