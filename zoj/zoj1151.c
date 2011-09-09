#include <stdio.h>
#include <string.h>

int main(){
	int n,i,j,k;
	int in,len;
	char t;
	char str[1000];
	scanf("%d",&in);
	while(in--){
		scanf("%d\n",&n);
		while(n--){
			gets(str);
			j=0;
			k=0;
			len=strlen(str);
			for(i=0;i<len;i++){
				j=i+1;
				while(j<len&&str[j]!=' ' )
					j++;
				for(k=0;k<(j-i)/2;k++){
					t=str[i+k];
					str[i+k]=str[j-k-1];
					str[j-k-1]=t;
				}
				i=j;
			}	
			puts(str);
		}
		if(in)
			printf("\n");
	}
	return 0;
}
