#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main ()
{
  int ax,bx,cx;
  int ay,by,cy;
  scanf("%d%d",&ax,&ay);
  scanf("%d%d",&bx,&by);
  scanf("%d%d",&cx,&cy);
  int x,y;
  x = bx - cx;
  y = by - cy;
  int it[4][2];
  it[0][0] = ax;
  it[0][1] = ay;
  it[1][0] = ax + ay;
  it[1][1] = ay - ax;
  it[2][0] = it[1][0] - ax;
  it[2][1] = it[1][1] - ay;
  it[3][0] = it[2][0] - ay;
  it[3][1] = it[2][1] + ax;
  int i;
  int flag1,flag2;
  for (i = 0; i < 4; i++)
    {
      flag1 = flag2 = 0;
      if (it[i][0] == 0 && x)
	continue;
      else if (it[i][1] == 0 && y)
	continue;
      if ((it[i][0] == 0 && !x) || (x%it[i][0] == 0))
	{
	  flag1 = 1;
	}
      if ((it[i][1] == 0 && !y) || (y%it[i][1] == 0))
	{
	  flag2 = 1;
	}
      if (flag1 && flag2)
	{
	  printf("YES");
	  return 0;
	}
    }
  printf("NO");
  return 0;
}
