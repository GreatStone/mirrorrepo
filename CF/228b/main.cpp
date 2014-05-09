#include <iostream>
#include <cstdio>
using namespace std;

int flag[200][200];
int main()
{
    int n;
    scanf("%d",&n);
    char save[200][200];
    int i,j;
    int count = 0;
    int jing = 0;
    for (i = 0; i < n; i++)
    {
        scanf ("%s",save[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (save[i][j] == '#')
            jing++;
        }
    }
    for (i = 1; i < n-1; i++)
    {
        for (j = 1; j < n-1; j++)
        {
            if (save[i][j] == '#')
            {
                if (flag[i][j])
                    continue;
                if (save[i][j-1] == '#' && save[i][j+1] == '#' && save[i+1][j] == '#' && save[i-1][j] == '#')
                {
                    if (!flag[i][j-1] && !flag[i][j+1] && !flag[i+1][j] && !flag[i-1][j])
                    {
                        flag[i][j] = flag[i][j-1] = flag[i][j+1] = flag[i+1][j] = flag[i-1][j] = 1;
                        count += 5;
                    }
                }
            }
        }
    }
    if (count < jing)
    printf("NO");
    else
    printf("YES");
    return 0;
}
