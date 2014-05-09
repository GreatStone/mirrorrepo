#include <iostream>
#include <cstdio>
using namespace std;
#define LL __int64

typedef struct {
    LL left;
    LL right;
    LL sum;
    LL add;
} node;

LL N,Q;
node tree[2000000];
LL save[600000];

void build (LL root, LL left, LL right)
{
    tree[root].left = left;
    tree[root].right = right;
    tree[root].add = 0;
    if (left == right)
        tree[root].sum = save[left-1];
    else
    {
        LL mid = (left + right)/2;
        build (root*2,left,mid);
        build (root*2+1,mid+1,right);
        tree[root].sum = tree[root*2].sum + tree[root*2+1].sum;
    }
}

void push (LL root)
{
    LL l = root*2;
    LL r = root*2+1;
    tree[l].add += tree[root].add;
    tree[l].sum += (tree[l].right - tree[l].left + 1) * tree[root].add;
    tree[r].add += tree[root].add;
    tree[r].sum += (tree[r].right - tree[r].left + 1) * tree[root].add;
    tree[root].add = 0;
}

void fresh (LL root, LL left, LL right, LL add)
{
    if (tree[root].left == left && tree[root].right == right)
    {
        tree[root].sum += (tree[root].right - tree[root].left + 1) * add;
        tree[root].add += add;
        return;
    }
    int mid = (tree[root].left + tree[root].right) / 2;
    int l = root*2;
    int r = root*2+1;

    if (tree[root].add)
    {
        push (root);
    }
    if (mid < left)
    fresh (root*2+1,left,right,add);
    else if (mid + 1 > right)
    fresh (root*2,left,right,add);
    else
    {
        fresh (root*2,left,mid,add);
        fresh (root*2+1,mid+1,right,add);
    }
    tree[root].sum = tree[l].sum + tree[r].sum;
}

LL query (int root, int left, int right)
{
    int mid = (tree[root].right + tree[root].left) / 2;

    if (left == tree[root].left && right == tree[root].right)
    {
        return tree[root].sum;
    }

    if (tree[root].add)
        push (root);


    if (mid < left)
    {
        return query (root*2+1,left,right);
    }
    else if (mid + 1 > right)
    {
        return query (root*2,left,right);
    }
    else
    {
        return query (root*2,left,mid) + query (root*2+1,mid+1,right);
    }
}

int main()
{
  //  freopen("write","w",stdout);
    scanf ("%I64d%I64d",&N,&Q);
    int i;
    for (i = 0; i < N ;i++)
    {
        scanf ("%I64d",save+i);
    }
    build(1,1,N);
    char command[10];
    LL left,right;
    LL add;
    for (i = 0; i< Q; i++)
    {
        scanf("%s",command);
        if (command[0] == 'Q')
        {
            scanf("%I64d%I64d",&left,&right);
            printf("%I64d\n",query(1,left,right));
        }
        else
        {
            scanf("%I64d%I64d%I64d",&left,&right,&add);
            fresh(1,left,right,add);
        }
    }
    return 0;
}


//没过
