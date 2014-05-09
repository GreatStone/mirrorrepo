#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;

typedef pair<string,int> psi;

string save[1010];

int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int i,j;
        map <string,int> vis;
        int flag = 1;
        for (i = 0; i < n; i++)
        {
            cin >> save[i];
            if (save[i] == "russian")
                flag = 0;
        }
        if (!flag)
        {
            printf("Igor is wrong.\n");
            continue;
        }
        int len;
        int num = 0;
        for (len = n; len >= 1; len--)
        {
            if (n % len)
                continue;
            vis.clear();
            int res = n/len;
            int flag = 1;
            string cur;
            for (i = 0; i < res; i++)
            {
                cur = ".";
                for (j = len*i; j < len*(i+1); j++)
                {
                    if (save[j] == "unknown")
                        continue;
                    if (cur != "." && cur != save[j])
                    {
                        flag = 0;
                        break;
                    }
                    else if (cur == ".")
                    {
                        cur = save[j];
                    }
                }
                if (!flag)
                    break;
                if (cur != ".")
                {
                    if(vis.find(cur) != vis.end())
                    {
                        flag = 0;
                        break;
                    }
                    else
                        vis.insert(psi(cur,0));
                }
            }
            if (flag)
            {
                printf("%d ",n/len);
                num++;
            }
        }
        if (!num)
        printf("Igor is wrong.");
        printf("\n");
    }
    return 0;
}
