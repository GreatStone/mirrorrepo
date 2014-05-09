#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main ()
{
  int save[200];
  int n,s;
  int i;
  scanf("%d%d",&n,&s);
  int sum = 0;
  for (i = 0; i < n; i++)
    {
      scanf("%d",save + i);
      sum += save[i];
    }
  sort(save,save + n);
  sum -= save[n-1];
  if (sum <= s)
    printf("YES");
  else
    printf("NO");
  return 0;
}
