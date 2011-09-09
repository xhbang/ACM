#include <stdio.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define min4(a,b,c,d) (min(min(a,b),min(c,d)))

int main(){
	int p2,p3,p5,p7,n=1;
	p2=p3=p5=p7=1;
	int ans[5843];
	ans[1]=1;
	while(n<5842){
		ans[++n]=min4(2*ans[p2],3*ans[p3],5*ans[p5],7*ans[p7]);
		//don not use 2*p2 instead of 2*ans[p2]
		//don not use switch,constant required
		if(ans[n]==2*ans[p2])
			p2++;
		if(ans[n]==3*ans[p3])
			p3++;
		if(ans[n]==5*ans[p5])
			p5++;
		if(ans[n]==7*ans[p7])
			p7++;
	}
	while(scanf("%d",&n)&&n!=0){
		printf("The %d",n);
		if(n/10%10!=1){
			if(n%10==1)
				printf("st");
			else if(n%10==2)
				printf("nd");
			else if(n%10==3)
				printf("rd");
			else 
				printf("th");
		}
		else
			printf("th");
		printf(" humble number is %d.\n",ans[n]);
	}
}
