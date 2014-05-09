#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int i,j;
    char tmp[5];
    int count[3];
    count[0] = count[1] = count[2] = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j ++)
        {
            scanf("%s",tmp);
            count[tmp[0] + tmp[1] - '0' - '0']++;
        }
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (count[2] > 0)
            {
                printf("11");
                count[2]--;
            }
            else if (count[1] > 0)
            {
                if (i % 2)
                printf("01");
                else
                printf("10");
                count[1]--;
            }
            else
            {
                printf("00");
                count[0]--;
            }
            if (j < m-1)
            printf(" ");
        }
        printf("\n");
        if (count[2] == 0)
        {
            break;
        }
    }
    for (i++; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (count[0] > 0)
            {
                printf("00");
                count[0]--;
            }
            else
            {
                if (i % 2)
                printf("01");
                else
                printf("10");
                count[1]--;
            }

            if (j < m-1)
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
