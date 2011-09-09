#include <stdio.h>
#include <string.h>
#define MAX 100
//don't forget string.h

int main(){
	int i,j;
	char src[MAX];
	while(scanf("%s",src)!=EOF){	//do not use &src
		char dest[MAX]={'0'};
		int index=0;				//put index here before one operation
		for(i=strlen(src)-1;i>1;i--){
			int num=src[i]-'0';
			for(j=0;j<index ||num;j++){
				int temp=num*10+(j<index?dest[j]-'0':0);
				dest[j]=temp/8+'0';	//do not forget +'0'
				num=temp%8;
			}
			index=j;
		}
		dest[j]='\0';
		printf("%s [8] = 0.%s [10]\n",src,dest);
	}
	return 0;
}
