#include <stdio.h>
#include <memory.h>

#define N 8
int king[N][N];
int tx[]={1,1,2,2,-1,-1,-2,-2};
int ty[]={2,-2,1,-1,2,-2,1,-1};

void dfs(int x,int y,int move){
	if(x<0 ||x>7 ||y<0 ||y>7||king[x][y]<=move)
		return;
	int i;
	king[x][y]=move;
	for(i=0;i<8;i++){
		dfs(x+tx[i],y+ty[i],move+1);
	}
}

int main(){
	int x,y;
	char a[10],b[10];
	while(scanf("%s%s",a,b)!=EOF){
		memset(king,10,sizeof(king));
		x=a[0]-'a';
		y=a[1]-'1';
		dfs(x,y,0);
		printf("To get from %s to %s takes %d knight moves.\n",a,b,king[b[0]-'a'][b[1]-'1']);
	}
	return 0;
}
