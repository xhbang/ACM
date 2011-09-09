#include <stdio.h>
#include <memory.h>

#define MAX 1025

int tree[MAX][MAX];
int n;

int update(int i,int j,int add){
	int t;
	while(i<=n){
		t=j;
		while(t<=n){
			tree[i][t]+=add;
			t+=(t&-t);
		}
		i+=(i&-i);
	}
}

int getsum(int x,int y){
	int i,j;
	int sum=0;
	for(i=x;i>0;i-=(i&-i))
		for(j=y;j>0;j-=(j&-j))
			sum+=tree[i][j];
	return sum;
}

int main(){
	int sum,none;
	int x1,y1,x2,y2,val;
	memset(tree,0,sizeof(tree));
	scanf("%d%d",&none,&n);
	while(scanf("%d",&none)&&none!=3){
		switch(none){
			case 1:
				scanf("%d%d%d",&x1,&y1,&val);
				x1++,y1++;
				update(x1,y1,val);
				break;
			case 2:
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				x1++,y1++,x2++,y2++;
				sum=getsum(x2,y2)-getsum(x1-1,y2)-getsum(x2,y1-1)+getsum(x1-1,y1-1);
				printf("%d\n",sum);
				break;
		}
	}
	return 0;
}
