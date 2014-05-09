#include <iostream>
#include "stdio.h"
#include "string.h"
using namespace std;
#define LEN 1000010

char str[2][1000010];

struct node{
    int left;
    int right;
    int num;
}T[LEN<<3];

void build (int l,int r,int index)
{
    T[index].left = l;
    T[index].right = r;
    T[index].num = 0;
    if (l == r)
        return;
    int mid = (l+r)/2;
    build (l,mid,index*2);
    build (mid+1,r,index*2+1);
}

void insert (int i, int index, int val)
{
    if (T[index].left == i && T[index].right == i)
    {
        T[index].num = val;
        return;
    }
    int mid = (T[index].left + T[index].right) / 2;
    if (i > mid)
        insert(i,index*2+1,val);
    else if (i < mid + 1)
        insert(i,index*2,val);
    T[index].num = T[index*2].num && T[index*2+1].num;
}

int getindex (int i, int index)
{
    if (T[index].left == i)
        return index;

    int mid = (T[index].right + T[index].left) / 2;
    if (i > mid)
        return getindex(i,index*2+1);
    else
        return getindex(i,index*2);
}

int querry(int i,int u)
{
   if(T[u].num)
   {
       return T[u].right;
   }
   if(T[u].left==T[u].right)
   {
       return T[u].left-1;
   }
   int mid=T[u].left+(T[u].right-T[u].left)/2;
   if(i<=mid)
   {
       int temp;
       temp=querry(i,2*u);
       if(temp==mid)
       {
           return querry(mid+1,2*u+1);
       }
       else
       {
           return temp;
       }
   }
   else
   {
       return querry(i,2*u+1);
   }
}

int query (int index)
{
    if (T[index].right == T[index].left)
        return T[index].num;

    if (T[index].num && index%2)
        return T[index].right - T[index].left + 1;
    else if (T[index].num == 0)
        return query(index*2);
    else if (index%2 == 0 && T[index].num)
        return T[index].right - T[index].left + 1 + query(index+1);
}

int max (int x,int y)
{
    return x > y ? x : y;
}

int min (int x , int y)
{
    return x < y ? x : y;
}

int main()
{
    int cas;
    scanf("%d",&cas);
    int T;
    int i;
    int len;
    int que;
    int com;
    int index,to;
    char c[5];
    int minlen;
    for (T = 0; T < cas; T++)
    {
        scanf("%s%s",str[0],str[1]);
        len = max(strlen(str[0]),strlen(str[1]));
        minlen = min(strlen(str[0]),strlen(str[1]));
        build(1,len,1);
        for (i = 0; i < len; i++)
        {
            if (str[0][i] == str[1][i])
                insert(i+1,1,1);
        }
        scanf("%d",&que);
        printf("Case %d:\n",T+1);
        for (i = 0; i < que; i++)
        {
            scanf("%d",&com);
            if (com == 1)
            {
                scanf("%d%d%s",&to,&index,c);
                str[to-1][index] = c[0];
                if (index > minlen - 1)
                    ;
                else if (str[0][index] == str[1][index])
                    insert(index+1,1,1);
                else
                    insert(index+1,1,0);
            }
            else
            {
                scanf("%d",&index);
                int result = query(getindex(index+1,1));
                printf("%d\n",querry(index+1,1)-index);
            }
        }
    }
    return 0;
}
