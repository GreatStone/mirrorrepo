#include <iostream>
#include <cstdio>
#include "martrix.h"
using namespace std;

int main()
{
    int rows,clos;
    int n;
    martrix save;
    printf ("please input the number of rows of this martrix\n");
    scanf ("%d", &rows);
    printf ("please input the number of colomns of this martrix\n");
    scanf ("%d", &clos);
    printf ("please input the number of non-zero elements in this martrix\n");
    scanf ("%d", &n);
    mar_init (&save,rows,clos);
    int i;
    int x,y,val;
    for (i = 0; i < n; i++)
    {
        printf ("please input the row-index of the no.%d element\n", i+1);
        scanf ("%d", &x);
        printf ("please input the colomn-index of the no.%d element\n", i+1);
        scanf ("%d", &y);
        printf ("please input the value of this element\n");
        scanf ("%d", &val);
        addElement (x,y,val,&save);
    }
    printf ("before transposition\n");
    print (&save);
    transposition (&save);
    printf ("after transposition\n");
    print (&save);
    return 0;
}
