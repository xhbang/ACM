#include <stdio.h>

int main(){
	char in;
	while(1){
		int sum=0;
		while(scanf("%c",&in)&&in!='\n'){
			sum+=in-'0';	
		}
		if(sum==0)
			break;
		else if(sum%9==0)
			sum=9;
		else
			sum=sum%9;
		printf("%d\n",sum);
	}
	return 0;
}
