#include <iostream>
#include "stdio.h"
#include <cstring>
using namespace std;

int save[6000];

void getpre (char* source, int* pre)
{
    int i,j;
    int len = strlen (source);
    pre[0] = pre[1] = 0;
    for (i = 1; i < len; i++)
    {

    }
}

int main()
{
    char tmp [100];
    tmp[0] = 1;
    scanf ("%s",tmp+1);
    int pre[100];
    getpre (tmp,pre);
    for (int i = 0; i < strlen (tmp); i++)
    {
        cout << pre[i] << endl;
    }
    return 0;
}
