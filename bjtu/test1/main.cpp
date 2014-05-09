#include "stdio.h"
#include "string.h"

int main()
{
  //  freopen("2.in","r",stdin);
    freopen("out","w",stdout);
    char c;
    int i, n, j;

    scanf("%d", &n);
    i = 0;
    j = 0;
    getchar();
    while (i < n)
    {
        c = getchar();
        j++;
        if (c == '\n' && j != 1)
        {
            i++;
            j = 0;
            printf("%s\n", "YES");
            continue;
        }
        if (c == '\n' && j == 1)
        {
            j = 0;
            continue;
        }
        if (j == 1 && !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_'))
        {
            printf("%s\n", "NO");
            i++;
            j = 0;
            while (c != '\n')
                c = getchar();
            continue;
        }
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == '_' || (c >= '0' && c <='9')))
        {
            printf("%s\n", "NO");
            i++;
            j = 0;
            while (c != '\n')
                c = getchar();
            continue;
        }
    }
    return 0;
}
