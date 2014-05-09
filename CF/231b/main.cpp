#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char save[15][1000010];

int main()
{
    int p,x;
    scanf("%d%d",&p,&x);
    int add[15];
    int i,j;
    for (i = 0; i < 10; i++)
    {
        save[i][0] = i;
        add[i] = 0;
    }
    for (j = 1; j <= p; j++)
    {
        for (i = 0; i < 10; i++)
        {
            int dtmp = x * save[i][j-1] + add[i];
            save[i][j] = dtmp%10;
            add[i] = dtmp/10;
        }
    }

    int is[15];
    int num = 10;
    for (i = 0; i < 10; i++)
    is[i] = 1;
    for (i = 0; i < 10; i++)
    {
        if (save[i][0] != save[i][p] || add[i] != 0 || save[i][p-1] == 0 || save[i][p] == 0)
        {
            is[i] = 0;
            num--;
        }
    }
    if (num == 0)
    {
        printf("Impossible");
        return 0;
    }
    for (i = p-1; i >= 0 && num > 1; i--)
    {
        int min = 9;
        for(j = 0; j < 10; j++)
        {
            if (!is[j])
            continue;
            if (save[j][i] < min)
            min = save[j][i];
        }
        for(j = 0; j < 10; j++)
        {
            if (!is[j])
            continue;
            if (save[j][i] > min)
            {
                is[j] = 0;
                num--;
            }
        }
    }


    for (i = 0; i < 10; i++)
    {
        if (is[i])
        {
            for (j = p-1; j >= 0; j--)
            {
                printf("%c",save[i][j] + '0');
            }
            printf("\n");
            return 0;
        }
    }
    return 0;
}
