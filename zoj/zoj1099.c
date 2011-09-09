#include <stdio.h>
#include <string.h>

int main(){
	int count=0;
	char word[20];
	while(scanf("%s",word)!=EOF){
		if(strcmp(word,"<hr>")==0){
			if(count!=0)
				printf("\n");
			int i;
			for(i=0;i<80;i++)
				printf("-");
			printf("\n");
			count=0;
		}
		else if(strcmp(word,"<br>")==0){
			printf("\n");	
			count=0;
		}
		else{
			if(count+strlen(word)+(count==0?0:1)>80){
				//if begins,do not add space
				printf("\n%s",word);
				count=strlen(word);
			}else{
				if(count!=0){
					printf(" ");
				}
				printf("%s",word);
				count+=strlen(word)+1;
				//1 for space
			}
		}
	}
	printf("\n");
	return 0;
}
