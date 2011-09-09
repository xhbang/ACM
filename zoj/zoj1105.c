#include <stdio.h>
#include <math.h>

double dist(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main(){
	double x0,y0;
	double x1,y1,x2,y2;
	char in[30];
	while(scanf("%lf%lf\n",&x0,&y0)!=EOF){
		double distance=0;	
		//放这里，每次case都要清零
		gets(in);
		//用g++编译时会报the "gets" function is dangerous and should not be used这个warning,不理会
		while(in[0]!='j'){
			sscanf(in,"%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			//sscanf很使用
			distance+=dist(x1,y1,x2,y2);
			gets(in);
		}	
		distance=2*60*distance/20000.0;
		int time=floor(distance+0.5);
		//舍入
		printf("%d:%02d",time/60,time%60);
		//打印
	}
	return 0;
}
