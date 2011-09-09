#include <stdio.h>
#include <string.h>

int main(){
	int n,m,i,j;
	scanf("%d",&n);
	while(n--){
		while(scanf("%d",&m)&&m){
			//开始写成&d了。
			int sum=0;
			int val=0;
			char in[200];
			//最好开大点，要不然WA
			scanf("%s",in);
			int len=strlen(in);
			for(i=0;i<len;i++){
				j=in[i]-'0';
				sum+=j;
				val=m*val+j;
			}
			(val%sum==0)?printf("yes\n"):printf("no\n");
		}
		if(n)
			printf("\n");
	}
	return 0;
}
