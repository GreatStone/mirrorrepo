#include <iostream>
#include "stdio.h"
#include "math.h"
using namespace std;

typedef struct point{
    int x;
    int y;
}point;

int max(int a,int b)
{
    return a > b ? a : b;
}

int abs (int a)
{
    return a > 0 ? a : -a;
}

int main()
{
    point start;
    point end;
    scanf("%d%d%d%d",&start.x,&start.y,&end.x,&end.y);
    if (start.x != end.x && start.y != end.y)
        printf("2 ");
    else
        printf("1 ");

    int suma = start.x + start.y;
    int sumb = end.x + end.y;
    if (suma % 2 != sumb %2)
        printf("0 ");
    else
    {
        if (abs(start.x - end.x) == abs (start.y - end.y))
            printf("1 ");
        else
            printf("2 ");
    }

    int disx = abs(start.x - end.x);
    int disy = abs(start.y - end.y);
    printf("%d\n",max(disx,disy));
    return 0;
}
