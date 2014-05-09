#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <stack>
using namespace std;

char save[200010];
char res[200010];

int main()
{
    while (scanf("%s",save) != EOF)
    {
        int cur = 0;
        stack<char> s;
        int i;
        int len = strlen (save);
        for (i = 0; i < len; i++)
        {
            if (!s.empty())
            {
                if (s.top() == save[i])
                {
                    s.pop();
                    cur--;
                }
                else
                {
                    res[cur++] = save[i];
                    s.push(save[i]);
                }
            }
            else
            {
                res[cur++] = save[i];
                s.push(save[i]);
            }
        }
        res[cur] = 0;
        printf("%s\n",res);
    }
    return 0;
}
