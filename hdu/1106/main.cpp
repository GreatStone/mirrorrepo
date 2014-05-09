#include <stdio.h>
#include <math.h>

	struct point{
	double x;
	double y;}point[10];

	double Dist(struct point p1,struct point p2);

int main()
{
	int i,n;
	double drray[9];

	for(i=0;i<10;i++){
		printf("Enter point p%d:\n",i);
		scanf("%lf%lf",&point[i].x,&point[i].y);
	}

	for(n=0;n<9;n++)
		drray[n]=Dist(point[0],point[n]);


	double max;
	int m;
	max=drray[0];

	for(m=1;m<9;m++){
		if(drray[m]>max)
			max=drray[m];
	}

	printf("Max disance=%lf\n",max);

return 0;
}


double Dist(struct point p1,struct point p2)
{
	double a=p1.x-p2.x;
	double b=p1.y-p2.y;

	double d;
	d=sqrt(a*a+b*b);

	return d;
}
