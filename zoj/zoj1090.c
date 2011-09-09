#include <stdio.h>
#include <math.h>
#define PI acos(-1)

int main(){
	double x1,y1,x2,y2,x3,y3;
	double a2,b2,c2,r;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF){
		a2=pow((x1-x2),2)+pow((y1-y2),2);
		b2=pow((x2-x3),2)+pow((y2-y3),2);
		c2=pow((x1-x3),2)+pow((y1-y3),2);
		r=sqrt(c2/(1-pow((a2+b2-c2),2)/a2/b2/4))/2;
		printf("%.2lf\n",2*PI*r);
	}
	return 0;
}
