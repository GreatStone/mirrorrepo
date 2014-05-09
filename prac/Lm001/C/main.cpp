#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;

char save[100010];
pii sum [26];
int is[26];
int vis[26];
char res[100010];

int com (pii a, pii b)
{
    return a.second < b.second;
}

int main()
{
    int k;
    scanf("%s%d",save,&k);
    int len = strlen (save);
    if (len <= k)
    {
        printf("0\n\n");
        return 0;
    }
    int i;
    for (i = 0; i < 26; i++)
    {
        sum[i] = pii(i,0);
    }
    for (i = 0; i < len; i++)
    {
        sum[save[i] - 'a'].second++;
    }
    sort (sum,sum+26,com);
    int flag = 0;
    int q = k;
    for (i = 0; i < 26; i++)
    {
        q -= sum[i].second;
        if (q < 0)
        {
            break;
        }
        else
        {
            is [sum[i].first ] = 1;
        }
    }
    int cur = 0;
    int u = 0;
    for (i = 0; i < len; i++)
    {
        if (is[save[i] - 'a' ])
            continue;
        else
        {
            if (!vis[save[i] - 'a'])
            {
                vis[save[i] - 'a'] = 1;
                u++;
            }
            res[cur++] = save[i];
        }
    }
    res[cur] = 0;
    printf("%d\n%s\n",u,res);
    return 0;
}
