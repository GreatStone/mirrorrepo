#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void put (int a,int b,int c)
{
    int i;
    for (i = 0; i < a ; i++)
    {
        printf("|");
    }
    printf("+");
    for (i = 0; i < b; i++)
    {
        printf("|");
    }
    printf("=");
    for (i = 0; i < c; i++)
    {
        printf("|");
    }
}

int main()
{
    char save[500];
    scanf("%s",save);
    int i;
    int len = strlen(save);
    int a,b,c;
    a = b = c = 0;
    for(i = 0; i < len; i++)
    {
        if (save[i] != '+')
        a++;
        else
        break;
    }
    for (i++; i < len; i++)
    {
        if (save[i] != '=')
        b++;
        else
        break;
    }
    for (i++; i < len; i++)
    {
        c++;
    }
    int n = a;
    int m = b;
    int x = c;
    if (n + m == x)
    put (n,m,x);
    else if (n + m-1 == x+1  && m-1>0)
    put(n,m-1,x+1);
    else if (n-1 + m == x+1 && n-1 >0)
    put (n-1,m,x+1);
    else if (n+1 + m == x-1 && x-1>0)
    put (n+1,m,x-1);
    else if(n + m+1 == x -1&& x-1>0)
    put (n,m+1,x-1);
    else
    printf("Impossible");
    return 0;
}
