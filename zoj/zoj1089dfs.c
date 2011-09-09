#include <stdio.h>
int ans[5];
int input[12];
int n;

void dfs(int d,int now){
	int i;
	if(d>5)
		printf("%d %d %d %d %d %d\n",ans[0],ans[1],ans[2],ans[3],ans[4],ans[5]);
	else
		for(i=now;i<n-(6-d)+1;i++){
			//此处注意i的临界值，加1是必须的
			ans[d]=input[i];
			dfs(d+1,i+1);
		}
}

int main(){
	int flag=1;
	int i;
	while(scanf("%d",&n)&&n){
		if(flag==0)
			printf("\n");
		for(i=0;i<n;i++){
			scanf("%d",&input[i]);
		}
		dfs(0,0);
		flag=0;
	}
	return 0;
}
