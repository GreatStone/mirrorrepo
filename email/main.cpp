#include "stdio.h"

int main()
{
    char a[20];
    int l,r;
    printf("输入号头\n");
    scanf ("%s",a);
    printf ("输入左端点\n");
    scanf ("%d",&l);
    printf("输入右端点\n");
    scanf ("%d",&r);
    freopen ("out.txt","w",stdout);
    for (int i = l; i <= r; i++)
    {
        printf ("%s%04d@bjtu.edu.cn,",a,i);
    }
    return 0;
}
