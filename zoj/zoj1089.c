#include <stdio.h>
int input[12];

int main(){
	int line=0;
	int n;
	while(scanf("%d",&n)&&n){
		if(line)
			printf("\n");
		for(int i=0;i<n;i++){
			scanf("%d",&input[i]);
		}
		for(int a=0;a<n-5;a++)
			for(int b=a+1;b<n-4;b++)
				for(int c=b+1;c<n-3;c++)
					for(int d=c+1;d<n-2;d++)
						for(int e=d+1;e<n-1;e++)
							for(int f=e+1;f<n;f++){
								printf("%d %d %d %d %d %d\n",input[a],input[b],input[c],input[d],input[e],input[f]);
							}
		line=1;

	}
}
