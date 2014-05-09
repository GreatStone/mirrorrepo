#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    int sizem,sizen;
    printf("please input the number of rows of this martrix.\n");
    scanf("%d",&sizem);
    printf("please input the number of columns of this martrix.\n");
    scanf ("%d",&sizen);

    int* martrix = (int*)malloc (sizeof (int) * sizem * sizen);
    int* minrow = (int*) malloc (sizeof (int) * sizem);
    memset (minrow, 0, sizeof (minrow));
    int* maxclo = (int*) malloc (sizeof (int) * sizen);
    memset (maxclo, 0, sizeof (maxclo));

    int i,j;
    printf("please input the elements in this martrix.\n");
    for (i = 0; i < sizem; i++)
    {
        for (j = 0; j < sizen; j++)
        {
            scanf("%d",martrix + i * sizen + j);
            if (martrix[i * sizen + j] < martrix[i * sizen + minrow[i]])
            {
                minrow[i] = j;
            }
            if (martrix[i * sizen + j] > martrix[maxclo[j] * sizen + j])
            {
                maxclo[j] = i;
            }
        }
    }

    for (i = 0; i < sizem; i++)
    {
        if (maxclo[minrow[i]] == i)
        {
            printf("one of the saddle points is located at (%d,%d), its value is %d",i+1,minrow[i]+1,martrix[i * sizen + minrow[i]]);
        }
    }

    return 0;
}
