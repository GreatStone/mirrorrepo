#include <iostream>
#include "stdio.h"
#include "algorithm"
#include "string.h"
using namespace std;

int main()
{
    int n,k;
    char getin[20];
    scanf("%d%d",&n,&k);
    int i,j;
    int sum = 0;
    for (i = 0; i < n; i++){
        scanf("%s",getin);
        int len = strlen(getin);
        int diflen = unique(getin,getin + len) - getin;
        getin[diflen] = 0;
        sort (getin,getin + strlen(getin));
        if (strlen(getin) < k+1)
            continue;
        else
        {
            if (getin[k] == k + '0')
            {
                sum++;
                printf("1\n");
            }
            else
            {
                printf("0\n");
            }
        }
    }
    printf("%d",sum);
    return 0;
}
