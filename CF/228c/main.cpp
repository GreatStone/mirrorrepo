#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int save[200];
    scanf ("%d",&n);
    int i,j;
    for (i = 0; i < n; i++)
    {
        scanf("%d",save+i);
    }
    sort (save,save+n);
    int pile = 1;
    int heigh[200];
    memset (heigh,0,sizeof(int)*200);
    int done;
    for (i = 0; i < n; i++)
    {
        done = 0;
        for (j = 0; j < pile; j++)
        {
            if (save[i] >= heigh[j])
            {
                heigh[j]++;
                done = 1;
                break;
            }
        }
        if (!done)
        {
            heigh[pile]++;
            pile++;
        }
    }
    printf("%d",pile);
    return 0;
}
