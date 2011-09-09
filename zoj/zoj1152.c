#include <stdio.h>

int main(){
	int n,m,d,a,b,i,j,ans;
	scanf("%d",&d);
	for(i=0;i<d;i++){		
		if(i)
			printf("\n");
		j=1;
		while(scanf("%d%d",&n,&m)&&(n||m)){
			ans=0;
			for(a=1;a<n;a++)
				for(b=a+1;b<n;b++)
					if(!((a*a+b*b+m)%(a*b)))
						//!(),or will wa
						ans++;	
			printf("Case %d: %d\n",j++,ans);
		}
	}
	return 0;
}
