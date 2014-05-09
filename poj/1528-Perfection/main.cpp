#include <iostream>
#include "stdio.h"
using namespace std;

int getsum(int n)
{
    int result = 0;
    for (int i = 1; i < n; i++)
    {
        if (n%i == 0)
            result += i;
    }
    return result;
}

int main()
{
    int n;
    printf("PERFECTION OUTPUT\n");
    for (;scanf("%d",&n);)
    {
        if (!n)
            break;
        printf("%5d  ",n);
        int tmp = getsum(n);
        if (tmp == n)
        printf("PERFECT\n");
        else if (tmp < n)
        printf("DEFICIENT\n");
        else
        printf("ABUNDANT\n");
    }
    printf("END OF OUTPUT");
    return 0;
}
