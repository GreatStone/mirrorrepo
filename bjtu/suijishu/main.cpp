#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define MOD 1000000000

int main()
{
    freopen ("in.txt","w",stdout);
    int n;
    scanf ("%d",&n);
    printf("%d\n",n);
    int i;
    srand (time(NULL));
    for (i = 0; i < n; i++)
    {
        printf("%d\n",abs(rand() % MOD));
    }
    return 0;
}
