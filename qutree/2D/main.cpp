#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct {
    int l,r;
    int cover;
    int l1,r1;
    int l0,r0;
    int ll1,ll0;
    int turn;
}node;

node tree[400000];
int save[100010];

void pushup (int rt)
{
    tree[rt].l0 = tree[root]
}

void build (int rt,int l, int r)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].turn = 0;
    if (l == r)
    {
        tree[rt].cover = save[l-1];
        if (save[l-1])
        {
            tree[rt].l1 = tree[rt].r1 = 1;
            tree[rt].l0 = tree[rt].r0 = 0;
            tree[rt].ll1 = 1;
            tree[rt].ll0 = 0;
        }
        else
        {
            tree[rt].l1 = tree[rt].r1 = 0;
            tree[rt].l0 = tree[rt].r0 = 1;
            tree[rt].ll1 = 0;
            tree[rt].ll0 = 1;
        }
        return;
    }
}



int main()
{
    return 0;
}
