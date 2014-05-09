#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int get[30];

int main()
{
    char in[200];
    scanf("%s",in);
    memset(get,0,sizeof(get));
    int i;
    for(i = 0; i < strlen(in); i++)
    {
        get[in[i] - 'a']++;
    }
    int a[5];
    a[0] = (get['n' - 'a'] - 1)/2;
    a[1] = get['i' - 'a'];
    a[2] = get['e' - 'a'] / 3;
    a[3] = get['t' - 'a'];
    int res = 99999;
    for (i = 0; i < 4; i++)
    {
        if (a[i] < res)
         res = a[i];
    }
    printf("%d",res);
    return 0;
}
