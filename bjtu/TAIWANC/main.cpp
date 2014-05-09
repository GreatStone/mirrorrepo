#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <list>
#include <stack>
using namespace std;

typedef pair<int,int> pii;

list<int> ph[10010];
pii res[10010];
int begin2,end2;
int vis[10010];

typedef struct node {
    int data;
    node (){}
    node (int a){data = a;}
    bool operator< (const node& b) const
    {
        return res[data].second < res[b.data].second;
    }
}node;

void djs ()
{
    priority_queue<node> que;
    que.push (node(begin2) );
    vis[begin2] = 1;
    res[begin2] = pii(0,0);
    for (;!que.empty();)
    {
        int cur = que.top().data;
        que.pop();
        list<int>::iterator it = ph[cur].begin();
        for (;it != ph[cur].end(); it++)
        {
            if (vis[*it])
                continue;
            if (res[cur].second + 1 < res[*it].second)
            {
                res[*it].second = res[cur].second + 1;
                res[*it].first = cur;
            }
            que.push (*it);
            vis[*it] = 1;
        }
    }
}

int main()
{
    int n;
    for (;scanf("%d",&n)!=EOF;)
    {
        memset(vis,0,sizeof(vis));
        int a;
        int pre;
        int i;
        for (i = 0; i < 10010; i++)
        {
            res[i] = pii(0,999999999);
        }
        for (i = 0; i < n; i++)
        {
            scanf("%d",&a);
            if (i == 0)
            {
                begin2 = a;
                pre = a;
            }
            else
            {
                ph[pre].push_back(a);
                pre = a;
            }
            if (i == n-1)
            {
                end2 = a;
            }
        }
        stack<int> s;
        int w = end2;
        s.push(w);
        djs();
        for (;;)
        {
            w = res[w].first;
            s.push(w);
            if (w == begin2)
            break;
        }
        for (;!s.empty();)
        {
            printf("%d ",s.top());
            s.pop();
        }
        printf("\n");
    }
    return 0;
}
