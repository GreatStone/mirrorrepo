#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int save[200][200];

int n,m;

int is (int rows)
{
  int i,j;
  for (i = 0; i < rows / 2; i++)
    {
      for (j = 0; j < m; j++)
	{
	  if (save[i][j] != save[rows - 1 - i][j])
	      return 0;
	}
    }
  return 1;
}

int main ()
{
  scanf("%d%d",&n,&m);
  int i,j;
  for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
	{
	  scanf("%d",save[i] + j);
	}
    }
  int rows = n;
  for (;rows>0;)
    {
      if(rows % 2)
	{
	  printf("%d",rows);
	  return 0;
	}
      if (is (rows))
	rows /= 2;
    }
  return 0;
}
