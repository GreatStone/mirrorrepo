#include "stdio.h"
#include <iostream>
#include <queue>
using namespace std;

int move[4][2];
int n,m,ini,inj,a,b;

typedef struct {
	int x;
	int y;
	int step;
} point;

queue <point> que;

int in (int x ,int y)
{
	return x >= 1 && x <= n && y >= 1 && y <= m;
}

int conner (point source)
{
	return (source.x == 1 || source.x == n) && (source.y == 1 && source.y == m);
}

int abs (int x)
{
    return (x < 0 ? -x : x);
}

int main (){
	scanf ("%d%d%d%d%d%d",&n,&m,&ini,&inj,&a,&b);
	int con[4][2] = {1,m,n,1,n,m,1,1};
	int resultx,resulty;
	int disx,disy;
	int tmpx,tmpy;
	int i;
	resultx = 1000000000;
	resulty = 1000000000;
	int get = 0;
	for (i = 0; i < 4; i++)
	{
	    disx = abs(con[i][0]-ini);
	    disy = abs(con[i][1] - inj);
	    if (disx % a || disy % b)
            continue;
        else
        {
            tmpx = disx / a;
            tmpy = disy / b;
            if ((tmpx > tmpy ? tmpx : tmpy) < (resultx > resulty ? resultx : resulty) && tmpx % 2== tmpy % 2)
            {
                resultx = tmpx;
                resulty = tmpy;
                get = 1;
            }
        }
	}
	if (!get || !in(ini,inj))
	printf("Poor Inna and pony!\n");
	else
	printf("%d\n",resultx>resulty ? resultx : resulty);
	return 0;
}
