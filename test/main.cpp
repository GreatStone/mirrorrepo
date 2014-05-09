//B. Sysadmin Bob

#include "stdio.h"
#include "string.h"
int x()
{
    char save[500];
    int index[500];
    long long int depart[500];
    memset ((void*)index,0,500*sizeof(int));
    memset ((void*)depart,0,500*sizeof(long long int));
    if (scanf ("%s",save) == EOF)
        return 1;
    int len = strlen(save);
    if (save[0] == '@' || save[len-1] == '@')
    {
        printf("No solution\n");
        return 0;
    }
    int i;
    int indde = 0;
    for (i = 0; i < len; i++)
    {
        if (save[i] == '@')
        {
            indde++;
            index[i+1] = 1;
            if (save[i+2] == '@' || save[i+1] == '@')
            {
                printf("No solution\n");
                return 0;
            }
        }
        else
        {
            depart[indde]++;
        }
    }
    for (i = len-1; i >= 0; i--)
    {
        if (index[i])
        {
            index[i] = 0;
            break;
        }
    }
    long long int mul = 1;
    for (i = 1; i < indde; i++)
    {
        mul *= depart[i]-1;
    }
    if (mul < 1 || indde < 1)
    {
        printf("No solution\n");
        return 0;
    }
    if (mul != 1)
    {
        printf ("%lld\n",mul);
        return 0;
    }
    for (i = 0; i < len; i++)
    {
        printf("%c",save[i]);
        if (index[i])
            printf(",");
    }
    printf("\n");
    return 0;
}

int main()
{
    freopen ("test","r",stdin);
    freopen("out","w",stdout);
    for (int i = 0; i < 76; i++)
    {
       if (x())
            return 0;
    }
}
