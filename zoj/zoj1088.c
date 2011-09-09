#include <stdio.h>
#include <memory.h>

#define MAX 150

int main(){
	int n,i,j;
	int cut[MAX];
	int next[MAX];
	while(scanf("%d",&n)&&n){
		int m=1;
		int find=0;
		//careful when make links
		next[n]=1;
		for(i=1;i<n;i++){
			next[i]=i+1;
		}
		while(!find){
			memset(cut,0,sizeof(cut));
			m++;
			int left=n;
			int from=1;
			//remember to cut by 1
			left=n-1;
			cut[1]=1;
			while(left>1){
				int jump=0;
				j=from;
				while(jump<m){
					j=next[j];
					if(!cut[j])
						jump++;
				}
				//mark and cut
				cut[j]=1;
				left--;
				from=j;
				if(from==2&&left!=1){
					break;
				}
			}
			if(left==1&&cut[2]==0){
				find=1;	
			}
		}
		printf("%d\n",m);
	}
	return 0;
}
