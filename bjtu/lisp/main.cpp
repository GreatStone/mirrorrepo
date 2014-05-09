#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
using namespace std;

int getres (char* source)
{
    int i;
    int len = strlen(source);
    for (i = 0; i < len; i++)
    {
        if (source[i] == '(' || source[i] == ')')
            source[i] = ' ';
    }
    source[len] = ';';
    source[len+1] = 0;
    char be[1000];
    char tmp[1000];
    char t2[1000];
    for (;;)
    {
        sscanf (source,"%s%[^\n]",tmp,source);
        if (tmp[0] == ';')
        {
    /*        printf("%s",be);
            return 1;
            */
            break;
        }
        sprintf(t2,"%s %s",tmp, be);
        sprintf(be,"%s",t2);
    }
    stack<int> stc;
    len = strlen(be);
    be[len] = ' ';
    be[len+1] = ';';
    be[len+2] = 0;
    char op[50];
    int a,b;
    for (;;)
    {
        sscanf(be,"%s%[^\n]",op,be);
        if (op[0] == ';')
            break;
        if (op[0] == '+')
        {
            a = stc.top();
            stc.pop();
            b = stc.top();
            stc.pop();
            stc.push(a + b);
        }
        else if (op[0] == '-')
        {
            a = stc.top();
            stc.pop();
            b = stc.top();
            stc.pop();
            stc.push(a - b);
        }
        else if (op[0] == '*')
        {
            a = stc.top();
            stc.pop();
            b = stc.top();
            stc.pop();
            stc.push(a * b);
        }
        else if (op[0] == '/')
        {
            a = stc.top();
            stc.pop();
            b = stc.top();
            stc.pop();
            stc.push(a / b);
        }
        else
        {
            sscanf (op,"%d",&a);
            stc.push(a);
        }
    }
    return stc.top();
}
int main()
{
    freopen ("in.txt","r",stdin);
    freopen ("out.txt","w",stdout);
    int T;
    int cas;
    scanf ("%d",&T);
    char save[1000];
    for (cas = 1; cas <= T; cas++)
    {
        getchar();
        gets(save);
        printf("Case #%d: %d\n",cas,getres(save));
    }
    return 0;
}
