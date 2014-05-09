#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct {
    int left,right;
    int sum;
}node;

node tree[200000];
int n;
int save[100000];

void build (int root, int left, int right)
{
    tree[root].left = left;
    tree[root].right = right;
    if (left == right)
    {
        tree[root].sum = save[left-1];
        return;
    }

    int mid = (left + right) / 2;
    build (root * 2, left, mid);
    build(root*2+1,mid+1,right);
    tree[root].sum = tree[root*2].sum + tree[root*2+1].sum;
}

void add (int root, int aim, int x)
{
    if (tree[root].left == tree[root].right)
    {
        tree[root].sum += x;
        return;
    }
    int mid = (tree[root].left + tree[root].right) / 2;
    tree[root].sum += x;
    if (aim < mid+1)
    {
        add (root*2,aim,x);
    }
    else if (aim > mid)
    {
        add (root*2+1,aim,x);
    }
}

int query (int root, int left, int right)
{
    if (left == tree[root].left && right == tree[root].right)
    {
        return tree[root].sum;
    }

    int mid = (tree[root].left + tree[root].right) / 2;
    if (right < mid+1)
    {
        return query (root*2,left,right);
    }
    else if (left > mid)
    {
        return query (root*2+1,left,right);
    }
    else
    {
        return query (root*2,left,mid) + query (root*2+1,mid+1,right);
    }
}

int main()
{
    int e;
    scanf ("%d",&e);
    char comm[20];
    for (int cas = 1; cas <= e; cas++)
    {
        printf("Case %d:\n",cas);
        scanf ("%d",&n);
        int i;
        for (i = 0; i < n; i++)
        {
            scanf("%d",save+i);
        }
        build(1,1,n);
        int a,b;
        for (;;)
        {
            scanf("%s",comm);
            if(!strcmp(comm,"End"))
            break;
            else if (!strcmp (comm,"Add"))
            {
                scanf("%d%d",&a,&b);
                add(1,a,b);
            }
            else if (!strcmp (comm,"Sub"))
            {
                scanf("%d%d",&a,&b);
                add(1,a,0-b);
            }
            else if (!strcmp (comm,"Query"))
            {
                scanf("%d%d",&a,&b);
                printf("%d\n",query(1,a,b));
            }
        }
    }
    return 0;
}
