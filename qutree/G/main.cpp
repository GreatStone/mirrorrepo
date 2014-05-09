#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;


int ls[100100];
int rs[100100];
int all[400000];
int vis[600000];
int n;
map<int,int> flc;

typedef struct {
    int l,r;
    int over;
}node;

node tree[600000];

void build (int root, int l, int r)
{
    tree[root].l = l;
    tree[root].r = r;
    tree[root].over = 0;
    if (l == r)
    {
        return;
    }

    int mid = (l + r) / 2;
    build (root*2,l,mid);
    build (root*2+1,mid+1,r);
}

void update (int root)
{
    if (tree[root].l == tree[root].r)
        return;
    else if (tree[root].over)
    {
        tree[root*2+1].over = tree[root*2].over = tree[root].over;
    }
}

void insert (int root, int l, int r, int x)
{
    update (root);
    if (l == tree[root].l && r == tree[root].r)
    {
        tree[root].over = x;
        return;
    }

    int mid = (tree[root].l + tree[root].r) / 2;
    if (r < mid + 1)
    {
        insert (root*2,l,r,x);
    }
    else if (l > mid)
    {
        insert (root*2+1,l,r,x);
    }
    else
    {
        insert (root*2, l, mid, x);
        insert (root*2+1, mid+1, r, x);
    }
    tree[root].over = ((tree[root*2].over == tree[root*2+1].over) ? tree[root*2].over : 0);
}

int query (int root)
{
    if (tree[root].r == tree[root].l)
    {
        if (vis[tree[root].over])
            return 0;
        else
        {
            vis[tree[root].over] = 1;
            return 1;
        }
    }
    if (tree[root].over)
    {
        if (vis[tree[root].over])
        {
            return 0;
        }
        else
        {
            vis[tree[root].over] = 1;
            return 1;
        }
    }
    else
    {
        return query (root*2) + query (root*2+1);
    }
}

int main()
{
    int cas;
    scanf ("%d",&cas);
    while (cas--)
    {
        flc.clear();
        memset(vis,0,sizeof(vis));

        scanf("%d",&n);
        int i;
        for (i = 0; i < n; i++)
        {
            scanf ("%d%d",ls+i,rs+i);
            all[i*2] = ls[i];
            all[i*2+1] = rs[i];
        }
        sort (all, all + 2 * n);
        int size = unique (all,all+2*n) - all;
        for (i = 0; i < size; i++)
        {
            flc.insert(pair<int,int>(all[i],i));
        }
        for (i = 0; i < size; i++)
        {
            ls[i] = (flc.find(ls[i]))->second;
            rs[i] = (flc.find(rs[i]))->second;
        }

        build(1,1,size);
        for (i = 0; i < n; i++)
        {
            insert(1,ls[i]+1,rs[i]+1,i+1);
        }

        int res = query(1);
        printf("%d\n",res);
    }
    return 0;
}
