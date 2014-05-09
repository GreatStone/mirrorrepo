#include <iostream>
#include <cstdio>
using namespace std;

int w[200][200];
double a[200][200];
double b[200][200];

int main()
{
    int n;
    int i,j;
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d",w[i] + j);
        }
    }
    for (j = 0; j < n; j++)
    {
        for (i = 0; i < n; i++)
        {
            a[j][i] = ((double)w[i][j] + w[j][i]) / 2;
            b[j][i] = ((double)w[j][i] - w[i][j]) / 2;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%lf ",a[i][j]);
        }
        printf("\n");

    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%lf ",b[i][j]);
        }
        printf("\n");

    }
    return 0;
}
