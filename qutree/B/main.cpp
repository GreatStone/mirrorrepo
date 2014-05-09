#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct
{
    int l,r;
    int m;
} node;

int n,m;
int save[2000100];
node tree[4000000];

int max (int a, int b)
{
    return a>b?a:b;
}

void build (int root, int l, int r)
{
    tree[root].l = l;
    tree[root].r = r;
    if (l == r)
    {
        tree[root].m = save[l-1];
        return;
    }

    int mid = (l + r) / 2;
    build (root*2,l,mid);
    build (root*2+1,mid+1,r);
    tree[root].m = max (tree[root*2].m,tree[root*2+1].m);
}

void fresh (int root, int id ,int x)
{
    if (tree[root].l == tree[root].r)
    {
        tree[root].m = x;
        return;
    }

    int mid = (tree[root].l + tree[root].r) / 2;
    if (id < mid+1)
    {
        fresh (root*2,id,x);
    }
    else
    {
        fresh (root*2+1,id,x);
    }
    tree[root].m = max (tree[root*2].m,tree[root*2+1].m);
}

int gmax (int root, int l, int r)
{
    if (tree[root].l == l && tree[root].r == r)
    {
        return tree[root].m;
    }

    int mid = (tree[root].l + tree[root].r) / 2;
    if (r < mid+1)
    {
        return gmax (root*2,l,r);
    }
    else if (l > mid)
    {
        return gmax (root*2+1,l,r);
    }
    else
    {
        return max(gmax(root*2,l,mid),gmax(root*2+1,mid+1,r));
    }
}

int main()
{
    for (;scanf("%d%d",&n,&m)!=EOF;)
    {
        int i;
        for (i = 0 ; i < n; i++)
        {
            scanf ("%d",save+i);
        }
        build(1,1,n);
        for (i = 0; i < m; i++)
        {
            char com[5];
            int a,b;
            scanf ("%s%d%d",com,&a,&b);
            if (com[0] == 'U')
            {
                fresh(1,a,b);
            }
            else
            {
                printf("%d\n",gmax(1,a,b));
            }
        }
    }
    return 0;
}
