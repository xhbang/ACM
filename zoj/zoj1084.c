#include <stdio.h>
#include <memory.h>
#define N 26

int adj[N][N];
int used[N];
int n;

int dfs(int id,int color){
	int i,j;
	for(i=0;i<color;i++){
		int flag=1;
		//MUST
		used[id]=i;
		//==i
		for(j=0;j<n;j++){
			if(j==id)
				continue;
			else{
				if(adj[id][j]&&used[j]==used[id]){
					flag=0;
					break;
				}
			}
		}
		if(flag && (id==n-1||dfs(id+1,color)))
			//color
			return 1;
	}
	return 0;
}

int main(){
	int i,j;
	char line[28];

	/*
	memset(adj,0,sizeof(adj));
	memset(used,0,sizeof(used));
	*/

	while(scanf("%d",&n)&&n){
		int firstok=1;
		memset(adj,0,sizeof(adj));
		memset(used,0,sizeof(used));
		for(i=0;i<n;i++){
			//gets(line);
			scanf("%s",line);
			for(j=2;line[j];j++,firstok=0){
				adj[i][line[j]-'A']=1;
				adj[line[j]-'A'][i]=1;
			}
		}
		if(firstok)
			printf("1 channel needed.\n");
		else if(dfs(1,2))
			printf("2 channels needed.\n");
		else if(dfs(1,3))
			printf("3 channels needed.\n");
		else
			printf("4 channels needed.\n");
	}
	return 0;
}
