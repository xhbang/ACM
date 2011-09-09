#include <stdio.h>
#define N 10000

struct{
	int minx,miny;
	int maxx,maxy;
}a[N];

int main(){
	int i,j,n,sum;
	while(scanf("%d",&n)!=EOF){
		int t=n;
		while(n--)
			scanf("%d%d%d%d",&a[n].minx,&a[n].maxx,&a[n].miny,&a[n].maxy);
		sum=0;
		for(i=0;i<t;i++){
			for(j=0;j<t;j++){
				if(j!=i&&a[j].maxx>=a[i].maxx&&a[j].minx<=a[i].minx&&a[j].maxy>=a[i].maxy&&a[j].miny<=a[i].miny){
					sum++;
					break;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
