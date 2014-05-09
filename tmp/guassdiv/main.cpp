#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

double a[50];
double b[50];
double c[50];
double x[50];
double y[50];
double res1[50];
double res2[50];


int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%lf",a + i);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%lf",b + i);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%lf",c + i);
    }
    x[0] = b[0];
    y[0] = c[0]/b[0];
    for (i = 1; i < n; i++)
    {
        y[i] = c[i] / (b[i] - a[i] * y[i-1]);
        x[i] = b[i] - a[i] * y[i-1];
    }
    for (i = 0; i < n; i++)
    {
        printf ("x:%lf y:%lf\n",x[i],y[i]);
    }
    return 0;
}
