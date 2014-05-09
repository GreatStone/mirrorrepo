#include <iostream>
#include <cstdio>
using namespace std;

int n;
int save[200][200];
int sum[200][200];
int sesum [200][200];

int main()
{
    scanf ("%d",&n);
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf ("%d",save[i] + j);
            if (!j)
            {
                sesum[i][j] = save[i][j];
            }
            else
            {
                sesum[i][j] = sesum[i][j-1] + save[i][j];
            }
        }
    }
    int s,e;

    int tmp;
    for (s = 0; s < n; s++)
    {
        for (e = s; e < n; e++)
        {
            tmp = 0;
            for (i = 0; i < n; i++)
            {

            }
        }
    }

    return 0;
}
